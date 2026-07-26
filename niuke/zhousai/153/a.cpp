#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i!=0)cout<<'.';
        cout<<s[i];
    }
    cout<<'\n';
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