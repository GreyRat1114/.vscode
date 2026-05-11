#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1,vector<LL>(2,0));
    for(int i=0;i<=1;i++){
        string s;
        cin>>s;
        //cout<<s<<'\n';
        for(int j=0;j<n;j++){
            a[j+1][i]=s[j]-'0';
        }
    }

    if(n%3!=0||n<=2){
        cout<<-1<<'\n';
        return;
    }
    vector<vector<LL>> dp(n+1,vector<LL>(5,1e9)),dp2(n+1,vector<LL>(5,1e9));
    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=0;
    for(int i=3;i<=n;i+=3){
        LL pt0=(a[i-2][0]^1)+(a[i-2][1]^1)+(a[i-1][0]^1)+(a[i-1][1]^0)+(a[i][0]^0)+(a[i][1]^0);
        LL pt1=(a[i-2][0]^1)+(a[i-2][1]^1)+(a[i-1][0]^0)+(a[i-1][1]^1)+(a[i][0]^0)+(a[i][1]^0);
        LL pt2=(a[i-2][0]^0)+(a[i-2][1]^0)+(a[i-1][0]^0)+(a[i-1][1]^1)+(a[i][0]^1)+(a[i][1]^1);
        LL pt3=(a[i-2][0]^0)+(a[i-2][1]^0)+(a[i-1][0]^1)+(a[i-1][1]^0)+(a[i][0]^1)+(a[i][1]^1);
        dp[i][0]=min(dp[i-3][0],dp[i-3][1])+pt0;
        dp[i][1]=min(dp[i-3][0],dp[i-3][1])+pt1;
        dp[i][2]=min(dp[i-3][2],dp[i-3][3])+pt2;
        dp[i][3]=min(dp[i-3][2],dp[i-3][3])+pt3;
        //printf("{%lld,%lld,%lld,%lld,%lld}\n",i,dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
    }
    LL ans=min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]});
    dp2[0][0]=0;
    dp2[0][1]=0;
    for(int i=3;i<=n;i+=3){
        LL pt0=(a[i-2][0]^1)+(a[i-2][1]^0)+(a[i-1][0]^1)+(a[i-1][1]^0)+(a[i][0]^1)+(a[i][1]^0);
        LL pt1=(a[i-2][0]^0)+(a[i-2][1]^1)+(a[i-1][0]^0)+(a[i-1][1]^1)+(a[i][0]^0)+(a[i][1]^1);
        dp2[i][0]=dp2[i-3][1]+pt0;
        dp2[i][1]=dp2[i-3][0]+pt1;
    }
    ans=min({ans,dp2[n][0],dp2[n][1]});
    cout<<ans<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}