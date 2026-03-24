#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
void solve(){
    LL n;
    cin>>n;
    LL p;
    for(LL i=31;i>=0;i--){
        LL x=(1ll<<i);
        //printf("{%lld}",x);
        if(x<=n){
            p=i;
            break;
        }
    }
    LL l=1ll<<(p+1);
    LL r=(1ll<<(p+1))+1;
    l=l*n;
    r=r*n;
    cout<<l<<' '<<r<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}