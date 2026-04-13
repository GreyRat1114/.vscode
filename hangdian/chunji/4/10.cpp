#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<vector<LL>> a(n+1,vector<LL>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    LL pre=0;
    for(int i=1;i<=n;i++){
        LL minn=1e9;
        for(int j=1;j<=m;j++){
            if(a[i][j]>pre){
                minn=min(minn,a[i][j]);
            }
        }
        if(minn==1e9){
            cout<<"NO"<<'\n';
            return;
        }
        pre=minn;
    }    
    cout<<"YES"<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}