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
    vector<LL> a(k+1),vis(n+1,0);
    for(int i=1;i<=k;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    set<LL> ans;
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        LL u=i;
        vector<LL> q;
        LL c=0;
        for(auto v:e[u]){
            if(vis[v]==1){
                c++;
                continue;
            }
            q.push_back(v);
        }
        if(c==2&&e[u].size()==3){
            ans.insert(q[0]);
            ans.insert(u);
        }else if(c==1||c==3||c==2){
            ans.insert(u);
        }
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