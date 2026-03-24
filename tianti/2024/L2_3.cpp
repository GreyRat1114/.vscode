#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
vector<int> e[N];
int d[N];
int p;
void dfs(int u,int fa){
    int tot=0;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        tot++;
        dfs(v,u);
    }
    d[u]=tot;
}
void dfs1(int u,int fa){
    if(u==p){
        cout<<u;
    }else{
        cout<<' '<<u;
    }
    
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs1(v,u);
    }
}
void solve(){
    int n;
    cin>>n;
    int x;
    for(int i=0;i<=n+1;i++){
        e[i].clear();
        d[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==0){
            p=i;
            continue;
        }
        e[i].push_back(x);
        e[x].push_back(i);
    }
    dfs(p,0);
    x=d[p];
    int tag=1;
    int maxn=0;
    // for(int i=1;i<=n;i++){
    //     printf("{%d}",d[i]);
    // }
    for(int i=1;i<=n;i++){
        if(e[i].size()==1){
            continue;
        }
        if(d[i]!=x){
            tag=0;
        }
        x=d[i];
        maxn=max(maxn,d[i]);
    }
    if(tag){
        cout<<maxn<<' '<<"yes"<<'\n';
    }else{
        cout<<maxn<<' '<<"no"<<'\n';
    }
    dfs1(p,0);
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}