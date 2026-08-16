#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    map<LL,vector<LL>> mp1,mp2;
    LL n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        LL x,y;
        cin>>x>>y;
        mp1[x].push_back(y);
        mp2[y].push_back(x);
    }
    LL ans=1e8;
    for(int i=1;i<=n;i++){
        LL x=n-mp1[i].size();
        ans=min(ans,x);
    }
    for(int i=1;i<=n;i++){
        LL x=n-mp2[i].size();
        ans=min(ans,x);
    }    
    cout<<ans<<'\n';
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