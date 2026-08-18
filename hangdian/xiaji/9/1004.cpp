#include<bits/stdc++.h>
using ll=long long;
const int N=7e6+10;
int ch[N][2],tot;
void insert(ll x){
    int u=1;
    for(ll i=60;i>=0;i--){
        int c=((x>>i)&1ll);

        if(!ch[u][c])ch[u][c]=++tot;
        u=ch[u][c];
    }
}
ll get(ll x){
    ll res=0;
    int u=1;
    for(ll i=60;i>=0;i--){
        int c=((x>>i)&1);
        if(ch[u][(c^1)]){
            u=ch[u][c^1];
            res|=(1ll<<i);
        }else{
            u=ch[u][c];
        }
    }
    return res;
}
void solve(){
    int n,q,len;
    memset(ch,0,sizeof(ch));
    tot=1;
    std::cin>>n>>len>>q;
    std::vector<ll>a(n+1),sum(n+1);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    int pos=0;
    for(int i=len;i<=n;i++){
      //  std::cout<<sum[i]<<" "<<sum[pos]<<'\n';
        insert((sum[i]^sum[pos]));
        pos++;
    }
    while(q--){
        ll x;
        std::cin>>x;
       // std::cout<<x<<'\n';
        std::cout<<get(x)<<'\n';
    }
    
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T=1;
    std::cin>>T;
    while(T--){
        solve();
    }

    return 0;
}