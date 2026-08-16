#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> e;
vector<LL> ds,dmax,d;

void init(LL u,LL fa,LL d0){
    d[u]=d0;
    ds[u]=d0;
    dmax[u]=d0;
    for(auto v:e[u]){
        if(v==u)continue;
        init(v,u,d0+1);
        ds[u]+=ds[v];
        dmax[u]=max(dmax[v],dmax[u]);
    }
}
void dfs1(LL u,LL fa){
    priority_queue<pair<LL,LL>> q;
    for(auto v:e[u]){
        if(v==fa)continue;
        
    }
}
void dfs2(){

}
void solve(){
    LL n;
    cin>>n;
    e.assign(n+1,vector<LL>());
    ds.assign(n+1,0);
    dmax.assign(n+1,0);
    d.assign(n+1,0);
    for(int i=2;i<=n;i++){
        LL x;
        cin>>x;
        e[x].push_back(i);
        e[i].push_back(x);
    }
    dfs1(1,1,0);
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