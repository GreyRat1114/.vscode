//cf1656D
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n; 
    LL x=n;
    if(x%2==1){
        cout<<2<<'\n';
        return;
    }
    while(x%2==0){
        x=x/2;
    }
    if(x==1){
        cout<<-1<<'\n';
    }else{
        LL y=2*n/x;
        LL k=min(x,y);
        cout<<k<<'\n';
    }
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