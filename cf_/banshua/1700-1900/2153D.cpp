#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#pragma GCC optimize(3)
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(2*n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    LL ans=1e18;
    for(int d=0;d<=3;d++){
        vector<LL> dp(2*n+1,1e18);
        dp[d]=0;
        for(int i=1+d;i<=n+d;i++){
            if(i-d>=2){
                dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-1]));
            }
            if(i-d>=3){
                LL pt1=abs(a[i-2]-a[i-1])+abs(a[i-2]-a[i]);
                LL pt2=abs(a[i-1]-a[i-2])+abs(a[i-1]-a[i]);
                LL pt3=abs(a[i]-a[i-1])+abs(a[i]-a[i-2]);
                dp[i]=min(dp[i],dp[i-3]+min(pt1,min(pt2,pt3)));
            }
        }
        ans=min(ans,dp[n+d]);
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}