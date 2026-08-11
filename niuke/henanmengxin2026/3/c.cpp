#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1),c(n+1,0);
    map<LL,LL> mp;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=(c[i-1]+a[i])%m;
        s+=a[i];
    }
    LL yu=s%m;
    //printf("{%lld}",yu);
    LL ans=1e9;
    mp[0]=0;
    for(int i=1;i<=n;i++){
        if((a[i]%m)==yu){
            cout<<n-1<<'\n';
            return;
        }
    }
    for(int i=1;i<=n;i++){
        LL r=i;
        LL x=c[i];
        LL tar=(x-yu+m)%m;
        if(!mp.count(tar)){
            mp[c[i]]=i;
            continue;
        }
        LL l=mp[tar];
        if(r==n&&l==0){
            continue;
        }
        //printf("{%lld,%lld,%lld}",tar,l,r);
        ans=min(ans,r-l);
        mp[c[i]]=i;
    }
    if(ans==1e9){
        cout<<-1<<'\n';
    }else{
        cout<<n-ans<<'\n';
    }
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