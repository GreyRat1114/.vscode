#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+5;
#define m make_pair
const LL mod=1e9+7;
vector<int> e[N];
 
void dfs(int u,int fa,vector<int> &cnt){
    cnt[u]=1;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u,cnt);
        cnt[u]+=cnt[v];
    }
    //printf("{%lld,%lld}",u,cnt[u]);
}
void get_ans(int u,int fa,vector<LL> &dp,vector<int> &cnt){
    dp[u]=((cnt[u]-1)*2+1+dp[fa])%mod;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        get_ans(v,u,dp,cnt);
    }    
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        e[i].clear();
    }
    vector<int> cnt(n+1,0);
    vector<LL> dp(n+1,0);
    int l,r;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        if(l==r&&l==0){
            continue;
        }
        e[i].push_back(r);
        e[i].push_back(l);
        e[r].push_back(i);
        e[l].push_back(i);        
    }   
    dfs(1,1,cnt);
    dp[1]=(cnt[1]-1)*2+1;
    get_ans(1,0,dp,cnt);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<' ';
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