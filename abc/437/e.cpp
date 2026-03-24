#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
const LL mod=998244353;
map<int,int> tr[N];
int idx[N];
vector<int> g[N];
void dfs(int u){
    for(auto x:g[u]){
        cout<<x<<' ';
    }
    for(auto x:tr[u]){
        dfs(x.second);
    }
}
void solve(){
    int n;
    cin>>n;
    int x,y;
    idx[0]=0;
    int tot=0;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        int u=idx[x];
        if(tr[u].count(y)==0){
            tot++;
            tr[u][y]=tot;
        }
        int v=tr[u][y];
        idx[i]=v;
        g[v].push_back(i);
    }
    dfs(0);
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
