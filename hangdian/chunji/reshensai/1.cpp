#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL maxn=0;
    for(LL i=1;i*i<=n;i++){
        LL x=i;
        LL y=n/i;
        if(n%x==0&&x>=3){
            cout<<y<<'\n';
            return;
        }
        if(n%y==0){
            maxn=max(maxn,x);
        }
    }
    cout<<maxn<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}