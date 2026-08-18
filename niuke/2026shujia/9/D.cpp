#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using PII=std::pair<int,int>;
const int N=2e5+10;
int vis[N];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(vis,0,sizeof(vis));
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>>adj(n+1);
    std::vector<std::vector<PII>>vec(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i=1;i<=m;i++){
        int x,s;
        std::cin>>x>>s;
        vec[x].emplace_back(i,s);
    }
    vector<map<LL,vector<LL>>> st1(n+1);
    std::vector<int>dep(n+1);
    std::vector<std::map<int,std::vector<int>>>st(n+1);
    dep[0]=0;
    std::vector<int>p(n+1);
    if(n==1){
        std::map<int,std::vector<int>>q;
            for(auto [x,y]:vec[1]){
                q[y].emplace_back(x);
            }  
            for(auto [v,w]:q){
                if(w.size()==1){
                    vis[w[0]]=1;
                }
            }
        for(int i=1;i<=m;i++){
            std::cout<<vis[i];
        }
        std::cout<<'\n';
        return 0;
    }
    auto dfs=[&](auto &&self,int u,int fa){
        if(adj[u].size()==1&&u!=1){
            int rn=dep[u];
            std::map<int,std::vector<int>>q;
            for(auto [x,y]:vec[u]){
                q[y].emplace_back(x);
            }  
            for(auto [v,w]:q){
                if(w.size()==1){
                    st[u][rn+v].push_back(w[0]);
                }
            }
            p[u]=u;
            return;
        }
        int mins=-1;
        int k=0;
        for(auto v:adj[u]){
            if(v==fa)continue;
            dep[v]=dep[u]+1;
            self(self,v,u);
            int ms=st[p[v]].size();
            if(mins<ms){
                mins=ms;
                k=v;  
            }
        }
        p[u]=p[k];
        std::map<int,std::vector<int>>q;
        for(auto [x,y]:vec[u]){
                q[y+dep[u]].emplace_back(x);
        }
        for(auto v:adj[u]){
            if(v==fa||v==k)continue;
            for(auto [x,y]:st[p[v]]){
                for(auto t:y){
                    q[x].emplace_back(t);
                }
            }
        }
        for(auto [v,w]:q){
            if(w.size()==1&&!st[p[u]].count(v)){
                st[p[u]][v].emplace_back(w[0]);
            }else if(st[p[u]].count(v)){
                st[p[u]].erase(v);
            }
        }
    };
    dfs(dfs,1,0);
    for(auto [x,y]:st[p[1]]){
        //std::cerr<<y[0]<<'\n';
        vis[y[0]]=1;
    }
    for(int i=1;i<=m;i++){
        if(vis[i]){
            std::cout<<1;
        }else{
            std::cout<<0;
        }
    }
    std::cout<<'\n';
    return  0;
}