//洛谷B3647
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> dist;
void solve(){
    LL n,m;
    cin>>n>>m;
    dist.assign(n+1,vector<LL>(n+1,1e9));
    for(int i=1;i<=m;i++){
        LL u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[v][u],w);
    }
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }
    
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}