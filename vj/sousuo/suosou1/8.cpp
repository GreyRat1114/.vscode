#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=1e2+5;
const int M=1e5+5;
#define LL long long
LL n,m;
bool vis[N][N];
#define mp make_pair
struct node{
    int op;
    int x,y;
    int pre;
}a[M];
int tot;
int aa,bb,cc;
int bfs(int x0,int y0){
    vis[x0][y0]=true;
    queue<pair<pair<int,int>,pair<int,int> > > q;
    q.push(mp(mp(x0,y0),mp(0,0)));
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second.first;
        int pre=q.front().second.second;
        //printf("{%d %d %d %d}",x,y,pre,cnt);
        if(x==cc||y==cc){
            cout<<cnt<<'\n';
            return pre;
        }
        q.pop();
        cnt++;
        for(int i=1;i<=2;i++){
            if(i==1){
                if(vis[aa][y])continue;
                tot++;
                a[tot]={1,i,0,pre};                 
                vis[aa][y]=true;
                q.push(mp(mp(aa,y),mp(cnt,tot)));
            }else{
                if(vis[x][bb])continue;
                tot++;
                a[tot]={1,i,0,pre};   
                vis[x][bb]=true;
                q.push(mp(mp(x,bb),mp(cnt,tot)));
            }
        }

        if(x>bb-y){
            if(!vis[x+y-bb][bb]){
                tot++;
                a[tot]={2,1,2,pre};                
                vis[x+y-bb][bb]=true;
                q.push(mp(mp(x+y-bb,bb),mp(cnt,tot)));
            }

        }else{
            if(!vis[0][y+x]){
                tot++;
                a[tot]={2,1,2,pre};  
                vis[0][y+x]=true;
                q.push(mp(mp(0,y+x),mp(cnt,tot)));                
            }

        }        

        if(y>aa-x){
            if(!vis[aa][x+y-aa]){
                tot++;
                a[tot]={2,2,1,pre};                
                vis[aa][x+y-aa]=true;
                q.push(mp(mp(aa,x+y-aa),mp(cnt,tot)));                
            }

        }else{
            if(!vis[x+y][0]){
                tot++;
                a[tot]={2,2,1,pre};  
                vis[x+y][0]=true;
                q.push(mp(mp(x+y,0),mp(cnt,tot)));                
            }

        }            

        if(!vis[0][y]){
            tot++;
            a[tot]={3,1,0,pre};            
            vis[0][y]=true;
            q.push(mp(mp(0,y),mp(cnt,tot)));            
        }
        if(!vis[x][0]){
            tot++;
            a[tot]={3,2,0,pre};
            vis[x][0]=true;
            q.push(mp(mp(x,0),mp(cnt,tot)));
        }
    }
    return -1;
}
void dfs(int pos){
    if(pos==0){
        return;
    }
    dfs(a[pos].pre);
    if(a[pos].op==1){
        cout<<"FILL("<<a[pos].x<<")\n";
    }else if(a[pos].op==2){
        cout<<"POUR("<<a[pos].x<<','<<a[pos].y<<")\n";
    }else if(a[pos].op==3){
        cout<<"DROP("<<a[pos].x<<")\n";
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    tot=0;
    
    cin>>aa>>bb>>cc;
    int ans=bfs(0,0);
    if(ans!=-1){
        dfs(ans);
    }else{
        cout<<"impossible"<<'\n';
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}