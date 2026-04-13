#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL check(LL x){
    while(x/10){
        x=x/10;
    }
    return x;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<LL>> dp(n+1,vector<LL>(10,1e9));
    for(int i=0;i<10;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        LL cur=check(a[i]);
        LL lst=a[i]%10;
        for(int j=0;j<=9;j++){
            if(dp[i-1][j]==1e9){
                continue;
            }
            if(j==cur){
                dp[i][lst]=min(dp[i-1][j],dp[i][lst]);
            }else{
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            }
            //dp[i][cur]
        }   
    }
    LL ans=1e9;
    for(int i=0;i<10;i++){
        ans=min(ans,dp[n][i]);
    }
    cout<<ans<<'\n';

}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}