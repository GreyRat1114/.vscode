#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e5+5;
bool cmp(pair<LL,LL> &a,pair<LL,LL> &b){
    return a.first>b.first;
}
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
void solve(){
    LL n,m;
    cin>>n>>m;
    map<LL,LL> mp;
    LL maxn=0;
    for(int i=1;i<=n;i++){
        LL a,b;
        cin>>a>>b;
        mp[b]+=a;
        maxn+=a;
    }
    LL tot=0;
    vector<pair<LL,LL>> cp(n+1);
    for(auto x:mp){
        tot++;
        cp[tot]={x.first,x.second};
    }
    sort(cp.begin()+1,cp.begin()+tot+1,cmp);
    LL ans=0;
    LL last_b=cp[1].first;
    LL free_space=0;
    for(int i=1;i<=tot;i++){
        LL b=cp[i].first;
        LL a=cp[i].second;
        LL d=last_b-b;
        if(free_space>0){
            if(d>=60){
                free_space=maxn+1;
            }else if(maxn/(1ll<<d)<free_space){
                free_space=maxn+1;
            }else{
                free_space*=(1ll<<d);
            }
        }
        if(a<=free_space){
            free_space-=a;
        }else{
            LL def=a-free_space;
            LL cnt=(def-1)/m+1;
            ans=(ans+cnt%mod*qpow(2,b)%mod)%mod;
            free_space=cnt*m-def;
        }
        last_b=b;

    }
    cout<<ans%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}