// 洛谷P4779
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=2e5+5;
vector<pair<LL,LL>> e[N];
LL dist[N];
bool vis[N];
LL n,m,s;
void dijkstra(){
    priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> q;
    q.push(make_pair(0,s));
    dist[s]=0;
    while(!q.empty()){
        LL u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto &x:e[u]){
            LL v=x.first;
            LL w=x.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push(make_pair(dist[v],v));
            }
        }
    }
}
void solve(){
    cin>>n>>m>>s;
    LL u,v,w;
    for(int i=0;i<=n;i++){
        dist[i]=1e18;
        vis[i]=false;
        e[i].clear();
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back(make_pair(v,w));
    }   
    dijkstra();
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<' ';
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