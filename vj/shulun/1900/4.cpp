#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=100005;
LL getlcm(LL x,LL y){
    LL g=__gcd(x,y);
    LL ans=(x*y)/g;
    return ans;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    LL maxn=0;
    set<LL> at;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        at.insert(a[i]);
        maxn=max(maxn,a[i]);
    }
    LL lcm=a[1];
    for(int i=2;i<=n;i++){
        lcm=getlcm(lcm,a[i]);
        if(lcm>maxn){
            lcm=maxn+1;
            break;
        }
    }
    if(lcm!=maxn){
        cout<<n<<'\n';
        // printf("??");
        return;
    }
    set<LL> st;
    sort(a.begin()+1,a.begin()+1+n);
    for(LL i=1;i*i<=maxn;i++){
        if(maxn%i==0){
            LL x=i;
            LL y=maxn/i;
            st.insert(x);
            st.insert(y);
        }
    }
    // for(auto x:st){
    //     printf("|%lld|",x);
    // }
    // cout<<'\n';
    LL m=st.size();
    vector<map<LL,LL>> dp(n+2);
    dp[1][1]=0;
    LL ans=0;
    for(int i=1;i<=n;i++){
        dp[i+1]=dp[i];
        for(auto cp:dp[i]){
            LL x=cp.first;
            LL val=cp.second;
            LL y=getlcm(x,a[i]);
            if(y>maxn)continue;
            dp[i+1][y]=max(dp[i+1][y],dp[i][x]+1);
            //printf("{%lld,%lld,%lld}",i,x,dp[i][x]);
        }
    }    
    for(int i=1;i<=n+1;i++){
        for(auto cp:dp[i]){
            if(at.count(cp.first))continue;
            ans=max(ans,cp.second);
        }
    }
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