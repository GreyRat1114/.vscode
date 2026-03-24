#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using LL=long long;
const LL mod=998244353;
#define lc u<<1
#define rc u<<1|1
struct node{
    int l,r;
    long long sum;
    long long add;
    LL c;
}tr[N*4];
LL a[N];
int n;
void pushup(int u)
{
    tr[u].sum=(tr[lc].sum+tr[rc].sum)%mod;
    tr[u].c=(tr[lc].c+tr[rc].c)%mod;
}
void pushdown(int u)
{
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
void update(int u,int l,int r,long long k,LL c)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        tr[u].sum=(tr[u].sum+(tr[u].r-tr[u].l+1)*k)%mod;
        tr[u].c=(tr[u].c+c)%mod;
        return;
    }
    int m=tr[u].l+tr[u].r>>1;
    //pushdown(u);

    if(l<=m)
    {
        update(lc,l,r,k,c);

    }
    if(r>m)
    {
        update(rc,l,r,k,c);
    }
    pushup(u);

}
long long query(int u,int l,int r,LL &c)
{
    //printf("(%d,%d,%lld)\n",tr[u].l,tr[u].r,c);
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        c=tr[u].c;
        return tr[u].sum;
    }

    int m=tr[u].r+tr[u].l>>1;
    pushdown(u);
    long long sum=0;
    LL c1=0,c2=0;
    if(l<=m)
    {
        sum=(sum+query(lc,l,r,c1))%mod;
    }
    if(r>m)
    {
        sum=(sum+query(rc,l,r,c2))%mod;
    }
    c=(c1+c2)%mod;
    return sum;
}
int inv[N];
int tot;
LL check(LL x){
    int l=1;
    int r=tot;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(inv[mid]<x){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("{%d}",ans);
    return ans;
}
LL b[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    int tot=unique(a+1,a+n+1)-a-1; 
    //printf("{%d}",tot);   
    map<LL,int> mp;
    for(int i=1;i<=tot;i++){
        printf("{%lld}",a[i]);
        inv[i]=a[i];
        mp[a[i]]=i;
    }
    build(1,1,tot);
    LL ans=0;
    for(int i=1;i<=n;i++){
        //printf("<%lld>",b[i]);
        int p=check(b[i]);
        LL pt1=0;
        LL c=0;
        if(p==0){
            c=1;
            pt1=b[i];
            //printf("(%d,%lld)",i,pt1);
            update(1,mp[b[i]],mp[b[i]],pt1,c);
            ans=(pt1+ans)%mod;            
        }else{
            pt1=query(1,1,p,c);
            //printf("<%lld>",c);
            //cout<<pt1<<' ';
            c++;
            pt1=(pt1+(c*b[i])%mod)%mod;
            update(1,mp[b[i]],mp[b[i]],pt1,c);
            ans=(pt1+ans)%mod;            
        }
        printf("{%d,%lld,%lld,%lld}\n",i,pt1,c,ans);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);    
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}