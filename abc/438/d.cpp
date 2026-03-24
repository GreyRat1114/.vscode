#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
LL a[5][N];
LL dp[5][N];
void solve(){
    memset(dp,0,sizeof(dp));
    int n,m;
    cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dp[1][1]=a[1][1];

    for(int i=2;i<=n;i++){
        dp[1][i]=dp[1][i-1]+a[1][i];
    }

    for(int i=2;i<=3;i++){
        for(int j=i;j<=n;j++){
            if(j==i){
                dp[i][j]=dp[i-1][j-1]+a[i][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j-1],dp[i][j-1])+a[i][j];
            }
            
        }
    } 
    cout<<dp[3][n]<<'\n';

}
int main(){
    solve();
    return 0;
}