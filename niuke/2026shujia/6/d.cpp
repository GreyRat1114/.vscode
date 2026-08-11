#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> e;
vector<vector<LL>> dp;
void bfs(){
    queue<pair<LL,LL>> q;
    q.push({1,0});
    while(!q.empty()){
        LL u=q.front().first;
        LL w=q.front().second;
        q.pop();
        for(auto v:e[u]){
            if(v==1&&w==1)continue;
            if(dp[v][(w+1)%2])continue;
            dp[v][(w+1)%2]=dp[u][w]+1;
            //printf("{%lld,%lld,%lld,%lld,%lld}\n",u,v,dp[v][(w+1)%2],dp[v][w],(w+1)%2);
            q.push({v,(w+1)%2});
        }
    }
}
void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    e.assign(n+1,vector<LL>());
    dp.assign(n+1,vector<LL>(2,0));
    for(int i=1;i<=m;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs();
    // for(int i=1;i<=n;i++){
    //     printf("{%lld,%lld}",dp[i][0],dp[i][1]);
    // }
    vector<LL> ans(n+1,1e15);
    ans[1]=0;
    for(int i=2;i<=n;i++){
        if(k%2==0){
            if(dp[i][0]){
                LL d=dp[i][0]%k==0?k:dp[i][0]%k;
                ans[i]=(k-d)+dp[i][0];
            }else{
                ans[i]=-1;
            }
        }else{
            if(dp[i][1]){
                LL a=dp[i][1];
                LL q=(a-1)/k+1;
                if(q%2==0){
                    q++;
                }
                ans[i]=min(ans[i],q*k);
            }
            if(dp[i][0]){
                LL a=dp[i][0];
                LL q=(a-1)/k+1;
                if(q%2==1){
                    q++;
                }
                ans[i]=min(ans[i],q*k);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==1e15){
            cout<<-1<<' ';
        }else{
            cout<<ans[i]<<' ';
        }
        
    }
    cout<<'\n';
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