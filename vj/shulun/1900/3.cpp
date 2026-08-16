#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=100005;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    vector<LL> dp(2e5+5,0),vis(2e5+5,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    
    sort(a.begin()+1,a.begin()+n+1);
    vector<vector<LL>> pre(2e5+5);
    LL ans=0;
    for(int i=1;i<=2e5+5;i++){
        LL x=i;
        if(!vis[i])continue;
        for(int j=x;j<=2e5+5;j+=x){
            if(vis[j]){
                pre[j].push_back(x);
            }
        }
    }

    for(LL i=1;i<=n;i++){
        LL y=a[i];
        LL maxn=0;
        for(auto x:pre[y]){
            maxn=max(dp[x]+1,maxn);
        }
        dp[y]=max(maxn,dp[y]);
        ans=max(ans,dp[y]);
    }
    cout<<n-ans<<'\n';
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