#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL x;
    cin>>x;
    if(x>=3&&x<=18){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
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