#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
vector<LL> f,g;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans%mod;
}
void init(LL n){
    f[0]=g[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i%mod;
        g[i]=g[i-1]*qpow(i,mod-2)%mod;
    }
}
LL getc(LL n,LL m){
    return f[n]*g[m]%mod*g[n-m]%mod;
}
