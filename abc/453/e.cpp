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
    LL n;
    cin>>n;
    init(n+10);
    vector<LL> d1(n+5,0),d2(n+5,0);

    for(int i=1;i<=n;i++){
        LL l,r;
        cin>>l>>r;
        LL x=max(n-r,l);
        LL y=min(n-l,r);
        if(x<=y){
            d2[x]++;
            d2[y+1]--;            
        }
        d1[l]++;
        d1[r+1]--;

    }
    vector<LL> s1(n+1,0),s2(n+1,0);
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1]+d1[i];
        s2[i]=s2[i-1]+d2[i];
        //printf("{%lld,%lld}",s1[i],s2[i]);
    }
    LL ans=0;
    for(int i=1;i<=n-1;i++){
        LL a,b;
        a=s1[i];
        b=s1[n-i];
        LL c=s2[i];
        a=a-c;
        b=b-c;
        if(a+b+c!=n)continue;
        if(i<a||n-i<b)continue;
        ans=(ans+getc(c,i-a))%mod;
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}