#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
vector<int> e[N];
int siz[N];
int cnt;
void dfs(int u,int fa){
    siz[u]=1;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
void dfs1(int u,int fa){
    //printf("<%d>",u);
    int tag=1;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs1(v,u);
        if(siz[v]%2==0){
            tag=0;
        }
         
    }    
    if((siz[1]-siz[u])%2==0&&u!=1){
        tag=0;
    }
    if(tag){
        cnt++;
    }
}
void solve(){
    cnt=0;
    int n;
    cin>>n;
    for(int i=0;i<=n+5;i++){
        siz[i]=0;
        e[i].clear();
    }    
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1);
    // for(int i=1;i<=n;i++){
    //     printf("{%d}",siz[i]);
    // }
    dfs1(1,1);
    cout<<cnt<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}