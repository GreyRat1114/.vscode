#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
vector<vector<LL>> e;
vector<LL> vis;
vector<LL> a;
LL w;
LL tag;
LL id(LL u,LL d){
    return (u-1)*w+d;
}
void dfs(LL u){
    //printf("{%lld}",u);
    //printf("{%lld}",e[u].size());
    vis[u]=1;
    for(auto v:e[u]){
        //printf("{%lld,%lld}",u,v);
        if(vis[v]==2)continue;
        if(vis[v]==1){
            tag=1;
        }
        if(vis[v]==0&&a[v]){
            dfs(v);
        }
    }
    vis[u]=2;
}

void solve(){
    tag=0;
    LL n,m;
    cin>>n>>m;
    e.assign(n*10+1,vector<LL>());
    vector<pair<LL,LL>> op(m+1);
    for(int i=1;i<=m;i++){
        LL u,v;
        cin>>u>>v;
        op[i]={u,v};
    }
    cin>>w;
    for(int i=1;i<=n;i++){
        for(int j=0;j<w;j++){
            LL x=id(i,j);
            LL y=id(i,(j+1)%w);
            e[x].push_back(y);
            //e[y].push_back(x);
        }
    }    
    for(int i=1;i<=m;i++){
        LL u=op[i].first;
        LL v=op[i].second;
        for(int j=0;j<w;j++){
            LL u1=id(u,j);
            LL v1=id(v,(j+1)%w);
            LL u2=id(u,(j+1)%w);
            LL v2=id(v,j);            
            //printf("{%lld,%lld}",u1,v1);
            e[u1].push_back(v1);
            e[v2].push_back(u2);
        }        
    }
    LL tot=n*w;
    vis.assign(tot+1,0);
    a.assign(tot+1,0);    
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        //cout<<s<<'\n';
        for(int j=0;j<w;j++){
            if(s[j]=='o'){
                LL x=id(i,j);
                a[x]=1;
                //printf("{%lld,%lld}",i,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        LL x=id(i,0);
        if(vis[x]==0&&a[x]){
            dfs(x);
            if(tag){
                cout<<"Yes"<<'\n';
                return;
            }            
        }
    }
    cout<<"No"<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}