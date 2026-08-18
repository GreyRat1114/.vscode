#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    LL maxn=0;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
        maxn=max(maxn,a[i]);
    }
    cout<<s+maxn<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}