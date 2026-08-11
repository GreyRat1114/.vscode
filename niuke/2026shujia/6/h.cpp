#include<bits/stdc++.h>
using namespace std;
using LL=long long;
bool isp(LL x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
void solve(){
    LL n;
    cin>>n;
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    if(n==2){
        cout<<1<<' '<<2<<'\n';
        return;
    }
    if(n==3||n==4||n==6){
        cout<<-1<<'\n';
        return;
    }
    if(!isp(n-1)){
        for(int i=1;i<=n;i++){
            cout<<i<<' ';
        }
        cout<<'\n';        
        return;
    }
    for(int i=1;i<=n-4;i++){
        cout<<i<<' ';
    }
    for(int i=n;i>n-4;i--){
        cout<<i<<' ';
    }
    cout<<'\n';
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