#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
void solve(){
    LL x,y;
    cin>>x>>y;
    LL n=min(x,y);
    LL ans=0;
    for(LL i=1;i<=n;){
        LL v=x/i;
        ans+=(x/v-i+1)*v;
        i=x/v+1;
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