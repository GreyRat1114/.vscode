#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    LL x;
    cin>>x;
    if(x<x*x){
        cout<<"right"<<'\n';
    }else if(x>x*x){
        cout<<"left"<<'\n';

    }else{
        cout<<"equal"<<'\n';
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}