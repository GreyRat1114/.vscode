#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
// LL a[N];
// LL b[N];
LL din[N];
const LL mod=998244353;
void solve(){
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        din[a]++;
        din[b]++;
    }
    for(int i=1;i<=n;i++){
        LL y=n-1-din[i];
        if(y<3){
            cout<<0<<' ';
        }else{
            
            LL x=(y*(y-1)*(y-2))/6;
            cout<<x<<' ';
        }
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}