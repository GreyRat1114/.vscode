#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e6+5;
int cnt[N];
int a[N];
void solve(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=2;i<=n;i++){
        ans=(ans+k)%i;
    }
    cout<<ans+1<<'\n';
}
int main(){
    int t;
    cin>>t;    
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}