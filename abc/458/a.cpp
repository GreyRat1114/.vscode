#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    string s;
    cin>>s;
    LL n;
    cin>>n;
    for(int i=n;i<s.size()-n;i++){
        cout<<s[i];
    }
    cout<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}