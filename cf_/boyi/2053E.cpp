#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
vector<vector<LL>> e;
vector<LL> vis;
vector<LL> siz;
vector<LL> sum;
void dfs1(LL u,LL fa){
    if(vis[u]==1)sum[u]++;
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        sum[u]+=sum[v];
    }
}

LL pt2;
void dfs2(LL u,LL fa){
    if(vis[fa]==1&&e[u].size()!=1){
        LL d=(siz[1]-sum[1])-(siz[u]-sum[u]);
        pt2+=d;
    }
    for(auto v:e[u]){
        if(v==fa)continue;
        if(vis[v]==1&&e[u].size()!=1){
            LL d=siz[v]-sum[v];
            pt2+=d;
        }
    }
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs2(v,u);
    }
}
void solve(){
    LL n;
    cin>>n;
    e.assign(n+1,vector<LL>());
    vis.assign(n+1,0);
    siz.assign(n+1,1);
    sum.assign(n+1,0);
    pt2=0;
    for(int i=1;i<=n-1;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    LL c=0;
    for(int i=1;i<=n;i++){
        if(e[i].size()==1){
            c++;
            vis[e[i][0]]=1;
            siz[i]=0;
        }
    }
    //printf("{%lld}",c);
    LL pt1=c*(n-c);
    dfs1(1,1);
    dfs2(1,1);
    LL ans=pt1+pt2;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}