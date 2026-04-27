#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
vector<vector<LL>> e;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans%mod;
}
LL tot=0;
vector<LL> q; 
LL tag;
vector<LL> dev;
void dfs(LL u,LL fa){
    if(e[u].size()==1){
        tot++;
        q.push_back(u);
    }
    dev[u]=dev[fa]+1;
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
}
void solve(){
    LL n;
    cin>>n;
    tag=0;
    tot=0;
    q.clear();
    e.assign(n+1,vector<LL>());
    dev.assign(n+1,0);
    for(int i=1;i<=n-1;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    e[1].push_back(0);
    dfs(1,0);
    if(tot>2){
        cout<<0<<'\n';
        return;
    }
    if(tot==1){
        cout<<qpow(2,n)%mod<<'\n';
        return;
    }
    LL p1=q[0];
    LL p2=q[1];
    LL p3;
    for(int i=1;i<=n;i++){
        if(e[i].size()==3){
            p3=i;
        }
    }
    LL maxn=max(dev[p1]-dev[p3],dev[p2]-dev[p3]);
    LL minn=min(dev[p1]-dev[p3],dev[p2]-dev[p3]);
    if(maxn==minn){
        LL ans=qpow(2,dev[p3]+1);
        cout<<ans%mod<<'\n';
    }else{
        LL ans=qpow(2,maxn-minn+dev[p3])+qpow(2,maxn-minn-1+dev[p3]);
        cout<<ans%mod<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}