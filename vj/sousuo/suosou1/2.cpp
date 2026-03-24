#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=35;
#define LL long long
int ex,ey,ez;
char mp[N][N][N];
int l,r,c;
int cnt;
int dx[]={-1,0,0,1,0,0};
int dy[]={0,-1,1,0,0,0};
int dz[]={0,0,0,0,1,-1};
bool vis[N][N][N];
int tag;
struct node{
    int x,y,z;
    int dist;
};
void bfs(int sx,int sy,int sz){
    queue<node> q;
    q.push({sx,sy,sz,0});
    vis[sx][sy][sz];
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int z=q.front().z;
        int d=q.front().dist;
        q.pop();
        if(x==ex&&y==ey&&z==ez){
            tag=d;
            return;
        }        
        for(int i=0;i<6;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            int z1=z+dz[i];
            if(x1<1||x1>l||y1<1||y1>r||z1<1||z1>c){
                continue;
            }
            if(vis[x1][y1][z1]||mp[x1][y1][z1]=='#'){
                continue;
            }
            q.push({x1,y1,z1,d+1});
            vis[x1][y1][z1]=true;
        }        
    }

}
void solve(){
    cin>>l>>r>>c;
    while(l!=0){
        memset(vis,false,sizeof(vis));
        tag=-1;
        string s;
        int x,y,z;
        for(int i=1;i<=l;i++){
            for(int j=1;j<=r;j++){
                cin>>s;
                for(int k=0;k<c;k++){
                    mp[i][j][k+1]=s[k];
                    if(s[k]=='E'){
                        ex=i;
                        ey=j;
                        ez=k+1;
                    }
                    if(s[k]=='S'){
                        x=i,y=j,z=k+1;
                    }
                }
            }
        }      
        bfs(x,y,z);
        if(tag!=-1){
            cout<<"Escaped in "<<tag<<" minute(s).\n";
        }else{
            cout<<"Trapped!\n";
        }
        cin>>l>>r>>c;
    }

}
int main(){
    solve();
    return 0;
}