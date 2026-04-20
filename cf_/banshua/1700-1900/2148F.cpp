#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<LL> k(n+1);
    LL x,y;
    vector<vector<LL>> a(n+1,vector<LL>());
    LL maxn=0;
    
    for(int i=1;i<=n;i++){
        cin>>k[i];
        maxn=max(maxn,k[i]);
        for(int j=1;j<=k[i];j++){
            cin>>x;
            a[i].push_back(x);
        }        
    }
    vector<vector<LL>> vis(maxn+1,vector<LL>());
    vector<map<LL,LL>> mp(maxn+2);
     
    for(int i=1;i<=n;i++){
        for(int j=0;j<k[i];j++)vis[j].push_back(i);
    }
    auto getrk=[&](LL p,LL id)->int{
        auto it=mp[p].find(id);
        if(it==mp[p].end())return -1;
        return it->second;
    };

    for(int i=maxn-1;i>=0;i--){
        sort(vis[i].begin(),vis[i].end(),[&](LL x,LL y){
            if(a[x][i]!=a[y][i])return a[x][i]<a[y][i];
            return getrk(i+1,x)<getrk(i+1,y);
        });
        for(int j=0;j<vis[i].size();j++){
            mp[i][vis[i][j]]=j;
        }
    }
    for(int i=0;i<maxn;i++){
        LL x=vis[i][0];

        for(int j=i;j<a[x].size();j++){
            cout<<a[x][j]<<' ';
        }
        i=a[x].size()-1;
        //printf("{%lld}",k[x]);
    }
    cout<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}