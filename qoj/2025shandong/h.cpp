#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<pair<LL,LL>>> e;
struct DSU{
    vector<LL> fa;
    LL cnt;//连通块数量
    void init(LL n){
        fa.resize(n+1); 
        cnt=n;  
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
    }
    LL find(LL x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void merge(LL x,LL y){
        LL fx=find(x);
        LL fy=find(y);
        if(fx!=fy){
            fa[fx]=fy;
            cnt--;
        }
    }
};
void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    e.resize(n+1,vector<pair<LL,LL>>());
    DSU fa;
    fa.init(n);
    for(int i=1;i<=m;i++){
        LL u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        fa.merge(u,v);
    }
    
}
int main(){
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}