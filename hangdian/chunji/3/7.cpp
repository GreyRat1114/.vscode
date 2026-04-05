#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    vector<LL> a(2*n+1,0);
    vector<LL> pre(m+1,0),suf(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[(i-1)%m+1]+=a[i];
    }
    LL x=n%m;
    LL ans=pre[k];
    for(int i=n;i>=1;i--){
        pre[(i-1)%m+1]-=a[i];
        suf[(i-1)%m+1]+=a[i];
        ans=max(ans,suf[(k+i-1)%m+1]+pre[(k-(n-i)%m+m-1)%m+1]);
    }


    cout<<ans<<'\n';
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