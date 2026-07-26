#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n,l,r;
    cin>>n>>l>>r;
    vector<LL> cnt(3,0);
    cnt[l%3]=(r-l)/3+1;
    cnt[(l%3+1)%3]=l+1>r?0:(r-l-1)/3+1;
    cnt[(l%3+2)%3]=l+2>r?0:(r-l-2)/3+1;
    //printf("{%lld,%lld,%lld}",cnt[0],cnt[1],cnt[2]);
    vector<vector<LL>> dp(n+1,vector<LL>(3,0));
    dp[1][0]=cnt[0];
    dp[1][1]=cnt[1];
    dp[1][2]=cnt[2];
    for(int i=2;i<=n;i++){
        for(int j=0;j<=2;j++){
            if(dp[i-1][(j-1+3)%3]!=0){
                dp[i][j]+=dp[i-1][(j-1+3)%3]*cnt[1];
            }
            if(dp[i-1][j]!=0){
                dp[i][j]+=dp[i-1][j]*cnt[0];
            }
            if(dp[i-1][(j-2+3)%3]!=0){
                dp[i][j]+=dp[i-1][(j-2+3)%3]*cnt[2];
            }
            dp[i][j]=dp[i][j]%mod;
            //printf("{%lld,%lld,%lld}",i,j,dp[i][j]);
        }
    }
    cout<<dp[n][0]<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}