#include <bits/stdc++.h>
using namespace std;
using LL = long long;

static const LL NEG = -(1LL<<60);

void solve(){
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n+1);
    vector<LL> pre(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    // dp[i][r]: 到达 i，剩余受影响节点数 r
    vector<vector<LL>> dp(n+2, vector<LL>(k+1, NEG));
    dp[1][0] = 0;

    for(int i=1;i<=n;i++){
        for(int r=0;r<=k;r++){
            LL cur = dp[i][r];
            if(cur==NEG) continue;

            // 1) 普通收集
            LL gain_normal = (r>0 ? a[i]/2 : a[i]);
            int nr = max(0, r-1);
            dp[i+1][nr] = max(dp[i+1][nr], cur + gain_normal);

            // 2) 回溯（仅 r==0）
            if(r==0){
                dp[i+1][k] = max(dp[i+1][k], cur + 2LL*a[i]);
            }

            // 3) 跳跃（不受影响）
            int j = min(n, i + m);
            LL gain_jump = pre[j] - pre[i-1];
            int ni = i + m + 1;
            int nr2 = max(0, r - (m+1));
            dp[min(ni, n+1)][nr2] = max(dp[min(ni, n+1)][nr2], cur + gain_jump);
        }
    }

    LL ans = 0;
    for(int r=0;r<=k;r++) ans = max(ans, dp[n+1][r]);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}