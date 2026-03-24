// AT_dp_t Permutation
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
using LL=long long;

void solve()
{
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    vector<vector<LL>> dp(n+10,vector<LL>(n+10,0));
    vector<vector<LL>> s(n+10,vector<LL>(n+10,0));
    dp[1][1]=1;
    s[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(ss[i-2]=='<')
            {
                dp[i][j]=s[i-1][j-1]%mod;
                s[i][j]=(s[i][j-1]+dp[i][j])%mod;
            }
            else
            {
                dp[i][j]=(dp[i][j]+s[i-1][i-1]-s[i-1][j-1]+mod)%mod;
                s[i][j]=(s[i][j-1]+dp[i][j])%mod;
            }
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans<<'\n';
    

}
int main()
{
    solve();
    return 0;
}