#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
vector<LL> prim;
vector<LL> vis;
void getp(LL n){
    for(LL i=2;i<=n;i++){
        if(!vis[i])prim.push_back(i);
        for(auto p:prim){
            if(p*i>N)break;
            vis[p*i]=1;
            if(i%p==0)break;
        }
    }
}
void init(){
    vis.assign(N+10,0);
    getp(N);
    // for(int i=0;i<=10;i++){
    //     printf("{%lld}",prim[i]);
    // }
}
LL getcnt(LL r,LL n){
    if(r==0)return 0;
    if(r==1)return 1;
    LL x=n;
    vector<LL> a;
    LL ans=0;
    for(auto p:prim){
        if(x%p==0)a.push_back(p);
        while((x%p)==0){
            x=x/p;
        }
        if(x==1)break;
    }
    LL siz=a.size();
    LL m=(1<<siz)-1;
    // for(int i=0;i<siz;i++){
    //     printf("<%lld>",a[i]);
    // }
    for(int i=0;i<=m;i++){
        LL cnt=0;
        LL d=1;
        for(int j=0;j<siz;j++){
            if(i&(1<<j)){
                d*=a[j];
                cnt++;
            }
        }

        if(cnt){
            LL c=(r/d);
            
            if(cnt&1){
                ans+=c;
            }else{
                ans-=c;
            }   
            //printf("{%lld,%lld,%lld}",c,d,ans);         
        }


    }
    return r-ans;
}
void solve(){
    LL l,r,n;
    cin>>l>>r>>n;
    LL p=upper_bound(prim.begin(),prim.end(),n)-prim.begin()-1;
    //printf("\n|%lld,%lld|",p,prim[p]);
    auto check=[&](LL lt,LL rt)->LL{
        LL m=n-lt;
        vector<LL> dp(m+1,1e9);
        dp[1]=__gcd(n-1,n);
        for(int i=2;i<=m;i++){
            for(int j=1;j<=i-1;j++){
                dp[i]=min({dp[j]+__gcd(n-i,n-j),dp[i],__gcd(n-i,n)});
            }
        }
        LL sum=0;
        for(int i=1;i<=m;i++){
            if((n-i<=rt)&&(n-i>=lt))sum+=dp[i];
        }
        return sum;
    };
    if(p<0||prim[p]<l){
        LL ans=check(l,r);
        cout<<ans<<'\n';
        //printf("|");
        return;
    }
    LL ans=0;
    LL c=getcnt(min(r,prim[p]),n)-getcnt(l-1,n);
    //LL c=2;
    
    ans+=c;
    LL s=min(r,prim[p])-l+1-c;
    //printf("{%lld,%lld}",c,s);
    ans+=2*s;
    if(prim[p]+1<=r){
        ans+=check(prim[p]+1,r);
        //printf("<{%lld}>",check(prim[p]+1,r));  
    }
    // if(prim[p]<r){

    // }
    cout<<ans<<'\n';
}
int main(){
    init();
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}