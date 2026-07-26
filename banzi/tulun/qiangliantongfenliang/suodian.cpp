// 缩点模板
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e5+5;
int n,m;
int u,v;
int dfn[N];
int low[N];
int scc[N];
int siz[N];
int din[N];
int dout[N];

bool instk[N];
bool used[N];
vector<int>e[N];
vector<int>w[N];
stack<int>stk;

int tot;
int cnt;

int nx[N];
void tarjan(int x)
{
    int y;
    tot++;
    low[x]=dfn[x]=tot;
    // printf("(%d,%d,%d)",low[x],dfn[x],x);
    stk.push(x);
    instk[x]=true;
    for(auto y:e[x])
    {
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(instk[y])
        {
            low[x]=min(low[x],dfn[y]);
        }
    }
    // printf("[%d,%d,%d]\n",low[x],dfn[x],x);
    if(low[x]==dfn[x])
    {
        // printf("{%d}",x);
        int y;
        cnt++;
        do{
            y=stk.top();
            stk.pop();
            instk[y]=false;
            scc[y]=cnt;
            if(!used[y])
            {
                siz[cnt]+=nx[y];
                used[y]=true;
            }
        }while(x!=y);
    }
}
int maxn;
int dist[N];
int dp[N];
int main()
{
    tot=0;
    cnt=0;
    memset(dfn,0,sizeof(dfn));
    memset(instk,false,sizeof(instk));
    memset(used,false,sizeof(used));
    memset(siz,0,sizeof(siz));
    memset(din,0,sizeof(din));
    memset(dout,0,sizeof(dout));

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&nx[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
          
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++)
    {

        for(auto j:e[i])
        {
            if(scc[i]!=scc[j])
            {
                w[scc[i]].push_back(scc[j]);
            }
        }
    }
    for(int i=cnt;i;i--)
    {
        if(dp[i]==0)
        {
            dp[i]=siz[i];
        }
        for(auto j:w[i])
        {
            dp[j]=max(dp[j],dp[i]+siz[j]);
        }
    }
    int maxnn=0;
    for(int i=1;i<=cnt;i++)
    {
        maxnn=max(maxnn,dp[i]);
    }
    printf("%d\n",maxnn);

    return 0;
}