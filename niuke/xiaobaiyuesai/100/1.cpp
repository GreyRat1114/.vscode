#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
LL check(LL a,LL b,LL c){
    if(a+b>c&&a+c>b&&b+c>a&&a-b<c&&a-c<b&&b-c<a){
        return 1;
    }
    return 0;
}
void solve(){
    LL a,b,c;
    cin>>a>>b>>c;
    if(check(a*2,b,c)||check(a,b*2,c)||check(a,b,c*2)){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
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