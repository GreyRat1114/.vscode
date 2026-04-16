#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
vector<LL> e[N];
vector<LL> d;
LL fa[N];
void init(LL n){
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
}
LL find(LL x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(LL x,LL y){
    LL fx=find(x);
    LL fy=find(y);
    if(fx!=fy){
        fa[fy]=fx;
    }
}
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;            
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
void solve(){
    LL n;
    cin>>n;
    init(n);
    d.assign(n+1,0);
    for(int i=0;i<=n;i++){
        e[i].clear();
    }
    LL u,v;
    for(int i=1;i<=n;i++){
        u=i;
        cin>>v;
        e[u].push_back(v);
        d[v]++;
        merge(u,v);
    }
    // for(int i=1;i<=n;i++){
    //     //printf("{%lld}",d[i]);
    // }
    map<LL,LL> mp1,mp2;
    queue<LL> q;
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        LL fx=find(i);
        mp1[fx]++;
        if(d[i]==0){
            q.push(i);
            vis[i]=true;
        }
    }
    auto bfs=[&]()->void{
        while(!q.empty()){
            LL u=q.front();
            q.pop();
            for(auto v:e[u]){
                d[v]--;
                if(d[v]==0){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    };
    bfs();
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            LL fx=fa[i];
            mp2[fx]++;
            //printf("{%lld,}",i);
        }
    }
    LL ans=0;
    for(auto x:mp1){
        LL fx=x.first;
        LL cnt1=x.second;
        LL cnt2=mp2[fx];
        //printf("{%lld,%lld,%lld}",fx,cnt1,cnt2);
        ans=(ans*(qpow(25ll,cnt1-cnt2)*(qpow(25ll,cnt2)+qpow(-1ll,cnt2)*25ll)%mod)%mod)%mod;
        //printf("{%lld,%lld}",qpow(25ll,cnt1-cnt2),(qpow(25ll,cnt2)+qpow(-1ll,cnt2)*25ll));
    }
    
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}