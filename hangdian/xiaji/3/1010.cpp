#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
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
void solve(){
    LL w,l;
    cin>>w>>l;
    cout<<(qpow(w,l)+l-1+mod)%mod<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}