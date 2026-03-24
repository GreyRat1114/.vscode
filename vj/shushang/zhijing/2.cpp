#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
vector<int> e[N];
bool vis[N];
LL dist[3][N];
int d[N];
int f[N][30];
int p;
int p1,p2;
LL maxn;
void dfs0(int u,int fa){
    f[u][0]=fa;
    d[u]=d[fa]+1;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs0(v,u);
    }    
}
void dfs(int u,int op){
    
    vis[u]=true;
    if(dist[op][u]>maxn){
        maxn=dist[op][u];
        p=u;
    }
    for(auto v:e[u]){
        if(vis[v]){
            continue;
        }
        dist[op][v]=dist[op][u]+1;
        dfs(v,op);
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    memset(dist,0,sizeof(dist));
    memset(f,0,sizeof(f));
    memset(d,0,sizeof(d));
    maxn=0;
    int n;
    LL k,c;
    int u,v;
    cin>>n>>k>>c;
    for(int i=0;i<=n+5;i++){
        e[i].clear();
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs0(1,1);
    for(int j=1;j<=10;j++){
        for(int i=1;i<=n;i++){
            
        }
    }
    
    dfs(1,0);
    p1=p;
    if(c>=k){
        cout<<dist[0][p]*k<<'\n';
        return;
    }
    memset(vis,false,sizeof(vis));
    maxn=0;
    dfs(p1,1);
    p2=p;
    LL ans=(d[p1]-d[1])*k+(d[p2]-d[1])*(k-c);
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}