#include<bits/stdc++.h>
#define fi first
#define sc second
#define endl '\n'
using ll=long long ;
using ull=unsigned long long;
using i128=__int128;
using PII=std::pair<int,int>;
using Pll=std::pair<int,ll>;
const int Mod=998244353;
const int N=1e5+10;
ll pre[N];
void init(int n){
    pre[1]=1,pre[0]=1;
    for(ll i=2;i<=n;i++){
        pre[i]=pre[i-1]*i%Mod;
    }
}
int fa[N];
ll siz[N];
ll nums[N];
ll sizm[N];
void solve(){
    int n;
    std::cin>>n;
    int x;
    std::vector<std::vector<int>>adj(n+5),g(n+5);
    for(int i=2;i<=n;i++){
        std::cin>>x;
        fa[i]=x;
        adj[x].push_back(i);
        adj[i].push_back(x);        
    }   
    auto dfs=[&](auto &&self,int u,int fas)->void{
        siz[u]=1;
        nums[u]=1;
        if(adj[u].size()==1){
            return ;
        }
        std::vector<PII>vec;
        for(auto v:adj[u]){
            if(v==fas){
                continue;
            }
            self(self,v,u);
            vec.push_back({siz[v],v});
            nums[u]=nums[u]*nums[v]%Mod;
            siz[u]+=siz[v];
        }
        std::sort(vec.begin(),vec.end());
       // std::cerr<<vec.size()<<endl;
        int pres=vec.back().first;
        std::reverse(vec.begin(),vec.end());
        int cnt=0;
        for(auto [x,y]:vec){
            if(x!=pres){
                nums[u]=1ll*nums[u]*pre[cnt]%Mod;
                cnt=0;
            }
            cnt++;
            pres=x;
        }
        nums[u]=nums[u]*pre[cnt]%Mod;
        cnt=0;
        int ms=vec[0].second;
        g[u].push_back(ms);
        int prem=ms;
        for(int i=1;i<vec.size();i++){
            g[prem].push_back(vec[i].second);
            prem=vec[i].second;
        }
    };
    auto dfs1=[&](auto &&self,int u,int fas)->void{
          sizm[u]=1;
          for(auto v:g[u]){
             if(v==fas){
                continue;
             }
             self(self,v,u);
             sizm[u]+=sizm[v];
          }
    };
    dfs(dfs,1,0);
    dfs1(dfs1,1,0);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=sizm[i];
    }
    std::cout<<ans<<endl;
    std::cout<<nums[1]<<endl;
    
}
int main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int T=1;
    //std::cin>>T;
    init(N);
    while(T--){
        solve();
    }

    return 0;
}
/*
5
1 1 1 2
5 
1 1 1 1
*/