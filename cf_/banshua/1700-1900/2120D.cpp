#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
vector<LL> A(N+1,0);
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans%mod;
}
void init(){
    A[0]=1;
    for(int i=1;i<=N;i++){
        A[i]=A[i-1]*qpow(i,mod-2)%mod;
    }
}
void solve(){
    LL a,b,k;
    cin>>a>>b>>k;
    LL n=(k*(a-1)+1)%mod;
    //printf("{%lld}",n);
    LL c=A[a];
    for(int i=0;i<=a-1;i++){
        c=c*(n-i)%mod;
    }
    //printf("{%lld,%lld,%lld}",k,c,b);
    LL m=k*c%mod*(b-1)%mod+1;
    cout<<n%mod<<' '<<m%mod<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    init();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}