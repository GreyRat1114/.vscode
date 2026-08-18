#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<std::string,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int mod=998244353;
struct MInt{
    ll val;
    constexpr static ll norm(ll x,ll m=mod){
        x%=m;
        if(x<0)x+=m;
        return x;
    }
    constexpr MInt():val(0){}
    constexpr MInt(ll x):val(norm(x)){}
    constexpr MInt pow(ll x) const {
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
        ll v;
        is>>v;
        x=MInt(v);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os,const MInt& x){
        return os<<x.val;
    }
};
using Z=MInt;
const int N=1e5+10;
ll a[N];
struct Node{
    int l,r;
    Z sum;
    Z ssum; //second pow;
    Z tsum;
    ll lazy;
    ll rlazy;//assign lazy;
}seg[N<<2];
void pushup(int index){
    seg[index].sum=seg[index<<1].sum+seg[index<<1|1].sum;
    seg[index].ssum=seg[index<<1].ssum+seg[index<<1|1].ssum;
    seg[index].tsum=seg[index<<1].tsum+seg[index<<1|1].tsum;
}
void build(int index,int l,int r){
    if(l==r){
        seg[index]={l,r,a[l],a[l]*a[l],a[l]*a[l]*a[l],0,101};
        return ;
    }
    seg[index].l=l,seg[index].r=r;
    seg[index].rlazy=101,seg[index].lazy=0;
    int mid=(l+r)>>1;
    build(index<<1,l,mid);
    build(index<<1|1,mid+1,r);
    pushup(index);
}
void add(int index,int flag,ll k){
    Z p=k;
    if(flag){//represent assign operator 1
        seg[index].sum=(seg[index].r-seg[index].l+1)*p;
        seg[index].ssum=(seg[index].r-seg[index].l+1)*p*p;
        seg[index].tsum=(seg[index].r-seg[index].l+1)*p*p*p;
        seg[index].rlazy=k;
        seg[index].lazy=0;
    }else{
        seg[index].tsum+=seg[index].ssum*3*p+seg[index].sum*3*p*p+(seg[index].r-seg[index].l+1)*p*p*p;
        seg[index].ssum+=(seg[index].r-seg[index].l+1)*p*p+seg[index].sum*2*p;
        seg[index].sum+=(seg[index].r-seg[index].l+1)*p;
        seg[index].lazy+=k;
    }
}
void pushdown(int index){
    if(seg[index].rlazy!=101){
         add(index<<1,1,seg[index].rlazy);
         add(index<<1|1,1,seg[index].rlazy);
         seg[index].rlazy=101;    
    }
    if(seg[index].lazy==0){
        add(index<<1,0,seg[index].lazy);
        add(index<<1|1,0,seg[index].lazy);
        seg[index].lazy=0;
    }
    
}
void modify(int index,int l,int r,ll k){
    if(seg[index].l>=l&&seg[index].r<=r){
        add(index,0,k);
        return ;
    }
    if(seg[index].l>r||seg[index].r<l){
        return ;
    }
    pushdown(index);
    modify(index<<1,l,r,k);
    modify(index<<1|1,l,r,k);
    pushup(index);
}
void update(int index,int l,int r,ll k){
     if(seg[index].l>=l&&seg[index].r<=r){
        add(index,1,k);
        return ;
    }
    if(seg[index].l>r||seg[index].r<l){
        return ;
    }
    pushdown(index);
    update(index<<1,l,r,k);
    update(index<<1|1,l,r,k);
    pushup(index);
}
Z query(int index,int l,int r){
    if(seg[index].l>=l&&seg[index].r<=r){
        return seg[index].sum;
    }
    if(seg[index].l>r||seg[index].r<l){
        return 0;
    }
    pushdown(index);
    return query(index<<1,l,r)+query(index<<1|1,l,r);
}
Z query1(int index,int l,int r){
     if(seg[index].l>=l&&seg[index].r<=r){
        return seg[index].ssum;
    }
    if(seg[index].l>r||seg[index].r<l){
        return 0;
    }
    pushdown(index);
    return query1(index<<1,l,r)+query1(index<<1|1,l,r);
}
Z query2(int index,int l,int r){
     if(seg[index].l>=l&&seg[index].r<=r){
        return seg[index].tsum;
    }
    if(seg[index].l>r||seg[index].r<l){
        return 0;
    }
    pushdown(index);
//    int mid=(seg[index].l+seg[index].r)>>1;
    return query2(index<<1,l,r)+query2(index<<1|1,l,r);
}
void solve() {
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    } 
    build(1,1,n);
    ll cnt=0;

    while(m--){
        cnt++;
        if(cnt==3){
            for(int j=1;j<=n;j++){
                cout<<query(1,j,j)<<' ';
            }
            cout<<'\n';
            break;
        }
        int opt,l,r;
        ll k;
        std::cin>>opt>>l>>r;
        Z t=r-l+1;
        if(opt==1){
            std::cin>>k;
            modify(1,l,r,k);
        }else if(opt==2){
            std::cin>>k;
            update(1,l,r,k);
        }else if(opt==3){
            Z l1=query(1,l,r),l2=query1(1,l,r);
            Z mid=l1*t.inv();
            Z ans=l2-2*mid*l1+mid*mid*t;
            std::cout<<ans*t.inv()<<'\n';
        }else {
            Z l1=query(1,l,r),l2=query1(1,l,r),l3=query2(1,l,r);
            Z mid=l1*t.inv();
            Z ans=l3-3ll*mid*l2+3ll*mid*mid*l1-t*mid*mid*mid;
            std::cout<<ans*t.inv()<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
