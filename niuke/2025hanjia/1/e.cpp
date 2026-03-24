#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
void solve(){
    LL n,k;
    cin>>n>>k;
    LL maxn=-10000000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=k;
    maxn=max(maxn,a[1]+a[n+1]);
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]+a[i+1]);
    }
    cout<<maxn<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}