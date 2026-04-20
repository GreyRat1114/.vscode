#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+1),s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    deque<LL> q;
    vector<LL> dp(n+1,1e18);
    dp[1]=a[1];
    q.push_back(1);
    for(int i=2;i<=n;i++){

        while(!q.empty()&&q.front()<i-k-1){
            q.pop_front();
        }
        if(!q.empty()){
            LL j=q.front();
            dp[i]=dp[j]-s[j]/2+s[i]/2+a[i]/2;
        }
        while(!q.empty()&&dp[i]-s[i]/2<=dp[q.back()]-s[q.back()]/2){
            q.pop_back();
        }
        q.push_back(i);
    }
    LL ans=1e18;
    for(int i=n;i>=max(1ll,n-k);i--){
        ans=min(ans,dp[i]+(s[n]-s[i])/2);
    }
    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",dp[i]);
    // }
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