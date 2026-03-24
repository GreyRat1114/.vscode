#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    int t;
    cin>>t;
    LL n,m;
    LL x;
    for(int i=1;i<=t;i++){
        cin>>x;
        if(x%2==1){
            cout<<"Case "<<i<<": "<<"Impossible"<<'\n';
            continue;
        }
        m=1;
        n=x;
        while(n%2==0){
            m*=2;
            n=n/2;
        }
        cout<<"Case "<<i<<": "<<n<<' '<<m<<'\n';
    }
}
int main(){
    solve();
    return 0;
}