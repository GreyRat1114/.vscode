#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1);
    vector<pair<LL,LL>> e(m+1);
    vector<map<LL,LL>> dp(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL u,v;
    for(int i=1;i<=m;i++){
        cin>>e[i].first>>e[i].second;
    }
    sort(e.begin()+1,e.end(),[&](pair<LL,LL> &e1,pair<LL,LL> &e2){
        return a[e1.first]+a[e1.second]<a[e2.first]+a[e2.second];
    });
    LL ans=0;
    for(int i=1;i<=m;i++){
        LL u=e[i].first;
        LL v=e[i].second;
        ans=(ans+dp[u][a[v]]+1)%mod;
        dp[v][a[u]+a[v]]=(dp[v][a[u]+a[v]]+dp[u][a[v]]+1)%mod;

        //printf("{%lld,%lld}",e[i].first,e[i].second);
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}