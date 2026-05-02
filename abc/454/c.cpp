#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> e;
vector<LL> vis;
void dfs(LL u,LL fa){
    vis[u]=1;
    for(auto v:e[u]){
        if(v==fa||vis[v])continue;
        dfs(v,u);
    }
}
void solve(){
    LL n,m;
    cin>>n>>m;
    e.assign(n+1,vector<LL>());
    vis.assign(n+1,0);
    vector<LL> a(m+1),b(m+1);
    LL u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
    }
    dfs(1,1);
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i])ans++;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}