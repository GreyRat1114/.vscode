#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<LL> dp(n+1,-1e18);
    vector<LL> maxn(2,-1e18);
    dp[0]=0;
    dp[1]=0;
    maxn[(a[1]%2+2)%2]=dp[0]+a[1];
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i],dp[i-1]);
        LL c=(a[i]%2+2)%2;
        dp[i]=max(dp[i],maxn[c]+a[i]);
        maxn[c]=max(maxn[c],dp[i-1]+a[i]);
    }
    LL ans=0;
    for(int i=2;i<=n;i++){
        ans=max(ans,dp[i]);
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