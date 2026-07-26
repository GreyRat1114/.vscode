#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        LL x;
        cin>>x;
        mp[x]++;
    }
    if(mp.size()==1){
        cout<<n-2<<'\n';
        return;
    }
    LL cnt=0;
    for(auto x:mp){
        if(x.second==1){
            cnt++;
        }else if(x.second>=3){
            cnt=cnt+x.second-2;
        }
    }
    cout<<cnt/2<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}