#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
vector<vector<vector<LL>>> dist,vis;
//vector<vector<LL>> vis;
vector<vector<char>> a;
LL dx[]={-1,0,0,1};
LL dy[]={0,-1,1,0};
LL n,m;
struct node{
    LL x,y;
    LL w;
    LL tag;
    bool operator < (const node o) const {
        return w>o.w;
    }
};
void dijkstra(){
    priority_queue<node> q;
    q.push({1,1,0,0});
    vis[1][1][0]=1;
    dist[1][1][0]=0;
    while(!q.empty()){
        LL x=q.top().x;
        LL y=q.top().y;
        LL w=q.top().w;
        LL tag=q.top().tag;
        q.pop();
        if(x==n&&y==m)return;
        vis[x][y][tag]=0;
        for(int i=0;i<4;i++){
            LL x1=x+dx[i];
            LL y1=y+dy[i];
            if(x1<1||x1>n||y1<1||y1>m)continue;
            if((a[x1][y1]=='#')&&(tag==0)&&(w+1<dist[x1][y1][1])){
                dist[x1][y1][1]=w+1;
                if(vis[x1][y1][1]==0){
                    q.push({x1,y1,w+1,1});
                    vis[x1][y1][1]=1;
                }
            }
            if(a[x1][y1]=='#')continue;
            if(w+1<dist[x1][y1][tag]){
                dist[x1][y1][tag]=w+1;
                if(vis[x1][y1][tag]==0){
                    q.push({x1,y1,w+1,tag});  
                    vis[x1][y1][tag]=1;
                }              
            }
        }
    }
    return;
}
void solve(){
    cin>>n>>m;
    dist.assign(n+1,vector<vector<LL>>(m+1,vector<LL>(2,1e9)));
    vis.assign(n+1,vector<vector<LL>>(m+1,vector<LL>(2,0)));
    a.assign(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j+1]=s[j];
        }
    }
    dijkstra();
    if((dist[n][m][0]==1e9)&&(dist[n][m][1]==1e9)){
        cout<<-1<<'\n';
        return;
    }
    cout<<min(dist[n][m][0],dist[n][m][1])<<'\n';
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