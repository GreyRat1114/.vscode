#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using PII=std::pair<int,int>;
using ll=long long;
const int N=2e5+10;
const ll MAXN=1e15;
int a[N];
bool vis[N][600];
int cut[N][10];
ll dis[N][600];
int run[N];
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<600;j++){
            vis[i][j]=false;
            dis[i][j]=MAXN;
        }
        for(int j=0;j<9;j++){
            cut[i][j]=0;
        }
        run[i]=0;
    }
}
struct Node{
    ll w;
    int u;
    int mk;
    bool operator < (const Node &b)const{
        return w>b.w;
    }
};
std::vector<int>result;
void get(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)n/=i;
            result.emplace_back(i);
        }
    }
    if(n!=1)result.emplace_back(n);
}
int get2(int x,int y){
    int cnts=0;
    while(x){
        if(x%y==0){
            cnts++;
        }else{
           break;
        }
        x/=y;
    }
    return cnts;
}
void solve(){
    result.clear();
    int n,m,V;
    ll ans=MAXN;
    std::cin>>n>>m>>V;
    init(n);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    get(V); 
     int cnt=0;
    std::array<int,10>tk;
    int ps=0;
    for(auto v:result){
        tk[cnt]=get2(V,v);
        ps+=(1<<cnt);
        cnt++;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<cnt;j++){
            cut[i][j]=get2(a[i],result[j]);
            run[i]+=(cut[i][j]>tk[j])?0:(1<<j);
        }
    }
    std::vector<std::vector<PII>>adj(n+5);
    for(int i=1;i<=m;i++){
      int u,v,w;
      std::cin>>u>>v>>w;
      if(u==v)continue;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    if(V==1){
        std::cout<<0<<endl;
        return ;
    }
    //mask掩码代表已经符合条件的
    auto dij=[&]()->void{
        std::priority_queue<Node>q;
        Node fi;
        fi.u=1,fi.w=0;
        fi.mk=run[1];
        q.push(fi);
        dis[1][run[1]]=0;
        while(!q.empty()){
            Node pos=q.top();
            q.pop();
            if(vis[pos.u][pos.mk]){
                continue;
            }
            vis[pos.u][pos.mk]=true;
            if(pos.mk==ps){ //std::cout<<pos.u<<endl;
               ans=std::min(ans,dis[pos.u][pos.mk]);
               //continue;
               break;
            }
           
            for(auto [v,w]:adj[pos.u]){
                int ms=(run[v]|pos.mk);
        
                if(dis[v][ms]>dis[pos.u][pos.mk]+w){
                    dis[v][ms]=dis[pos.u][pos.mk]+w;
                     if(!vis[v][ms])
                        q.push({dis[v][ms],v,ms});
                }
            }
        }
    };
    dij();
    if(ans==MAXN)std::cout<<-1<<endl;
    else std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin>>T;
    while(T--){
        solve();
    }
    
    return 0;
} 