#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;

void solve(){
    LL k,n;
    cin>>n>>k;
    vector<LL> a(n+1);
    //printf("{%lld,%lld}",n,k);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=1e18;
    auto check=[&](LL p,LL i)->void{
        vector<vector<LL>> dp1(k+10,vector<LL>(2,1e18)),dp2(k+10,vector<LL>(2,1e18));
        LL l=max(i-k+1,1ll);
        LL r=min(i+k-1,n);
        //printf("{%lld,%lld,%lld}",i,l,r);
        //dp1[0][0]=0;
        dp1[0][1]=a[i];
        //dp2[0][0]=0;
        dp2[0][1]=a[i];
        for(int j=1;i-j>=l;j++){
            dp1[j][0]=dp1[j-1][1];
            dp1[j][1]=min(dp1[j-1][1],dp1[j-1][0])+a[i-j];
            //printf("{%lld}",dp1[j][1]);
        }
        for(int j=1;i+j<=r;j++){
            dp2[j][0]=dp2[j-1][1];
            dp2[j][1]=min(dp2[j-1][1],dp2[j-1][0])+a[i+j];
            //printf("{%lld}",dp2[j][1]);
        }
        for(int j=0;j<=k-1;j++){
            ans=min(ans,dp1[j][1]+dp2[k-j-1][1]-a[i]);
            //printf("{%lld,%lld,%lld}",j,dp1[i-j][1],dp2[j+k-1][1]);
        }
        //cout<<'\n';        
    };
    for(int i=1;i<=n;i+=k){
        LL p=i;
        check(p,i);
        if(i+1<=n)check(p,i+1);
    }
    k++;
    for(int i=1;i<=n;i+=k){
        LL p=i;
        check(p,i);
        if(i+1<=n)check(p,i+1);        
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