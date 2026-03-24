#include<bits/stdc++.h>
using namespace std;
const int N=205;
using LL=long long;
bool vis[N];
vector<int> e[N];
int dist[3][N];
int n,k;
int p,maxn;
int p1,p2;
// bool tag[N];
void dfs(int u,int op,int stp){
    //printf("{%d %d}\n",u,op);
    vis[u]=true;
    if(dist[op][u]>=maxn){
        p=u;
        maxn=dist[op][u];
    }
    for(auto v:e[u]){
        if(vis[v]||v==stp){
            continue;
        }
        dist[op][v]=dist[op][u]+1;
        dfs(v,op,stp);
    }
}
void solve(){
    
    
    //memset(tag,false,sizeof(tag));
    cin>>n;
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(auto j:e[i]){
            memset(dist,0,sizeof(dist));
            memset(vis,false,sizeof(vis));
            maxn=0;
            dfs(i,0,j);
            memset(vis,false,sizeof(vis));
            maxn=0;
            dfs(p,1,j);
            //p=i;
            LL maxn1=maxn;
            //printf("<%d %d>",p,maxn);
            memset(dist,0,sizeof(dist));
            memset(vis,false,sizeof(vis));
            maxn=0;
            dfs(j,0,i);
            memset(vis,false,sizeof(vis));
            maxn=0;
            dfs(p,1,i);
            //printf("<%d %d>",p,maxn);
            //p=j;
            LL maxn2=maxn;
            ans=max(ans,maxn1*maxn2);
            //printf("|%lld %d,%d|",ans,i,j);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}