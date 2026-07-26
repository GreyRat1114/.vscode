#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<string> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cout<<a[i]<<'\n';
    }
    vector<vector<string>> b(m+1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            string s;
            cin>>s;
            b[i].push_back(s);            
        }


    }
}
int main(){
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}