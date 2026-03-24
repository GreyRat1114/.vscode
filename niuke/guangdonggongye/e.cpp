#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
vector<int> e[N];
int prim[N];
int tot;
int dist[N];
bool vis[N];
void bfs(int s){
    for(int i=1;i<=10005;i++){
        dist[i]=1e9;
        vis[i]=false;
    }
    queue<int> q;
    q.push(s);
    dist[s]=0;
    vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(auto v:e[u]){
            if(dist[u]+1<dist[v]){
                dist[v]=dist[u]+1;
                if(vis[v]==false){
                    q.push(v);
                }
            }
        }
    }
}
void init(){
    tot=0;
    for(int i=2;i<=10000;i++){
        int tag=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                tag=0;
                break;
            }
        }
        if(tag){
            tot++;
            prim[tot]=i;
        }
    }
}
void solve(){
    int a,b;
    cin>>a>>b;
    bfs(a);
    int ans=dist[b];
    if(ans==1e9){
        cout<<-1<<'\n';
    }
    else{
        cout<<ans<<'\n';
    }
}
int main(){
    init();
    for(int i=1;i<=tot;i++){
        for(int j=1;j<=tot;j++){
            int a=prim[i];
            int b=prim[j];
            int x,y;
            int cnt=0;
            while(a!=0||b!=0){
                x=a%10;
                y=b%10;
                a=a/10;
                b=b/10;
                if(x!=y){
                    cnt++;
                }
            }
            if(cnt==1){
                e[prim[i]].push_back(prim[j]);
                e[prim[j]].push_back(prim[i]);
                // printf("{%d %d}",prim[i],prim[j]);
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}