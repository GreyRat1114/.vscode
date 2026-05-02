#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    string s;
    cin>>s;
    //cout<<s<<'\n';
    for(int i=0;i<n;i++){
        
        if(s[i]=='L'){
            cout<<i+1<<'\n';
            return;
        }
        
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