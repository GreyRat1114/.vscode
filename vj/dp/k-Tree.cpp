#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n,k,d;
    cin>>n>>k>>d;
    vector<vector<vector<LL>>> dp(n+10,vector<vector<LL>>(2,vector<LL>(n+1,0)));
    dp[1][0][0]=1;
    for(int i=2;i<=n+2;i++){
        for(int j=1;j<=k;j++){
            for(int s=j;s<=n;s++){
                if(j>=d){
                    //dp[i][0][s]=0;
                    dp[i][1][s]=(dp[i][1][s]+dp[i-1][0][s-j]+dp[i-1][1][s-j])%mod;
                }else{
                    dp[i][0][s]=(dp[i][0][s]+dp[i-1][0][s-j])%mod;
                    dp[i][1][s]=(dp[i][1][s]+dp[i-1][1][s-j])%mod;
                }
                //printf("{%lld,%lld,%lld,%lld,%lld,%lld}",i,j,j>=d?1:0,s,dp[i][0][s],dp[i][1][s]);
            }
        }

    }
    LL ans=0;
    for(int i=1;i<=n+2;i++){
        ans=(ans+dp[i][1][n])%mod;
    }
    cout<<ans%mod<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}