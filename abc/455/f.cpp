#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define lc (u<<1)
#define rc (u<<1|1)
const LL mod=998244353;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
struct SegTree{
    struct node{
        LL l,r;
        LL sum=0;
        LL maxn=0;
        LL minn=0;
        LL sum2=0;
        LL add=0;//区间加
        LL add2=0;
        LL mul=1;//区间乘
        LL setv=0;//区间赋值
        bool vis=false;//是否存在赋值标记
    };
    LL n;
    vector<node> tr;

    void init(LL _n){
        n=_n;
        tr.assign(n*4+5,node());
    }
    void pushup(LL u){
        tr[u].sum=(tr[lc].sum+tr[rc].sum)%mod;
        tr[u].sum2=(tr[lc].sum2+tr[rc].sum2)%mod;
        tr[u].maxn=max(tr[lc].maxn,tr[rc].maxn);
        tr[u].minn=min(tr[lc].minn,tr[rc].minn);
    }
    void pushdown(LL u){
        if(tr[u].l==tr[u].r)return;
        if(tr[u].vis){
            applyset(lc,tr[u].setv);
            applyset(rc,tr[u].setv);
            tr[u].vis=false;
        }        
        if(tr[u].mul!=1){
            applymul(lc,tr[u].mul);
            applymul(rc,tr[u].mul);
            tr[u].mul=1;
        }
        if(tr[u].add){
            applyadd(lc,tr[u].add);
            applyadd(rc,tr[u].add);
            tr[u].add=0;
        }
    }
    void build(LL u,LL l,LL r,const vector<LL> &a){
        tr[u].l=l;
        tr[u].r=r;
        if(l==r){
            tr[u].sum=tr[u].maxn=tr[u].minn=a[l];
            return;
        }
        LL mid=(l+r)/2;
        build(lc,l,mid,a);
        build(rc,mid+1,r,a);
        pushup(u);
    }
    void applyadd(LL u,LL val){
        tr[u].sum2=(tr[u].sum2+2*tr[u].sum*val%mod+(tr[u].r-tr[u].l+1)*val%mod*val%mod)%mod;
        //printf("{%lld,%lld,%lld}",tr[u].l,tr[u].r,tr[u].sum2);
        tr[u].sum=(tr[u].sum+val*(tr[u].r-tr[u].l+1)%mod)%mod;
        tr[u].maxn+=val;
        tr[u].minn+=val;
        if(tr[u].vis){
            tr[u].setv+=val;
        }else{
            tr[u].add=(tr[u].add+val)%mod;
        }
    }


    void applymul(LL u,LL k){
        tr[u].sum=tr[u].sum*k;
        if(k>=0){
            tr[u].maxn=tr[u].maxn*k;
            tr[u].minn=tr[u].minn*k;
        }else{
            tr[u].maxn=tr[u].minn*k;
            tr[u].minn=tr[u].maxn*k;
        }
        if(tr[u].vis){
            tr[u].setv*=k;
        }else{
            tr[u].mul=tr[u].mul*k;
            tr[u].add=tr[u].add*k;            
        }
    }
    void applyset(LL u,LL val){
        tr[u].sum=val*(tr[u].r-tr[u].l+1);
        tr[u].maxn=val;
        tr[u].minn=val;
        tr[u].setv=val;
        tr[u].vis=true;
        tr[u].add=0;
        tr[u].mul=1;
    }
    void rangeadd(LL u,LL l,LL r,LL val){//区间加
        if(tr[u].l>=l&&tr[u].r<=r){
            applyadd(u,val);
            return;
        }
        pushdown(u);
        LL mid=(tr[u].l+tr[u].r)/2;
        if(l<=mid){
            rangeadd(lc,l,r,val);
        }
        if(r>=mid+1){
            rangeadd(rc,l,r,val);
        }
        pushup(u);
    }

    void rangemul(LL u,LL l,LL r,LL k){//区间乘
        if(tr[u].l>=l&&tr[u].r<=r){
            applymul(u,k);
            return;
        }
        pushdown(u);
        LL mid=(tr[u].l+tr[u].r)/2;
        if(l<=mid){
            rangemul(lc,l,r,k);
        }
        if(r>=mid+1){
            rangemul(rc,l,r,k);
        }
        pushup(u);
    }
    void rangeset(LL u,LL l,LL r,LL val){//区间赋值
        if(tr[u].l>=l&&tr[u].r<=r){
            applyset(u,val);
            return;
        }
        pushdown(u);
        LL mid=(tr[u].l+tr[u].r)/2;
        if(l<=mid){
            rangeset(lc,l,r,val);
        }
        if(r>=mid+1){
            rangeset(rc,l,r,val);
        }
        pushup(u);
    }
    LL querysum(LL u,LL l,LL r){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u].sum;
        }        
        pushdown(u);
        LL mid=(tr[u].l+tr[u].r)/2;
        LL sum=0;
        if(l<=mid){
            sum+=querysum(lc,l,r);
        }
        if(r>=mid+1){
            sum+=querysum(rc,l,r);
        }
        return sum%mod;   
    }
    LL querysum2(LL u,LL l,LL r){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u].sum2;
        }        
        pushdown(u);
        LL mid=(tr[u].l+tr[u].r)/2;
        LL sum2=0;
        if(l<=mid){
            sum2+=querysum2(lc,l,r);
        }
        if(r>=mid+1){
            sum2+=querysum2(rc,l,r);
        }
        return sum2%mod;   
    }
    LL querymax(LL u,LL l,LL r){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u].maxn;
        }        
        pushdown(u);
        LL mid=(tr[u].l+tr[u].r)/2;
        LL maxn=-1e18;
        if(l<=mid){
            maxn=max(maxn,querymax(lc,l,r));
        }
        if(r>=mid+1){
            maxn=max(maxn,querymax(rc,l,r));
        }
        return maxn;
    }
    LL querymin(LL u,LL l,LL r){
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u].minn;
        }        
        pushdown(u);
        LL mid=(tr[u].l+tr[u].r)/2;
        LL minn=1e18;
        if(l<=mid){
            minn=min(minn,querymin(lc,l,r));
        }
        if(r>=mid+1){
            minn=min(minn,querymin(rc,l,r));
        }
        return minn;
    }    
};
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(n+1,0);
    SegTree tr1;
    tr1.init(n);
    tr1.build(1,1,n,a);   
    for(int i=1;i<=q;i++){
        LL l,r,k;
        cin>>l>>r>>k;
        tr1.rangeadd(1,l,r,k);
        LL sum=tr1.querysum(1,l,r);   
        LL sum2=tr1.querysum2(1,l,r);   
        LL pt1=sum*sum%mod;  
        cout<<(pt1-sum2+mod)%mod*qpow(2,mod-2)%mod<<'\n';
        //printf("{%lld,%lld}",sum,sum2);
        
        
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}