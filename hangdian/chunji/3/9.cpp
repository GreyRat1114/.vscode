#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
const LL INF=1e9;
#define lc u<<1
#define rc u<<1|1
struct node{
    LL l;
    LL r;
    LL val;
    LL tag0;
    LL tag1;
    LL tag2;
}tr[N*4];
LL w[N];
void pushup(LL u){
    tr[u].val=min(tr[lc].val,tr[rc].val);
}
void pushdown(LL u){
    if(tr[u].tag0){

    }
}
void build(LL u,LL l,LL r){
    tr[u]={l,r,INF,0,0,0};
    if(l==r){
        tr[u].val=w[l];
        return;
    }
    LL mid=(l+r)/2;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(u);
}


void update(LL u,LL l,LL r,LL k,LL x){
    if(l<=tr[u].l&&r>=tr[u].r){

    }
    LL mid=(tr[u].l+tr[u].r)/2;
    pushdown(u);
    if(l<=mid){
        update(lc,l,r,k,x);
    }
    if(r>mid){
        update(rc,l,r,k,x);
    }
    pushup(u);
}   

LL query(LL u,LL l,LL r){
    if(l>tr[u].r||r<tr[u].l)return 0;
    if(l<=tr[u].l&&r>=tr[u].r) return tr[u].val;
    pushdown(u);
    return (query(lc,l,r)+query(rc,l,r));
}
void solve(){
    LL n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=q;i++){
        LL op;
        cin>>op;
        LL l,r,x;
        if(op==1){
            cin>>l>>r>>x;
        }else{
            cin>>l>>r;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}