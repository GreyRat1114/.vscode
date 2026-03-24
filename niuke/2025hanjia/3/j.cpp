#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
void solve(){
    LL n,qq;
    cin>>n>>qq;
    LL cnt1=0;
    while((1ll<<cnt1)<=n){
        cnt1++;
    }
    LL m=(1ll<<cnt1);
    LL d=n-m+1ll;
    //printf("{%lld,%lld,%lld}",x,m,d);
    LL q;
    for(LL i=1ll;i<=qq;i++){
        cin>>q;
        LL cnt2=0;
        while((1ll<<cnt2)<=q){
            cnt2++;
        }
        //printf("{%lld,%lld}",cnt1,cnt2);
        LL ans;
        if(cnt1==cnt2){
            ans=n-(1ll<<(cnt1-1ll))+1ll;
        }else{
            ans=(1ll<<(cnt2-1ll));
            
        }
        cout<<ans<<'\n';
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