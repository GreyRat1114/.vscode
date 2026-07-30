#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
void solve(){
    LL n,x,y;
    cin>>n>>x>>y;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(x==0||y==0){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    LL ans=0;
    LL ax=a[1];
    LL ay=a[1];
    for(int i=1;i<=n;i++){
        LL d=max((a[i]-1)/x+1,(a[i]-1)/y+1);
        ans+=d;
        // LL dy=max(ax/x,ay/y);
        // LL yx=max(0ll,ax-(dy*x));
        // LL yy=max(0ll,ay-(dy*y));
        // ax=max(0ll,a[i+1]-(x-yx));
        // ay=max(0ll,a[i+1]-(y-yy));
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}