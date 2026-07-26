#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    //if()
    if(m<=n-1){
        cout<<m*(m-1)/2<<'\n';
    }else{
        LL ans=(n-2)*(n-1)/2-(m-n+1);
        cout<<ans<<'\n';
    }
    // for(int i=2;i<=n;i++){
    //     cout<<1<<' '<<'i';
    // }
    //cout<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}