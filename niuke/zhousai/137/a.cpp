#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    LL x=n/3600;
    n=n%3600;
    LL y=n/60;
    n=n%60;
    LL z=n;
    cout<<x<<' '<<y<<' '<<z<<'\n';
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    return 0;
}