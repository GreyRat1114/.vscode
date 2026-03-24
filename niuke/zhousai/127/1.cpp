#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c||a-b==c||a*b==c||(a/b==c&&a%b==0)){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    solve();
    return 0;
}