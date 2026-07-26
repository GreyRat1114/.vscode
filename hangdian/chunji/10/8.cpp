// 【模板】线段树1
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define lc u<<1
#define rc u<<1|1
const int mod=998244353;
const int N=1e5+5;
struct MInt{
    LL val;
    constexpr static LL norm(LL x,LL m=mod){
        x%=m;
        if(x<0)x+=m;
        return x;
    }
    constexpr MInt():val(0){}
    constexpr MInt(LL x):val(norm(x)){}
    constexpr MInt pow(LL x) const {
        MInt res=1;
        MInt a=*this;
        while(x>0){
            if(x&1)res*=a;
            a*=a;
            x>>=1;
        }
        return res;
    }

    constexpr MInt inv() const {
        return pow(mod-2);
    }

    constexpr friend MInt operator+(MInt a,MInt b){return a.val+b.val;}
    constexpr friend MInt operator-(MInt a,MInt b){return a.val-b.val;}
    constexpr friend MInt operator*(MInt a,MInt b){return 1ll*a.val*b.val;}
    constexpr friend MInt operator/(MInt a,MInt b){return a.val*b.inv();}

    constexpr friend MInt& operator+=(MInt& a,MInt b){return a=a+b;}
    constexpr friend MInt& operator-=(MInt& a,MInt b){return a=a-b;}
    constexpr friend MInt& operator*=(MInt& a,MInt b){return a=a*b;}
    constexpr friend MInt& operator/=(MInt& a,MInt b){return a=a/b;}

    constexpr friend bool operator==(MInt a,MInt b){return a.val==b.val;};
    constexpr friend bool operator!=(MInt a,MInt b){return a.val!=b.val;};
    
    friend std::istream& operator>>(std::istream& is,MInt& x){
        LL v;
        is>>v;
        x=MInt(v);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os,const MInt& x){
        return os<<x.val;
    }
};
using Z=MInt;
struct node{
    int l,r;
    Z sum;
    Z add;
    Z tag;
    Z sum2;
}tr[N*4];
vector<LL>a;
void pushup(int u)
{
    tr[u].sum=tr[lc].sum+tr[rc].sum;
    tr[u].sum2=tr[lc].sum2+tr[rc].sum2;
}
void add(int u,Z k){
     tr[u].tag+=tr[u].sum*2ll*k+(tr[u].r-tr[u].l+1)*k*k;
     tr[u].sum2+=tr[u].sum*2ll*k+(tr[u].r-tr[u].l+1)*k*k;
     tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
     tr[u].add+=k;
}
void pushdown(int u)
{
    if(tr[u].add.val)
    {
        add(lc,tr[u].add);
        add(rc,tr[u].add);
        tr[u].tag=tr[u].add=0;
    }
}

void build(int u,int l,int r)
{
    tr[u]={l,r,a[l],0,0,a[l]*a[l]};
    if(l==r)
    {
        return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(u);

}
void update(int u,int l,int r,Z k)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {   
        add(u,k);
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
Z query(int u,int l,int r)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        return tr[u].sum;
    }
    int m=tr[u].r+tr[u].l>>1;
    pushdown(u);
    Z sum=0;
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
Z query1(int u,int l,int r)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        return tr[u].sum2;
    }
    int m=tr[u].r+tr[u].l>>1;
    pushdown(u);
    Z sum=0;
    if(l<=m)
    {
        sum+=query1(lc,l,r);
    }
    if(r>m)
    {
        sum+=query1(rc,l,r);
    }
    return sum;
}
int n,m;
void solve(){
    Z s=2;
    LL n,q;
    cin>>n>>q;
    a.resize(n+5);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    build(1,1,n);
    while(q--){
        int opt;
        std::cin>>opt;
        if(opt==1){
            int l,r;
            Z d;
            std::cin>>l>>r>>d;
            update(1,l,r,d);
        }else{
            int l,r;
            std::cin>>l>>r;
         //   std::cerr<<query(1,l,r)<<" "<<query1(1,l,r)<<'\n';
            std::cout<<(query(1,l,r)*query(1,l,r)-query1(1,l,r))*s.inv()<<'\n';
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}