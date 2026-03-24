#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+5;
LL a[N];
bool vis[N];
LL s[N];
LL ans;
vector<pair<LL,LL>> e[N];
void dfs(int u){
    vis[u]=true;
    for(auto x:e[u]){
        int v=x.first;  
        int w1=x.second;
        if(vis[v]){
            continue;
        }
        dfs(v);
        ans+=abs(a[v])*w1;
        a[u]+=a[v];
    }
}
void solve(){
    ans=0;
    memset(vis,false,sizeof(vis));
    int n;
    cin>>n;
    int u,v;
    LL w;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1);
    cout<<ans<<'\n';
}
int main(){ 
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}