#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define lc u<<1
#define rc u<<1|1
struct node{
    int l,r;
    LL maxn1;
    LL minn1;
    LL maxn2;
    LL minn2;
    long long add;
}tr[N*4];
long long w[N];
LL d[N];
int xi[N];
int yi[N];
void pushup(int u)
{
    tr[u].maxn1=max(tr[lc].maxn1,tr[rc].maxn1);
    tr[u].minn1=min(tr[lc].minn1,tr[rc].minn1);
    tr[u].maxn2=max(tr[lc].maxn2,tr[rc].maxn2);
    tr[u].minn2=min(tr[lc].minn2,tr[rc].minn2);    
}
void build(int u,int l,int r)
{
    tr[u]={l,r,w[l],w[l],d[l],d[l],0};
    if(l==r)
    {
        return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(u);

}
void update(int u,int l,int r,long long x,LL y)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        tr[u].maxn1=x+y;
        tr[u].minn1=x+y;
        tr[u].maxn2=x-y;
        tr[u].minn2=x-y;        
        return;
    }
    int m=tr[u].l+tr[u].r>>1;
    // pushdown(u);
    if(l<=m)
    {
        update(lc,l,r,x,y);

    }
    if(r>m)
    {
        update(rc,l,r,x,y);
    }
    pushup(u);

}
void query(int u,int l,int r,LL &max1,LL &min1,LL &max2,LL &min2)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        max1=tr[u].maxn1;
        min1=tr[u].minn1;
        max2=tr[u].maxn2;
        min2=tr[u].minn2;      
        return;  
    }
    int m=tr[u].r+tr[u].l>>1;
    // pushdown(u);
    long long sum=0;
    LL maxn1=-1e18, minn1=1e18, maxn2=-1e18, minn2=1e18;
    LL maxn3=-1e18, minn3=1e18, maxn4=-1e18, minn4=1e18;
    if(l<=m)
    {
        query(lc,l,r,maxn1,minn1,maxn2,minn2);
    }
    if(r>m)
    {
        query(rc,l,r,maxn3,minn3,maxn4,minn4);
    }
    max1=max(maxn1,maxn3);
    min1=min(minn1,minn3);
    max2=max(maxn2,maxn4);
    min2=min(minn2,minn4);

}
void solve(){
    int n,q;
    cin>>n>>q;
    
    LL a,b,x,y;

    for(int i=1;i<=n;i++){
        cin>>x>>y;
        w[i]=x+y;
        d[i]=x-y;   
    }    
    build(1,1,n);
    int op,p,l,r;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            cin>>p>>x>>y;
            update(1,p,p,x,y);
        }
        else{
            cin>>l>>r>>x>>y;
            LL maxn1=-1e9,maxn2=-1e9;
            LL minn1=1e9,minn2=1e9;            
            query(1,l,r,maxn1,minn1,maxn2,minn2);
            a=max(abs(x+y-maxn1),abs(x+y-minn1));
            b=max(abs(x-y-maxn2),abs(x-y-minn2));
            LL ans=max(a,b);
            cout<<ans<<'\n';
        }
    }

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
