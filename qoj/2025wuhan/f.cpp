#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e5+5;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
bool cmp(pair<LL,LL> x,pair<LL,LL> y){
    return x.second>y.second;
}
void solve(){
    LL n,m;
    cin>>n>>m;
    map<LL,LL> a;
    for(int i=1;i<=n;i++){
        LL a1,b1;
        cin>>a1>>b1;
        a[b1]+=a1;
    }
    LL pre=0;
    LL c=0;
    map<LL,LL> mp2;
    //LL tot=0;
    for(auto x:a){
        LL val=x.first;
        LL cnt=x.second;
        LL d=0;
        
        if(cnt>m){
            d=(cnt-m+1)/2;
            printf("{%lld}",d);
            cnt-=d;
            a[val]-=d*2;
            a[val+1]+=d;
        }
        printf("{%lld,%lld}",val,cnt);
        if(cnt>m-c){
            //printf("{%lld,%lld}",val,cnt);
            mp2[pre]=1;
        }
        pre=val;
        c=cnt;
    }
    LL ans=0;
    for(auto x:mp2){
        ans=(ans+qpow(2,x.first))%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}