#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    string s;
    cin>>s;
    LL n=s.size();
    vector<vector<LL>> dp(n+1,vector<LL>(3,0));
    // dp[0][0]=1;
    // dp[0][1]=1;
    // dp[0][2]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-1][2];
        if(s[i-1]=='a'){
            dp[i][0]+=(dp[i-1][1]+dp[i-1][2]+1)%mod;
        }else if(s[i-1]=='b'){
            dp[i][1]+=(dp[i-1][2]+dp[i-1][0]+1)%mod;
        }else{
            dp[i][2]+=(dp[i-1][1]+dp[i-1][0]+1)%mod;
        }

    }
    LL ans=(dp[n][0]+dp[n][1]+dp[n][2])%mod;
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