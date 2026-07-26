#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
const LL mod=998244353;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans%mod;
}
LL gcd(LL a,LL b){
    while(b){
        LL t=a;
        a=b;
        b=t%b;
    }
    return a;
}
void solve(){
    LL n;
    cin>>n;
    //printf("{%lld}",qpow(2,4));
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[1]<<'\n';
        return;
    }
    LL fz=(n+4)*(a[1]+a[n]);
    for(int i=2;i<=n-1;i++){
        fz=(fz+((n+3)*a[i])%mod)%mod;
    }
    LL fm=qpow(6,mod-2);
    LL ans=(fz*fm)%mod;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}