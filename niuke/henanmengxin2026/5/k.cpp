#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
void solve(){
    LL l,r;
    cin>>l>>r;
    vector<LL> s(r+1,0);
    double ans=0.0;
    for(LL i=1;i<=r;i++){
        for(LL j=1;j*i<=r;j++){
            LL v=i*j;
            s[v]+=i;
        }
    }
    for(LL i=l;i<=r;i++){
        ans=max(ans,1.0*s[i]/i);
    }
    cout<<setprecision(10)<<fixed<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    //init(1e6+5);
    while(t--){
        solve();
    }
    return 0;
}