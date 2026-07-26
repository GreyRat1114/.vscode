
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
struct node1{
    LL l,r;
    mutable LL v;
    bool operator < (const node1 &o)const{
        return l<o.l;
    }
};
set<node1> odt;
auto split(LL x){//切割区间
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
void assign(LL l,LL r,LL v){//区间推平
    auto itr=split(r+1),itl=split(l);
    odt.erase(itl,itr);
    odt.insert({l,r,v});
}
void perform(LL l,LL r){//暴力遍历区间
    auto itr=split(r+1),itl=split(l);
    for(;itl!=itr;itl++){
        
    }
}
void solve(){

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