#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
LL sum[N];
void solve(){
    LL n,q,s;

    cin>>n>>q>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[0]=s-1;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        //printf("{%lld}",sum[i]);
    }
    LL x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        LL ans=sum[x-1]+y;
        cout<<ans<<'\n';
    }

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}