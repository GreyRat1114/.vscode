#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const int M=2e5+5;
LL last[N];
LL tot=1;
LL d[N];
LL cur[N];
LL s,t;
LL n,m;

struct node{
    LL v;
    LL c;
    LL next;
}a[M*2];
void add(int u,int v,int w)
{
    tot++;
    a[tot]={v,w,last[u]};
    last[u]=tot;
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

    tot=1;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(last,0,sizeof(last));
    memset(cur,0,sizeof(cur));
    memset(d,0,sizeof(d));
    LL x,y,dd;
    map<LL,LL> mpx0,mpx2,mpy1,mpy3;
    //vector<vector<LL>> a(n+1,vector<LL>(5,0));
    for(int i=1;i<=n;i++){
        cin>>x>>y>>dd;
        //a[i][0]=x;
        //a[i][1]=y;
        //a[i][2]=dd;
        if(dd==0){
            mpx0[x]=max(mpx0[x],y);
        }else if(dd==1){
            mpy1[y]=max(mpy1[y],x);
        }else if(dd==2){
            if(!mpx2.count(x)){
                mpx2[x]=y;
            }else{
                mpx2[x]=min(mpx2[x],y);
            }
            
        }else{
            if(!mpy3.count(y)){
                mpy3[y]=x;
            }else{            
                mpy3[y]=min(mpy3[y],x);
            }
        }
    }
    LL cnt=0;
    LL c1=0,c2=0;
    c1=mpx0.size()+mpx2.size();
    c2=mpy1.size()+mpy3.size();
    s=0;
    t=c1+c2+1;
    for(int i=1;i<=c1;i++){
        add(s,i,1);
        add(i,s,0);
    }
    for(int i=c1+1;i<=c2+c1;i++){
        add(i,t,1);
        add(t,i,0);
    }
    LL n1=0,n2=c1;
    for(auto x:mpx0){
        n1++;
        n2=c1;
        for(auto y:mpy1){
            n2++;
            if(y.first>=x.second&&y.second<=x.first){
                add(n1,n2,1);
                add(n2,n1,0);
            }
        }
        for(auto y:mpy3){
            n2++;
            if(y.first>=x.second&&y.second>=x.first){
                add(n1,n2,1);
                add(n2,n1,0);
            }
        }
    }
    for(auto x:mpx2){
        n1++;
        n2=c1;
        for(auto y:mpy1){
            n2++;
            if(y.first<=x.second&&y.second<=x.first){
                add(n1,n2,1);
                add(n2,n1,0);
            }
        }
        for(auto y:mpy3){
            n2++;
            if(y.first<=x.second&&y.second>=x.first){
                add(n1,n2,1);
                add(n2,n1,0);
            }
        }
    }
    LL ans=c1+c2-dinic();
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}