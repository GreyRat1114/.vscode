// 后缀表达式
// #include<bits/stdc++.h>
// using namespace std;
// char a[100];
// int main()
// {
//     stack<int>q;

//     scanf("%s",a);
//     int l=strlen(a);
//     int n=0;
//     for(int i=0;i<=l;i++)
//     {        
//         if(a[i]=='@')
//         {
//             break;
//         }
//         if(a[i]=='.')
//         {
//             q.push(n);
//             n=0;
//         }
//         if(a[i]>='0'&&a[i]<='9')
//         {
//             n=n*10+a[i]-'0';
//         }
//         if(a[i]=='+')
//         {
//             int c=q.top();
//             q.pop();
//             int b=q.top();
//             q.pop();
//             q.push(c+b);
//         }
//         if(a[i]=='-')
//         {
//             int c=q.top();
//             q.pop();
//             int b=q.top();
//             q.pop();
//             int d=b-c;
//             q.push(d);
//         }
//         if(a[i]=='*')
//         {
//             int c=q.top();
//             q.pop();
//             int b=q.top();
//             q.pop();
//             q.push(c*b);
//         }
//         if(a[i]=='/')
//         {
//             int c=q.top();
//             q.pop();
//             int b=q.top();
//             q.pop();
//             q.push(b/c);
//         }
//     } 
//     printf("%d",q.top());
//     return 0;
// }

// 表达式括号匹配
// #include<bits/stdc++.h>
// using namespace std;
// char a[1000];
// int main()
// {
//     stack<int>q;
//     scanf("%s",a);
//     for(int i=0;i<1000;i++)
//     {
//         if(a[i]=='@')
//         {
//             break;
//         }
//         if(a[i]=='(')
//         {
//             q.push(1);

//         }
//         if(a[i]==')')
//         {
//             if(q.empty())
//             {
//                 printf("NO");
//                 return 0;
//             }
//             q.pop();
//         }
//     }
//     if(q.empty())
//     {
//         printf("YES");
//     }
//     else
//     {
//         printf("NO");
//     }
//     return 0;
// }

// 机器翻译
// #include<bits/stdc++.h>
// using namespace std;
// bool vis[1005];
// int main()
// {
//     queue<int>q;
//     int s=0;
//     int sum=0;
//     int n,m;
//     memset(vis,false,sizeof(vis));
//     scanf("%d%d",&m,&n);
//     for(int i=1;i<=n;i++)
//     {
//         int x;
//         scanf("%d",&x);
        
//         if(vis[x]==true)
//         {
//             continue;
//         }
//         s++;
//         q.push(x);
//         vis[x]=true;
//         if(q.size()>m)
//         {
//             int y=q.front();
//             vis[y]=false;
//             q.pop();
//         }
//     }
//     printf("%d",s);
//     return 0;
// }

// st表&&RMO问题
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// const int M=1e6+5;
// int f[N][25];
// int n,m;
// int main()
// {
//     int lt,rt;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&f[i][0]);
//     }

//     for(int j=1;j<=20;j++)
//     {
//         for(                                                                             )
//         {
//             f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//         }
//     }    
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&lt,&rt);
//         int k=log2(rt-lt+1);
//         printf("%d\n",max(f[lt][k],f[rt-(1<<k)+1][k]));
//     }
//     return 0;
// }

// 质量检测
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// int f[N][25];
// int n,m;
// int main()
// {
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&f[i][0]);

//     }
//     int lt,rt;
//     for(int j=1;j<=20;j++)
//     {
//         for(int i=1;i+(1<<j)-1<=n;i++)
//         {
//             f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//         }
//     }
//     for(int i=1;i<=n-m+1;i++)
//     {
//         int k=log2(m);
//         printf("%d\n",min(f[i][k],f[i+m-(1<<k)][k]));
//     }
//     return 0;
// }

// 忠诚
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005;
// int f[N][20];
// int n,m;

// int main()
// {
//     scanf("%d%d",&m,&n);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d",&f[i][0]);

//     }
//     int l,r;
//     for(int j=1;j<=20;j++)
//     {
//         for(int i=1;i<=m-(1<<j)+1;i++)
//         {
//             f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);

//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&l,&r);
//         int k=log2(r-l+1);
//         printf("%d ",min(f[l][k],f[r-(1<<k)+1][k]));
//     }
//     return 0;
// }

// 最大数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=200005;
// long long f[N][20];
// long long a[N];
// int n;
// void change(int u)
// {
//     f[u][0]=a[u];
//     for(int i=1;u-(1<<i)>=0;i++)
//     {
//         f[u][i]=max(f[u][i-1],f[u-(1<<(i-1))][i-1]);
//     }
// }
// long long find(int l,int r)
// {
//     double tx=log(r-l+1)/log(2);
//     int k=tx;
//     return max(f[r][k],f[l+(1<<k)-1][k]);
// }
// int main()
// {
//     memset(f,0,sizeof(f));
//     memset(a,0,sizeof(a));
//     long long n,t,d;
//     int m;
//     t=0;
//     n=0;
//     long long x;
//     char g;
//     scanf("%d%lld",&m,&d);
//     for(int i=1;i<=m;i++)
//     {
//         cin>>g;
//         if(g=='A')
//         {
//             scanf("%lld",&x);
//             x=(x+t)%d;
//             a[++n]=x;
//             change(n);

//         }
//         else if(g=='Q')
//         {
//             scanf("%lld",&x);
//             long long ans;
//             if(x==1)
//             {
//                 printf("%lld\n",a[n]);
//                 t=a[n];
//                 continue;
//             }
//             ans=find(n-x+1,n);
//             printf("%lld\n",ans);
//             t=ans;
//         }
//     }
//     return 0;
// }

// 忠诚
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005;
// int f[N][20];
// int n,m;

// int main()
// {
//     scanf("%d%d",&m,&n);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d",&f[i][0]);

//     }
//     int l,r;
//     for(int j=1;j<=20;j++)
//     {
//         for(int i=1;i<=m-(1<<j)+1;i++)
//         {
//             f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);

//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&l,&r);
//         int k=log2(r-l+1);
        
//     }


//     return 0;
// }

// 【模板】树状数组1
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// int nx[N];
// int n,m,s[N];
// int lowbit(int x)
// {
//     return x&-x;
// }
// void change(int x,int k)//向后修
// {
//     while(x<=n)
//     {
//         s[x]+=k;
//         x+=lowbit(x);
//     }
// }
// int query(int x)//向前查
// {
//     int t=0;
//     while(x)
//     {
//         t+=s[x];
//         x-=lowbit(x);
//     }
//     return t;

// }
// int main()
// {
//     int op;
//     int x,y;
//     int a;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&a);
//         change(i,a);

//     }
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d",&op);
//         if(op==1)
//         {
//             scanf("%d%d",&x,&y);
//             change(x,y);
//             // for(int i=1;i<=5;i++)
//             // {
//             //     printf("[%d],",s[i]);
//             // }
//             // printf("\n");
//         }
//         else
//         {
//             scanf("%d%d",&x,&y);
//             int s1=query(x-1);
//             int s2=query(y);
//             printf("%d\n",s2-s1);
//         }
//     }
//     return 0;
// }

// 树状数组2
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// const int M=5e5+5;
// int n,m;
// int s[N];
// int a[N];

// int lowbit(int x)
// {
//     return x&-x;
// }
// void change(int x,int k)
// {
//     while(x<=n)
//     {
//         s[x]+=k;
//         x+=lowbit(x);
//     }
// }
// int query(int x)
// {
//     int t=0;
//     while(x)
//     {
//         t+=s[x];
//         x-=lowbit(x);
//     }
//     return t;
// }
// int main()
// {
//     int op;
//     int x,y,k;
//     scanf("%d%d",&n,&m);

//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d",&op);
//         if(op==1)
//         {
//             scanf("%d%d%d",&x,&y,&k);
//             change(x,k);
//             change(y+1,-k);

//         }
//         else
//         {
//             scanf("%d",&x);
//             printf("%d\n",a[x]+query(x));
//         }
//     }
//     return 0;
// }

// 逆序对
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// int n;
// long long sum;
// int s[N];
// int a[N];
// int b[N];
// int lowbit(int x)
// {
//     return x&-x;
// }
// void change(int x,int k)
// {
//     while(x<=n)
//     {
//         s[x]+=k;
//         x+=lowbit(x);
//     }
// }
// int query(int x)
// {
//     int t=0;
//     while(x)
//     {
//         t+=s[x];
//         x-=lowbit(x);

//     }
//     return t;
// }
// int main()
// {
//     sum=0;
//     int x,y;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&b[i]);
//         a[i]=b[i];
//     }
//     sort(a+1,a+n+1);
//     int p=unique(a+1,a+n+1)-a-1;
//     int q;
//     long long s1,s2;
//     for(int i=1;i<=n;i++)
//     {
//         q=lower_bound(a+1,a+p+1,b[i])-a;
//         change(q,1);
//         s1=query(q);
//         s2=query(n);
//         sum+=s2-s1;
//         // printf("[%d]",s2-s1);  
//         // printf("%d,",q);
//     }
//     printf("%lld",sum);   
//     return 0;
// }

// 火柴排队
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// const int mod=99999997;
// struct node{
//     int val;
//     int pos;

// }a[N],b[N];
// int c[N];
// int s[N];
// int n;
// int lowbit(int x)
// {
//     return x&-x;
// }
// void change(int x,int k)
// {
//     while(x<=n)
//     {
//         s[x]+=k;
//         x+=lowbit(x);
//     }
// }
// int query(int x)
// {
//     int t=0;
//     while(x)
//     {
//         t+=s[x];
//         x-=lowbit(x);
//     }
//     return t;
// }
// bool cmp(node a,node b)
// {
//     if(a.val<b.val)
//     {
//         return 1;
//     }
//     return 0;
// }
// int main()
// {
//     long long sum=0;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&a[i].val);
//         a[i].pos=i;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&b[i].val);
//         b[i].pos=i;
//     }
//     sort(a+1,a+n+1,cmp);
//     sort(b+1,b+n+1,cmp);
//     for(int i=1;i<=n;i++)
//     {
//         c[a[i].pos]=b[i].pos;
//     }
//     long long s1,s2;
//     for(int i=1;i<=n;i++)
//     {
//         change(c[i],1);
//         s1=query(c[i]);
//         s2=query(n);
//         sum=(sum+s2-s1)%mod;
//     }
//     printf("%lld",sum);

//     return 0;
// }


// 【模板】线段树1
// #include<bits/stdc++.h>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e5+5;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
// }tr[N*4];
// long long w[N];
// void pushup(int u)
// {
//     tr[u].sum=tr[lc].sum+tr[rc].sum;
// }
// void pushdown(int u)
// {
//     if(tr[u].add)
//     {
//         tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
//         tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
//         tr[lc].add+=tr[u].add;
//         tr[rc].add+=tr[u].add;
//         tr[u].add=0;
//     }
// }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,w[l],0};
//     if(l==r)
//     {
//         return;
//     }
//     int m=l+r>>1;
//     build(lc,l,m);
//     build(rc,m+1,r);
//     pushup(u);

// }
// void update(int u,int l,int r,long long k)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
//         tr[u].add+=k;
//         return;
//     }
//     int m=tr[u].l+tr[u].r>>1;
//     pushdown(u);

//     if(l<=m)
//     {
//         update(lc,l,r,k);

//     }
//     if(r>m)
//     {
//         update(rc,l,r,k);
//     }
//     pushup(u);

// }
// long long query(int u,int l,int r)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         return tr[u].sum;
//     }
//     int m=tr[u].r+tr[u].l>>1;
//     pushdown(u);
//     long long sum=0;
//     if(l<=m)
//     {
//         sum+=query(lc,l,r);
//     }
//     if(r>m)
//     {
//         sum+=query(rc,l,r);
//     }
//     return sum;
// }
// int n,m;
// int main()
// {
//     int op;
//     int x,y;
//     long long z;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&w[i]);

//     }
//     build(1,1,n);

//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d",&op);
//         if(op==1)
//         {
//             scanf("%d%d%lld",&x,&y,&z);
//             update(1,x,y,z);
//         }
//         else
//         {
//             scanf("%d%d",&x,&y);
//             printf("%lld\n",query(1,x,y));

//         }

//     }
//     return 0;
// }


// 【模板】线段树2
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;

// #define lc u<<1
// #define rc u<<1|1
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
//     long long add2;
// }tr[N*4];
// long long w[N];
// long long n,m,q;
// void pushup(int u)
// {
//     tr[u].sum=(tr[lc].sum+tr[rc].sum)%m;

// }
// void pushdown(int u)
// {
//     tr[lc].sum=(tr[lc].sum*tr[u].add2+tr[u].add*(tr[lc].r-tr[lc].l+1))%m;
//     tr[rc].sum=(tr[rc].sum*tr[u].add2+tr[u].add*(tr[rc].r-tr[rc].l+1))%m;
//     tr[lc].add=(tr[lc].add*tr[u].add2+tr[u].add)%m;
//     tr[lc].add2=(tr[lc].add2*tr[u].add2)%m;
//     tr[rc].add=(tr[rc].add*tr[u].add2+tr[u].add)%m;
//     tr[rc].add2=(tr[rc].add2*tr[u].add2)%m;
//     tr[u].add=0;        
//     tr[u].add2=1;
// }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,0,0,1};
//     if(l==r)
//     {
//         tr[u].sum=w[l];
//         return;
//     }
//     int m=l+r>>1;

//     build(lc,l,m);
//     build(rc,m+1,r);
//     pushup(u);
// }
// void update(int u,int l,int r,long long k,long long x)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].sum=(x*(tr[u].sum+k*(tr[u].r-tr[u].l+1)))%m;
//         tr[u].add+=k;
//         tr[u].add2*=x;
//         return;
//     }
//     int m=tr[u].l+tr[u].r>>1;
//     pushdown(u);
//     if(l<=m)
//     {
//         update(lc,l,r,k,x);
//     }
//     if(r>m)
//     {
//         update(rc,l,r,k,x);

//     }
//     pushup(u);
// }
// long long query(int u,int l,int r)
// {
//   if(l>tr[u].r || r<tr[u].l) return 0;
//   if(l<=tr[u].l&&tr[u].r<=r) return tr[u].sum;
//   pushdown(u);
//   return (query(lc,l,r)+query(rc,l,r))%m;
// }

// int main()
// {
//     int op;
//     long long x,y,z;
//     scanf("%d%d%d",&n,&q,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&w[i]);
//     }
//     build(1,1,n);
//     for(int i=1;i<=q;i++)
//     {
//         scanf("%d",&op);
//         if(op==1)
//         {
//             scanf("%lld%lld%lld",&x,&y,&z);
//             update(1,x,y,0,z);
//         }
//         else if(op==2)
//         {
//             scanf("%lld%lld%lld",&x,&y,&z);
//             update(1,x,y,z,1);
//         }
//         else if(op==3)
//         {
//             scanf("%lld%lld",&x,&y);
//             printf("%lld\n",query(1,x,y)%m);
//         }
//     }
//     return 0;
// }


// 旅行
// #include<bits/stdc++.h>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e5+5;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
// }tr[N*4];
// int n,m,q;
// int w[N];
// int fa[N];
// int dep[N];
// int son[N];
// int sz[N];
// int top[N];
// int id[N];
// int nw[N];
// vector<int> e[N];



// void pushup(int u)
// {
//     tr[u].sum=tr[lc].sum+tr[rc].sum;
// }
// void pushdown(int u)
// {
//     if(tr[u].add)
//     {
//         tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
//         tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
//         tr[lc].add+=tr[u].add;
//         tr[rc].add+=tr[u].add;
//         tr[u].add=0;
//     }
// }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,w[l],0};
//     if(l==r)
//     {
//         return;
//     }
//     int m=l+r>>1;
//     build(lc,l,m);
//     build(rc,m+1,r);
//     pushup(u);

// }
// void update(int u,int l,int r,long long k)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
//         tr[u].add+=k;
//         return;
//     }
//     int m=tr[u].l+tr[u].r>>1;
//     pushdown(u);

//     if(l<=m)
//     {
//         update(lc,l,r,k);

//     }
//     if(r>m)
//     {
//         update(rc,l,r,k);
//     }
//     pushup(u);

// }
// long long query(int u,int l,int r)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         return tr[u].sum;
//     }
//     int m=tr[u].r+tr[u].l>>1;
//     pushdown(u);
//     long long sum=0;
//     if(l<=m)
//     {
//         sum+=query(lc,l,r);
//     }
//     if(r>m)
//     {
//         sum+=query(rc,l,r);
//     }
//     return sum;
// }
// char op[10];
// int c[N];

// int main()
// {
//     int x,y;
//     long long z;
//     scanf("%d%d",&n,&q);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&w[i],&c[i]);

//     }
//     build(1,1,n);
//     for(int i=1;i<=n-1;i++)
//     {
//         scanf("%d%d",&x,&y);
//         e[x].push_back(y);
//         e[y].push_back(x);

//     }
//     for(int i=1;i<=q;i++)
//     {
//         scanf("%s",&op);
//         if(op[1]=='C'&&op[2]=='C')
//         {
//             scanf("%d%d",&x,&y);
//             update(1,x,y,z);
//         }
//         else if(op[1]=='C'&&op[2]=='W')
//         {
//             scanf("%d%d",&x,&y);
//             printf("%lld\n",query(1,x,y));

//         }
//         else if(op[1]=='Q'&&op[2]=='S')
//         {
//             scanf("%d%d",&x,&y);
//         }
//         else if(op[1]=='Q'&&op[2]=='M')
//         {
//             scanf("%d%d",&x,&y);
//         }

//     }
//     return 0;
// }


// 哈希冲突
// #include<bits/stdc++.h>
// using namespace std;
// const int N=150005;
// using LL=long long;
// LL a[N];
// LL dp[405][405];


// int main()
// {
//     char op;
//     int n,m;
    
//     scanf("%d%d",&n,&m);
//     double p=sqrt(n);
//     // printf("%lf",sqrt(n));
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);

//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=p;j++)
//         {
//             dp[j][i%j]+=a[i];
//         }
//     }
//     int x,y;
//     for(int i=1;i<=m;i++)
//     {
//         scanf(" %c",&op);
//         scanf("%d%d",&x,&y);
        
//         if(op=='A')
//         {
//             LL ans=0;
//             if(x<=p)
//             {
//                 ans=dp[x][y];
//             }
//             else
//             {
//                 for(int i=y;i<=n;i=i+x)
//                 {
//                     ans+=a[i];
//                 }
//             }
//             printf("%lld\n",ans);
//         }
//         else if(op=='C')
//         {
//             for(int i=1;i<=p;i++)
//             {
//                 dp[i][x%i]=dp[i][x%i]-a[x]+y;
//             }
//             a[x]=y;
//         }
//     }
//     return 0;
// }


// 扫描线&&矩阵并面积
// #include<bits/stdc++.h>
// using namespace std;
// const int N=200005;
// using LL=long long;
// #define lc u<<1
// #define rc u<<1|1
// int n,m;
// struct line{
//     int x1,x2,y;
//     int tag;
//     bool operator<(line &t)
//     {
//         return y<t.y;
//     }
// }L[N*2];
// struct node{
//     int l,r;
//     int cnt,len;
// }tr[N*8];
// int xn[N*2];
// void pushup(int u)
// {
//     if(tr[u].cnt)
//     {
//         tr[u].len=xn[tr[u].r+1]-xn[tr[u].l];
//     }
//     else
//     {
//         tr[u].len=tr[lc].len+tr[rc].len;

//     }
// }

// void build(int u,int l,int r)
// {
//     tr[u]={l,r,0,0};
//     if(l==r)
//     {
//         return;
//     }
//     int m=l+r>>1;

//     build(lc,l,m);
//     build(rc,m+1,r);
// }
// void update(int u,int l,int r,int tag)
// {
//     if(l>tr[u].r||r<tr[u].l)
//     {
//         return;
//     }
//     if(l<=tr[u].l&&tr[u].r<=r)
//     {
//         tr[u].cnt+=tag;
//         pushup(u);
//         return;
//     }
//     update(lc,l,r,tag);
//     update(rc,l,r,tag);
//     pushup(u);
// }
// int main()
// {
//     int x1,x2,y1,y2;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//         L[i]={x1,x2,y1,1};
//         L[i+n]={x1,x2,y2,-1};
//         xn[i]=x1;
//         xn[i+n]=x2;

//     }
//     n*=2;
//     sort(L+1,L+n+1);
//     sort(xn+1,xn+n+1);
//     int s=unique(xn+1,xn+n+1)-xn-1;
//     build(1,1,s-1);
//     LL ans=0;
//     for(int i=1;i<n;i++)
//     {
//         int l=lower_bound(xn+1,xn+s+1,L[i].x1)-xn;
//         int r=lower_bound(xn+1,xn+s+1,L[i].x2)-xn;
//         update(1,l,r-1,L[i].tag);
//         ans+=1ll*tr[1].len*(L[i+1].y-L[i].y);
//     }
//     printf("%lld\n",ans);

//     return 0;

// }


// 【模板】普通平衡树
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// #define ls(x) tr[x].s[0]
// #define rs(x) tr[x].s[1]
// const int N=1e6+5;
// struct node{
//     int s[2];
//     int p;
//     int v;
//     int cnt;
//     int size;
//     void init(int p1,int v1)
//     {
//         p=p1;
//         v=v1;
//         cnt=size=1;
//     }
// }tr[N];
// int root;
// int idx;
// void pushup(int x)
// {
//     tr[x].size=tr[tr[x].s[0]].size+tr[tr[x].s[1]].size+tr[x].cnt;
// }
// void rotate(int x)
// {
//     int y=tr[x].p;
//     int z=tr[y].p;
//     int k=tr[y].s[1]==x;
//     tr[y].s[k]=tr[x].s[k^1];
//     tr[tr[x].s[k^1]].p=y;
//     tr[x].s[k^1]=y;
//     tr[y].p=x;
//     tr[z].s[tr[z].s[1]==y]=x;
//     tr[x].p=z;
//     pushup(y);
//     pushup(x);

// }
// void splay(int x,int k)
// {
//     while(tr[x].p!=k)
//     {
//         int y=tr[x].p;
//         int z=tr[y].p;
//         if(z!=k)
//         {
//             (tr[y].s[0]==x)^(tr[z].s[0]==y)?rotate(x):rotate(y);

//         }
//         rotate(x);
//     }
//     if(k==0)
//     {
//         root=x;
//     }
// }
// void insert(int v)
// {
//     int x=root;
//     int p=0;
//     while(x&&tr[x].v!=v)
//     {
//         p=x;
//         x=tr[x].s[v>tr[x].v];
//     }
//     if(x)
//     {
//         tr[x].cnt++;
//     }
//     else
//     {
//         idx++;
//         x=idx;
//         tr[p].s[v>tr[p].v]=x;
//         tr[x].init(p,v);
//     }
//     splay(x,0);    
// }
// void find(int v)
// {
//     int x=root;
//     while(tr[x].s[v>tr[x].v]&&v!=tr[x].v)
//     {
//         x=tr[x].s[v>tr[x].v];

//     }
//     splay(x,0);

// }
// int get_pre(int v)
// {
//     find(v);
//     int x=root;
//     if(tr[x].v<v)
//     {
//         return x;
//     }
//     x=tr[x].s[0];
//     while(tr[x].s[1])
//     {
//         x=tr[x].s[1];
//     }
//     return x;
// }
// int get_suc(int v)
// {
//     find(v);
//     int x=root;
//     if(tr[x].v>v)
//     {
//         return x;

//     }
//     x=tr[x].s[1];
//     while(tr[x].s[0])
//     {
//         x=tr[x].s[0];

//     }
//     return x;
// }
// void del(int v)
// {
//     int pre=get_pre(v);
//     int suc=get_suc(v);
//     splay(pre,0);
//     splay(suc,pre);
//     int del=tr[suc].s[0];
//     if(tr[del].cnt>1)
//     {
//         tr[del].cnt--;
//         splay(del,0);
//     }
//     else
//     {
//         tr[suc].s[0]=0;
//         splay(suc,0);
//     }
// }
// int get_rank(int v)
// {
//     insert(v);
//     int res=tr[tr[root].s[0]].size;
//     del(v);

//     return res;
// }
// int get_val(int k)
// {
//   int x=root;
//   while(true){
//     if(k<=tr[ls(x)].size) x=ls(x);
//     else if(k<=tr[ls(x)].size+tr[x].cnt) break;
//     else k-=tr[ls(x)].size+tr[x].cnt, x=rs(x);
//   }
//   splay(x, 0);
//   return tr[x].v;
// }
// int main()
// {
//     insert(-1e9);
//     insert(1e9);
//     int n;
//     int op;
//     int x;

//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&op,&x);
//         if(op==1)
//         {
//             insert(x);
//         }
//         else if(op==2)
//         {
//             del(x);
//         }
//         else if(op==3)
//         {
//             printf("%d\n",get_rank(x));
//         }
//         else if(op==4)
//         {
//             printf("%d\n",get_val(x+1));
//         }
//         else if(op==5)
//         {
//             printf("%d\n",tr[get_pre(x)].v);
//         }
//         else if(op==6)
//         {
//             printf("%d\n",tr[get_suc(x)].v);
//         }
//     }

//     return 0;
// }


// 数列区间最大值
// #include<bits/stdc++.h>
// using namespace std;
// const int M=1e6+5;
// int f[M][30];
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&f[i][0]);
//     }
//     for(int j=1;j<=21;j++)
//     {
//         for(int i=1;i<=n-(1<<j)+1;i++)
//         {
//             f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//             // printf("{%d}",f[i][j]);
//         }
//         // printf("\n");
//     }
//     int x,y;
//     int l;
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&x,&y);
//         if(x>y)
//         {
//             swap(x,y);
//         }
//         l=log2(y-x+1);
//         int ans=max(f[x][l],f[y-(1<<l)+1][l]);
//         printf("%d\n",ans);
//     }
//     return 0;
// }


// 最敏捷的机器人
// #include<bits/stdc++.h>
// using namespace std;
// const int M=1e6+5;
// using LL=long long;

// LL f[M][30];
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&f[i][0]);
//     }
//     for(int j=1;j<=21;j++)
//     {
//         for(int i=1;i<=n-(1<<j)+1;i++)
//         {
//             f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);

//             // printf("{%d}",f[i][j]);
//         }
//         // printf("\n");
//     }
//     int x,y;
//     int l;
//     int m;
//     scanf("%d",&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&x,&y);
//         if(x>y)
//         {
//             swap(x,y);
//         }
//         l=log2(y-x+1);
//         LL ans1=max(f[x][l],f[y-(1<<l)+1][l]);
//         printf("%lld\n",ans1);
//     }
//     return 0;
// }



// Balanced Lineup
// #include<bits/stdc++.h>
// using namespace std;
// const int M=1e6+5;
// int f[M][30];
// int g[M][30];
// int main()
// {
//     int n,q;
//     scanf("%d%d",&n,&q);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&f[i][0]);
//         g[i][0]=f[i][0];
//     }
//     for(int j=1;j<=21;j++)
//     {
//         for(int i=1;i<=n-(1<<j)+1;i++)
//         {
//             f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//             g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);

//             // printf("{%d}",f[i][j]);
//         }
//         // printf("\n");
//     }
//     int x,y;
//     int l;
//     for(int i=1;i<=q;i++)
//     {
//         scanf("%d%d",&x,&y);
//         if(x>y)
//         {
//             swap(x,y);
//         }
//         l=log2(y-x+1);
//         int ans1=max(f[x][l],f[y-(1<<l)+1][l]);
//         int ans2=min(g[x][l],g[y-(1<<l)+1][l]);
//         printf("%d\n",ans1-ans2);
//     }
//     return 0;
// }


// 最近的共同祖先
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=1e4+5;
int fa[N];
bool vis[N];

vector<int> e[N];
int a,b;
int f[N];
int ans=0;
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        f[i]=i;
        fa[i]=i;
    }
    memset(vis,false,sizeof(vis));
    e->clear();

}
int find(int x)
{
    if(x==fa[x])
    {
        return x;
    }
    return fa[x]=find(fa[x]);
}
void tarjan(int u)
{
    vis[u]=true;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];

        if(!vis[v])
        {
            tarjan(v);
            fa[v]=u;            
        }

    }
    if(u==a)
    {
        if(vis[b])
        {
            ans=find(b);
        }

    }
    if(u==b)
    {
        if(vis[a])
        {
            ans=find(a);

        }
    }
}


void solve()
{
    
    int n;
    scanf("%d",&n);
    init(n);
    int x,y;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&x,&y);
        f[y]=x;
        
        e[x].push_back(y);
        e[y].push_back(x);        
    }

    scanf("%d%d",&a,&b);
    int s=1;
    while(f[s]!=s)
    {
        s=f[s];
    }
    // printf("{%d}",s);
    tarjan(s);
    printf("%d\n",ans);

    // for(int i=1;i<=n;i++)
    // {
    //     printf("[%d]",f[i]);
    // }    
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}


// 选择客栈
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// const int M=1e6+5;
// using LL=long long;
// int aft[N];
// int tot[N];
// int num[N];

// int main()
// {
//     int n,k,p;
//     int c,w;
//     int ans=0;
//     int last=0;
//     scanf("%d%d%d",&n,&k,&p);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&c,&w);
//         if(w<=p)
//         {
//             last=i;
            
//         }
//         if(last>aft[c])
//         {
//             tot[c]=num[c];
//         }
//         aft[c]=i;
//         ans+=tot[c];
        
//         num[c]++;

//     }
//     printf("%d\n",ans);
    

//     return 0;
// }


// 最近公共祖先
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// int fa[N];
// bool vis[N];
// int n;
// vector<int> e[N];
// int a,b;
// int f[N];
// int ans[N];

// vector<int> query[N];
// void init(int n)
// {
//     for(int i=0;i<=n;i++)
//     {
//         f[i]=i;
//         fa[i]=i;
//     }
//     memset(vis,false,sizeof(vis));
//     memset(ans,0,sizeof(ans));

//     e->clear();

// }
// int find(int x)
// {
//     if(x==fa[x])
//     {
//         return x;
//     }
//     return fa[x]=find(fa[x]);
// }
// void tarjan(int u)
// {
//     vis[u]=true;
//     for(auto v:e[u])
//     {
//         if(!vis[v])
//         {
//             tarjan(v);
//             fa[v]=u;            
//         }

//     }
//     for(auto v:query[u])
//     {
//         if(vis[v])
//         {
//             int fx=find(v);
//             ans[fx]++;

//         }
//     }
// }


// void solve()
// {
//     init(n);
//     int x,y,z;
//     for(int i=1;i<=n;i++)
//     {      
//         scanf("%d:(%d)",&x,&y);
//         for(int i=1;i<=y;i++)
//         {
//             scanf("%d",&z);
//             f[z]=x;
//             e[x].push_back(z);
//             e[z].push_back(x);              
//         }
//     }
//     int s=1;
//     while(f[s]!=s)
//     {
//         s=f[s];
//     }

//     int m;
//     scanf("%d",&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("(%d %d)",&x,&y);
//         query[x].push_back(y);
//         query[y].push_back(x);

//     }
//     tarjan(s);
//     for(int i=1;i<=n;i++)
//     {
//         if(ans[i]>0)
//         {
//             printf("%d:%d\n",i,ans[i]);
//         }
//     }
//     // printf("%d\n",ans);

//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("[%d]",f[i]);
//     // }    
// }
// int main()
// {
//     while(scanf("%d",&n)!=EOF)
//     {
//         solve();
//     }
//     return 0;
// }


