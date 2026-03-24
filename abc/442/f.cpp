#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
using LL =long long;
char c[N][N];
int dp[3][N];
int s0[N];
int s1[N];
void solve(){
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            c[i][j+1]=s[j];
        }
    }
    int tag=0;

    for(int i=1;i<=n;i++){
        tag=tag^1;
        s0[0]=0;
        s1[0]=0;
        for(int j=1;j<=n;j++){
            if(c[i][j]=='.'){
                s0[j]=s0[j-1]+1;
                s1[j]=s1[j-1];
            }else{
                s0[j]=s0[j-1];
                s1[j]=s1[j-1]+1;
            }
        }
        // for(int j=0;j<=n;j++){
        //     printf("{%d %d}",s0[j],s1[j]);
        // }
        int minn=1e9;
        for(int j=n;j>=0;j--){
            if(dp[tag^1][j]<minn){
                minn=dp[tag^1][j];
            }
            dp[tag][j]=minn+s1[j]-s1[0]+s0[n]-s0[j];
            
        }
        // for(int j=0;j<=n;j++){
        //     printf("{%d}",dp[tag][j]);
        // }
        // cout<<'\n';
        
    }
    int ans=1e9;
    for(int i=0;i<=n;i++){
        //cout<<dp[tag][i]<<' ';
        ans=min(ans,dp[tag][i]);
    }
    //cout<<'\n';
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;

}