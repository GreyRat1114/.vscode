//luogu P3371
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=1e18;
vector<vector<pair<LL,LL>>> e;
vector<LL> dist;
vector<LL> vis;
LL n,m,s;
void spfa(){
    queue<LL> q;
    dist[s]=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        LL u=q.front();
        q.pop();
        vis[u]=0;
        for(auto x:e[u]){
            LL v=x.first;
            LL w=x.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(vis[v]==0){
                    q.push(v);
                    vis[v]=1;                    
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m>>s;
    e.assign(n+1,vector<pair<LL,LL>>());
    dist.assign(n+1,INF);
    vis.assign(n+1,0);
    for(int i=1;i<=m;i++){
        LL u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        //e[v].push_back({u,w});
    }
    spfa();
    for(int i=1;i<=n;i++){
        if(dist[i]==INF){
            cout<<(1<<31)-1<<' ';
        }else{
            cout<<dist[i]<<' ';
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}