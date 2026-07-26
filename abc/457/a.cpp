#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(200);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL x;
    cin>>x;
    cout<<a[x]<<'\n';
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