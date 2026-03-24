#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e6+5;
int a[N];
char c[3][N];
int dp[3][N];
int vis[3][N];
void solve(){
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int fst=0;
    int lst=-1;
    int n=s1.length();
    for(int i=0;i<n;i++){
        c[1][i+1]=s1[i];
        c[2][i+1]=s2[i];
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]=='#'){
                vis[i][j]=1;
            }    
        }
    }
    for(int i=1;i<=n;i++){
        if((c[1][i]=='#'||c[2][i]=='#')&&fst==0){
            fst=i;
        }     
        if(c[1][i]=='#'||c[2][i]=='#'){
            lst=i;
        }             
    }
    for(int i=fst;i<=lst;i++){
        dp[1][i]=min(dp[1][i-1]+1-vis[1][i],dp[2][i-1]+2-vis[2][i]-vis[1][i]);
        dp[2][i]=min(dp[2][i-1]+1-vis[2][i],dp[1][i-1]+2-vis[1][i]-vis[2][i]);
    }
    int ans=min(dp[1][lst],dp[2][lst]);
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}