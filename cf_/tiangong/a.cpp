#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=998244353;
LL dp[105][10020];
void solve(){
    memset(dp,0,sizeof(dp));
    int n,x;
    cin>>n>>x;
    vector<LL> a(n+1);
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    s+=x;
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    LL ans=1e9;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2*s+1;j++){
            if(j>=2*a[i]&&dp[i-1][j-2*a[i]]){
                dp[i][j]=dp[i-1][j-2*a[i]]+1;
                
                ans=min(abs(s-j),ans);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}