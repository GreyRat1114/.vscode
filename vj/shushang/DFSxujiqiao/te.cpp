#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int id,n,m;
int val[N];
#define lc (u<<1)
#define rc (u<<1|1)
#define it set<int>::iterator
const LL M=1e18;
struct node{
    int l,r;
    LL minn;
    long long add;
}tr[N*4];
void pushup(int u)
{
    tr[u].minn=min(tr[lc].minn,tr[rc].minn);
}
void pushdown(int u)
{
    if(tr[u].add){
        tr[lc].minn=tr[u].minn;
        tr[rc].minn=tr[u].minn;
        tr[lc].add=tr[u].add;
        tr[rc].add=tr[u].add;
        tr[u].add=0;        
    }

}
void build(int u,int l,int r)
{
    tr[u]={l,r,val[l],0};
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
        tr[u].minn=k;
        tr[u].add=k;
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
        return tr[u].minn;
    }
    int m=tr[u].r+tr[u].l>>1;
    pushdown(u);
    long long minn=M;
    if(l<=m)
    {
        minn=min(minn,query(lc,l,r));
    }
    if(r>m)
    {
        minn=min(minn,query(rc,l,r));
    }
    return minn;
}
void solve(){
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r,w;
            cin>>l>>r>>w;
            update(1,l,r,w);
        }else{
            int l,r;
            cin>>l>>r;
            LL ans=query(1,l,r);
            cout<<ans<<'\n';
        }
    }
}
int main(){
    solve();
    return 0;
}