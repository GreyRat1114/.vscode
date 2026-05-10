#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,x;
    cin>>n>>x;
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        LL val;
        cin>>val;
        mp[val]++;
    }
    LL cnt=0;
    for(auto y:mp){
        if(y.second<=x){
            cnt+=y.second;
        }
    }
    cout<<cnt<<'\n';
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