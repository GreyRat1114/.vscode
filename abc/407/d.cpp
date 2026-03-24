#include<bits/stdc++.h>
using namespace std;
const int N=25;
using LL=long long;
LL a[N][N];
bool vis[N][N];
int h,w;
LL maxn;
void dfs(int x,int y,LL cur){
    if(y==w+1){
        x++;
        y=1;
    }    
    if(x==h+1){
        maxn=max(maxn,cur);
        return;
    }

    if(x-1>=1&&!vis[x-1][y]){
        vis[x][y]=vis[x-1][y]=true;
        dfs(x,y+1,cur^a[x][y]^a[x-1][y]);
        vis[x][y]=vis[x-1][y]=false;

    }
    if(y-1>=1&&!vis[x][y-1]){
        vis[x][y]=vis[x][y-1]=true;
        dfs(x,y+1,cur^a[x][y]^a[x][y-1]);
        vis[x][y]=vis[x][y-1]=false;
    }
    dfs(x,y+1,cur);
}
void solve(){
    memset(vis,false,sizeof(vis));
    maxn=0;
    cin>>h>>w;
    LL s=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
            s=s^a[i][j];
        }
    }
    dfs(1,1,s);
    cout<<maxn<<'\n';
}
int main(){
    solve();
    return 0;
}