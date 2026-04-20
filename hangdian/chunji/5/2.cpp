#include<bits/stdc++.h>
#define fi first
#define sc second
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using ll=long long ;
using ull=unsigned long long;
using i128=__int128;
using PII=std::pair<int,int>;
using Pll=std::pair<int,ll>;
using std::string;
const string s1="Yes";
const string s2="No";
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
void init(){
}
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>>adj(n+1);
    std::vector<int>vis(n+5);
    std::vector<int>dist(n+1,-1);
    for(int i=1;i<=m;i++){
         int u,v;
         std::cin>>u>>v;
         adj[u].push_back(v);
         //adj[v].push_back(u);
    }
    std::priority_queue<int,std::vector<int>,std::greater<int>>st;
    st.push(1);
    dist[1]=1;
    while(!st.empty()){
        int u=st.top();
        st.pop();
        for(auto v:adj[u]){
            if(!vis[v]){
               st.push(v);
               vis[v]=true;
               dist[v]=std::max(v,dist[u]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        std::cout<<dist[i]<<" ";
    }
    std::cout<<endl;

}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T=1;
    std::cin>>T;
    while(T--){
        solve();
    }

    return 0;
}