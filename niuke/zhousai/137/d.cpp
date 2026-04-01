#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    vector<LL> dp(n+1,1e18);
    dp[0]=0;
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        //dp[i]=s[i];
        LL minn=1e18;
        for(int j=i-1;j>=0;j--){
            minn=min(minn,dp[j]);
            dp[i]=min(dp[i],minn+(s[i]^s[j]));
        }
        //printf("{%lld,%lld}",i,dp[i]);
    }
    cout<<dp[n]<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}