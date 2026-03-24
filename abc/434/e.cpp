#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e6+5;
const int M=1e6+5;
int last[N];
int tot1=1;
int d[N];
int cur[N];
int s,t;
int n,m;
struct node{
    int v;
    LL c;
    int next;
}a[M*2];
void add(int u,int v,int w)
{
    tot1++;
    a[tot1]={v,w,last[u]};
    last[u]=tot1;
}
bool bfs()
{
    memset(d,0,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s]=1;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int i=last[u];i>0;i=a[i].next)
        {
            int v=a[i].v;
            if(d[v]==0&&a[i].c)
            {
                d[v]=d[u]+1;
                q.push(v);
                if(v==t)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
LL dfs(int u,LL mf)
{
    if(u==t)
    {
        return mf;
    }
    LL sum=0;
    for(int i=cur[u];i;i=a[i].next)
    {
        cur[u]=i;
        int v=a[i].v;
        if(d[v]==d[u]+1&&a[i].c)
        {
            LL f=dfs(v,min(mf,a[i].c));
            a[i].c-=f;
            a[i^1].c+=f;
            sum+=f;
            mf-=f;
            if(mf==0)
            {
                break;
            }
        }
    }
    if(sum==0)
    {
        d[u]=0;
    }
    return sum;
}

LL dinic()
{
    LL flow=0;
    while(bfs())
    {
        memcpy(cur,last,sizeof(last));
        flow+=dfs(s,1e9);
    }
    return flow;
}

void solve(){
    tot1=1;
    cin>>n;
    LL x,r;
    map<LL,int> mp;
    int tot=n+1;
    for(int i=1;i<=n;i++){
        add(n+1,i,1);
        add(i,n+1,0);
        cin>>x>>r;
        LL lt=x-r;
        LL rt=x+r;
        if(!mp.count(lt)){
            tot++;
            mp[lt]=tot;
        }
        if(!mp.count(rt)){
            tot++;
            mp[rt]=tot;
        }
        add(i,mp[lt],1);
        add(mp[lt],i,0);
        add(i,mp[rt],1);
        add(mp[rt],i,0);
    }
    s=n+1;
    t=tot+1;    
    for(int i=n+2;i<=tot;i++){
        add(i,t,1);
        add(t,i,0);        
    }
    LL ans=dinic();
    cout<<ans<<'\n';
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    
    return 0;
}


