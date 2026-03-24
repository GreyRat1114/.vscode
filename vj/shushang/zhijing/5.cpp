#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
bool vis[N];
vector<int> e[N];
LL dist[3][N];
int n,k;
int p;
LL maxn;
int p1,p2; 
// bool tag[N];
void dfs(int u,int op){
    //printf("{%d %d}\n",u,op);
    vis[u]=true;
    if(dist[op][u]>=maxn){
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
int vec[N];
int tot;
bool dfs1(int u,int fa){
    if(u==p2){
        tot++;
        vec[tot]=u;
        vis[u]=true;

        return true;
    }
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        if(dfs1(v,u)){
            tot++;
            vec[tot]=u;    
            vis[u]=true;        
            return true;
        }
    }
    return false;
}
void dfs2(int u,LL d,int fa){
    if(maxn<d){
        maxn=d;
        p=u;
    }
    for(auto v:e[u]){
        if(v==fa||vis[v]){
            continue;
        }
        dfs2(v,d+1,u);
    }    
}
void solve(){
    memset(dist,0,sizeof(dist));
    cin>>n;
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    maxn=0;
    dfs(1,0);
    p1=p;
    memset(vis,false,sizeof(vis));
    maxn=0;
    dfs(p1,1);
    p2=p;
    memset(vis,false,sizeof(vis));
    maxn=0;
    dfs(p2,2);
    p=0;
    tot=0;
    //printf("{%d %d}",p1,p2);
    memset(vis,false,sizeof(vis));
    dfs1(p1,p1);
    LL ans=0;
    LL maxx=0;    
    for(int i=1;i<=tot;i++){

        maxn=0;
        dfs2(vec[i],0,vec[i]);
        if(maxn>maxx){
            ans=p;
            maxx=maxn;
        }
    }
    if(ans==0){
        for(int i=1;i<=n;i++){
            if(i!=p1&&i!=p2){
                ans=i;
                break;
            }
        }
    }
    //cout<<maxx<<'\n';
    // for(int i=1;i<=n;i++){
    //     if(i==p1||i==p2){
    //         continue;
    //     }
    //     LL x=max(dist[1][i],dist[2][i]);
    //     if(x>maxx){
    //         ans=i;
    //         maxx=x;
    //     }
    // }
    cout<<maxx+dist[1][p2]<<'\n';
    cout<<p1<<' '<<p2<<' '<<ans<<'\n';
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}