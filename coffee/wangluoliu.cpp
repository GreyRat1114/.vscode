// A - 搭配飞行员
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e3+5;
// struct node{
//     int v,w,next;
// }a[N];
// int d[N];
// int last[N];
// int cur[N];
// int tot;
// int s,t;
// int n,m;

// void add(int u,int v,int w)
// {
//     tot++;
//     a[tot]={v,w,last[u]};
//     last[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));
//     queue<int> q;
//     q.push(s);
//     d[s]=1;
//     int u,v,c;
//     while(!q.empty())
//     {
        
//         u=q.front();
//         // printf("{%d}",u);
//         q.pop();
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             v=a[i].v;
//             c=a[i].w;
//             if(!d[v]&&c)
//             {
//                 d[v]=d[u]+1;
//                 q.push(v);
//                 if(t==v)
//                 {
//                     // printf("()");
//                     return true;
//                 }
//             }
//         }

//     }
//     return false;
// }
// int dfs(int u,int mf)
// {
    
//     if(t==u)
//     {
//         return mf;
//     }
//     int sum=0;
//     for(int i=cur[u];i>=1;i=a[i].next)
//     {
//         cur[u]=i;
//         int v=a[i].v;
//         int c=a[i].w;

//         if(d[v]=d[u]+1&&c)
//         {
//             int f=dfs(v,min(mf,c));
//             sum+=f;
//             a[i].w-=f;
//             a[i^1].w+=f;
//             mf-=f;
//             if(mf==0)
//             {
//                 break;
//             }
//         }
//     }
//     if(sum==0)
//     {
//         d[u]=0;

//     }
//     return sum;

// }
// int dinic()
// {
//     int flow=0;
//     while(bfs())
//     {
//         // printf("__");
//         memcpy(cur,last,sizeof(last));
//         flow+=dfs(s,1e9);
//     }
//     return flow;
// }
// int zheng[N];
// int fu[N];
// void solve()
// {
//     tot=1;
//     memset(last,0,sizeof(last));

//     cin>>n>>m;
//     int u,v;
//     while(scanf("%d%d",&u,&v)!=EOF)
//     {

//         add(u,v,1);
//         add(v,u,0);
//     }
//     s=0;
//     t=200;
//     for(int i=1;i<=m;i++)
//     {
//         add(s,i,1);
//         add(i,s,0);
//     }
//     for(int i=m+1;i<=n;i++)
//     {
//         add(i,t,1);
//         add(t,i,0);
//     }
//     int ans=dinic();
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// B - 太空飞行计划
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=105;
// int last[N];
// int d[N];
// int cur[N];
// int tot;
// int s,t;

// struct node{
//     int v,c,next;
// }a[N];
// void add(int u,int v,int c)
// {
//     tot++;
//     a[tot]={v,c,last[u]};
//     last[u]=tot;
// }
// bool bfs()
// {
//     queue<int> q;
//     q.push(s);
//     d[s]=1;
//     int u,v,c;

//     while(!q.empty())
//     {
//         u=q.front();
//         q.pop();
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             v=a[i].v;
//             c=a[i].c;
//             if(!d[v]&&c)
//             {
//                 d[v]=d[u]+1;
//                 q.push(v);
//                 if(v==t)
//                 {
//                     return true;
//                 }
//             }

//         }
//     }
//     return false;
// }
// int dfs(int u,int mf)
// {
//     if(u==t)
//     {

//         return mf;
//     }
//     int sum=0;
//     int v,c;

//     for(int i=cur[u];i>=1;i=a[i].next)
//     {
//         v=a[i].v;
//         c=a[i].c;
//         if(d[v]==d[u]+1&&c)
//         {
//             int f=dfs(v,min(mf,c));
//             sum+=f;
//             a[i].c-=f;
//             a[i^1].c+=f;
//             mf-=f;
//             if(mf==0)
//             {
//                 break;
//             }
//         }
//     }
//     if(sum==0)
//     {
//         d[u]=0;

//     }
//     return sum;
// }
// int dinic()
// {
//     int flow=0;
//     while(bfs())
//     {
//         memcpy(cur,last,sizeof(last));
//         flow+=dfs(s,1e9);

//     }
//     return flow;

// }
// string str;
// void solve()
// {
//     tot=1;
//     memset(last,0,sizeof(last));

//     int m,n;
//     cin>>m>>n;
//     int x,y;
//     for(int i=1;i<=m;i++)
//     {
//         getchar();
//         getline(cin,str);

//         istringstream iss(str);
//         cin>>x;
//         add(0,i,x);
//         add(i,0,0);
//         while(iss>>y)
//         {
//             add
//         }

//     }
    
// }
// int main()
// {
//     solve();
//     return 0;
// }


// E - 圆桌聚餐
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e3+5;
// const int M=1e6+5;
// int last[N];
// int d[N];
// int cur[N];
// int tot;
// int s,t;
// struct node{
//     int v;
//     LL c;
//     int next;
// }a[M];
// void add(int u,int v,LL c)
// {
//     tot++;
//     a[tot]={v,c,last[u]};
//     last[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));
//     queue<int> q;
//     q.push(s);
//     d[s]=1;
//     int u,v;
//     LL c;

//     while(!q.empty())
//     {
//         u=q.front();
//         q.pop();
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             v=a[i].v;
//             c=a[i].c;
//             if(!d[v]&&c)
//             {
//                 d[v]=d[u]+1;
//                 q.push(v);
//                 if(v==t)
//                 {
//                     return true;
//                 }
//             }

//         }
//     }
//     return false;
// }
// LL dfs(int u,LL mf)
// {
//     if(u==t)
//     {

//         return mf;
//     }
//     LL sum=0;
//     int v;
//     LL c;

//     for(int i=cur[u];i>=1;i=a[i].next)
//     {
//         v=a[i].v;
//         c=a[i].c;
//         if(d[v]==d[u]+1&&c)
//         {
//             LL f=dfs(v,min(mf,c));
//             sum+=f;
//             a[i].c-=f;
//             a[i^1].c+=f;
//             mf-=f;
//             if(mf==0)
//             {
//                 break;
//             }
//         }
//     }
//     if(sum==0)
//     {
//         d[u]=0;

//     }
//     return sum;
// }
// LL dinic()
// {
//     LL flow=0;
//     while(bfs())
//     {
//         memcpy(cur,last,sizeof(last));
//         flow+=dfs(s,1e9);

//     }
//     return flow;

// }
// string str;
// int mx[N];
// int nx[N];
// void solve()
// {
//     tot=1;
//     memset(last,0,sizeof(last));
//     LL sum=0;
//     int m,n;
//     cin>>m>>n;
//     LL x,y;
//     s=0;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>x;
//         sum+=x;
//         mx[i]=x;
//         add(s,i,x);
//         add(i,s,0);

//     }
//     t=n+m+10;
//     for(int i=m+1;i<=n+m;i++)
//     {
//         cin>>x;
//         nx[i]=x;
//         add(i,t,x);
//         add(t,i,0);
//     }
//     // for(int i=1;i<=m;i++)
//     // {
//     //     printf("{%d}",mx[i]);
//     // }
//     // for(int i=m+1;i<=m+n;i++)
//     // {
//     //     printf("{%d}",nx[i]);
//     // }
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=m+1;j<=n+m;j++)
//         {
//             add(i,j,1);
//             add(j,i,0);
//         }
//     }
//     LL ans=dinic();
//     // cout<<ans<<'\n';
//     if(ans==sum)
//     {
//         cout<<"1"<<'\n';   
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=last[i];j>=1;j=a[j].next)
//             {
//                 int v=a[j].v;
//                 LL c=a[j].c;
//                 if(v==s||c==1)
//                 {
//                     continue;
//                 }
//                 cout<<v-m<<' ';
//             }
//             cout<<'\n';
//         }    
//     }
//     else
//     {
//         cout<<"0"<<'\n';
//     }

// }
// int main()
// {
//     solve();
//     return 0;
// }



// C - 最小路径覆盖
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e3+5;
// const int M=1e6+5;
// int last[N];
// int d[N];
// int cur[N];
// int tot;
// int s,t;
// struct node{
//     int v;
//     LL c;
//     int next;
// }a[M];
// void add(int u,int v,LL c)
// {
//     tot++;
//     a[tot]={v,c,last[u]};
//     last[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));
//     queue<int> q;
//     q.push(s);
//     d[s]=1;
//     int u,v;
//     LL c;

//     while(!q.empty())
//     {
//         u=q.front();
//         q.pop();
//         LL sum=0;
//         // for(int i=last[u];i>=1;i=a[i].next)
//         // {
//         //     v=a[i].v;
//         //     c=a[i].c;
//         //     if(!d[v]&&c)
//         //     {
//         //         sum=1;
//         //     }
//         // }
//         // if(sum==0)
//         // {
//         //     return true;
//         // }        
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             v=a[i].v;
//             c=a[i].c;
//             if(!d[v]&&c)
//             {
//                 d[v]=d[u]+1;
//                 q.push(v);

//                 if(v==t)
//                 {
//                     return true;
//                 }
//             }

//         }

//     }
//     return true;
// }
// LL dfs(int u,LL mf)
// {
//     // if(u==t)
//     // {

//     //     return mf;
//     // }
//     LL sum=0;
//     int v;
//     LL c;

//     for(int i=cur[u];i>=1;i=a[i].next)
//     {
//         v=a[i].v;
//         c=a[i].c;
//         if(d[v]==d[u]+1&&c)
//         {
//             LL f=dfs(v,min(mf,c));
//             sum+=f;
//             a[i].c-=f;
//             a[i^1].c+=f;
//             mf-=f;
//             if(mf==0)
//             {
//                 break;
//             }
//         }
//     }
//     if(sum==0)
//     {
//         d[u]=0;

//     }
//     return sum;
// }
// LL dinic()
// {
//     LL flow=0;
//     while(bfs())
//     {
//         memcpy(cur,last,sizeof(last));
//         flow+=dfs(s,1e9);

//     }
//     return flow;

// }
// string str;
// int mx[N];
// int nx[N];
// void solve()
// {
//     tot=1;
//     memset(last,0,sizeof(last));
//     int n,m;
//     cin>>n>>m;
//     int u,v;
//     s=0;
//     t=n+1;    
//     for(int i=1;i<=m;i++)
//     {
//         cin>>u>>v;
//         add(s,u,1);
//         add(u,v,1);
//         add(v,t,1);
//         add(u,s,0);
//         add(v,u,0);
//         add(t,v,0);        
//     }
//     LL ans=dinic();
//     cout<<ans<<'\n';

// }
// int main()
// {
//     solve();
//     return 0;
// }



// 最小路径覆盖
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// int last[N];
// int d[N];
// int tot;
// int cur[N];
// int s,t;
// int n,m;
// struct node{
//     int v;
//     LL c;
//     int next;
// }a[N];
// int nxt[N];
// void add(int u,int v,LL c)
// {
//     tot++;
//     a[tot]={v,c,last[u]};
//     last[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));

//     queue<int> q;
//     int u,v;
//     LL c;
//     d[s]=1;
//     q.push(s);
//     while(!q.empty())
//     {
        
//         u=q.front();
//         // printf("{%d}",u);
//         q.pop();
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             v=a[i].v;
//             c=a[i].c;
//             if(!d[v]&&c)
//             {
//                 q.push(v);
//                 d[v]=d[u]+1;
//                 if(v==t)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }
// LL dfs(int u,LL mf)
// {
    
//     if(u==t)
//     {
//         return mf;
//     }
//     LL sum=0;
//     int v;
//     LL c;
//     for(int i=cur[u];i>=1;i=a[i].next)
//     {
//         v=a[i].v;
//         c=a[i].c;
//         if(d[v]==d[u]+1&&c)
//         {
//             LL f=dfs(v,min(c,mf));
//             sum+=f;
//             a[i].c-=f;
//             a[i^1].c+=f;
//             mf-=f;
//             if(f)
//             {
//                 nxt[u]=v-n;
//             }
//             if(mf==0)
//             {
//                 break;
//             }
//         }
//     }
//     if(sum==0)
//     {
//         d[u]=0;
//     }
//     return sum;
// }
// LL dinic()
// {
//     LL flow=0;
//     while(bfs())
//     {
//         memcpy(cur,last,sizeof(last));
//         flow+=dfs(s,1e18);

//     }
//     return flow;
// }
// void solve()
// {
//     memset(last,0,sizeof(last));
//     memset(nxt,0,sizeof(nxt));
//     tot=1;
//     cin>>n>>m;
//     s=0;
//     t=2*n+1;
//     int u,v;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>u>>v;
//         add(u,v+n,1);
//         add(v+n,u,0);
        
//     }
//     for(int i=1;i<=n;i++)
//     {
//         add(s,i,1);
//         add(i,s,0);
//         add(i+n,t,1);
//         add(t,i+n,0);

//     }
//     LL x=dinic();
//     LL y=n-x;

//     for(int i=last[t];i>=1;i=a[i].next)
//     {
//         v=a[i].v-n;
//         LL c=a[i^1].c;
//         if(c==1)
//         {
//             int p=v;
//             while(p)
//             {
//                 cout<<p<<' ';
//                 p=nxt[p];
//             }
//             cout<<'\n';
//         }
//     }
//     cout<<y<<'\n';
// }
// int main()
// {
//     solve();

//     return 0;
// }


// J - 软件补丁 
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// int last[N];
// int d[N];
// int tot;
// int cur[N];
// int s,t;
// int n,m;
// struct node{
//     int v;
//     LL c;
//     int next;
// }a[N];
// int nxt[N];
// void add(int u,int v,LL c)
// {
//     tot++;
//     a[tot]={v,c,last[u]};
//     last[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));

//     queue<int> q;
//     int u,v;
//     LL c;
//     d[s]=1;
//     q.push(s);
//     while(!q.empty())
//     {
        
//         u=q.front();
//         // printf("{%d}",u);
//         q.pop();
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             v=a[i].v;
//             c=a[i].c;
//             if(!d[v]&&c)
//             {
//                 q.push(v);
//                 d[v]=d[u]+1;
//                 if(v==t)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }
// LL dfs(int u,LL mf)
// {
    
//     if(u==t)
//     {
//         return mf;
//     }
//     LL sum=0;
//     int v;
//     LL c;
//     for(int i=cur[u];i>=1;i=a[i].next)
//     {
//         v=a[i].v;
//         c=a[i].c;
//         if(d[v]==d[u]+1&&c)
//         {
//             LL f=dfs(v,min(c,mf));
//             sum+=f;
//             a[i].c-=f;
//             a[i^1].c+=f;
//             mf-=f;
//             if(mf==0)
//             {
//                 break;
//             }
//         }
//     }
//     if(sum==0)
//     {
//         d[u]=0;
//     }
//     return sum;
// }
// LL dinic()
// {
//     LL flow=0;
//     while(bfs())
//     {
//         memcpy(cur,last,sizeof(last));
//         flow+=dfs(s,1e18);

//     }
//     return flow;
// }
// void solve()
// {
//     memset(last,0,sizeof(last));
//     memset(nxt,0,sizeof(nxt));
//     tot=1;
//     cin>>n>>m;

// }
// int main()
// {
//     solve();

//     return 0;
// }



// L - 运输问题
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// int last[N];
// int d[N];
// int d1[N];

// bool vis[N];
// LL mf[N];
// int tot;
// int pre[N];
// int s,t;
// int n,m;
// LL flow;
// LL cost;

// struct node{
//     int v;
//     LL c,w;
//     int next;
// }a[N];
// int nxt[N];
// void add(int u,int v,LL c,LL w)
// {
//     tot++;
//     a[tot]={v,c,w,last[u]};
//     last[u]=tot;
// }
// bool spfa()
// {
//     memset(d,0x3f,sizeof(d));


//     memset(mf,0,sizeof(mf));
//     queue<int> q;
//     q.push(s);
//     d[s]=0;
//     mf[s]=1e18;
//     vis[s]=true;
//     while(q.size())
//     {
//         int u=q.front();
//         q.pop();
//         vis[u]=false;
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             int v=a[i].v;
//             LL c=a[i].c;
//             LL w=a[i].w;
//             if(d[u]+w<d[v]&&c)
//             {
//                 d[v]=d[u]+w;
//                 mf[v]=min(mf[u],c);
//                 pre[v]=i;
//                 if(!vis[v])
//                 {
//                     q.push(v);
//                     vis[v]=1;

//                 }
//             }
//         }
//     }
//     return mf[t]>0;
// }

// void EK()
// {

//     while(spfa())
//     {
//         for(int v=t;v!=s;)
//         {
//             int i=pre[v];
//             a[i].c-=mf[t];
//             a[i^1].c+=mf[t];
//             v=a[i^1].v;

//         }
//         flow+=mf[t];
//         cost+=mf[t]*d[t];
        
//     }
// }

// LL ax[105];
// LL bx[105];
// LL ww[105][105];
// void solve1()
// {
//     memset(last,0,sizeof(last));
//     memset(nxt,0,sizeof(nxt));
//     memset(vis,false,sizeof(vis));
//     memset(pre,0,sizeof(pre));
//     flow=0;
//     cost=0;

//     tot=1;
//     cin>>m>>n;
//     s=0;
//     t=n+m+1;    
//     for(int i=1;i<=m;i++)
//     {
//         cin>>ax[i];
//         add(s,i,ax[i],0);
//         add(i,s,0,0);

//     }
//     for(int i=m+1;i<=m+n;i++)
//     {
//         cin>>bx[i];
//         add(i,t,bx[i],0);
//         add(t,i,0,0);

//     }


//     for(int i=1;i<=m;i++)
//     {
//         for(int j=m+1;j<=m+n;j++)
//         {
//             cin>>ww[i][j];
//             add(i,j,1e16,ww[i][j]);
//             add(j,i,0,-ww[i][j]);

//         }
//     }
//     EK();
//     LL c1=cost;
//     cout<<c1<<'\n';
    
// }
// void solve2()
// {
//     memset(a,0,sizeof(a));
//     memset(last,0,sizeof(last));
//     memset(nxt,0,sizeof(nxt));
//     memset(vis,false,sizeof(vis));
//     memset(pre,0,sizeof(pre));
//     flow=0;
//     cost=0;
//     tot=1;
//     s=0;
//     t=n+m+1;    
//     for(int i=1;i<=m;i++)
//     {
//         add(s,i,ax[i],0);
//         add(i,s,0,0);
//     }
//     for(int i=m+1;i<=m+n;i++)
//     {
//         add(i,t,bx[i],0);
//         add(t,i,0,0);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=m+1;j<=m+n;j++)
//         {
//             add(i,j,1e18,-ww[i][j]);
//             add(j,i,0,ww[i][j]);

//         }
//     }    
//     EK();
//     cout<<-cost<<'\n';
// }
// int main()
// {
//     solve1();
//     solve2();
//     return 0;
// }



// M - 分配问题
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// int last[N];
// int d[N];
// int d1[N];

// bool vis[N];
// LL mf[N];
// int tot;
// int pre[N];
// int s,t;
// int n,m;
// LL flow;
// LL cost;
// struct node{
//     int v;
//     LL c,w;
//     int next;
// }a[N];
// void add(int u,int v,LL c,LL w)
// {
//     tot++;
//     a[tot]={v,c,w,last[u]};
//     last[u]=tot;
// }
// bool spfa()
// {
//     memset(d,0x3f,sizeof(d));
//     memset(mf,0,sizeof(mf));
//     queue<int> q;
//     q.push(s);
//     d[s]=0;
//     mf[s]=1e18;
//     vis[s]=true;
//     while(q.size())
//     {
//         int u=q.front();
//         q.pop();
//         vis[u]=false;
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             int v=a[i].v;
//             LL c=a[i].c;
//             LL w=a[i].w;
//             if(d[u]+w<d[v]&&c)
//             {
//                 d[v]=d[u]+w;
//                 mf[v]=min(mf[u],c);
//                 pre[v]=i;
//                 if(!vis[v])
//                 {
//                     q.push(v);
//                     vis[v]=1;

//                 }
//             }
//         }
//     }
//     return mf[t]>0;
// }

// void EK()
// {

//     while(spfa())
//     {
//         for(int v=t;v!=s;)
//         {
//             int i=pre[v];
//             a[i].c-=mf[t];
//             a[i^1].c+=mf[t];
//             v=a[i^1].v;

//         }
//         flow+=mf[t];
//         cost+=mf[t]*d[t];
        
//     }
// }
// LL ww[105][105];
// void solve()
// {
//     memset(last,0,sizeof(last));
//     memset(vis,false,sizeof(vis));
//     memset(pre,0,sizeof(pre));
//     flow=0;
//     cost=0;
//     tot=1;
//     cin>>n;
//     int u,v;
//     s=0;
//     t=2*n+1;
//     for(int i=1;i<=n;i++)
//     {
//         add(s,i,1,0);
//         add(i,s,0,0);
//     }
//     for(int i=n+1;i<=n+n;i++)
//     {
//         add(i,t,1,0);
//         add(t,i,0,0);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=n+1;j<=n+n;j++)
//         {
//             cin>>ww[i][j];
//             add(i,j,1,ww[i][j]);
//             add(j,i,0,-ww[i][j]);
//         }
//     }
//     EK();
//     cout<<cost<<'\n';
//     memset(last,0,sizeof(last));
//     memset(vis,false,sizeof(vis));
//     memset(pre,0,sizeof(pre));
//     cost=0;
//     flow=0;
//     tot=1;
//     for(int i=1;i<=n;i++)
//     {
//         add(s,i,1,0);
//         add(i,s,0,0);
//     }
//     for(int i=n+1;i<=n+n;i++)
//     {
//         add(i,t,1,0);
//         add(t,i,0,0);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=n+1;j<=n+n;j++)
//         {
//             add(i,j,1,-ww[i][j]);
//             add(j,i,0,ww[i][j]);
//         }
//     }
//     EK();
//     cout<<-cost<<'\n';
// }

// int main()
// {
//     solve();
//     return 0;
// }



// N - 负载平衡
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// int last[N];
// int d[N];
// bool vis[N];
// LL mf[N];
// int tot;
// int pre[N];
// int s,t;
// int n,m;
// LL flow;
// LL cost;
// struct node{
//     int v;
//     LL c,w;
//     int next;
// }a[N];
// void add(int u,int v,LL c,LL w)
// {
//     tot++;
//     a[tot]={v,c,w,last[u]};
//     last[u]=tot;
// }
// bool spfa()
// {
//     memset(d,0x3f,sizeof(d));
//     memset(mf,0,sizeof(mf));
//     queue<int> q;
//     q.push(s);
//     d[s]=0;
//     mf[s]=1e18;
//     vis[s]=true;
//     while(q.size())
//     {
//         int u=q.front();
//         // printf("{%d}",u);
//         q.pop();
//         vis[u]=false;
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             int v=a[i].v;
//             LL c=a[i].c;
//             LL w=a[i].w;
//             if(d[u]+w<d[v]&&c)
//             {
//                 d[v]=d[u]+w;
//                 mf[v]=min(mf[u],c);
//                 pre[v]=i;
//                 if(!vis[v])
//                 {
//                     q.push(v);
//                     vis[v]=1;

//                 }
//             }
//         }
//     }
//     return mf[t]>0;
// }

// void EK()
// {

//     while(spfa())
//     {
//         // printf("()");
//         for(int v=t;v!=s;)
//         {
//             int i=pre[v];
//             a[i].c-=mf[t];
//             a[i^1].c+=mf[t];
//             v=a[i^1].v;

//         }
//         flow+=mf[t];
//         cost+=mf[t]*d[t];

//     }
// }
// LL ww[105][105];
// LL ax[N];
// void solve()
// {
//     memset(last,0,sizeof(last));
//     memset(vis,false,sizeof(vis));
//     memset(pre,0,sizeof(pre));
//     flow=0;
//     cost=0;
//     tot=1;
//     cin>>n;
//     LL ss=0;
//     LL x;
//     s=0;
//     t=2*n+1;


//     for(int i=1;i<=n;i++)
//     {
//         cin>>ax[i];
//         ss+=ax[i];

//     }
//     LL y=ss/n;

//     for(int i=1;i<=n;i++)
//     {
//         add(s,i,ax[i],0);
//         add(i,s,0,0);
//         add(i,t,y,0);
//         add(t,i,0,0);        
//         // add(i,i+n,1e9,1);
//         // add(i,i+n,0,-1);

//     }   
//     for(int i=1;i<=n-1;i++)
//     {
//         add(i,i+1,1e9,1);
//         add(i+1,i,0,-1);
        
//     }
//     for(int i=2;i<=n;i++)
//     {
//         add(i,i-1,1e9,1);
//         add(i-1,i,0,-1);
//     }
//     add(1,n,1e9,1);
//     add(n,1,0,-1);
//     add(n,1,1e9,1);
//     add(1,n,0,-1);    
//     EK();
//     cout<<cost<<'\n';
// }

// int main()
// {
//     solve();
//     return 0;
// }


// F - 最长递增子序列
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// int num[N];
// int dp[N];
// int ss[N];
// void solve()
// {
//     memset(dp,0,sizeof(dp));
//     memset(ss,0,sizeof(ss));

//     int m,n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>num[i];
//     }
//     ss[0]=1;
//     num[0]=0;

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i-1;j>=0;j--)
//         {
//             if(num[j]<=num[i])
//             {
//                 if(dp[i]<dp[j]+1)
//                 {
//                     dp[i]=dp[j]+1;
//                     ss[i]=ss[j];
//                 }
//                 else if(dp[i]==dp[j]+1)
//                 {
//                     ss[i]+=ss[j];
//                 }
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         printf("%d ",dp[i]);
//     }
//     printf("\n");
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%d ",ss[i]);
//     // }
// }
// int main()
// {
//     solve();
//     return 0;
// }