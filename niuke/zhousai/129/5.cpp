#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
map<LL,int> tr;
const LL mod=1000000007;
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
    for(int i=1;i<=N;i++)
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
    init();
    LL n;
    cin>>n;
    LL y=(qpow(2,n)/2)%mod;

    for(int i=1;i<=n;i++){
        LL x=(getc(n,i)*y)%mod;
        cout<<x<<' ';
    }

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}