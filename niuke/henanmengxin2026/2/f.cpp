#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=2000+10;
const LL atk=669;
vector<vector<LL>> e;
vector<vector<pair<double,LL>>> dp;
vector<LL> a;
LL dfs(LL u,LL fa){
    if(e[u].size()==1&&u!=1){
        dp[u][0]={a[u],1};
        dp[u][1]={a[u],1};
        return 1;
    }
    LL max1=0;
    LL max2=0;
    LL c=0;
    for(auto v:e[u]){
        if(v==fa)continue;
        LL tag=dfs(v,u);
        if(tag){
            double x=1.0*(dp[v][0].first*dp[v][0].second+a[u])/(dp[v][0].second+1);
            if(x>=dp[u][0].first){
                dp[u][0]={x,dp[v][0].second+1};
            }            
            continue;
        }
        c++;
        double x=1.0*(dp[v][0].first*dp[v][0].second+a[u])/(dp[v][0].second+1);
        if(x>=dp[u][0].first){
            dp[u][0]={x,dp[v][0].second+1};
        }
        if(x>=dp[u][1].first){
            dp[u][1]={x,dp[v][0].second+1};
        }        
        if(x>dp[max1][0].first){
            max2=max1;
            max1=v;
        }else if(x>dp[max2][0].first){
            max2=v;
        }
        if(dp[v][1].first>dp[u][1].first){
            dp[u][1]=dp[v][1];
        }
    }
    if(c>=2){
        double y=1.0*(dp[max1][0].first*dp[max1][0].second+dp[max2][0].first*dp[max2][0].second)/(dp[max1][0].second+dp[max2][0].second);
        if(y>dp[u][1].first){
            dp[u][1]={y,dp[max1][0].second+dp[max2][0].second};
        }
        
    }
    return 0;
}
void solve(){
    LL n;
    cin>>n;
    a.assign(n+1,0);
    dp.assign(n+1,vector<pair<double,LL>>(2,{0.0,1}));
    e.assign(n+1,vector<LL>());
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }   
    dfs(1,1);
    cout<<setprecision(2)<<fixed<<max(dp[1][0].first,dp[1][1].first)<<'\n';

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