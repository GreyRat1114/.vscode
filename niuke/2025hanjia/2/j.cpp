#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define mp make_pair
const int N=2e5+5;
vector<int> e[N];
int cnt[N];
int ans[N];
int n,m;
bool vis[N];
void bfs(int x,set<int> &tr){
    memset(vis,false,sizeof(vis));
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        if(cnt[i]==x){
            q.push(mp(i,0));
            vis[i]=true;
        }
    }
    while(!q.empty()){
        int u=q.front().first;
        int d=q.front().second;
        q.pop();
        for(auto v:e[u]){
            if(vis[v]||cnt[v]>=x){
                continue;
            }
            q.push(mp(v,d+1));
            vis[v]=true;
            ans[v]=min(ans[v],d+1);
        }
    }
}
void solve(){
    memset(cnt,0,sizeof(cnt));
    
    cin>>n>>m;
    for(int i=0;i<=n+2;i++){
        ans[i]=1e9;
    }
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    set<int> tr;
    for(int i=1;i<=n;i++){
        tr.insert(cnt[i]);
    }
    for(auto it=tr.rbegin();it!=tr.rend();it++){
        bfs(*it,tr);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==1e9){
            cout<<-1<<' ';
        }else{
            cout<<ans[i]<<' ';
        }
        
    }
    cout<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}