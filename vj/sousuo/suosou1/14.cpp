#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <map>
using namespace std;
const int N=205;
const int M=1e3+5;
#define LL long long
int s,n,m;
bool vis[N][N];
#define mp make_pair
int tot;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
char c[N][N];
struct node{
    int x,y;
    int cnt;
};
int dist[3][N][N];
void bfs(int x0,int y0,int tag){
    queue<node> q;
    q.push({x0,y0,0});
    vis[x0][y0]=true;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int cnt=q.front().cnt;
        q.pop();
        if(c[x][y]=='@'){
            dist[tag][x][y]=cnt;
        }
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<1||y1<1||x1>n||y1>m){
                continue;
            }
            if(vis[x1][y1]||c[x1][y1]=='#'){
                continue;
            }
            q.push({x1,y1,cnt+1});
            vis[x1][y1]=true;
        }
    }
}
void solve(){
    
    while(cin>>n>>m){
        memset(dist,0x3f,sizeof(dist));
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                c[i][j+1]=s[j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i][j]=='Y'){
                    memset(vis,false,sizeof(vis));
                    
                    bfs(i,j,1);
                }
                if(c[i][j]=='M'){
                    memset(vis,false,sizeof(vis));
                    bfs(i,j,2);
                }
            }
        }  
        int ans=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i][j]=='@'){
                    ans=min(ans,dist[1][i][j]+dist[2][i][j]);
                }
            }
        }
        cout<<ans*11<<'\n';

    }
}

int main(){
    solve();
    return 0;
}