#include<bits/stdc++.h>
using namespace std;
void solve(){
    int d,n;
    cin>>d>>n;
    int ans=(d-n)%7;
    cout<<7-ans<<'\n';
}
int main(){
    solve();
    return 0;
}