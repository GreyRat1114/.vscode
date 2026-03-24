#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=5e5+5;
#define LL long long
int n,k;
bool vis[N];
struct node{
    int x;
    int t;
};
void bfs(int s){
    queue<node> q;
    q.push({s,0});
    vis[s]=true;
    while(!q.empty()){
        int x=q.front().x;
        int t=q.front().t;
        if(x==k){
            cout<<t<<'\n';
            return;
        }
        q.pop();
        int y=x+1;
        if(!vis[y]&&y<=1e5){
            q.push({y,t+1});
            vis[y]=true;
        }
        y=x-1;
        if(!vis[y]&&y>=0){
            q.push({y,t+1});
            vis[y]=true;
        }
        y=2*x;
        if(!vis[y]&&y<=1e5){
            q.push({y,t+1});
            vis[y]=true;
        }        

    }
}
void solve(){
    cin>>n>>k;
    bfs(n);

}
int main(){
    solve();
    return 0;
}