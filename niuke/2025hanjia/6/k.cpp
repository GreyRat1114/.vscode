#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
void solve(){
    LL n,m,z;
    cin>>m>>n>>z;
    LL x=n+m;
    LL y=z%x;
    if(y==0){
        cout<<1;
        return;
    }
    if(y<=m){
        cout<<0;
    }else{
        cout<<1;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}