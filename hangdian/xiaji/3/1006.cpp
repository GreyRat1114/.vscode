#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans*=a;
        b=b>>1;
        a=a*a;
    }
    return ans;
}
void solve(){
    LL n;
    cin>>n;
    if(n==1){
        cout<<1<<'\n';
        cout<<1<<'\n';
        return;
    }
    set<LL> ans;
    auto get_c=[&](LL x,LL k)->LL{
        LL c=0;
        LL y=k;
        while(y<=x){
            y*=k;
            c++;
        }
        return c;
    };
    for(int i=1;i<=n;i+=2){
        LL c=get_c(n/i,3);
        ans.insert(i*qpow(2,c));
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}