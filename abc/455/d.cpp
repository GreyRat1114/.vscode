#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> down;
vector<LL> up;
vector<LL> vis;
void init(LL n){
    for(int i=1;i<=n;i++){
        down[i]=-1;
        up[i]=-1;
    }    
}
LL findup(LL x){
    if(up[x]==-1)return 1;
    return findup(up[x])+1;
}
LL finddown(LL x){
    if(down[x]==-1&&vis[x])return x;
    return finddown(down[x]);
}
void solve(){
    LL n,q;
    cin>>n>>q;
    
    down.resize(n+1);
    up.resize(n+1);
    vis.assign(n+1,1);
    init(n);
    LL c,p;
    for(int i=1;i<=q;i++){
        cin>>c>>p;
        if(down[c]!=-1)up[down[c]]=-1;
        up[p]=c;
        down[c]=p;
        vis[c]=0;

        // for(int j=1;j<=n;j++){
        //     printf("{%lld,%lld}",down[j],top[j]);
        // }
        // cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cout<<findup(i)<<' ';
        }else{
            cout<<0<<' ';
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}