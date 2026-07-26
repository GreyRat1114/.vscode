#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<LL>> dp(n+2,vector<LL>(2,1e9));
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    dp[1][0]=a[2];
    dp[1][1]=0;
    for(int i=2;i<=n-1;i++){
        dp[i][0]=min(dp[i-1][0]+a[i+1],dp[i-1][1]+max(a[i-1],a[i+1]));
        dp[i][1]=min(dp[i-1][0],dp[i-1][1]+a[i-1]);
    }
    //printf("{%lld,%lld}",dp[n-1][0],dp[n-1][1]);
    LL ans=min(dp[n-1][0],dp[n-1][1]+a[n-1]);
    cout<<ans<<'\n';
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