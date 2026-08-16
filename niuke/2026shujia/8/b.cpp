#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;

void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> vis(1e4+5,0);
    LL tag=0;
    for(int i=1;i<=m;i++){
        LL x;
        cin>>x;
        if(x>=2*n){tag=1;}
        else{
            vis[x]=1;
        }
        
    }
    if(tag){
        cout<<0<<'\n';
        return;
    }
    vector<vector<LL>> dp(2*n+5,vector<LL>(2*n+5,0));
    dp[0][0]=1;
    LL ans=0;
    for(int i=1;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            LL d1;
            LL d2=dp[i-1][j+1];
            if(vis[i])d2=0;
            if(j==0){
                d1=0;
            }else{
                d1=dp[i-1][j-1];
            }
            

            dp[i][j]=(d1+d2)%mod;
            //printf("{%lld,%lld,%lld}\n",i,j,dp[i][j]);
        }
    }
    cout<<dp[2*n][0]%mod<<'\n';
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
