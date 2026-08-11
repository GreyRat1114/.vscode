//cf1360D
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> prim;
vector<LL> not_prim;
vector<LL> minp;
void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            minp[i*p]=p;
            if(i%p==0)break;
        }
    }
}
void init(LL n){
    not_prim.assign(n+10,0);
    minp.assign(n+10,0);
    get_prim(n+1);
}
void solve(){
    LL n,k;
    cin>>n>>k;
    LL maxn=1;
    for(LL i=1;i*i<=n;i++){
        if(n%i==0){
            LL x=n/i;
            if(i<=k)maxn=x;
            if(x<=k){
                cout<<i<<'\n';
                return;
            }
        }
    }
    //printf("|");
    cout<<maxn<<'\n';
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