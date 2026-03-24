#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
void solve(){
    LL n;
    cin>>n;
    LL maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    LL ans=maxn*n;
    if(a[1]==a[n]&&a[1]==maxn){
        cout<<ans<<'\n';
    }else if(a[1]==maxn){
        cout<<ans-maxn+a[n]<<'\n';
    }else if(a[n]==maxn){
        cout<<ans-maxn+a[1]<<'\n';
    }else{
        cout<<ans-2*maxn+a[1]+a[n]<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}