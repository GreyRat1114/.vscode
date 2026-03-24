#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
LL b[N];
LL f[N];
void init(){
    f[0]=1;
    for(int i=1;i<=N;i++){
        f[i]=(f[i-1]*i)%mod;
    }
}
void solve(){
    LL n,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL minn=1e9+5;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        minn=min(minn,b[i]);
    }   
    int tot=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=minn){
            tot++;
        }
    }    
    LL ans=(f[tot]*f[n-tot])%mod;
    //printf("{%lld,%lld}",f[tot],f[n-tot]);
    cout<<ans<<'\n';
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}