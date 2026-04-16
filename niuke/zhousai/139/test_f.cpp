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
    LL x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        cout<<qpow(x,y)<<'\n';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}