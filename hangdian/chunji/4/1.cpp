#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> a;
vector<vector<LL>> vis;
map<LL,LL> mp;
LL dx[]={-1,-1,-1,0,0,1,1,1};
LL dy[]={-1,0,1,-1,1,-1,0,1};
LL n,m;
LL bfs(LL sx,LL sy,LL val){
    queue<pair<LL,LL>> q;
    q.push(make_pair(sx,sy));
    vis[sx][sy]=1;  
    LL pt1=0;
    LL pt2=0;
    while(!q.empty()){
        LL x=q.front().first;
        LL y=q.front().second;
        q.pop();
        if(x==1||y==m){
            pt1=1;
        }
        if(x==n||y==1){
            pt2=1;
        }
        if(pt1&&pt2){
            return 1;
        }
        for(int i=0;i<8;i++){
            LL x1=x+dx[i];
            LL y1=y+dy[i];
            if(x1<1||x1>n||y1<1||y1>m)continue;
            if(!vis[x1][y1]&&a[x1][y1]==val){
                vis[x1][y1]=1;
                q.push(make_pair(x1,y1));
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    a.assign(n+1,vector<LL>(m+1,0));
    vis.assign(n+1,vector<LL>(m+1,0));
    mp.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j])continue;
            mp[a[i][j]]=max(mp[a[i][j]],bfs(i,j,a[i][j]));
        }
    }
    LL pre=-1;
    for(auto v:mp){
        //printf("{%lld,%lld}",v.first,v.second);
        if(!v.second){
            break;
        }
        pre=v.first;
    }
    cout<<pre+1<<'\n';
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