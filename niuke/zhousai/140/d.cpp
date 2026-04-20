#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> vis;
LL n,x,y;
void dfs(LL p){
    if(p<1||p>n||vis[p])return;
    vis[p]=1;
    if(p+x>=1&&p+x<=n&&vis[p+x]==0){
        dfs(p+x);
    }
    if(p-x>=1&&p-x<=n&&vis[p-x]==0){
        dfs(p-x);
    }
    if(p+y<=n&&vis[p+y]==0&&p+y>=1){
        dfs(p+y);
    }
    if(p-y<=n&&vis[p-y]==0&&p-y>=1){
        dfs(p-y);
    }
}
void solve(){
    cin>>n>>x>>y;
    vis.assign(n+1,0);
    vis[0]=1;
    vector<LL> a(n+1),d(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=abs(a[i]-i);
    }
    dfs(x);
    dfs(y);
    for(int i=1;i<=n;i++){
        if(vis[d[i]]==0){
            //printf("{%lld}",d[i]);
            cout<<"No"<<'\n';
            return;
        }
    }
    cout<<"Yes"<<'\n';

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}