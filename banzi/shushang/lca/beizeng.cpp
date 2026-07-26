// 最近公共祖先（模版）
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,s,f[N][33],dep[N];

vector <int> e[N];
bool vis[N];
void dfs(int u,int fa)
{
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(auto v:e[u])
    {
        if(v!=fa)
        {
            dfs(v,u);
        }
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])
    {
        swap(u,v);
    }
    for(int i=22;i>=0;i--)
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
    for(int i=22;i>=0;i--)
    {
        if(f[u][i]!=f[v][i])
        {
            u=f[u][i];
            v=f[v][i];

        }
    }
    return f[u][0];
}
void init()
{
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            f[i][j]=f[f[i][j-1]][j-1];

        }
    }
}
int main()
{
    int x,y;
    int a,b;
    scanf("%d%d%d",&n,&m,&s);

    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(s,0);
    init();
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}