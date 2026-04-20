#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct node{
    LL l,r;
    mutable LL v;
    //node(const LL &li,const LL &ri,const LL &v):l(li);{
    bool operator<(const node &o){
        return l<o.l;
    }
};
set<node> odt;
auto split(LL x){
    auto it=odt.lower_bound({x,0,0});
    if(it!=odt.end()&&it->l==x){
        return it;
    }
    --it;
    LL l=it->l;
    LL r=it->r;
    LL v=it->v;
    odt.erase(it);
    odt.insert({l,x-1,v});
    return odt.insert({x,r,v}).first;
}
void assign(LL l,LL r,LL v){
    auto itr=split(r+1),itl=split(l);
    odt.erase(itl,itr);
    odt.insert({l,r,v});
}

void solve(){

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}