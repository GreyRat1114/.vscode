#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n;
    cin>>n;
    //printf("{%lld}",n);
    vector<LL> a(n+1),b(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mp[b[i]]++;
    }
    LL ans=0;
    for(auto x:mp){
        if(x.second==1){
            cout<<-1<<'\n';
            return;
        }
        ans=ans+(x.second-1)/2+1;
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}