#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
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
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),b(n+1);
    vector<set<LL>> mp(n+1);
    //map<LL,> mp;
    queue<pair<LL,LL>> q;
    
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        mp[a[i]].insert(i);
        mp[b[i]].insert(i);
    }
    LL cnt=0;
    for(int i=1;i<=n;i++){
        if(mp[i].size()==1){
            q.push({i,*mp[i].begin()});
            cnt++;            
        }
    }
    while(!q.empty()){
        LL v=q.front().first;
        LL pos=q.front().second;
        q.pop();
        LL x;
        if(v==a[pos]){
            x=b[pos];
        }else{
            x=a[pos];
        }
        mp[x].erase(pos);
        if(mp[x].size()==1){
            q.push({x,*mp[x].begin()});
            cnt++;
        }
    }
    LL ans=(n+cnt)%mod*qpow(2,mod-2)%mod;
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