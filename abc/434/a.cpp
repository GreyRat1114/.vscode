// A - Balloon Trip
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL w,b;
    cin>>w>>b;
    w*=1000;
    LL ans=w/b+1;
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}