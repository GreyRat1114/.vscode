#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair

void solve(){
    LL n;
    cin>>n;
    LL x=n%10;
    if(x==0){
        cout<<1<<'\n';
    }else if(x==5){
        cout<<2<<'\n';
    }else if(x==1||x==3||x==7||x==9){
        cout<<10<<'\n';
    }else if(x==2||x==4||x==6||x==8){
        cout<<5<<'\n';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}