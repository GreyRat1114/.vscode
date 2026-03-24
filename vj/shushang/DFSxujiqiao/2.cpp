#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define mp make_pair
int n;
int a[N];
int b[N];
int dfn[N];
int siz[N];
vector<int> e1[N];
vector<int> e2[N];
int tot;
set<pair<int,int>> tr;
int ans;
int add(int now){
    set<pair<int,int>>::iterator it=tr.lower_bound(mp(dfn[now],now));
    if(it!=tr.end()&&(dfn[it->second]<=dfn[now]+siz[now]-1)){
        return -2;
    }
    if(it==tr.begin()){
        return -1;
    }
    --it;
    int res=it->second;
    if(dfn[res]+siz[res]-1<dfn[now]){
        return -1;
    }
    tr.erase(it);
    return res;
}
void dfs1(int u,int fa){
    tot++;
    dfn[u]=tot;
    siz[u]=1;
    for(auto v:e2[u]){
        if(v==fa){
            continue;
        }
        dfs1(v,u);
        siz[u]+=siz[v];
    }
}
void dfs2(int u,int fa){
    int res=add(u);
    if(res!=-2){
        tr.insert(mp(dfn[u],u));
    }
    ans=max(ans,(int)tr.size());
    for(auto v:e1[u]){
        if(v==fa){
            continue;
        }
        dfs2(v,u);
    }
    if(res!=-2){
        tr.erase(mp(dfn[u],u));
        if(res!=-1){
            tr.insert(mp(dfn[res],res));
        }
    }
}
void solve(){
    tr.clear();
    tot=0;
    ans=0;
    cin>>n;
    for(int i=0;i<=n+5;i++){
        e1[i].clear();
        e2[i].clear();
        dfn[i]=0;
        siz[i]=0;
    }
    for(int i=2;i<=n;i++){
        cin>>a[i];
        e1[i].push_back(a[i]);
        e1[a[i]].push_back(i);        
    }
    for(int i=2;i<=n;i++){
        cin>>b[i];
        e2[i].push_back(b[i]);
        e2[b[i]].push_back(i);
    }
    dfs1(1,1);
    dfs2(1,1);
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}