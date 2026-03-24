#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define LLL __int128_t
void solve(){
    LL n,k;
    LL a;
    LLL y=1,x;
    cin>>n>>k;
    LLL m=1;
    while(k--)
    {
        m=m*10;
    }
    // printf("{%lld}",m);
    for(int i=1;i<=n;i++){
        cin>>a;
        x=a;
        y*=x;
        if(y>=m){
            y=1;
        }
    }
    LL ans=y;
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}