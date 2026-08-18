//cf1470B
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=100005;
vector<LL> prim;
vector<LL> not_prim,minp;

void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
            minp[i]=i;
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            minp[i*p]=p;
            if(i%p==0)break;
        }
    }
}
void init(LL n){
    not_prim.assign(n+10,0);
    minp.assign(n+10,0);
    minp[1]=1;
    get_prim(n+1);
}
LL get_v(LL x){
    map<LL,LL> mp;
    while(1){
        mp[minp[x]]++;
        if(x==1)break;
        x=x/minp[x];
    }
    LL ans=1;
    for(auto cp:mp){
        if(cp.second%2==1){
            ans*=cp.first;
        }
    }
    return ans;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),f(n+1);
    map<LL,LL> mp;
    LL premax=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=get_v(a[i]);
        mp[f[i]]++;
        premax=max(premax,mp[f[i]]);
    }
    LL curmax=0;
    map<LL,LL> mp2;
    for(auto cp:mp){
        if(cp.first==1){
            mp2[1]=cp.second;
            curmax=max(curmax,mp2[1]);
            continue;
        }
        if(cp.second%2==0){
            mp2[1]+=cp.second;
            curmax=max(curmax,mp2[1]);
        }else{
            mp2[cp.first]=cp.second;
            curmax=max(curmax,mp2[cp.first]);
        }
    }
    LL q;
    cin>>q;
    for(int i=1;i<=q;i++){
        LL w;
        cin>>w;
        if(w==0){
            cout<<premax<<'\n';
        }else{
            cout<<curmax<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    init(1e6+1);
    while(t--){
        solve();
    }
    return 0;
}