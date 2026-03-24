#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+5;
vector<int> e[N];
bool vis[N];
void dfs(int u){
    vis[u]=true;
    for(auto v:e[u]){
        if(vis[v]){
            continue;
        }
        
        dfs(v);
        
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    int n,m;
    cin>>n>>m; 
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[v].push_back(u);
    }
    int q,op;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>op>>v;
        if(op==1){
            if(vis[v]){
                continue;
            }
            dfs(v);
            
        }
        else{
            if(vis[v]){
                cout<<"Yes"<<'\n';
            }
            else{
                cout<<"No"<<'\n';
            }
        }
        
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}