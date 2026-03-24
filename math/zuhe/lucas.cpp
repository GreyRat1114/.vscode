// P3807 【模板】卢卡斯定理/Lucas 定理
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL f[N];
LL g[N];
LL qpow(LL a,LL b,LL p)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%p;
        }
        a=a*a%p;
        b=b>>1;
    }
    return ans;
}
void init(LL p)
{
    f[0]=g[0]=1;
    for(int i=1;i<=N;i++)
    {
        f[i]=f[i-1]*i%p;
        g[i]=g[i-1]*qpow (i,p-2,p)%p;
    }
}
LL getc(LL n,LL m,LL p)
{
    if(n<m||n>p||m>p){
        return 0;
        // printf("{%lld %lld}",n,m);
    }
    return f[n]*g[n-m]%p*g[m]%p;
}
LL lucas(LL n,LL m,LL p){
    if(m==0){
        return 1;
    }
    return lucas(n/p,m/p,p)*getc(n%p,m%p,p)%p;
}
void solve(){
    LL n,m,p;
    cin>>n>>m>>p;
    init(p);
    // LL ans=getc(n+m,n,p);
    LL ans=lucas(n+m,m,p);
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

