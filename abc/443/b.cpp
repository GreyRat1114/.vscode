#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    LL n,k;
    cin>>n>>k;
    for(LL i=0;i*i<=2*k;i++){
        LL x=i*i+(2*n+1)*i+2*n;
        if(x>=2*k){
            cout<<i<<'\n';
            return;
        }
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}