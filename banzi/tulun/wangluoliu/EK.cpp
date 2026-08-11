//复杂度：点*边*边
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 305;
const int MAXM = 3005;
const LL INF = (1LL << 60);
struct Edge {
    LL v;
    LL next;
    LL cap;
}e[MAXM];

LL n, m, s, t;
LL head[MAXN];
LL last[MAXN];
LL tot;
LL flow[MAXN];

void init(LL n) {
    tot=2;
    for(int i=1;i<=n;i++){
        head[i]=0;
    }
}
void add(LL u,LL v,LL cap){
    e[tot]={v,head[u],cap};
    head[u]=tot;
    tot++;
    e[tot]={u,head[v],0};
    head[v]=tot;
    tot++;
}

// 寻找一条增广路
bool bfs() {
    memset(last,-1,sizeof(last));
    queue<LL> q;
    q.push(s);
    flow[s]=INF;
    last[s]=-1;
    while(!q.empty()){
        LL u=q.front();
        q.pop();
        if(u==t)break;
        for(int i=head[u];i!=0;i=e[i].next){
            LL v=e[i].v;
            LL cap=e[i].cap;
            if(cap>0&&last[v]==-1){
                last[v]=i;
                flow[v]=min(flow[u],cap);
                q.push(v);
            }
        }
    }
    return last[t]!=-1;
}

LL getflow(){
    LL maxflow=0;
    while(bfs()){
        maxflow+=flow[t];
        for(int i=t;i!=s;i=e[last[i]^1].v){
            e[last[i]].cap-=flow[t];
            e[last[i]^1].cap+=flow[t];
        }
    }
    return maxflow;
}
void solve(){
    cin>>n>>m>>s>>t;
    init(n);

}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}