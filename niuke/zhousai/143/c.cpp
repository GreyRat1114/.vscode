#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
LL qpow(LL a,LL b){
    a=a%mod;
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
void solve(){
    LL x,y;
    cin>>x>>y;
    LL v=x*y%mod;
    LL ans=0;
    vector<LL> q1,q2;
    for(LL i=1;i*i<=x;i++){
        if(x%i==0){
            if((x/i)==i){
                q1.push_back(i);
            }else{
                q1.push_back(i);
                q1.push_back(x/i);
            }
        }
    }
    for(LL i=1;i*i<=y;i++){
        if(y%i==0){
            if((y/i)==i){
                q2.push_back(i);
            }else{
                q2.push_back(i);
                q2.push_back(y/i);
            }
        }
    }    
    set<LL> st;
    //printf("{%lld,%lld}",q1.size(),q2.size());
    for(int i=0;i<q1.size();i++){
        for(int j=0;j<q2.size();j++){
            LL a=q1[i];
            LL b=q2[j];
            st.insert(a*b);
           // printf("{%lld}",a,b);
            //
        }
    }
    for(auto z:st){
        //printf("{%lld}",z);
        ans=(ans+qpow(z,z))%mod;
    }
    cout<<ans%mod<<'\n';
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