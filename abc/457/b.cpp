#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1);
    for(int i=1;i<=n;i++){
        LL l;
        cin>>l;
        a[i].resize(l+1);
        vector<LL> b(l+1);
        for(int j=1;j<=l;j++){
            cin>>a[i][j];
            //printf("{%lld}",b[j]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<a[i].size();j++){
    //         cout<<a[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    LL x,y;
    cin>>x>>y;
    cout<<a[x][y]<<'\n';

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