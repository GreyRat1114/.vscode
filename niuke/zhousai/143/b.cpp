#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n,m,x;
    cin>>n>>m>>x;
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        LL a;
        cin>>a;
        mp[a]++;

    }
    LL cnt=0;
    for(auto y:mp){
        if(y.second>x){
            cnt++;
        }        
    }
    cout<<m-cnt<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}