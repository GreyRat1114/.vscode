#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
struct Tree{
    LL n;
    vector<LL> s;
    void init(LL _n){
        n=_n;
        s.assign(n+1,0);
    }
    LL lowbit(LL x){
        return x&-x;
    }
    void update(LL x,LL k){
        while(x<=n){
            s[x]+=k;
            x+=lowbit(x);
        }
    }
    LL query(LL x){
        LL ans=0;
        while(x){
            ans+=s[x];
            x-=lowbit(x);
        }
        return ans;
    }
};


void solve(){
    LL n;
    cin>>n;
    
    vector<LL> a(n+1);
    vector<pair<LL,LL>> b;
    LL m=3e5;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m=max(m,a[i]);
        if(i!=1&&i!=n)b.push_back({a[i],i});
    }
    if(n==1||n==2){
        cout<<0<<'\n';
        return;
    }
    LL def=0;
    LL add=0;

    for(int i=4;i<=n;i++){
        LL x=a[i-3]+a[i-1];
        LL y=a[i-2]+a[i];
        if(a[i-2]-a[i-1]>0&&x-y>0){
            def++;
        }else if(a[i-2]-a[i-1]<0&&x-y<0){
            def++;
        }
        LL u=(a[i-3]-a[i-2])*(a[i-3]-a[i-2])+(a[i-2]-a[i-1])*(a[i-2]-a[i-1])+(a[i-1]-a[i])*(a[i-1]-a[i]);
        LL v=(a[i-3]-a[i-1])*(a[i-3]-a[i-1])+(a[i-2]-a[i-1])*(a[i-2]-a[i-1])+(a[i-2]-a[i])*(a[i-2]-a[i]);
        if(v>u)add++;
    }
    //printf("{%lld,%lld}",def,add);
    sort(b.begin(),b.end());
    Tree tr;

    tr.init(2*m+5);
    LL ans=0;
    LL len=0;
    vector<int> e;
    for(int i=0;i<n-2;i++){
        
        LL d=a[b[i].second-1]+a[b[i].second+1];
        LL c=tr.query(d-1);
        //printf("|%lld|\n",c);
        ans+=c;
        if(b[i].first == b[i+1].first) e.push_back(d);
        else{
            for(int& x : e) tr.update(x,1);
            tr.update(d,1);
            e.clear();
        }
    }
    //printf("{%lld}\n",ans);
    // sort(b.begin(),b.end(),cmp);
    // Tree tr2;
    // tr2.init(2*m+5);
    // for(int i=0;i<n-2;i++){
    //     LL d=a[b[i].second-1]+a[b[i].second+1];
    //     LL c=tr2.query(m)-tr2.query(d);
    //     //printf("|%lld|\n",c);
    //     ans+=c;
    //     tr2.update(d,1);
    // }    
    
    ans-=def;
    ans+=add;
    //printf("{%lld}\n",ans);
    add=0;
    //printf("{%lld}\n",ans);
    for(int i=3;i<=n-1;i++){
        LL u=(a[2]-a[1])*(a[2]-a[1]);
        LL v=(a[2]-a[i])*(a[2]-a[i]);
        u+=(a[i]-a[i+1])*(a[i]-a[i+1])+(a[i-1]-a[i])*(a[i-1]-a[i]);
        v+=(a[1]-a[i+1])*(a[1]-a[i+1])+(a[i-1]-a[1])*(a[i-1]-a[1]);
        if(v>u)ans++;
    }
    
    for(int i=n-2;i>=2;i--){
        LL u=(a[n-1]-a[n])*(a[n-1]-a[n]);
        LL v=(a[n-1]-a[i])*(a[n-1]-a[i]);
        u+=(a[i]-a[i+1])*(a[i]-a[i+1])+(a[i-1]-a[i])*(a[i-1]-a[i]);
        v+=(a[n]-a[i+1])*(a[n]-a[i+1])+(a[i-1]-a[n])*(a[i-1]-a[n]);
        if(v>u)ans++;
    }    
    //printf("{%lld}\n",ans);
    
    add=0;
    if((a[2]-a[1])*(a[2]-a[1])+(a[n-1]-a[n])*(a[n-1]-a[n])<(a[2]-a[n])*(a[2]-a[n])+(a[n-1]-a[1])*(a[n-1]-a[1]))ans++;

    
    if((a[2]-a[3])*(a[2]-a[3])<(a[1]-a[3])*(a[1]-a[3]))ans++;
    if((a[n-2]-a[n-1])*(a[n-2]-a[n-1])<(a[n-2]-a[n])*(a[n-2]-a[n]))ans++;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}