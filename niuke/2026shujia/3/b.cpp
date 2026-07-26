#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
vector<LL> f,g;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
LL getc(LL n,LL m){
    if(n<m||m<0||n<0)return 0;
    return f[n]*g[m]%mod*g[n-m]%mod;
}
void init(LL n){
    f.assign(n+1,0);
    g.assign(n+1,0);
    f[0]=1;
    g[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
        g[i]=(g[i-1]*qpow(i,mod-2))%mod;
    }
}
void solve(){
    LL n,m,c,a,b;
    cin>>n>>m>>c>>a>>b;
    if(m<n){
        cout<<0<<'\n';
        return;
    }
    if(((m-n)%c)!=0){
        cout<<0<<'\n';
        return;
    }
    LL k=(m-n)/c;
    LL pt1=n*qpow(m,mod-2)%mod;
    LL pt2=getc(m,k)%mod;
    LL pt3=qpow(a,k)*qpow(qpow(b,mod-2),k)%mod;
    LL pt4=qpow(b-a,m-k)*qpow(qpow(b,mod-2),m-k)%mod;
    LL ans=pt1*pt2%mod*pt3%mod*pt4%mod;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    init(2e6+10);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}