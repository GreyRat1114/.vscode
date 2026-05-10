#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
vector<int> prim;
vector<int> not_prim;
vector<int> f;
vector<int> powpart;
vector<int> low;
LL n,q,d;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1; 
        a=(a*a)%mod;
    }
    return ans%mod;
}
void get_prim(LL n){
    for(LL i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
            low[i]=i;
            powpart[i]=qpow(i,d);
            f[i]=(1+powpart[i])%mod;
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            LL x=i*p;
            low[x]=p;
            f[x]=1ll*f[i]*f[p]%mod;
            if(i%p==0){
                low[x]=low[i]*p;
                if(i==low[i]){
                    f[x]=(1+1ll*powpart[p]*f[i])%mod;
                }else{
                    f[x]=1ll*f[i/low[i]]*f[p*low[i]]%mod;
                }
                break;
            }
        }
    }
}
void solve(){
    cin>>n>>d>>q;
    d %= mod - 1;
    prim.clear();
    not_prim.assign(n+1,0);
    f.assign(n+1,0);
    f[1]=1;
    powpart.assign(n+1,0);
    low.assign(n+1,0);
    get_prim(n);
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++){
        s[i]=(s[i-1]+f[i])%mod;
    }
    for(int i=1;i<=q;i++){
        LL l,r;
        cin>>l>>r;
        cout<<(s[r]-s[l-1]+mod)%mod<<'\n';
    }
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