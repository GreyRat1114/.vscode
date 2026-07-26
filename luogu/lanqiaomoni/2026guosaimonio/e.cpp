#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;

void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL cnt=0;
    LL pre=1;
    LL ans=0;
    for(int i=1;i<=n;i++){
        LL hav=mp[a[i]];
        LL ans=0;
        LL c=m-hav;
        ans=(pre*c)%mod;
        cout<<ans<<' ';
        if(mp.count(a[i]))cnt++;
        mp[a[i]]++;
        
        pre=ans;
    }
    
    cout<<'\n';
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