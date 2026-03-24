#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int din[N];
vector<int> e[N];
void solve(){
    memset(din,0,sizeof(din));

    int n;
    cin>>n;
    for(int i=0;i<=n+10;i++){
        e[i].clear();
    }    
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        din[u]++;
        din[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int maxn=-1;
    int p=0;
    for(int i=1;i<=n;i++){
        int s=0;
        for(auto j:e[i]){
            s+=din[j]-1;
        }
        if(s>maxn){
            maxn=s;
            p=i;
        }
    }
    cout<<p<<' '<<maxn<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}