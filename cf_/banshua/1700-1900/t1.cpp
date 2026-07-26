#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=ans*a;
        b=b>>1;
        a=a*a;
    }
    return ans;
}
void solve(){
    LL c,k,a;
    cin>>c>>k>>a;
    LL cur=qpow(c,k);
    //cout<<cur<<'\n';
    LL cnt=0;
    while(a&&cur!=0){
        cnt+=a/cur;
        a=a%cur;
        cur=cur/c;
    }
    cout<<cnt<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}