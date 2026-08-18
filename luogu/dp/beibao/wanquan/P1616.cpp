#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> dp(n+1,0);
    //vector<vector<LL>> dp(m+1,vector<LL>(n+1,0));
    vector<LL> a(m+1),b(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    LL ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j-a[i]<0)continue;
            dp[j]=max(dp[j-a[i]]+b[i],dp[j]);
            ans=max(ans,dp[j]);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}