#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
using LL=long long;
vector<int> e[N];
int val[N];
int dfn[N];
int siz[N];
int tot;
int f[N][30];
int dep[N];
int id,n,m;
int inv[N];
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
    if(tr[u].add!=-1){
        tr[lc].minn=tr[u].minn;
        tr[rc].minn=tr[u].minn;
        tr[lc].add=tr[u].add;
        tr[rc].add=tr[u].add;
        tr[u].add=-1;        
    }

}
void build(int u,int l,int r)
{
    tr[u]={l,r,inv[l],-1};
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
void dfs(int u,int fa){
    siz[u]=1;
    tot++;
    dfn[u]=tot;
    inv[tot]=val[u];
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(int i=1;i<=20;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])
    {
        swap(u,v);
    }
    for(int i=20;i>=0;i--)
    {
        if(dep[f[u][i]]>=dep[v])
        {
            u=f[u][i];

        }
    }
    if(u==v)
    {
        return u;
    }
    for(int i=20;i>=0;i--)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];
        }
    }
    return f[u][0];
}
void solve(){
    memset(f,0,sizeof(f));
    tot=0;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    cin>>id;
    dfs(id,id);
    build(1,1,n);
    int op;
    int x,y,w,q;
    int r;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>id;
        }else if(op==2){
            cin>>x>>y>>w;
            int z=lca(x,y);
            int x1=z,y1=z;
            for(auto v:e[z]){
                if(dep[v]<dep[z]){
                    continue;
                }
                if(dfn[x]>=dfn[v]&&dfn[x]<=dfn[v]+siz[v]-1){
                    x1=v;
                }
                if(dfn[y]>=dfn[v]&&dfn[y]<=dfn[v]+siz[v]-1){
                    y1=v;
                }
            }
            //printf("{%d %d %d}\n",x1,y1,z);        
            update(1,dfn[x1],dfn[x],w);
            update(1,dfn[y1],dfn[y],w);
            update(1,dep[z],dep[z],w);
            //update(1,)
        }else{
            cin>>q;
            LL ans;
            if(dep[q]<dep[id]){
                int l=dfn[q]-1;
                int r=dfn[q]+siz[q];  
                //printf("{ fist %d %d}",l,r);        
                ans=min(query(1,1,l),query(1,r,n));

            }else if(dep[q]==dep[id]){
                ans=query(1,1,n);
            }else{
                int l=dfn[q];
                int r=dfn[q]+siz[q]-1;
                //printf("{ last %d %d}",l,r);        
                ans=query(1,l,r);
            }
            cout<<ans<<'\n';
        }
    }
}
int main(){
    solve();
    return 0;
}