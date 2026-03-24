#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
int b[N];
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),px(n+1),lp(n+1),rp(n+1);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        LL op;
        cin>>op;
        cout<<lower_bound(b,b+n,op)-b<<'\n';

    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}