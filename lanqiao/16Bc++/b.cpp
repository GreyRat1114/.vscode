#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=1e9+7;
LL qpow(LL x,LL y){
    LL ans=1; 
    while(y){
        if(y&1){
            ans=(ans*x)%mod;
        }
        x=(x*x)%mod;
        y=y>>1;
    }
    return ans;
}
void solve(){
    LL n,m;
    cin>>n>>m;
    cout<<qpow(n,m);
}
int main(){
    solve();
    return 0;
}