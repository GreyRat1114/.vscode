#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
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
    if(n<0||m<0||m>n)return 0;
    return f[n]*g[m]%mod*g[n-m]%mod;
}

void solve(){
    LL x1,x2,x3;
    
    cin>>x1>>x2>>x3;
    LL maxn=max(max(x1,x2),x3);
    LL n=x2+1;
    init(2*maxn);
    LL ans=0;
    for(int i=1;i<=n-1;i++){
        LL pt1=getc(n,i);
        LL pt2=getc(x1-1,n-i-1);
        LL pt3=getc(x3+i-1,i-1);
        ans=(ans+(pt1*pt2)%mod*pt3%mod)%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
