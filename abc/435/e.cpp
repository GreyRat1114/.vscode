#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define IT set<node>::iterator
struct node{
    LL l,r;
    mutable int v;
    node(LL L,LL R=-1,int V=0):l(L),r(R),v(V){}
    bool operator < (const node &o) const{
        return l<o.l;
    }
};
set<node> s;
LL sum=0;
IT split(LL pos){
    IT it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos){
        return it;
    }
    --it;
    LL L=it->l,R=it->r;
    int V=it->v;
    s.erase(it);
    s.insert(node(L,pos-1,V));
    return s.insert(node(pos,R,V)).first;
}
void tp(LL l,LL r,int val){
    IT itr=split(r+1),itl=split(l),it=itl;
    for(;itl!=itr;++itl){
        sum-=itl->v*(itl->r-itl->l+1);
    }
    s.erase(it,itr);
    s.insert(node(l,r,val));
    sum+=val*(r-l+1);
}
void solve(){
    LL l,r,k;
    LL n,q;
    cin>>n>>q;
    s.insert(node(1,n,1));
    sum=n;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        tp(l,r,0);
        cout<<sum<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}