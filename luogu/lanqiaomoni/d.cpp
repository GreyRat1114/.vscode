#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
LL qpow(LL x,LL y){
    LL ans=1;
    while(y){
        if(y&1){
            ans=(ans*x)%mod;
        }
        y=y>>1;
        x=(x*x)%mod;
    }
    return ans;
}
void solve(){
    LL x,y;
    cin>>x>>y;
    if(x<=y){
        cout<<1<<'\n';
        return;
    }

    LL ans=((y+1)*qpow(2,x-y-1))%mod;
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}