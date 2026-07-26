#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    vector<LL> a(2*n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    vector<vector<LL>> dp(2*n+1,vector<LL>(2*n+1,0));
    LL ans=0;
    for(int len=3;len<=n;len++){
        for(int i=1;i+len-1<=2*n;i++){
            int j=i+len-1;
            for(int k=i+1;k<=j-1;k++){
                dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k+1][j-1]+a[i]*a[j]*a[k]);
            }
            for(int k=i;k<=j-1;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            //printf("{%lld,%lld,%lld}",i,j,dp[i][j]);
            ans=max(ans,dp[i][j]);
        }
    }
    
    cout<<ans<<'\n';
    
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}