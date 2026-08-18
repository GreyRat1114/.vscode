#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
void solve(){
    LL n;
    cin>>n;
    if(n<=3){
        cout<<"Huo"<<'\n';
        return;
    }
    if(n%4==0){
        cout<<"Bai"<<'\n';
    }else{
        cout<<"Huo"<<'\n';
    }
    
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