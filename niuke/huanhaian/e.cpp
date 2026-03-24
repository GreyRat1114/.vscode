#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e7+5;
int last[N];
int tot;
int dist[N];
bool vis[N];
bool is[N];
int n,m,d;
struct node{
    int v,w;
    int next;
}a[N];
void add(int u,int v,int w){
    tot++;
    a[tot].v=v;
    a[tot].w=w;
    a[tot].next=last[u];
    last[u]=tot;
}
struct nd{
    int u;
    int x;//路程
    int y;//现有油
    int cnt;
};
void spfa(int s){
    for(int i=1;i<=n+10;i++){
        dist[i]=1e9;
    }
    queue<nd> q;
    q.push({s,0,0});
    dist[s]=0;
    vis[s]=true;
    while(!q.empty()){
        int u=q.front().u;
        int cnt=q.front().cnt;
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        if(is[u]){
            x=0;
        }
        for(int i=last[u];i>=1;i=a[i].next){
            int v=a[i].v;
            int w=a[i].w;
            if(w+x>y){
                if(w+x>d){
                    continue;
                }
                else{
                    cnt++;
                                       
                }

            }
        }
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    memset(is,false,sizeof(is));
    tot=0;
    cin>>n>>m>>d;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);

    }
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==1){
            is[i]=true;
        }else{
            is[i]=false;
        }
    }
    spfa(1);
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}