#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
void solve(){
    LL n,k;
    cin>>n>>k;
    
    string s;
    cin>>s;
    vector<LL> dp(n+1,1e9);
    dp[0]=0;
    dp[1]=0;
    for(int i=1;i<=n;i++){
        int tag=1;
        LL cnt=0;
        for(int j=i-1;j>=0;j--){
            if(j==i-1){
                dp[i]=min(dp[i],dp[j]+1);
                continue;
            }
            if(i-j>k){
                break;
            }
            if(s[j]!=s[j-1]){
                cnt++;
            }else{
                cnt=0;
            }
            dp[i]=min(dp[j]+cnt,dp[i]);
            //printf("{%lld,%lld,%lld}",i,j,dp[i]);
        }
        
    }
    cout<<dp[n]<<'\n';
    //cout<<n/k-1;


}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}