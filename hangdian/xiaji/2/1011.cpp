#include<bits/stdc++.h>
using namespace std;
using LL= long long;
vector<LL> e,a;
vector<vector<vector<LL>>> dp;
struct node{
    LL x,y;
};
LL dfs(LL u,LL fa,LL id){
    if(e[u]==0){
        dp[u][1][id]=min({dp[u][1][id],dp[fa][0][id]+a[fa]});
        dp[u][0][id]=min(dp[u][0][id],dp[fa][1][id]);
        printf("{%lld,%lld,%lld}",dp[u][1][id],dp[u][0][id],u);   
        return min(dp[u][0][id],dp[u][1][id]);
    }      
    LL v=e[u];    
    dp[u][1][id]=min({dp[u][1][id],dp[fa][0][id]+a[fa],dp[fa][1][id]+a[v]});
    dp[u][0][id]=min(dp[u][0][id],dp[fa][1][id]);
    printf("{%lld,%lld,%lld}",dp[u][1][id],dp[u][0][id],u);      
    return dfs(v,u,id);
}
LL work(node nd){
    LL x=nd.x;
    LL y=nd.y;
    LL rt=max(a[e[x]],a[y]);
    dp[e[x]][0][0]=0;
    dp[e[x]][1][0]=a[e[e[x]]];
    //printf("{%lld,%lld,%lld,%lld}",dp[e[x]][0][0],dp[e[x]][1][0]=a[e[e[x]]],x,e[x]);
    dp[e[y]][0][0]=1e9;
    dp[e[y]][1][0]=a[y];
    printf("<%lld>",a[y]);
    rt+=dfs(e[x],x,0);
    printf("|%lld|\n",rt);
    rt+=dfs(e[y],y,0);
    printf("|%lld|\n",rt);
    LL ans=rt;
    rt=max(a[e[y]],a[x]);
    dp[e[x]][0][1]=0;
    dp[e[x]][1][1]=a[e[e[x]]];
    dp[e[y]][0][1]=1e9;
    dp[e[y]][1][1]=a[x]; 
    rt+=dfs(e[x],x,1);
    printf("|%lld|\n",rt);
    rt+=dfs(e[y],y,1);
    printf("|%lld|\n",rt);
    ans=min(ans,rt);
    printf("(%lld)",ans);
    return ans;
}
void solve(){
    LL n;
    cin>>n;
    a.resize(n+1);
    e.assign(n+1,0);
    dp.assign(n+1,vector<vector<LL>>(2,vector<LL>(2,1e9)));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    e[2]=1;
    e[n-1]=n;
    queue<node> q;
    for(int i=2;i<=n-1;i++){
        LL fa=a[i-1]>a[i+1]?i-1:i+1;
        if(e[i]==fa){
            q.push({i,fa});
            //printf("{%lld,%lld}",i,fa);
            continue;
        }
        e[fa]=i;
        LL maxn=max(a[i-1],a[i+1]);
    }
    for(int i=1;i<=n;i++){
        printf("{%lld}",e[i]);
    }
    LL ans=0;
    while(!q.empty()){
        ans+=work(q.front());
        q.pop();
    }
    cout<<ans<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}