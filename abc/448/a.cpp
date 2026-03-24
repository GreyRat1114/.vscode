#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    LL n,x;
    cin>>n>>x;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<x){
            cout<<1<<' ';
            x=a[i];
        }else{
            cout<<0<<' ';
        }
        
    }
    
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}