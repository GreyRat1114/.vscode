#include<bits/stdc++.h>
using namespace std;
const int N=4e6+5;
using LL=long long;
const LL mod=998244353;
LL f[N];
LL g[N];
LL qpow(LL a,LL b)
{
    LL ans=1;
    LL p;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    return ans;
}
void init()
{
    f[0]=g[0]=1;
    for(int i=1;i<=N-1;i++)
    {
        f[i]=f[i-1]*i%mod;
        g[i]=g[i-1]*qpow (i,mod-2)%mod;
    }
}
LL getc(LL n,LL m)
{
    return f[n]*g[n-m]%mod*g[m]%mod;
}

void solve(){
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    LL ans=0;
    for(int i=0;i<=c;i++){
        ans=ans+(getc(a+b+i,b)*getc(d-1+c-i,d-1)%mod);
        ans=ans%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    init();
    solve();
    return 0;
}