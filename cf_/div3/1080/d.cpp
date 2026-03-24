#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),f(n+1),sa(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    LL sum=(f[1]+f[n])/(n-1ll);
    LL s2=0;
    for(int i=2;i<=n;i++){
        LL x=f[i-1]-f[i];
        LL y=(sum-x)/2-s2;
        a[i-1]=y;
        s2+=y;
    }
    a[n]=sum-s2;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}