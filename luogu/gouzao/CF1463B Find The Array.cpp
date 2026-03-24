#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int a[N];
LL f[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x=log2(a[i]);
        cout<<f[x]<<' ';
    }
    cout<<'\n';
}
int main(){
    f[0]=1;
    for(int i=1;i<=30;i++){
        f[i]=f[i-1]*2;
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}