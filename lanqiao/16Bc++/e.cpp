#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
void solve(){
    int n,m;
    LL x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    LL ans=1e18;
    for(int i=0;i<=n-m;i++){
        LL x=a[m+i]*a[m+i]-a[1+i]*a[1+i];
        ans=min(ans,x);
    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}