#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
vector<LL> a;
void solve(){
    LL n;
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
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