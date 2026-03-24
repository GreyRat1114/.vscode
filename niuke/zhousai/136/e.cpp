#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
vector<int> e[N];
int dfs(int u,int fa){
    int tot=0;
    if(e[u].size()==1&&u!=1){
        return 1;
    }
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        if(dfs(v,u)){
            tot++;
        }
    }
    if(u==1){
        return tot>=1?1:0;
    }else{
        return tot>=2?1:0;
    }
    
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<=n+1;i++){
        e[i].clear();
    }
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(dfs(1,1)){
        cout<<"red"<<'\n';
    }else{
        cout<<"purple"<<'\n';
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}