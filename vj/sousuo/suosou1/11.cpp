#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=15;
const int M=1e3+5;
#define LL long long
LL n,m;
bool vis[N][N];
#define mp make_pair
int tot;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
struct node{
    int x,y;
    int pre;
}p[M];
int a[10][10];
int bfs(int x0,int y0){
    queue<node> q;
    q.push({x0,y0,0});
    vis[x0][y0]=true;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int pre=q.front().pre;
        if(x==5&&y==5){
            return pre;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<1||x1>5||y1<1||y1>5){
                continue;
            }
            if(vis[x1][y1]||a[x1][y1]==1){
                continue;
            }
            tot++;
            p[tot]={x1,y1,pre};
            q.push({x1,y1,tot});
            vis[x1][y1]=true;
        }
    }
    return -1;
}
void dfs(int pos){
    if(pos==0){
        return;
    }
    dfs(p[pos].pre);
    printf("(%d, %d)\n",p[pos].x-1,p[pos].y-1);
}
void solve(){
    tot=0;
    memset(vis,false,sizeof(vis));

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    int x=bfs(1,1);
    printf("(0, 0)\n");
    dfs(x);
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}