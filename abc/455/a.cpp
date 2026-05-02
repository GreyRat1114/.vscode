#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL a,b,c;
    cin>>a>>b>>c;
    if(a!=b&&b==c){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}