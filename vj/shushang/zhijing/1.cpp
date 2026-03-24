#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
vector<pair<int,LL>> e[N];
bool vis[N];
int p;
int p1,p2;
LL maxn;
LL dist[3][N];
void dfs(int u,int op){
    if(dist[op][u]>maxn){
        maxn=dist[op][u];
        p=u;
    }
    vis[u]=true;
    for(auto x:e[u]){
        int v=x.first;
        LL w=x.second;
        if(vis[v]){
            continue;
        }        
        dist[op][v]=dist[op][u]+w;
        dfs(v,op);
    }
}
int q[N];
int tot=0;
int tag=0;
bool dfs2(int u,int fa){
    if(u==p2){
        tot++;
        q[tot]=u;
        vis[u]=true;
        return true;
    }
    for(auto x:e[u]){
        int v=x.first;
        LL w=x.second;
        if(v==fa){
            continue;
        }
        if(dfs2(v,u)){
            tot++;
            q[tot]=u;
            vis[u]=true;
            return true;
        }
    }
    return false;
}
bool vis1[N];
bool dfs3(int u,LL dis,int f,int op){
    vis1[u]=true;
    if(dis==dist[op][f]&&u!=f){
        return true;
    }
    for(auto x:e[u]){
        int v=x.first;
        LL w=x.second;
        if(vis[v]||vis1[v]){
            continue;
        }
        if(dfs3(v,dis+w,f,op)){
            return true;
        }        
    }
    return false;
}
void solve(){
    memset(vis,false,sizeof(vis));
    memset(dist,false,sizeof(dist));
    maxn=0;
    int n;
    int u,v,w;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);
    memset(vis,false,sizeof(vis));
    maxn=0;
    p1=p; 
    dfs(p1,1);
    p2=p;
    memset(vis,false,sizeof(vis));
    dfs(p2,2);
    cout<<dist[1][p2]<<'\n';
    memset(vis,false,sizeof(vis));
    dfs2(p1,p1);
    LL ans=0;
    int pos1,pos2;
    memset(vis1,false,sizeof(vis1));
    for(int i=1;i<=tot;i++){
        int x=q[i];
        pos1=i;
        if(dfs3(x,0,x,1)){
            break;
        }
    }
    memset(vis1,false,sizeof(vis1));
    for(int i=pos1;i>=1;i--){
        int x=q[i];
        pos2=i;
        if(dfs3(x,0,x,2)){
            break;
        }
    }
    cout<<pos1-pos2<<'\n';
}
int main(){
    solve();
    return 0;
}