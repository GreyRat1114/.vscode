#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
const int MAXN=2005;
const int MAXM=1e5;
const LL INF=(1LL<<60);
struct Edge{
    LL v,next,cap,cost;
}e[MAXM];

LL n,m,s,t;
LL head[MAXN],last[MAXN],flow[MAXN],dis[MAXN];
bool inq[MAXN];
LL tot;
LL maxflow,mincost;
void init(){    
    tot=1;
    maxflow=0;
    mincost=0;
    for(int i=0;i<=n+m+1;i++){
        head[i]=0;
    }
}

void add(LL u,LL v,LL cap,LL cost){
    e[++tot]={v,head[u],cap,cost};
    head[u]=tot;
    e[++tot]={u,head[v],0,-cost};
    head[v]=tot;
}

bool spfa(){
    memset(last,-1,sizeof(last));
    memset(inq,0,sizeof(inq));
    memset(dis,0x3f,sizeof(dis));
    queue<LL>q;
    dis[s]=0;
    flow[s]=INF;
    inq[s]=1;
    q.push(s);
    while(!q.empty()){
        LL u=q.front();
        q.pop();
        inq[u]=0;
        for(LL i=head[u];i!=0;i=e[i].next){
            LL v=e[i].v;
            LL cap=e[i].cap;
            LL cost=e[i].cost;
            if(cap>0&&dis[v]>dis[u]+cost){
                dis[v]=dis[u]+cost;
                last[v]=i;
                flow[v]=min(flow[u],cap);
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return last[t]!=-1;
}

void MCMF(){
    while(spfa()){
        LL f=flow[t];
        maxflow+=f;
        mincost+=f*dis[t];
        for(LL i=t;i!=s;i=e[last[i]^1].v){
            e[last[i]].cap-=f;
            e[last[i]^1].cap+=f;
        }
    }
}

void solve(){
    cin>>n>>m;
    s=0;
    t=n+m+1;
    init();
    for(int i=1;i<=n;i++){
        add(s,i,1,0);
    }
    
    for(int i=1;i<=n;i++){
        LL x;
        cin>>x;
        for(int j=1;j<=x;j++){
            LL y;
            cin>>y;
            add(i,y+n,1,0);
        }
    }
    for(int i=1+n;i<=n+m;i++){
        LL y;
        cin>>y;
        for(int j=1;j<=y;j++){
            LL x;
            cin>>x;
            add(i,t,1,x);
            //b[i].push_back(x);
        }
    }
    MCMF();
    cout<<mincost<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}