#include<bits/stdc++.h>
using namespace std;
const int N=2048+15;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
LL b[N];
bool vis[N][N];
int n;
LL maxn;
void dfs(LL u,int d){
    if(d==n+1){
        maxn=max(maxn,u);
        return;
    }
    LL v1=max(0ll,u-a[d]);
    LL v2=u^b[d];
    if(!vis[d][v1]){
        vis[d][v1]=true;
        dfs(v1,d+1);
    }
    if(!vis[d][v2]){
        vis[d][v2]=true;
        dfs(v2,d+1);
    }    
    
}
void solve(){
    memset(vis,false,sizeof(vis));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    maxn=0;
    dfs(0,1);
    cout<<maxn<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}