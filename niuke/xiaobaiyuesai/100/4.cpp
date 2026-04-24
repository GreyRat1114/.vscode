#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
vector<vector<LL>> vis;
LL dx[]={-1,0,0,1};
LL dy[]={0,-1,1,0};
LL n,m;
vector<vector<LL>> dist;
vector<vector<pair<LL,LL>>> pos;
void bfs(vector<string> &a,LL &cost,LL x0,LL y0){
    queue<pair<pair<pair<LL,LL>,pair<LL,LL>>,LL>> q;
    q.push(make_pair(make_pair(make_pair(x0,y0),make_pair(x0,y0)),0));
    vis[x0][y0]=1;
    dist[x0][y0]=0;
    while(!q.empty()){
        LL x1=q.front().first.first.first;
        LL y1=q.front().first.first.second;
        LL x2=q.front().first.second.first;
        LL y2=q.front().first.second.second;
        LL w=q.front().second;
        q.pop();
        if(a[x1][y1]=='@'){
            cost=w;
            dist[x1][y1]=w;
            //printf("{%lld,%lld,%lld}",x1,y1,w);
            pos[x1][y1]=make_pair(x2,y2);
            continue;
            //return make_pair(x2,y2);
        }
        if(a[x2][y2]=='@'){
            cost=w;
            dist[x2][y2]=w;
            //printf("{%lld,%lld,%lld}",x1,y1,w);
            pos[x2][y2]=make_pair(x1,y1);
            continue;
            //return make_pair(x1,y1);
        }        
        for(int i=0;i<4;i++){
            LL x3=x1+dx[i];
            LL y3=y1+dy[i];
            LL x4=x2-dx[i];
            LL y4=y2-dy[i];   
            if(x3<0||x3>=n||y3<0||y3>=m||x4<0||x4>=n||y4<0||y4>=m)continue;
            if(vis[x3][y3]||vis[x4][y4])continue;
            if(a[x3][y3]=='#'||a[x4][y4]=='#')continue;
            q.push(make_pair(make_pair(make_pair(x3,y3),make_pair(x4,y4)),w+1));
            vis[x3][y3]=1;
            vis[x4][y4]=1;
        }
    }
}
vector<vector<LL>> dist2;
void bfs3(queue<pair<pair<LL,LL>,LL>> &q,vector<string> &a){
    while(!q.empty()){
        LL x=q.front().first.first;
        LL y=q.front().first.second;
        LL w=q.front().second;
        q.pop();
        if(a[x][y]=='.'){
            //printf("{%lld}",w);
            dist2[x][y]=w;
        }
        for(int i=0;i<4;i++){
            LL x1=x+dx[i];
            LL y1=y+dy[i];
            if(x1<0||y1<0||x1>=n||y1>=m)continue;
            if(vis[x1][y1])continue;
            if(a[x1][y1]=='#')continue;
            q.push(make_pair(make_pair(x1,y1),w+1));
            vis[x1][y1]=1;
        }
    }
}
void solve(){
    LL x,y;
    cin>>n>>m>>x>>y;
    vis.assign(n,vector<LL>(m,0));
    dist.assign(n,vector<LL>(m,1e9));
    dist2.assign(n,vector<LL>(m,1e9));
    pos.assign(n,vector<pair<LL,LL>>(m));
    string s;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    LL w=0;
    bfs(a,w,x-1,y-1);
    //printf("{%lld}",w);
    queue<pair<pair<LL,LL>,LL>> q;
    vis.assign(n,vector<LL>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='@'){
                q.push(make_pair(make_pair(i,j),0));
                dist2[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
    bfs3(q,a);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //printf("{%lld,%lld,%lld,%lld}\n",i,j,dist[i][j],dist2[i][j]);
        }
    }    
    LL ans=1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='@'&&dist2[i][j]!=1e9){
                LL x1=pos[i][j].first;
                LL y1=pos[i][j].second;
                ans=min(ans,dist[i][j]+dist2[x1][y1]);
            }
        }
    }
    if(ans==1e9){
        cout<<-1<<'\n';
    }else{
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}