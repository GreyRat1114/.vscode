#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=1e9+7;
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+1,0);
    LL s=0;
    LL maxn=0;
    LL minn=1e18;
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
        mp[a[i]]++;
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    LL x=(k+s)/n;
    if(x<maxn){
        cout<<-1<<'\n';
        return;
    }
    //printf("{%lld}",x);
    LL ans=0;
    LL d=(mp[minn]-1)*(x-minn-1);
    for(int i=1;i<=n;i++){
        if(a[i]==minn)continue;
        ans+=x-a[i];
    }
    cout<<ans+d<<'\n';

}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}