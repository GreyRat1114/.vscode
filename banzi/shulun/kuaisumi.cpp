#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
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