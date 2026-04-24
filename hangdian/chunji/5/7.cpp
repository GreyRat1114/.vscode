#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
#define lc u<<1
#define rc u<<1|1
struct node{
    int l,r;
    long long sum;
    LL add;
    long long clr;
}tr[N*4];

void pushup(int u)
{
    tr[u].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(int u)
{
    if(tr[u].clr){
        tr[lc].add=tr[rc].add=0;
        tr[lc].sum=tr[rc].sum=0;
        tr[lc].clr=tr[rc].clr=1;
        tr[u].clr=0;
    }
    if(tr[u].add)
    {
        tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
        tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
        tr[lc].add+=tr[u].add;
        tr[rc].add+=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,int l,int r)
{
    tr[u]={l,r,0,0,0};
    if(l==r)
    {
        return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(u);

}
void update(int u,int l,int r,long long k)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
        tr[u].add+=k;
        return;
    }
    int m=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(l<=m)
    {
        update(lc,l,r,k);
    }
    if(r>m)
    {
        update(rc,l,r,k);
    }
    pushup(u);
}
long long query(int u,int l,int r)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        return tr[u].sum;
    }
    int m=tr[u].r+tr[u].l>>1;
    pushdown(u);
    long long sum=0;
    if(l<=m)
    {
        sum+=query(lc,l,r);
    }
    if(r>m)
    {
        sum+=query(rc,l,r);
    }
    return sum;
}
void clear(LL u,LL l,LL r){
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        tr[u].sum=0;
        tr[u].add=0;
        tr[u].clr=1;
        return;
    }
    int m=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(l<=m)
    {
        clear(lc,l,r);
    }
    if(r>m)
    {
        clear(rc,l,r);
    }
    pushup(u);  
}
struct node1{
    LL l,r;
    mutable LL v;
    //node(const LL &li,const LL &ri,const LL &v):l(li);{
    bool operator < (const node1 &o)const{
        return l<o.l;
    }
};
vector<LL> cnt;
set<node1> odt;
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
void perform(LL l,LL r){
    auto itr=split(r+1),itl=split(l);
    for(;itl!=itr;itl++){
        LL l=itl->l;
        LL r=itl->r;
        if(itl->v==0)continue;
        cnt[itl->v]+=query(1,l,r);
    }
}
void solve(){
    LL n,m,q;
    cin>>n>>m>>q;
    vector<LL> a(n+2,0);
    odt.insert({n+1,n+1,0});
    cnt.assign(m+1,0);
    odt.clear();
    LL pre=1;
    a[n+1]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n+1;i++){
        if(a[i]!=a[pre]){
            odt.insert({pre,i-1,a[i-1]});
            pre=i;
        }        
    }
    build(1,1,n);
    for(int i=1;i<=q;i++){
        LL op,l,r,x;
        cin>>op>>l>>r>>x;
        if(op==1){
            perform(l,r);
            clear(1,l,r);
            assign(l,r,x);
        }else{
            update(1,l,r,x);
        }
    }
    perform(1,n);
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
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