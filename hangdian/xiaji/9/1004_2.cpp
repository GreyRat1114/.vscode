#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
vector<LL> p;
void insert(LL x){
    for(int i=62;i>=0;i--){
        if(x>>i&1){
            if(p[i]){
                x^=p[i];            
            }else{
                p[i]=x;
                break;
            }
        }
    }
}
void solve(){
    LL n,len,q;
    cin>>n>>len>>q;
    p.assign(100,0);
    vector<LL> a(n+1),s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(int i=len;i<=n;i++){
        LL d=s[i]^s[i-len];
        insert(d);
        //printf("{%lld}",d);
    }
    for(int i=1;i<=q;i++){
        LL x;
        cin>>x;
        LL ans=x;
        for(int j=62;j>=0;j--){
            ans=max(ans,ans^p[j]);
            // if(((ans&(1ll<<j))==0)&&p[j]){
            //     x=x^p[j];
            // }
        }
        cout<<ans<<'\n';
    }
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