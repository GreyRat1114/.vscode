#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define mp make_pair
const int N=2e5+5;
vector<int> e[N];
int tot=0;

void dfs(int u,int fa,vector<int> &inv){
    tot++;
    inv[tot]=u;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u,inv);
    }
}

void solve(){
    tot=0;
    int n;
    cin>>n;
    vector<int> inv(n+1);
    for(int i=0;i<=n+1;i++){
        e[i].clear();
    }
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1,inv);

    for(int i=1;i*2<=n;i++){
        cout<<'?'<<' '<<inv[2*i-1]<<' '<<inv[2*i]<<'\n';
        cout.flush();
        int op;
        cin>>op;
        if(op==1){
            cout<<'?'<<' '<<inv[2*i-1]<<' '<<inv[2*i-1]<<'\n';
            cout.flush();      
            int op2;
            cin>>op2;
            if(op2==1){
                cout<<'!'<<' '<<inv[2*i-1]<<'\n';
                cout.flush();
            }else{
                cout<<'!'<<' '<<inv[2*i]<<'\n';
                cout.flush();
            } 
            return;
        }
    }
    if(n%2==1){
        cout<<'!'<<' '<<inv[n]<<'\n';
        cout.flush();        
    }
}
int main(){
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
    
    return 0;
}