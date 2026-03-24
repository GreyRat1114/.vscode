#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=105;
const int M=1e3+5;
#define LL long long
LL n,m;
bool vis[N][N];
#define mp make_pair
int tot;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
char c[N][N];
void dfs(int x,int y){
    //printf("{%d,%d}",x,y);
    vis[x][y]=true;
    for(int i=0;i<8;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1<1||y1<1||x1>n||y1>m){
            continue;
        }
        if(vis[x1][y1]||c[x1][y1]=='*'){
            continue;
        }
        dfs(x1,y1);
    }
}
void solve(){
    while(1){
        memset(vis,false,sizeof(vis));
        cin>>n>>m;
        if(n==0&&m==0){
            break;
        }
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                c[i][j+1]=s[j];
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i][j]=='@'&&vis[i][j]==false){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
}

int main(){
        solve();
    return 0;
}