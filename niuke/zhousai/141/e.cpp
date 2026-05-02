#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n,m;
    cin>>n>>m;
    if(n<2*m||n>m*(m+1)/2+1){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    for(int i=2;i<=m+1;i++){
        cout<<i-1<<' '<<i<<'\n';
    }
    LL tot=m+1;
    LL need=m*(m+1)/2+1-n;
    //printf("{%lld}",need);
    for(LL i=1;i<=m-1;i++){
        LL use=min(i-1,need);
        need-=use;
        LL pre=use+1;
        //printf("{%lld,%lld,%lld}",i,use,need);
        for(int j=1;j<=i-use;j++){
            tot++;
            cout<<tot<<' '<<pre<<'\n';
            pre=tot;
        }
    }
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}