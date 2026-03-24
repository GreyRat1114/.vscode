#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> e[N];
int dp[N][N];
int w[N];
bool vis[N];
bool dvs[N][N];
void dfs(int u){
    //printf("{%d}",u);
    vis[u]=true;
    if(e[u].size()==1&&u!=1){
        //printf("(%d)",u);
        dp[u][0]=0;
        dp[u][w[u]]=w[u];
        dvs[u][0]=true;
        dvs[u][w[u]]=true;
    }
    for(auto v:e[u]){
        if(vis[v]){
            continue;
        }
        dfs(v);
        for(int i=w[u];i>=0;i--){
            for(int j=0;j<=w[v];j++){
                
                if(!dvs[v][j]){
                    continue;
                }
                if(i>=j){
                    dp[u][i]=max(dp[u][i],dp[u][i-j]+j);
                    dvs[u][dp[u][i]]=true;

                }
                //printf("<%d %d %d %d %d>\n",u,v,i,j,dp[u][i]);
            }            
        }

    }
}
void solve(){
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
    memset(dvs,false,sizeof(dvs));
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    cout<<dp[1][w[1]]<<'\n';
}
int main(){
    solve();
    return 0;
}