#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
LL dp[N][2];
bool vis[N];
void solve(){
    int n,m;
    cin>>n;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=0;
    dp[1][0]=a[1];
    ans=a[1];
    if(n==1){
        cout<<ans<<'\n';
        return;
    }
    for(int i=2;i<=n;i++){
        dp[i][1]=max(dp[i-2][1]+a[i],dp[i-2][0]+a[i]);
        dp[i][0]=max(dp[i][0],dp[i-1][1]+a[i]);
    }
    ans=max(dp[n][0],dp[n][1]);
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}