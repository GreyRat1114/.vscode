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
int s,n,m;
bool vis[N][N][N];
#define mp make_pair
int tot;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
char c[N][N];
struct node{
    int a,b,c;
    int cnt;
};
int bfs(){
    queue<node> q;
    q.push({s,0,0,0});
    vis[s][0][0]=true;
    while(!q.empty()){
        int a1=q.front().a;
        int b1=q.front().b;
        int c1=q.front().c;
        int cnt=q.front().cnt;
        q.pop();
       // printf("{%d %d %d %d}",a1,b1,c1,cnt);
        if((b1==c1&&b1==s/2)||(a1==c1&&a1==s/2)||(b1==a1&&b1==s/2)){

            return cnt;
        }
        int x,y,z;
        x=min(n,b1+a1);
        y=a1-(x-b1);
        if(!vis[y][x][c1]){
            q.push({y,x,c1,cnt+1});
            vis[y][x][c1]=true;
        }
        x=min(s,a1+b1);
        y=b1-(x-a1);
        if(!vis[x][y][c1]){
            q.push({x,y,c1,cnt+1});
            vis[x][y][c1]=true;
        }        
        x=min(m,c1+a1);
        y=a1-(x-c1);
        if(!vis[y][b1][x]){
            q.push({y,b1,x,cnt+1});
            vis[y][b1][x]=true;
        }
        x=min(s,a1+c1);
        y=c1-(x-a1);
        if(!vis[x][b1][y]){
            q.push({x,b1,y,cnt+1});
            vis[x][b1][y]=true;
        }  
        x=min(m,b1+c1);
        y=b1-(x-c1);
        if(!vis[a1][y][x]){
            q.push({a1,y,x,cnt+1});
            vis[a1][y][x]=true;
        }     
        x=min(n,b1+c1);
        y=c1-(x-b1);
        if(!vis[a1][x][y]){
            q.push({a1,x,y,cnt+1});
            vis[a1][x][y]=true;
        }            
    }
    return -1;
}
void solve(){
    while(1){
        memset(vis,false,sizeof(vis));
        cin>>s>>n>>m;
        if(s%2==1){
            cout<<"NO"<<'\n';
            continue;
        }
        if(s==0&&n==0&&m==0){
            break;
        }
        int x=bfs();
        if(x==-1){
            cout<<"NO"<<'\n';
        }else{
            cout<<x<<'\n';
        }        
    }

}

int main(){
    solve();
    return 0;
}