#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
vector<LL> ans;
vector<vector<LL>> dp;
LL cur;
void work(LL n,LL k){
    if(n==0)return;
    for(int i=1;i<=n;i++){
        LL m=(i-1)*i/2;
        if(k>=m&&dp[n-i][k-m]){
            for(int j=1;j<=i;j++){
                ans[n-i+j]=++cur;
            }            
            work(n-i,k-m);
            return;
        }
    }
}
void solve(){
    cur=0;
    LL n,k1;
    cin>>n>>k1;
    k1=(n-1)*n/2-k1;
    ans.assign(n+1,0);
    dp.assign(n+1,vector<LL>((n-1)*n/2+1,0));
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        LL m=(i-1)*i/2;
        for(int j=0;j<=m;j++){
            if(dp[i][j]){
                for(int k=1;k+i<=n;k++){
                    LL x=(k-1)*k/2;
                    dp[i+k][j+x]=dp[i][j];     
                    //printf("{%lld}",dp[i+k][j+x]);               
                }
            }
        }
    }
    if(dp[n][k1]==0){
        cout<<0<<'\n';
        return;
    }
    work(n,k1);
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}