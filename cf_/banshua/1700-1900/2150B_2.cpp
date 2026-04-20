#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
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
        g[i]=g[i-1]*qpow(i,mod-2)%mod;
    }
}
LL getc(LL n,LL m)
{
    return f[n]*g[n-m]%mod*g[m]%mod;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1,0);
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    LL cnt=0;
    LL ans=1;
    if(s!=n){
        cout<<0<<'\n';
        return;
    }
    for(int i=n;i>=1;i--){
        if(i*2<=n){
            cnt+=2;
        }else if(n%2==1&&i*2==n+1){
            cnt+=1;
        }
        if(cnt<a[i]){
            cout<<0<<'\n';
            return;
        }
        ans=(ans*getc(cnt,a[i]))%mod;
        cnt-=a[i];
    }

    cout<<ans<<'\n';
}
int main(){
    init();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}