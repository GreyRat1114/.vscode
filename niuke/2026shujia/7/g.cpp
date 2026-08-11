#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    if(mp.size()<=3){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}