#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
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
    f.resize(n+1);
    g.resize(n+1);
    f[0]=g[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*i%mod;
        g[i]=g[i-1]*qpow(i,mod-2)%mod;
    }
}
LL getc(LL n,LL m){
    if(n<m||m<0)return 0;
    return f[n]*g[m]%mod*g[n-m]%mod;
}
void solve(){
    LL w,l;
    cin>>w>>l;
    LL fm=qpow(w,l)%mod;
    LL ans=1*qpow(10,mod-2)%mod;
    cout<<ans<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}