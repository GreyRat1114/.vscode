#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
void solve(){
    LL n;
    cin>>n;
    if(n==1){
        cout<<"YES"<<'\n';
        cout<<1<<'\n';
    }else if(n==3){
        cout<<"YES"<<'\n';
        cout<<1<<' '<<2<<' '<<3<<' '<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}