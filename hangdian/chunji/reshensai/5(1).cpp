#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
#define mp make_pair
#pragma GCC optimize("Ofast") // 启用最高级别的优化
#pragma GCC optimize("unroll-loops") // 循环展开优化
#pragma GCC optimize("inline") // 强制内联函数
#pragma GCC optimize("-ffast-math") // 快速数学计算优化
#pragma GCC optimize("-falign-loops") // 循环对齐优化
#pragma GCC optimize("-funroll-loops") // 循环展开
#pragma GCC optimize("-fstrict-aliasing") // 严格别名优化
void solve(){
    LL n,m,k;
    cin>>n>>k>>m;
    vector<LL> a(n+10);
    vector<vector<LL>> dp(n+10,vector<LL>(30,-1e9));
    vector<LL> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    dp[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(dp[i][j]==-1e9){
                continue;
            }
            LL sum=(j==0)?a[i]:a[i]/2;
            int r=max(0,j-1);
            dp[i+1][r]=max(dp[i][j]+sum,dp[i+1][r]);
            if(j==0){
                dp[i+1][k]=max(dp[i][j]+2ll*a[i],dp[i+1][k]);
            }
            int jp=min(n,i+m);
            sum=s[jp]-s[i-1];
            int ji=i+m+1;
            int nr2=max(0ll,j-(m+1));
            dp[min(1ll*ji, n+1)][nr2] = max(dp[min(1ll*ji, n+1)][nr2], dp[i][j] + sum);

        }

    }
    LL ans = 0;
    for(int r=0;r<=k;r++) ans = max(ans, dp[n+1][r]);
    cout << ans << '\n';    
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
