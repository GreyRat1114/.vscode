#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using i128 = __int128_t;
const int MOD = 998244353;

void solve(){
    LL n,x;
    cin >> n >> x;
    priority_queue<LL> pq;
    i128 ans = 0;
    LL cnt = 0;

    if(x == 1){
        for(int i=1;i<=n;i++){
            LL a;
            cin >> a;
            cnt = (cnt + a) % MOD;
        }
        cout << cnt << "\n";
        return;
    }

    for(int i=1;i<=n;i++){
        LL e;
        cin >> e;
        if(e >= x){
            ans += e / x;
            LL r = e % x;
            if(r != 0 && r < x - 1) pq.push(r);
        }
        else if(e < x - 1) pq.push(e);
    }

    if(ans == 0){
        while(!pq.empty()){
            auto e = pq.top();
            cnt = (cnt + e) % MOD;
            pq.pop();
        }
        cout << cnt << "\n";
        return;
    }

    while(!pq.empty()){
        auto e = pq.top();
        if(e + ans < x-1) break;
        LL dif = x - e - 1;
        ans -= dif;
        pq.pop();
    }

    ans = ans % (x-1);
    cnt = ans;

    while(!pq.empty()){
        auto e = pq.top();
        cnt = (cnt + e) % MOD;
        pq.pop();
    }

    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}