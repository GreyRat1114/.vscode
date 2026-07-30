#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    vector<LL> b(n+1);
    vector<vector<i128>> dp(n+1,vector<i128>(70,1e24));
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=60;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=1&&b[i]>=dp[i-1][j-1])dp[i][j]=min(dp[i][j],dp[i-1][j-1]+b[i]);
            //printf("{%lld}",(LL)dp[i][j]);
        }
        //cout<<'\n';
    }
    LL ans=0;
    for(int i=1;i<=65;i++){
        if(dp[n][i]!=1e24)ans=i;
    }
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