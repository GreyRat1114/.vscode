#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
void solve(){
    //170899
    LL pt1=qpow(21,170899)*qpow(5,170899)%mod;
    vector<vector<LL>> dp(341799+10,vector<LL>(4,0));
    dp[1][0]=5;
    dp[1][1]=21;
    for(int i=2;i<=341799;i++){
        dp[i][0]=dp[i-1][1]*5%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])*21%mod;
    }
    printf("{%lld,%lld}",dp[341799][0],dp[341799][1]);
    
    //cout<<pt1<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}