#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    LL x,y;
    cin>>x>>y;
    for(int i=1;i<=y;i++){
        x=x*2;
    }
    cout<<x<<'\n';
}
int main(){
    solve();
    return 0;
}