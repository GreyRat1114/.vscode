#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
LL fa[N];
void init(LL n){
    for(int i=1;i<=n;i++){
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
void solve(){
    LL n,k;
    cin>>n>>k;
    init(n);
    LL u,v;
    vector<pair<LL,LL>> a(n+1);
    for(int i=1;i<=k;i++){
        cin>>u>>v;
        merge(u,v);
        a[i]=make_pair(u,v);
    }
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        LL x=find(i);
        mp[x]++;
    }
    LL siz=mp.size();
    //printf("{%lld}",siz);
    LL ans=1;
    for(int i=1;i<=siz;i++){
        ans=(ans*26)%mod;
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