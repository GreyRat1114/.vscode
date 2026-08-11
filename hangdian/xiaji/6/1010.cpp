#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;

void solve(){
    LL x,y;
    cin >> x >> y;
    if(y == 0){
        cout << 0 << "\n";
        return;
    }
    if(x == 0){
        cout << y*(y-1)/2 << "\n";
        return;
    }
    LL cnt1 = y * x;
    LL cnt2 = y*(y-1)/2LL;
    LL cnt3 = x * (x-1);
    LL cnt4 = (x + 2) * (x - 1) / 2LL;
    LL ans = cnt1 + cnt2 + cnt3 - cnt4;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
