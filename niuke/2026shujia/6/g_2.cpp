#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> e;
void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    e.assign(n+1,vector<LL>());
    for(int i=1;i<=m;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<LL> vis(n+1,0);
    queue<LL> q;
    for(int i=1;i<=k;i++){
        LL u;
        cin>>u;
        vis[u]=-3;
        q.push(u);
    }
    while(!q.empty()){
        LL u=q.front();
        q.pop();
        for(auto v:e[u]){
            vis[v]++;
            if(vis[v]==2){
                q.push(v);
            }
        }
    }
    vector<LL> ans;
    for(int i=1;i<=n;i++){
        if(vis[i]>=1)ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    if(ans.size()==0)return;
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
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