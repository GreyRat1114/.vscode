#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    string s="Abiyoyo, Abiyoyo.";
    string s2="Abiyoyo, yo yoyo yo yoyo.\nAbiyoyo, yo yoyo yo yoyo.";
    for(int i=1;i<=n;i++){
        cout<<s<<'\n';
    }
    cout<<s2<<'\n';
    
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