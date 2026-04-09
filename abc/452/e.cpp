#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1,0),b(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    vector<LL> s(n+1,0),s1(n+1,0);
    for(int i=1;i<=n;i++){
        s[i]=(s[i-1]+a[i])%mod;
        s1[i]=(s1[i-1]+(a[i]*i)%mod)%mod;
    }
    LL ans=0;
    for(LL i=1;i<=m;i++){
        for(LL j=1;j<=n/i+1;j++){
            LL r=min(n,j*i-1);
            LL l=max(0ll,(j-1)*i);
            LL sum1=(s[r]-s[l]+mod)%mod;
            LL sum2=(s1[r]-s1[l]+mod)%mod;
            //printf("<%lld,%lld>",sum1,sum2);
            LL pt1=sum1*(j-1)*i%mod;
            LL sum=sum2-pt1;
            LL pt2=(sum*b[i])%mod;
            ans=(ans+pt2)%mod;
            //printf("{%lld,%lld,%lld,%lld,%lld}\n",i,j,l,r,ans);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}