#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(n+1);
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n-1;i++){
        LL u,v;
        cin>>u>>v;
    }
    for(int i=1;i<=q;i++){
        LL p;
        cin>>p;
        if(a[p]){
            cout<<0<<'\n';
        }else{
            cout<<s+1<<'\n';
        }
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