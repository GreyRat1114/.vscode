#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
vector<int> e[N];
map<LL,int> tr;
LL ans[N];
LL a[N];
void dfs(int u,int fa,int tag){
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        if(tag){
            ans[v]=1;
            tr[a[v]]++;
            dfs(v,u,1);
            tr[a[v]]--;
        }else{
            if(tr[a[v]]){
                ans[v]=1;
                tr[a[v]]++;
                dfs(v,u,1);
                tr[a[v]]--;
            }else{
                tr[a[v]]++;
                dfs(v,u,0);
                tr[a[v]]--;
            }            
        }
    }
}
void solve(){
    tr.clear();
    memset(ans,0,sizeof(ans));
    LL n,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int u,v; 

    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    tr[a[1]]++;
    dfs(1,1,0);
    for(int i=1;i<=n;i++){
        if(ans[i]){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}