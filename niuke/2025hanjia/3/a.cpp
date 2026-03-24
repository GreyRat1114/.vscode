#include<bits/stdc++.h>
using namespace std;
const int N=25;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL x[10];
void solve(){
    LL x;
    cin>>x;
    for(LL i=1;i<=x;i++){
        if(x==i*(i+1)){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<"\n";
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    return 0;
}