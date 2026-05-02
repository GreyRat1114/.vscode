#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> e;
vector<LL> vis;
vector<LL> col;
LL tag;
vector<LL> tot;
void dfs(LL u,LL fa){
    vis[u]=1;
    col[u]=col[fa]^1;
    tot[col[u]]++;
    //printf("{%lld,%lld}",u,col[u]);
    for(auto v:e[u]){
        if(vis[v]&&col[v]==col[u])tag=0;
        if(vis[v])continue;
        dfs(v,u);
    }
}
void solve(){
    LL n,m;
    cin>>n>>m;
    tag=1;
    e.assign(n+1,vector<LL>());
    vis.assign(n+1,0);
    col.assign(n+1,0);
    for(int i=1;i<=m;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    LL ans=0;

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            tot.assign(2,0);
            tag=1;
            dfs(i,i);
            //printf("{|%lld,%lld|}",i,tag);

            if(tag){
                LL maxn=max(tot[0],tot[1]);
                if(maxn==1){
                    ans+=1;
                }else{
                    ans+=maxn;
                }
                
            }
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