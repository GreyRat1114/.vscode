#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),b(n+1,0),c(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-i;
        c[i]=a[i]+i;
    }
    LL minn=1e9;
    LL ans=0;
    for(int i=1;i<=n;i++){
        minn=min(minn,b[i]);
        ans=max(ans,b[i]-minn);
    }
    minn=1e9;
    for(int i=n;i>=1;i--){
        minn=min(minn,c[i]);
        ans=max(ans,c[i]-minn);
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}