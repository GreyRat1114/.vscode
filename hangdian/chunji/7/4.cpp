#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+2);
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    vector<vector<vector<LL>>> dp(n+2,vector<vector<LL>>(n+2,vector<LL>(4,-1e18)));
    dp[0][0][0]=0;
    dp[1][1][1]=-a[1];
    dp[2][0][0]=-a[1]+a[2];
    dp[2][2][2]=-a[1]-a[2];
    if(n==1){
        cout<<-a[1]<<'\n';
        return;
    }else if(n==2){
        cout<<max(-a[1]+a[2],-a[1]-a[2])<<'\n';
        return;
    }
    for(int i=3;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j>=1){
                dp[i][j][1]=max({dp[i][j][1],dp[i-1][j-1][0]-a[i]});
                dp[i][j][2]=max({dp[i][j][2],dp[i-1][j-1][1]-a[i],dp[i-1][j-1][2]-a[i]});                
            }
            if(j<i){
                dp[i][j][0]=max({dp[i-1][j+1][1]+a[i],dp[i-1][j+1][0]+a[i],dp[i][j][0]});
                if(a[i-2]>a[i-1])dp[i][j][0]=max(dp[i-1][j+1][2]+a[i],dp[i][j][0]);
            }
        }
    }
    LL ans=-1e18;
    for(int i=0;i<=n;i++){
        ans=max({ans,dp[n][i][0]+a[n+1]*i,dp[n][i][1]+a[n+1]*i,dp[n][i][2]+a[n+1]*i});
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}