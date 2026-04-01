#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL n,x;
    cin>>n>>x;
    vector<LL> h(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    LL p=h[1];
    for(int i=1;i<=n-1;i++){
        if(h[i+1]-h[i]>1||h[i]-h[i+1]>x){
            cout<<"Lose"<<'\n';
            return;
        }
    }
    cout<<"Win"<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}