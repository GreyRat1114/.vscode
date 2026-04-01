#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k;
    cin>>n>>k;
    for(int i=1;i<=n-2;i++){
        cout<<1<<' ';
    }
    cout<<2<<' '<<k+n<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}