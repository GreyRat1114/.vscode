#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
vector<LL> e[N];
LL siz[N];
LL dp[N][2];
void dfs(LL u,LL fa){
    if(e[u].size()==1&&u!=1){
        //printf("{%lld}",u);
        dp[u][1]=0;
        dp[u][0]=1;
        return;
    }
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=min(dp[v][1],dp[v][0]);
        //printf("{%lld,%lld,%lld}",u,dp[u][0],dp[u][1]);
    }
    dp[u][0]++;
}
void solve(){
    LL n;
    cin>>n;
    for(int i=0;i<=n;i++){
        e[i].clear();
        siz[i]=1;
        dp[i][0]=0;
        dp[i][1]=0;
    }
    LL u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++){
        cout<<min(dp[i][0],dp[i][1])<<' ';
    }
    cout<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}