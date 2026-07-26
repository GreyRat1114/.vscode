#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128;
void solve(){
    LL a,b,n,m;
    cin>>a>>b>>n>>m;
    i128 c=n/m;
    i128 minn=min(a,b);
    //printf("{%lld}",c*c);
    i128 ji=c*c;
    if(minn<ji){
        cout<<"NO"<<'\n';
    }else{
        cout<<"YES"<<'\n';
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