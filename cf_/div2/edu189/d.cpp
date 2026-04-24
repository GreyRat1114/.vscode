#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL n,x;
    cin>>n>>x;
    if(x%4==0){
        LL l0=x/4;
        LL l1=x/4;
        LL r0=(n-x+1)/4;
        LL r1=(n-x+3)/4;
        l0=l0%mod;
        l1=l1%mod;
        r0=r0%mod;
        r1=r1%mod;
        //printf("{%lld,%lld,%lld,%lld}",l0,l1,r0,r1);
        LL ans=((l0*r0)%mod+(l1*r1)%mod+r0)%mod;
        cout<<ans%mod<<'\n';
    }else if(x%4==1){
        LL l0=x/4;
        LL l1=x/4;
        LL r0=(n-x+2)/4;
        LL r1=(n-x)/4+1;
        l0=l0%mod;
        l1=l1%mod;
        r0=r0%mod;
        r1=r1%mod;
        LL ans=((l0*r0)%mod+(l1*r1)%mod+r0)%mod;  
        if(x==1){
            cout<<r0%mod<<'\n';
        }else{
            cout<<ans%mod<<'\n'; 
        }
    }else if(x%4==2){
        LL l0=x/4;
        LL l1=x/4+1;
        LL r0=(n-x+3)/4;
        LL r1=(n-x+1)/4;
        l0=l0%mod;
        l1=l1%mod;
        r0=r0%mod;
        r1=r1%mod;
        LL ans=((l0*r0)%mod+(l1*r1)%mod+r0)%mod;   
        cout<<ans%mod<<'\n';         
    }else if(x%4==3){
        LL l0=x/4;
        LL l1=x/4+1;
        LL r0=(n-x)/4+1;
        LL r1=(n-x+2)/4;
        l0=l0%mod;
        l1=l1%mod;
        r0=r0%mod;
        r1=r1%mod;
        LL ans=((l0*r0)%mod+(l1*r1)%mod+r0)%mod;  
        cout<<ans%mod<<'\n';  
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