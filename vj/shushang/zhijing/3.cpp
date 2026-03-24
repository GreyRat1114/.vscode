#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
bool vis[N];
vector<int> e[N];
int dist[3][N];
int n,k;
bool tag[N];
int a[N];
int p,maxn;
int p1,p2;
void dfs(int u,int op){
    vis[u]=true;
    if(dist[op][u]>maxn&&tag[u]){
        p=u;
        maxn=dist[op][u];
    }
    for(auto v:e[u]){
        if(vis[v]){
            continue;
        }
        dist[op][v]=dist[op][u]+1;
        dfs(v,op);
    }
}
int minn;
bool dfs2(int u,int fa){
    //printf("<%d>",u);
    vis[u]=true;
    if(u==p2){
        minn=min(minn,max(dist[1][u],dist[2][u]));
        //printf("|%d %d|",minn,u);
        return true;
    }
    for(auto v:e[u]){
        if(vis[v]){
            continue;
        }
        if(dfs2(v,u)){
            minn=min(minn,max(dist[1][u],dist[2][u]));
            //printf("|%d %d|",minn,u);
            return true;
        }
    }    
    return false;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<=n+5;i++){
        vis[i]=false;
        dist[1][i]=0;
        dist[2][i]=0;
        tag[i]=false;
        e[i].clear();
    }
    for(int i=1;i<=k;i++){
        cin>>a[i];
        tag[a[i]]=true;
    }

    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(k==1){
        cout<<0<<'\n';
        return;
    }
    maxn=0;
    dfs(a[1],0);
    p1=p;
    for(int i=0;i<=n+5;i++){
        vis[i]=false;
    }
    maxn=0;
    dfs(p1,1);
    p2=p;
    for(int i=0;i<=n+5;i++){
        vis[i]=false;
    }
    dfs(p2,2);

    for(int i=0;i<=n+5;i++){
        vis[i]=false;
    }
    minn=1e9;
    // dist[1][p1]=1e9;
    // dist[2][p2]=1e9;
    // for(int i=1;i<=n;i++){
    //     printf("{%d}",dist[1][i]);
    // }
    // cout<<'\n';
    // for(int i=1;i<=n;i++){
    //     printf("{%d}",dist[2][i]);
    // }    
    dfs2(p1,p1);
    cout<<minn<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}