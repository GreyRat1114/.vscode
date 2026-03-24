// B - Kleene Inversion
#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
using LL=long long;
const LL mod=1000000007;
LL pre[N];
LL suf[N];
LL a[N];
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
    return ans%mod;
}
void solve(){
    memset(pre,0,sizeof(pre));
    memset(suf,0,sizeof(suf));
    LL n,k;
    cin>>n>>k;
    LL ny=qpow(2,mod-2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                if(a[j]<a[i]){
                    pre[i]++;
                }
            }
            else{
                if(a[j]<a[i]){
                    suf[i]++;
                }                
            }
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        LL d=pre[i]+suf[i];
        // printf("{%lld}",d);
        LL a1=suf[i];
        LL p1=((k-1)*k/2)%mod;
        LL s1=(p1*d)%mod;
        LL s2=(k*a1)%mod;
        LL s=(s1+s2);
        ans=(ans+s)%mod;
    }
    cout<<ans%mod<<'\n';
}
int main(){
    solve();
    return 0;
}