#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k,x;
    cin>>n>>k>>x;
    vector<LL> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    LL d=(x-a[k]+n)%n;
    //printf("{%lld,%lld}",d,a[k]);
    vector<LL> ans(n,0);
    ans[k]=x;
    for(int i=0;i<n;i++){
        if(i==k)continue;
        ans[i]=(a[i]+d+n)%n;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}