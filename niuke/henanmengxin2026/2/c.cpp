#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
vector<vector<pair<LL,LL>>> e;
vector<LL> vis;
vector<LL> a,dist;
LL s,t;
struct node{
    LL val,u;
    bool operator < (const node &o)const{
        if(val==o.val)return u>o.u;
        return val>o.val;
    }
};
void dijkstra(){
    priority_queue<node> q;
    q.push({0,s});
    vis[s]=1;
    dist[s]=0;
    while(!q.empty()){
        LL u=q.top().u;
        //printf("{%lld,%lld}",u,c);
        q.pop();
        vis[u]=0;
        for(auto x:e[u]){
            LL v=x.first;
            LL w=x.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(!vis[v]){
                    q.push({dist[v],v});
                    vis[v]=1;
                }
            }
        }
    }
    return;
}
void solve(){
    LL n,m,q;
    cin>>n>>m>>s>>t>>q;
    e.assign(n+1,vector<pair<LL,LL>>());
    dist.assign(n+1,1e18);
    vis.assign(n+1,0);
    for(int i=1;i<=m;i++){
        LL u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dijkstra();
    LL s=dist[t];
    //printf("{%lld}",s);
    LL cnt;
    for(LL i=0;i<=60;i++){
        if((1ll<<i)&s){
            cnt=i+1;
        }
    }
    if(cnt<=q){
        cout<<"YES"<<'\n';

    }else{
        cout<<"NO"<<'\n';
        cout<<cnt<<'\n';
    }
    //cout<<s<<'\n';
    // a.assign()
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