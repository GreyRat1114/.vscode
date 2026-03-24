// P1757 通天之分组背包
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N];
int b[N];
int dp[N];
vector<int> e[N];
void solve(){
    memset(dp,0,sizeof(dp));
    int n,m;
    cin>>m>>n;
    int c;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c;
        maxn=max(maxn,c);
        e[c].push_back(i);
    }
    for(int i=1;i<=maxn;i++){
        for(int j=m;j>=0;j--){
            for(auto k:e[i]){
                if(j>=a[k]){
                    dp[j]=max(dp[j],max(dp[j],dp[j-a[k]]+b[k]));
                }
            }
        }
    }
    int ans=0;
    for(int j=0;j<=m;j++){
        ans=max(ans,dp[j]);
    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}