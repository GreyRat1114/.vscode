#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=998244353;
char x[N],y[N];
void solve(){
    string x1,y1;
    cin>>x1;
    cin>>y1;
    int n=x1.length();
    vector<vector<LL>> dp(n+1,vector<LL>(2,0));
    dp[0][0]=0;
    dp[0][1]=1e9;
    for(int i=0;i<n;i++){
        LL x=x1[i]-'0';
        LL y=y1[i]-'0';
        dp[i+1][0]=min(dp[i][0]+(x^0)+(y^0),dp[i][1]+(x^1)+(y^0));
        dp[i+1][1]=min(dp[i][0]+(x^1)+(y^1),dp[i][1]+(x^0)+(y^1));
    }
    LL ans=min(dp[n][0],dp[n][1]);
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