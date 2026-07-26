#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL x;
    cin>>x;
    x=x%10;
    if(x==1||x==3||x==7||x==9){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}