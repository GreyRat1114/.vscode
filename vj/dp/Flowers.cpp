#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL t,k;
    cin>>t>>k;
    LL n=1e5+5;
    vector<vector<LL>> dp(n+5,vector<LL>(2,0));
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=k==1?1:0;
    for(int i=2;i<=n;i++){ 
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
        if(i>=k){
            dp[i][1]=(dp[i-k][0]+dp[i-k][1])%mod;
        }
    }
    
    vector<LL> s(n+1,0);
    for(int i=1;i<=n;i++){
        //printf("{%lld,%lld}",dp[i][0],dp[i][1]);
        s[i]=(s[i-1]+dp[i][0]+dp[i][1])%mod;
    }
    for(int i=1;i<=t;i++){
        LL a,b;
        cin>>a>>b;
        LL ans=(s[b]-s[a-1]+mod)%mod;
        cout<<ans<<'\n';
        //cout<<1;
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}