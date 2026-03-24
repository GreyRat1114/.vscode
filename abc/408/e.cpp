#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
using LL=long long;
struct egde{
    int u,v,w;
}a[N];
int fa[N];
bool vis[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve(){
    memset(vis,false,sizeof(false));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    LL ans=0;
    for(int j=29;j>=0;j--){
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            int u=find(a[i].u);
            int v=find(a[i].v);        
            if((a[i].w&(1<<j))!=0||vis[i]||u==v){
                continue;
            }
            fa[u]=v;
        }
        if(find(1)==find(n)){
            for(int i=1;i<=m;i++){
                if(a[i].w&(1<<j)){
                    vis[i]=true;
                }
            }
        }else{
            ans+=(1<<j);
        }  

    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}