#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int n,q;
vector<int> e[N];
int tot;
int dfn[N];
int siz[N];
int inv[N];
set<int> st[N];

#define lc u<<1
#define rc u<<1|1
#define it set<int>::iterator
struct node{
    int l,r;
    long long sum;
    long long add;
}tr[N*4];
long long w[N];
void pushup(int u)
{
    tr[u].sum=tr[lc].sum+tr[rc].sum;
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
    tr[u]={l,r,w[l],0};
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
void dfs(int u,int fa){
    tot++;
    dfn[u]=tot;
    inv[tot]=u;
    siz[u]=1;
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
void solve(){
    cin>>n>>q;
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    tot=0;
    dfs(1,1);
    int x,op,c;
    build(1,1,n);

    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            cin>>x>>c;
            int l=dfn[x];
            int r=dfn[x]+siz[x]-1;
            it t2=st[c].upper_bound(dfn[x]);
            if(t2!=st[c].begin()){
                t2--;
                if(dfn[x]>=*t2&&dfn[x]<=*t2+siz[inv[*t2]]-1){
                    continue;
                }
            }
            it t1=st[c].lower_bound(dfn[x]);
            while(t1!=st[c].end()&&*t1<=r){
                int now=*t1;
                update(1,now,now+siz[inv[now]]-1,-1);
                st[c].erase(t1);
                t1=st[c].lower_bound(dfn[x]);
            }
            update(1,l,r,1);
            st[c].insert(dfn[x]);

        }else{
            cin>>x;
            LL ans=query(1,dfn[x],dfn[x]+siz[x]-1);
            cout<<ans<<'\n';
        }
        
    }
}
int main(){
    solve();
    return 0;
}