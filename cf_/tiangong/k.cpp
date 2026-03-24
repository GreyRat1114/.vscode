#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
using LL=long long;
const LL mod=998244353;
LL a[N];
void solve(){
    LL n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    LL minn=1e10;
    for(int i=2;i<=n;i++){
        LL x=a[i-1]^a[i];
        if(x<=k){
            cout<<"Yes"<<'\n';
            return;
        }
    }
    cout<<"No"<<'\n';

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);    
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}