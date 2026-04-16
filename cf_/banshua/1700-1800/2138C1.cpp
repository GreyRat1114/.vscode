#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
const LL mod=1e9+7;
vector<LL> e[N];
vector<vector<LL>> d;
void dfs(LL u,LL fa,LL cnt){
    d[cnt].push_back(u);
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs(v,u,cnt+1);
    }
}
void solve(){

    LL n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        e[i].clear();
    }
    d.assign(n+1,vector<LL>());
    LL u,v;
    for(int i=2;i<=n;i++){
        cin>>u;
        e[u].push_back(i);
        e[i].push_back(u);
    }
    dfs(1,1,1);
    LL m=1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<d[i].size();j++){
            //printf("{%lld,%lld,%lld}",i,j,d[i][j]);
            if(e[d[i][j]].size()==1&&d[i][j]!=1){
                m=i;
            }
        }
    }
    vector<vector<LL>> dp(n+1,vector<LL>(k+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        LL siz=d[i].size();
        for(int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(j-siz>=0&&dp[i-1][j-siz]){
                dp[i][j]=dp[i-1][j-siz];
            }
        }
    }
    LL sum=0;
    //cout<<m<<'\n';
    for(int i=n;i>=1;i--){
        for(int j=max(0ll,k-sum);j<=k;j++){
            if(dp[i][j]){
                cout<<min(i*1ll,m)<<'\n';
                return;
            }
        }
        sum+=d[i].size();
    }

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