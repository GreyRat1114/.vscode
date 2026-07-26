#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 998244353;

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n==1){
        cout << a[1] << "\n";
        return;
    }
    vector<LL> w(n+1);
    int r = (n+1)/2;
    for(int i=1;i<=r;i++){
        w[i] = n+5-i;
    }
    for(int i=r+1;i<=n;i++){
        w[i] = w[n+1-i];
    }
    LL ans = 0;
    for(int i=1;i<=n;i++){
        ans = (ans + a[i]*w[i]%MOD) % MOD;
    }
    ans = (ans * qpow(6LL,MOD-2)) % MOD;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}