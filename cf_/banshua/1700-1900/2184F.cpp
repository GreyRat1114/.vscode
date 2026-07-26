#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> e;
vector<vector<LL>> dp;
vector<vector<LL>> vis;
void dfs2(vector<vector<LL>> &q,LL i,LL val,LL u){
    //printf("{%lld,%lld,%lld}",i,val,u);
    vis[i][val]=1;
    if(i==q.size()){
        dp[u][val]=1;
        return;
    }
    for(int j=0;j<=2;j++){
        if(!q[i][j])continue;
        if(vis[i+1][(j+val)%3])continue;
        dfs2(q,i+1,(j+val)%3,u);
    }
}
void dfs(LL u,LL fa){
    if(e[u].size()==1&&u!=1){
        return;
    }
    vector<vector<LL>> q;
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
        q.push_back(dp[v]);
    }
    vis.assign(q.size()+2,vector<LL>(3,0));
    dfs2(q,0,0,u);

}
void solve(){
    LL n;
    cin>>n;
    e.assign(n+1,vector<LL>());
    dp.assign(n+1,vector<LL>(3,0));
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
    }
    for(int i=1;i<=n-1;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    } 
    dfs(1,1);
    if(dp[1][0]){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
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