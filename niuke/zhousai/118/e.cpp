// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// vector<int> e[N];
// int n,m,s,f[N][33],dep[N];
// bool vis[N];
// void dfs(int u,int fa)
// {
//     f[u][0]=fa;
//     dep[u]=dep[fa]+1;
//     for(auto v:e[u])
//     {
//         if(v!=fa)
//         {
//             dfs(v,u);
//         }
//     }
// }
// int lca(int u,int v)
// {
//     if(dep[u]<dep[v])
//     {
//         swap(u,v);
//     }
//     for(int i=22;i>=0;i--)
//     {
//         if(dep[f[u][i]]>=dep[v])
//         {
//             u=f[u][i];
//         }

//     }
//     if(u==v)
//     {
//         return u;
//     }
//     for(int i=22;i>=0;i--)
//     {
//         if(f[u][i]!=f[v][i])
//         {
//             u=f[u][i];
//             v=f[v][i];

//         }
//     }
//     return f[u][0];
// }
// int dist[N];
// void init()
// {
//     memset(dist,0x3f,sizeof(dist));
//     memset(vis,false,sizeof(vis));
//     for(int j=1;(1<<j)<=n;j++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             f[i][j]=f[f[i][j-1]][j-1];

//         }
//     }
// }

// void dfs1(int u){
//     vis[u]=true;
//     for(int v:e[u]){
//         if(vis[v]){
//             continue;
//         }
//         dist[v]=dist[u]+1;
//         dfs1(v);
//     }
// }
// int minn;
// void dfs2(int u,int fa){
//     printf("*%d*",u);
//     vis[u]=true;
//     if(e[u].size()==1){
//         minn=min(minn,dist[u]);
//         printf("(%d)",dist[u]);
//     }
//     for(int v:e[u]){
//         if(v==fa){
//             continue;
//         }
//         dfs2(v,u);
//     }    
// }

// void solve(){

//     int a,b;
//     cin>>n;
//     cin>>a>>b;
//     init();
//     int u,v;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);

//     }
//     dfs(1,0);
//     int c=lca(a,b);
//     memset(vis,false,sizeof(vis));
//     dist[1]=0;
//     dfs1(1);
    
//     int d=dist[a]-dist[c]+dist[b]-dist[c];
//     // printf("{%d,%d,%d,%d}",c,dist[a],dist[b],d);
//     minn=1e9;
//     memset(vis,false,sizeof(vis));
//     for(int i=1;i<=n;i++){
//         printf("[%d]",dist[i]);
//     }
//     dfs2(a,a);
//     printf("<%d>",minn-dist[a]);

// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
    
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
vector<int> e[N];
int n,m,s,f[N][33],dep[N];
int a,b;
bool vis[N];
int dist1[N];
int dist2[N];
void init()
{
    for(int i=1;i<=n;i++){
        dist1[i]=-1;
        dist2[i]=-1;
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
}

void dfs1(int u){
    vis[u]=true;
    for(int v:e[u]){
        if(vis[v]){
            continue;
        }
        if(v==b){
            continue;
        }
        dist1[v]=dist1[u]+1;
        dfs1(v);
    }
}
int minn;
void dfs2(int u){
    vis[u]=true;
    for(int v:e[u]){
        if(vis[v]){
            continue;
        }
        dist2[v]=dist2[u]+1;
        dfs2(v);
    }
}

void solve(){

    cin>>n;
    cin>>a>>b;
    init();
    int u,v;
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int tot=0;
    vector<int> q(n+10,0);
    for(int i=1;i<=n;i++){
        if(e[i].size()==1){
            tot++;
            q[tot]=i;
            
        }
    }
    dist1[a]=0;
    dfs1(a);
    memset(vis,false,sizeof(vis));
    dist2[b]=0;
    dfs2(b);
    // for(int i=1;i<=n;i++){
    //     printf("{%d,%d}",dist1[i],dist2[i]);
    // }
    for(int i=1;i<=tot;i++){
        // cout<<q[i]<<'\n';
        if(dist1[q[i]]*2<=dist2[q[i]]&&dist1[q[i]]!=-1){
            cout<<"red"<<'\n';
            return;
        }
    }
    cout<<"purple"<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}