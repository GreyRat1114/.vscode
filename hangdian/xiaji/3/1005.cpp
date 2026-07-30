#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
vector<LL> prim;
vector<LL> not_prim;
void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            if(i%p==0)break;
        }
    }
}
void init(LL n){
    not_prim.assign(n+2,0);
    get_prim(n);
}

void solve(){
    LL x1;
    cin>>x1;
    LL x=x1;
    map<LL,LL> mp;
    for(auto p:prim){
        LL cnt=0;
        while(x%p==0){
            x=x/p;
            cnt++;
        }
        if(cnt>0)mp[p]=cnt;
    }
    auto check=[&](LL v)->LL{
        LL res=0;
        for(LL i=0;i<=60;i++){
            if((1ll<<i)&v){
                res=i;
            }
        }
        return res;
    };
    if(mp.size()==0){
        LL y=sqrt(x);
        if(y*y==x){
            cout<<2<<'\n';
        }else{
            cout<<1<<'\n';
        }
        //printf("{}");
    }else{
        LL ans=0;
        for(auto cp:mp){
            LL c=cp.second;
            ans=max(ans,c);
        }
        //printf("{%lld}",ans);
        cout<<check(ans)+1<<'\n';
    }
}
int main(){
    init(1e6+10);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}