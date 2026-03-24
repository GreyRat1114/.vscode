#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define MP make_pair
#define int long long
vector<int> e[N];
map<int,int> mp;
bool vis[N];
int num;
int s[N];
int dis[N];
int lowbit(int x){
    return x&-x;
}
void change(int x,int k)//向后修
{
    while(x<=N)
    {
        s[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x)//向前查
{
    int t=0;
    while(x)
    {
        t+=s[x];
        x-=lowbit(x);
    }
    return t;

}
void dfs(int u){
    
    dis[u]=1;
    vis[u]=true;
    for(int v:e[u]){
        if(vis[v]){
            continue;
        }
        dfs(v);
        dis[u]+=dis[v];
        num++;
        mp[v]=num;
    }
}
void solve(){
    memset(dis,0,sizeof(dis));
    memset(s,0,sizeof(s));
    int n,k,op;
    
    cin>>n;
    int sum=n;
    int u,v;
    vector<pair<int,int>> eg(n+10);
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        eg[i]=MP(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    num=0;
    dfs(1);
    mp[1]=n;
    cin>>k;
    int x,y,w;
    for(int i=1;i<=n;i++){
        change(mp[i],1);
    }
    for(int i=1;i<=k;i++){
        cin>>op;
        if(op==1){
            cin>>x>>w;
            change(mp[x],w);
            sum+=w;
        }
        else{
            cin>>y;
            int x1=eg[y].first;
            int y1=eg[y].second;
            int t;
            if(mp[x1]>mp[y1]){
                t=y1;
                y1=x1;
                x1=t;
            }
            int s1=query(mp[x1]-dis[x1]);
            int s2=query(mp[x1]);
            // printf("{%d,%d}",s1,s2);
            int ans=abs(sum-2*(s2-s1));
            cout<<ans<<'\n';
            
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("{%d}",dis[i]);
    // }
    // for(auto x :mp){
    //     cout<<x.second<<' ';
    // }
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}