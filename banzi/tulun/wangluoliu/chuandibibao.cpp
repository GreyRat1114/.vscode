#include<bits/stdc++.h>
using namespace std;
using LL=long long;
bitset<105> f[105];
vector<int> e[105];
int in[105];
LL n;
void solve(){
//DAG专用
    vector<int> topo;
    queue<int> q;

    for(int i=1;i<=n;i++)if(!in[i])q.push(i);

    while(!q.empty()){
        int u=q.front();q.pop();
        topo.push_back(u);
        for(int v:e[u])
            if(--in[v]==0)q.push(v);
    }

    for(int i=n-1;i>=0;i--){
        int u=topo[i];
        for(int v:e[u]){
            f[u][v]=1;
            f[u]|=f[v];
        }
    }    
//通用

// bitset<N> a[N];
    // for(int k=1;k<=n;k++){
    //     for(int i=1;i<=n;i++){
    //         if(a[i][k]){
    //             a[i]|=a[k];
    //         }
    //     }
    // }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}