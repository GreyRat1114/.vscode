#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    int n;
    cin>>n;
    vector<LL> a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<array<LL,7>> dp(n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=6;j++){
            dp[i][j]=1e9;
        }
    }
    for(int i=0;i<=6;i++){
        dp[1][i]=1;
    }
    dp[1][a[1]]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=6;j++){
            for(int k=1;k<=6;k++){
                if(j+k==7||j==k){
                    continue;
                }
                if(j==a[i]){

                    dp[i][j]=min(dp[i-1][k],dp[i][j]);
                }else{
                    dp[i][j]=min(dp[i-1][k]+1,dp[i][j]);
                }
                //printf("{%d,%d,%d,%lld,%lld}\n",i,j,k,dp[i][j],dp[i-1][k]);
            }
        }
    }
    LL ans=1e9;
    for(int i=1;i<=6;i++){
        ans=min(ans,dp[n][i]);
        //cout<<dp[n][i]<<' ';
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