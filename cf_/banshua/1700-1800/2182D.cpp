#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
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
LL geta(LL x){
    if(x==1||x==0){
        return 1;
    }
    return (x*geta(x-1))%mod;
}
void solve(){
    LL n,k;
    cin>>n;
    vector<LL> a(n+1);
    LL s=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    LL low=s/n;
    LL yu=s%n;
    LL nd=0;
    LL sh=0,sl=0;;
    for(int i=1;i<=n;i++){
        if(a[i]-low>=2){
            cout<<0<<'\n';
            return;
        }
        if(a[i]<low){
            nd+=low-a[i];
        }
        if(a[i]==low+1){
            sh++;
        }
    }
    sl=n-yu;
    LL pt1=getc(n-sh,sl);
    if(nd>a[0]){
        cout<<0<<'\n';
        return;        
    }
    LL ans=(geta(yu)*geta(sl))%mod;
    ans=(ans*pt1)%mod;
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