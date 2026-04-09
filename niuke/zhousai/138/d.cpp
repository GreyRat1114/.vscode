#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
vector<LL> e[N];
LL c[N];
LL siz[N];
LL ans;
void dfs(LL u,LL fa){
    //printf("{%lld}",u);
    siz[u]=1;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        if(c[u]==c[v]){
            siz[u]+=siz[v];
            
        }
    }
    ans+=siz[u]-1;
}
void solve(){
    ans=0;
    LL n;
    cin>>n;
    for(int i=0;i<=n+1;i++){
        siz[i]=0;
        e[i].clear();
        c[i]=0;
    }
    LL u,v;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        //printf("{%lld,%lld}",u,v);
    }
    dfs(1,1);
    cout<<ans<<'\n';

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}