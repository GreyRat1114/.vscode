#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int Mod=998244353;
using PII=std::pair<ll,ll>;
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1){
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y>>=1;
    }

    return res;
}
void solve(){
    ll n,m;
    std::cin>>n>>m;
    std::vector<PII>v(n);
    ll maxn=0;
    for(int i=0;i<n;i++){
        std::cin>>v[i].second>>v[i].first;
        maxn+=v[i].second;
    }
    std::sort(v.rbegin(),v.rend());
    std::vector<PII>merged;
    for(int i=0;i<n;i++){
        if(!merged.empty()&&merged.back().first==v[i].first){
            merged.back().second+=v[i].second;
        }else{
            merged.push_back(v[i]);
        }
    }
    
    ll ans=0;
    ll free_space=0;
    ll last_b=merged[0].first;

    for(int i=0;i<merged.size();i++){
        ll b=merged[i].first;
        ll a=merged[i].second;
       // std::cerr<<b<<" "<<a<<endl;
        ll delta=last_b-b;

        if(free_space>0){
            if(delta>=60){
                free_space=maxn+1;
            }else{
                if(maxn/(1ll<<delta)<free_space){
                    free_space=maxn+1;
                }else{
                    free_space*=(1ll<<delta);//提升空间(相对的)
                }
            }
        }

        if(a<=free_space){
            free_space-=a;
        }else{
            ll def=a-free_space;
            ll block_need=(def+m-1)/m;
            ans=(ans+(block_need%Mod)*qpow(2LL,b)%Mod)%Mod;
            free_space=block_need*m-def;
            printf("{%lld,%lld}",i,def);
        }
        printf("{%lld}",free_space);
        last_b=b;
    }
    std::cout<<ans<<std::endl;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        solve();
    }
    return 0;
}