// 【模板】二分图最大匹配_匈牙利算法
#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
using LL =long long;
int last[N];
int match[N];
int vis[N];

int tot;
struct node{
    int v;
    int next;
}a[N];
void add(int u,int v)
{
    tot++;
    a[tot]={v,last[u]};
    last[u]=tot;
}
bool dfs(int u)
{
    for(int i=last[u];i>0;i=a[i].next)
    {
        int v=a[i].v;
        if(vis[v])
        {
            continue;
        }
        vis[v]=1;
        if(!match[v]||dfs(match[v]))
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n,m,e;
    int u,v;

    scanf("%d%d%d",&n,&m,&e);
    for(int i=1;i<=e;i++)
    {
        scanf("%d%d",&u,&v);
        add(v,u);
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i))
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}