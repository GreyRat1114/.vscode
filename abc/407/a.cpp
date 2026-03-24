#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    int a,b;
    cin>>a>>b;
    double x=1.0*a/b;
    int y=a/b;
    int z=(a-1)/b+1;
    if(z-x<x-y){
        cout<<z<<'\n';
    }
    else{
        cout<<y<<'\n';
    }
}
int main(){
    solve();
    return 0;
}