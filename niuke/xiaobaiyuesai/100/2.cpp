#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<-1<<'\n';
        return;
    }
    if(n%2==1){
        cout<<n/2+1<<'\n';
    }else{
        cout<<n/2<<'\n';
    }
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