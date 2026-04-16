#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=1e9+7;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<vector<LL>>> dp(n+1,vector<vector<LL>>(n+1,vector<LL>(n+1,0)));
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++){
                dp[i][j][k]=(dp[i-1][j][k]+dp[i][j][k])%mod;
                if(a[i]>=j){
                    dp[i][a[i]][k]=(dp[i-1][j][k]+dp[i][a[i]][k])%mod;
                }else if(a[i]>=k){
                    dp[i][j][a[i]]=(dp[i-1][j][k]+dp[i][j][a[i]])%mod;
                }
            }
        }
    }
    LL ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            ans=(ans+dp[n][i][j])%mod;
        }
    }
    cout<<ans%mod<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}