#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
const LL mod=1e9+7;
void solve(){
    LL n,t,s;
    cin>>n>>t>>s;
    LL x=(1<<t)-1;
    LL y=x*n;
    if(s>y){
        cout<<"No"<<'\n';
    }else{
        cout<<"Yes"<<'\n';
    }    
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