#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL qpow(LL a,LL b)
{
    a=a%mod;
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
LL getans(LL a,LL b){
    LL ans=(a*qpow(b,mod-2))%mod;
    return ans;
}

void solve(){
    LL n,m;
    cin>>n>>m;
    LL ans=getans(n,m);
    // ans=qpow(ans,8);
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