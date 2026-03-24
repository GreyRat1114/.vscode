#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=1e9+7;
LL a[N];
LL qpow(LL x,LL y){
    LL ans=1; 
    while(y){
        if(y&1){
            ans=(ans*x)%mod;
        }
        x=(x*x)%mod;
        y=y>>1;
    }
    return ans%mod;
}
void solve(){
    int n;
    cin>>n;
    if(n==1){
        LL x;
        cin>>x;
        cout<<x;
        return;
    }
    LL p1=0;
    LL p2=0;
    LL p3=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p1=p1^a[i];
        if(i>=2&&i<=n-1){
            p3=(p3+(2*qpow(3,n-i-1)*p1)%mod)%mod;
        }        
    }
    p2=(a[1]*qpow(3,n-2)*2)%mod;
    LL ans=(p1+p3+p2)%mod;
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}