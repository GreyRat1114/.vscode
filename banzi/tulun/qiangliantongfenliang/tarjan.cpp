// The Cow Prom S_Tarjan模板
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const int M=5e4+5;
int n,m;
int nx[N];
int dfn[N];
int low[N];
int tot;
bool instk[N];
int scc[N];
int siz[N];
int cnt;
bool used[N];
stack<int> stk;
vector<int> e[N];
void tarjan(int x)
{
    int y;
    tot++;
    dfn[x]=low[x]=tot;
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
    if(low[x]==dfn[x])
    {
        int y;
        cnt++;
        do{
            y=stk.top();
            stk.pop();
            instk[y]=false;
            scc[y]=cnt;
            siz[cnt]++;
        }while(x!=y);
    }
}
int main()
{
    int u,v;
    int a,b;
    tot=0;
    cnt=0;
    memset(instk,false,sizeof(instk));
    memset(dfn,0,sizeof(dfn));  
    memset(siz,0,sizeof(siz));  
    memset(scc,0,sizeof(scc));  
    memset(used,false,sizeof(used));  
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    tarjan(1);
    int sum=0;
    for(int i=1;i<=cnt;i++)
    {
        if(siz[i]>1)
        {
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}