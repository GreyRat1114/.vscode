#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
vector<LL> e[N];
LL f[N];
LL g[N];
LL siz[N];
LL d[N];
LL qpow(LL a,LL b)
{
    LL ans=1;
    LL p;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    return ans;
}
void init()
{
    f[0]=g[0]=1;
    for(int i=1;i<=N;i++)
    {
        f[i]=f[i-1]*i%mod;
        g[i]=g[i-1]*qpow (i,mod-2)%mod;
    }
}
LL getc(LL n,LL m)
{
    return f[n]*g[n-m]%mod*g[m]%mod;
}
void dfs(LL u,LL fa){
    siz[u]=1;
    d[u]=d[fa]+1;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }

}
void solve(){
    init();
    LL n,k;
    cin>>n>>k;
    LL u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(k==1||k==2){
        cout<<getc(n,k);
    }else if(k==3){

    }else{

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