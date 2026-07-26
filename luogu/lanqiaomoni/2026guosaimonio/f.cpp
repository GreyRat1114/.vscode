#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
struct node{
    LL v;
    LL w;
};
vector<vector<node>> e;
vector<LL> din;
vector<vector<LL>> cnt;
void solve(){
    LL n,m,p;
    cin>>n>>m>>p;
    e.assign(n+2,vector<node>());
    cnt.assign(n+1,vector<LL>(p+10,0));
    din.assign(n+1,1);
    
    vector<LL> a(n+1);
    vector<vector<LL>> dp(n+2,vector<LL>(p+10,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[n+1].push_back({i,a[i]});
    }
    for(int i=1;i<=m;i++){
        LL x,y,w;
        cin>>x>>y>>w;
        e[x].push_back({y,w});
    }
    dp[n+1][0]=1;
    for(int i=0;i<=p;i++){
        for(int u=1;u<=n+1;u++){
            for(auto nd:e[u]){
                LL v=nd.v;
                LL w=nd.w;
                if(i+w<=p){
                    dp[v][i+w]=(dp[v][i+w]+dp[u][i])%mod;
                }
            }
        }
    } 
    for(int i=1;i<=n;i++){
        LL ans=0;
        for(int j=0;j<=p;j++){
            ans=(ans+dp[i][j])%mod;
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}