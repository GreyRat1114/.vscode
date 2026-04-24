#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL s=0;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    LL ans=0;
    for(LL j=30;j>=0;j--){
        if(((1ll<<j)-1ll)*n>=s){
            continue;
        }
        LL c=min(n,s/(1ll<<j));
        s=s-c*((1ll<<j));
        ans=ans|(1ll<<j);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}