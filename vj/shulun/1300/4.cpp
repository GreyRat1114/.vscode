//cf1372B
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
    LL n;
    cin>>n;
    if(n%2==0){
        cout<<n/2<<' '<<n/2<<'\n';
    }else{
        for(LL i=3;i*i<=n;i+=2){
            if(n%i==0){
                LL x=n/i;
                cout<<x<<' '<<n-x<<'\n';
                return;
            }
        }
        cout<<1<<' '<<n-1<<'\n';
    }
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