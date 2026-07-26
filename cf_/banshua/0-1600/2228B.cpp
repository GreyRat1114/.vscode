#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,x1,x2,k;
    cin>>n>>x1>>x2>>k;

    LL d=(x1-x2+n)%n;
    x1--;
    x2--;
    if(n==2){
        cout<<1<<'\n';
        return;
    }else if(n==3){
        cout<<1<<'\n';
        return;
    }
    if(d*2==n){
        cout<<k+d<<'\n';
    }else{
        LL d2=(n-d)%n;

        cout<<k+min(d,d2)<<'\n';
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