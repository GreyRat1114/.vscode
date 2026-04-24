#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    if(n%4==0||n%4==1){
        cout<<"Fluttershy"<<'\n';
    }else if(n%4==3||n%4==2){
        cout<<"Pinkie Pie"<<'\n';
    }
}
int main(){
    //ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}