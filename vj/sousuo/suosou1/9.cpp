#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=15;
const int M=1e5+5;
#define LL long long
LL n,m;
bool vis[N][N];
#define mp make_pair
char c[N][N];
int tot;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
struct node{
    int x,y;
    int t;
};
int dist[N][N];

void bfs(int x0,int y0,int x2,int y2){
    queue<node> q;
    q.push({x0,y0,0});
    q.push({x2,y2,0});
    vis[x0][y0]=true;
    vis[x2][y2]=true;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        //printf("{%d %d}",x,y);
        int t1=q.front().t;
        q.pop();
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            
            if(x1<1||x1>n||y1<1||y1>m){
                continue;
            }
            if(vis[x1][y1]||c[x1][y1]=='.'){
                continue;
            }
            vis[x1][y1]=true;
            dist[x1][y1]=dist[x][y]+1;

            q.push({x1,y1,t1+1});
        }
    }
}
struct node1{
    int x;
    int y;
};
void solve(int t){
    cin>>n>>m;
    string s;
    int x,y;
    tot=0;
    vector<node1> q;

    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            c[i][j+1]=s[j];
            if(c[i][j+1]=='#'){
                tot++;
                q.push_back({i,j+1});
            }
        }
    }
    int tag=0;
    int ans=1e9;
    int tmp;
    for(int i=0;i<q.size();i++){
        for(int j=0;j<q.size();j++){
            memset(vis,false,sizeof(vis));
            memset(dist,0,sizeof(dist));
            int cnt=0;
            int maxn=0;
            bfs(q[i].x,q[i].y,q[j].x,q[j].y);
            for(int k=0;k<q.size();k++){
                if(c[q[k].x][q[k].y]=='#'&&vis[q[k].x][q[k].y]){
                    cnt++;
                    maxn=max(maxn,dist[q[k].x][q[k].y]);
                }
                if(cnt==tot){
                    tag=1;
                    ans=min(maxn,ans);
                }
            }
        }
    }
    if(tag){
        printf("Case %d: %d\n",t,ans);
    }else{
        printf("Case %d: -1\n",t);
    }

}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}