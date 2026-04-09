#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
LL check(LL x){
    LL y;
    //map<LL,LL> mp;
    int mp[10]={0,0,0,0,0,0,0,0,0,0};
    //printf("{%lld}",x);
    while(x){
        y=x%10;
        mp[y]++;
        x=x/10;
        //printf("{%lld}",x);
    }
    
    if(mp[2]==2&&mp[0]==1&&mp[6]==1){
        return 1;
    }else{
        return 0;
    }
}
void solve(){
    LL n=20262026;
    LL ans=0;
    for(LL i=1;i<=n;i++){
        if(check(i)){
            ans++;
        }
        //ans+=check(i);
    }
    cout<<ans<<'\n';

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}