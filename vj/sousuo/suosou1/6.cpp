#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=1e4+5;
#define LL long long
vector<int> e[N];
LL n,m;
int tot;
int prim[N];
bool vis[N];
int ans;
void get_prim(){
    for(int i=1000;i<=9999;i++){
        int cnt=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                cnt++;
            }
        }
        if(cnt==0){
            tot++;
            prim[tot]=i;
        }
    }
}
struct node{
    int f;
    int s;
};
int bfs(int s){
    queue<node> q;
    q.push({s,0});
    vis[s]=true;
    int x,w;
    while(!q.empty()){
        x=q.front().f;
        w=q.front().s;
        //printf("{%d}",x);
        q.pop();
        if(x==m){
            return w;
        }
        vector<int>::iterator it;
        for(it=e[x].begin();it!=e[x].end();++it){
            int y=*it;
            if(vis[y]){
                continue;
            }
            q.push({y,w+1});
            vis[y]=true;
        }
    }
    return -1;
}
void solve(){
    memset(vis,false,sizeof(vis));
    cin>>n>>m;
    int ans=bfs(n);
    if(ans==-1){
        cout<<"Impossible"<<'\n';
    }else{
        cout<<ans<<'\n';
    }
}
int main(){
    tot=0;
    get_prim();
    // for(int i=1;i<=tot;i++){
    //     printf("{%d}",prim[i]);
    // }
    int tot1=0;
    for(int i=1;i<=tot;i++){
        for(int j=i;j<=tot;j++){
            int x=prim[i];
            int y=prim[j];
            int cnt=0;
            
            while(x!=0){
                if(x%10==y%10){
                    cnt++;
                }
                x=x/10;
                y=y/10;
            }
            if(cnt==3){
                tot1++;
                e[prim[i]].push_back(prim[j]);
                e[prim[j]].push_back(prim[i]);
            }
        }
    }
    //cout<<tot1<<'\n';
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}