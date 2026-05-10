#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
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
void solve(){
    LL n;
    cin>>n;
    LL s=0;
    vector<LL> a(n+1),b(n+1);
    vector<LL> pre(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=(s+a[i])%mod;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        pre[i]=(pre[i-1]+b[i])%mod;
    }    
    LL fz=0;
    LL fm=0;
    for(int i=1;i<=n;i++){
        fz=(fz+(a[i]*(pre[i-1]+b[i]*qpow(2,mod-2)%mod)%mod)%mod)%mod;
    }
    cout<<fz*qpow(s,mod-2)%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}