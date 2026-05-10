#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<pair<LL,LL>>> e;
vector<LL> a;
LL ans;
void dfs(LL u,LL fa,LL pre,LL &tag,LL lst){
  //  printf("{%lld,%lld,%lld,%lld}",u,ans,pre,lst);
    if(e[u].size()==1&&u!=1){
        ans+=pre;
        return ;
    }
    if(a[u]==1){
        ans+=pre;
        pre=0;
        lst=u;
        tag=1;
    }
    for(auto x:e[u]){
        LL v=x.first;
        LL w=x.second;
        if(v==fa)continue;
        LL tag2=0;
    
        dfs(v,u,pre+w,tag2,lst);
       
        
    }
}
void solve(){
    ans=0;
    LL n,m;
    cin>>n>>m; 
    e.assign(n+1,vector<pair<LL,LL>>());
    a.assign(n+1,0);     
    LL s=0;
  //  std::cout<<ans<<endl;
    for(int i=1;i<=n-1;i++){
        LL u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        s+=w;
    }
    for(int i=1;i<=m;i++){
        LL x;
        cin>>x;
        a[x]=1;
    }
    LL tag=0;
    dfs(1,1,0,tag,1);
    //std::cout<<ans<<endl;
    cout<<ans-s<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}