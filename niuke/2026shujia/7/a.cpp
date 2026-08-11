#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    auto get_v=[&](LL m,LL x,LL y)->LL{
        LL pre=0;
        for(LL i=40;i>=0;i--){
            if((x>>i)<(y>>i)){
                if(m&(1ll<<i)){
                    x=x^(1ll<<i);
                }else{
                    if(pre==0)return -1;
                    x=x^(1ll<<pre);
                    for(int j=pre-1;j>=0;j--){
                        if((m&(1ll<<j))&&((x&(1ll<<j))!=0))x=x^(1ll<<j);
                    }
                    return x;                    
                }
            }else if((x>>i)>(y>>i)){
                if(m&(1ll<<i)){
                    x=x^(1ll<<i);
                    pre=i;
                }else{
                    for(int j=i-1;j>=0;j--){
                        if((m&(1ll<<j))&&((x&(1ll<<j))!=0))x=x^(1ll<<j);
                    }
                    return x;
                }
            }else{
                if((m&(1ll<<i))&&((x&(1ll<<i))==0))pre=i;
            } 
        }    
        return x;    
    };
    auto check=[&](LL m)->bool{
        LL pre=0;
        for(LL i=1;i<=n;i++){
            LL mini=get_v(m,a[i],pre);
            //printf("{%lld,%lld,%lld,%lld}",i,pre,mini,m);
            if(mini>=pre){
                pre=max(pre,mini);
            }else{
                return false;
            }
        }
        return true;
    };
    LL ans=(1ll<<41)-1;
    for(LL i=40;i>=0;i--){
        LL x=ans^(1ll<<i);
        if(check(x)){
            ans=x;
        }
    }
    cout<<ans<<'\n';
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