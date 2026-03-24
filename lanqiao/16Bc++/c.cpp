#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
void solve(){
    int n,x;
    cin>>n;
    int d=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==1){
            d--;
        }
    }
    cout<<n+d<<'\n';
}
int main(){
    solve();
    return 0;
}