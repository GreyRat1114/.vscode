#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1);
    vector<LL> vis(m+1,0);
    LL tag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(vis[a[i]])tag=0;
        vis[a[i]]=1;
    }
    if(tag){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
    tag=1;
    for(int i=1;i<=m;i++){
        if(vis[i]==0)tag=0;
    }
    if(tag){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }    
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}