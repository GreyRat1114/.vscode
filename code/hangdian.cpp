// 半
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e6+5;
// int s[N];
// int n;
// int a[N];
// int b[N];
// int c[N];
// int ans[N];
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
//     int t;
    
//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(s,0,sizeof(s));
//         int ss1=0,ss2=0,ss3=0;
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&b[i]);
//         }
//         for(int i=1;i<=n;i++)
//         {
//             c[a[i]]=i;
//         }  
//         for(int i=1;i<=n;i++)
//         {
//             ss3=c[b[i]]-1;

//             int p=c[b[i]];
//             change(p,1);
//             int s1=query(p);
//             int s2=query(n);
//             ss1=s2-s1;
//             ss2=ss1+ss3;
//             ans[b[i]]=ss2;
//             // printf("%d,%d,%d..%d..%d\n",ss1,ss2,ss3,s1,s2);
//         }              
//         for(int i=1;i<=n;i++)
//         {
//             printf("%d ",ans[i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


// 紧急集合/聚会
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// vector<int> e[N];
// int fa[N],dep[N],son[N],sz[N];
// int top[N];


// void dfs1(int u,int father)
// {
//     fa[u]=father;
//     dep[u]=dep[father]+1;
//     sz[u]=1;
//     for(int v:e[u])
//     {
//         if(father==v)
//         {
//             continue;
//         }
//         dfs1(v,u);
//         sz[u]+=sz[v];
//         if(sz[son[u]]<sz[v])
//         {
//             son[u]=v;

//         }
//     }
// }
// void dfs2(int u,int t)
// {
//     top[u]=t;
//     if(!son[u])
//     {
//         return;
//     }
//     dfs2(son[u],t);
//     for(int v:e[u])
//     {
//         if(v==fa[u]||v==son[u])
//         {
//             continue;
//         }
//         dfs2(v,v);

//     }
// }
// int lca(int u,int v)
// {
//     while(top[u]!=top[v])
//     {
//         if(dep[top[u]]<dep[top[v]])
//         {
//             swap(u,v);
//         }
//         u=fa[top[u]];

//     }
//     return dep[u]<dep[v]?u:v;

// }
// int x,y,z;
// int ans;
// int a,b,c;
// int k;
// void check()
// {
// 	int s=dep[x]+dep[y]+dep[z]-dep[a]-2*dep[b];
//     //此式子不变
// 	if(s<ans) ans=s,k=a;
// }
// void answer()
// {
// 	scanf("%d%d%d",&x,&y,&z);
// 	ans=1e9;
//     //枚举a为三个lca，并检查，更新答案
// 	a=lca(x,y),b=lca(a,z);
// 	check();
// 	a=lca(x,z),b=lca(a,y);
// 	check();
// 	a=lca(y,z),b=lca(a,x);
// 	check();
// 	printf("%d %d\n",k,ans);
// 	return;
// }
// int main()
// {
//     int n,m;
//     int a,b;
//     int x,y,z;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n-1;i++)
//     {
//         scanf("%d%d",&a,&b);
//         e[a].push_back(b);
//         e[b].push_back(a);

//     }
//     dfs1(1,0);
//     dfs2(1,1);
//     int p,q,r;

//     for(int i=1;i<=m;i++)
//     {
//         answer();
//     }  
//     return 0;

// }


//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//#define lc u << 1
//#define rc u << 1 | 1
//constexpr int N = 1e6 + 10;
//int w[N];
//struct node{
//	int l, r;
//	long long sum;
//}tr[N * 4];
//
//void pushup(int u){
//	tr[u].sum = tr[lc].sum + tr[rc].sum;
//}
//
//void build(int u, int l, int r){
//	tr[u] = {l, r, w[r]};
//	if(l == r) return ;
//	int mid = (l + r) >> 1;
//	build(lc, l, mid), build(rc, mid + 1, r);
//	pushup(u);
//}
//
//void modify(int u, int pos, int v){
//	if(tr[u].l == tr[u].r) {
//	    tr[u].sum += v;
//	}
//	else{
//		int mid = (tr[u].l + tr[u].r) >> 1;
//		if(pos <= mid) modify(lc, pos, v);
//		else modify(rc, pos, v);
//		pushup(u);
//	}
//}
//
//long long query(int u, int l, int r){
//	if(tr[u].l >= l && tr[u].r <= r) {
//		return tr[u].sum;
//	}
//	int mid = (tr[u].l + tr[u].r) >> 1;
//	long long sum = 0;
//	if(l <= mid) sum = query(lc, l, r);
//	if(r > mid) sum += query(rc, l, r);
//	return sum;	
//}
//int main()
//{
//	int n,q,m,a,b;
//	long long ans;
//	scanf("%d%d",&n,&q);
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&w[i]);
//	}
//	build(1,1,n);
//	for(int i=0;i<q;i++)
//	{
//		scanf("%d%d%d",&m,&a,&b);
//		if(m==1)
//		{
//			modify(1,a,b);
//		}
//		else
//		{
//			ans=query(1,a,b);
//			printf("%lld\n",ans);
//		}
//	}
//	return 0;
//}


// 【模板】树链剖分
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// #define lc u<<1
// #define rc u<<1|1


// struct tree{
//     int l,r;
//     long long sum,add;
// }tr[N*4];
// int n,m,root,p,a,b,c,t,cnt;
// int w[N];

// int fa[N];
// int dep[N];
// int son[N];
// int sz[N];
// int top[N];
// int id[N];
// int nw[N];
// vector<int> e[N];

// void dfs1(int u,int father)
// {
//     fa[u]=father;
//     dep[u]=dep[father]+1;
//     sz[u]=1;
//     for(int v:e[u])
//     {
//         if(father==v)
//         {
//             continue;
//         }
//         dfs1(v,u);
//         sz[u]+=sz[v];
//         if(sz[son[u]]<sz[v])
//         {
//             son[u]=v;

//         }
//     }
// }
// void dfs2(int u,int t)
// {
//     top[u]=t;
//     cnt++;
//     id[u]=cnt;
//     nw[cnt]=w[u];

//     if(!son[u])
//     {
//         return;
//     }
//     dfs2(son[u],t);
//     for(int v:e[u])
//     {
//         if(v==fa[u]||v==son[u])
//         {
//             continue;
//         }
//         dfs2(v,v);

//     }
// }
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
//     tr[u]={l,r,nw[l],0};
//     if(l==r)
//     {
//         return;
//     }
//     int mid=(l+r)>>1;
//     build(lc,l,mid);
//     build(rc,mid+1,r);
//     pushup(u);
// }
// long long query(int u,int l,int r)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         return tr[u].sum;
//     }
//     pushdown(u);
//     int mid=(tr[u].l+tr[u].r)>>1;
//     long long res=0;
//     if(l<=mid)
//     {
//         res+=query(lc,l,r);

//     }
//     if(r>mid)
//     {
//         res+=query(rc,l,r);
//     }
//     return res;
// }
// long long query_path(int u,int v)
// {
//     long long res=0;
//     while(top[u]!=top[v])
//     {
//         if(dep[top[u]]<dep[top[v]])
//         {
//             swap(u,v);
//         }
//         res+=query(1,id[top[u]],id[u]);
//         u=fa[top[u]];
//     }
//     if(dep[u]<dep[v])
//     {
//         swap(u,v);
//     }
//     res+=query(1,id[v],id[u]);
//     return res;

// }
// void update(int u,int l,int r,int k)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].add+=k;
//         tr[u].sum+=k*(tr[u].r-tr[u].l+1);
//         return;
//     }
//     pushdown(u);
//     int mid=(tr[u].l+tr[u].r)>>1;
//     if(l<=mid)
//     {
//         update(lc,l,r,k);
//     }
//     if(r>mid)
//     {
//         update(rc,l,r,k);
//     }
//     pushup(u);
// }
// void update_path(int u,int v,int k)
// {
//     while(top[u]!=top[v])
//     {
//         if(dep[top[u]]<dep[top[v]])
//         {
//             swap(u,v);

//         }
//         update(1,id[top[u]],id[u],k);
//         u=fa[top[u]];
//     }
//     if(dep[u]<dep[v])
//     {
//         swap(u,v);

//     }
//     update(1,id[v],id[u],k);
// }
// void update_tree(int u,int k){ //修改子树
//   update(1,id[u],id[u]+sz[u]-1,k);
// }
// long long query_tree(int u){ //查询子树
//   return query(1,id[u],id[u]+sz[u]-1);
// }
// int main()
// {
//     int r,p;
//     int x,y,z;
//     int op;
//     scanf("%d%d%d%d",&n,&m,&r,&p);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&w[i]);
//     }
//     for(int i=1;i<=n-1;i++)
//     {
//         scanf("%d%d",&x,&y);
//         e[x].push_back(y);
//         e[y].push_back(x);
//     }
//     dfs1(r,0);
//     dfs2(r,r);
//     build(1,1,n);

//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d",&op);
//         if(op==1)
//         {
//             scanf("%d%d%d",&x,&y,&z);
//             update_path(x,y,z);

//         }
//         else if(op==2)
//         {
//             scanf("%d%d",&x,&y);
//             long long ans=query_path(x,y);
//             printf("%lld\n",ans%p);
//         }
//         else if(op==3)
//         {
//             scanf("%d%d",&x,&z);
//             update_tree(x,z);

//         }
//         else
//         {
//             scanf("%d",&x);
//             long long ans=query_tree(x);
//             printf("%lld\n",ans%p);
//         }
//     }
//     return 0;
// }

// 苹果树
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// #define lc u<<1
// #define rc u<<1|1


// struct tree{
//     int l,r;
//     long long maxn;
// }tr[N*4];
// int n,m,cnt;
// int w[N];

// int fa[N];
// int dep[N];
// int son[N];
// int sz[N];
// int top[N];
// int id[N];
// int nw[N];
// long long tag[N];
// vector<int> e[N];

// void init(){
//     cnt = 0;
//     for(int i=0;i<=n;i++){
//         e[i].clear();
//         dep[i] = 0;
//         sz[i] = 0;
//         top[i] = 0;
//         fa[i] = 0;
//         son[i] = 0;
//         tag[i] = 0;
//         id[i] = 0;
//         nw[i] = 0;
//         w[i]=0;
//     }
//     return;
// }
// void dfs1(int u,int father)
// {
//     fa[u]=father;
//     dep[u]=dep[father]+1;
//     sz[u]=1;
//     for(int v:e[u])
//     {
//         if(father==v)
//         {
//             continue;
//         }
//         dfs1(v,u);
//         sz[u]+=sz[v];
//         if(sz[son[u]]<sz[v])
//         {
//             son[u]=v;

//         }
//     }
// }
// void dfs2(int u,int t)
// {
//     top[u]=t;
//     cnt++;
//     id[u]=cnt;
//     nw[cnt]=w[u];

//     if(!son[u])
//     {
//         return;
//     }
//     dfs2(son[u],t);
//     for(int v:e[u])
//     {
//         if(v==fa[u]||v==son[u])
//         {
//             continue;
//         }
//         dfs2(v,v);

//     }
// }
// void pushup(int u)
// {
//     tr[u].maxn=max(tr[lc].maxn,tr[rc].maxn);
// }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,0};
//     if(l==r)
//     {
//         tr[u].maxn=nw[l];
//         return;
//     }
//     int mid=(l+r)>>1;
//     build(lc,l,mid);
//     build(rc,mid+1,r);
//     pushup(u);
// }
// long long maxn_(int u,int l,int r)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         return tr[u].maxn;
//     }    
//     int mid=(tr[u].l+tr[u].r)>>1;
//     long long res1=0;
//     long long res2=0;
//     long long res=0;
//     if(l<=mid)
//     {
//         res1=maxn_(lc,l,r);

//     }
//     if(r>mid)
//     {
//         res2=maxn_(rc,l,r);
//     }
//     res=max(res1,res2);

//     return res;   
// }
// long long maxn_path(int u,int v)
// {
//     long long maxn=0;
//     while(top[u]!=top[v])
//     {
//         if(dep[top[u]]<dep[top[v]])
//         {
//             swap(u,v);
//         }
//         maxn=max(maxn,maxn_(1,id[top[u]],id[u]));
//         maxn=max(maxn,w[top[u]]+tag[fa[top[u]]]);
//         u=fa[top[u]];

//     }
//     if(dep[u]<dep[v])
//     {
//         swap(u,v);
//     }
//     maxn=max(maxn,maxn_(1,id[v],id[u]));
//     if(u==top[u])
//     {
//         maxn=max(maxn,w[u]+tag[fa[u]]);
//     }
//     return maxn;
// }
// void update_(int u,int x,int k)
// {
//     if(tr[u].l==x&&tr[u].r==x)
//     {

//         tr[u].maxn+=k;
//         return;
//     }
//     int m=tr[u].l+tr[u].r>>1;
//     if(x<=m)
//     {
//         update_(lc,x,k);
//     }
//     if(x>m)
//     {
//         update_(rc,x,k);
//     }
//     pushup(u);
// }
// int main()
// {
//     int r,p;
//     int x,y,z;
//     int op;
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
        
//         init();

//         scanf("%d%d",&n,&m);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&w[i]);
//         }      
//         for(int i=1;i<=n-1;i++)
//         {
//             scanf("%d%d",&x,&y);
//             e[x].push_back(y);
//             e[y].push_back(x);
//         }       
//         dfs1(1,0);
//         dfs2(1,1);
//         build(1,1,n);  
//         for(int i=1;i<=m;i++)
//         {
//             scanf("%d",&op);
//             if(op==1)
//             {
//                 scanf("%d%d",&x,&y);
//                 printf("%lld\n",maxn_path(x,y));               

//             }
//             else if(op==2)
//             {
//                 scanf("%d%d",&x,&y);
//                 tag[x]+=y;
//                 if(fa[x]>0)
//                 {
//                     update_(1,id[fa[x]],y);
//                     w[fa[x]]+=y;
//                 }
//                 if(son[x]>0)
//                 {
//                     update_(1,id[son[x]],y);
//                     w[son[x]]+=y;
//                 }
//             }
//         }           
//     }
//     return 0;
// }


// 中位数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2005;
// int n;
// int a[N];
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
        

//     }
//     return 0;
// }


// 核心共振
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// const long long mod=1000000007;
// const long long inv2=500000004;
// struct core{
//     long long coord;
//     long long a;
// }arrU[N],arrV[N];
// long long sum1[N];
// long long sum2[N];
// long long an1[N];
// long long an2[N];
// long long sum1_an[N];
// long long sum2_an[N];
// long long ans1=0;
// long long ans2=0;
// long long ans=0;
// bool cmp(core &a,core &b)
// {
//     return a.coord<b.coord;
// }
// void init(int n)
// {
//     memset(sum1,0,sizeof(sum1));
//     memset(sum2,0,sizeof(sum2));
//     memset(an1,0,sizeof(an1));
//     memset(an2,0,sizeof(an2));
//     memset(sum1_an,0,sizeof(sum1_an));
//     memset(sum2_an,0,sizeof(sum2_an));
//     for(int i=0;i<=n;i++)
//     {
//         arrU[i]={0,0};
//         arrV[i]={0,0};

//     }

// }
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         int n;
//         scanf("%d",&n);
//         init(n);
//         long long x,y,a;
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld%lld%lld",&x,&y,&a);
//             long long u=x+y;
//             long long v=x-y;
//             arrU[i]={u,a};
//             arrV[i]={v,a};
//         }
//         sort(arrU+1,arrU+n+1,cmp);
//         sort(arrV+1,arrV+n+1,cmp);
//         // sum1[1]=arrU[1].coord;
//         // sum2[1]=arrV[1].coord;
//         // an1[1]=arrU[1].a;
//         // an2[1]=arrV[1].a;
//         // sum1_an[1]=arrU[1].coord*arrU[1].a;
//         // sum2_an[1]=arrV[1].coord*arrV[1].a;
//         for(int i=1;i<=n;i++)
//         {
//             sum1[i]=sum1[i-1]+arrU[i].coord;
//             sum2[i]=sum2[i-1]+arrV[i].coord;
//             an1[i]=(an1[i-1]+arrU[i].a)%mod;
//             an2[i]=(an2[i-1]+arrV[i].a)%mod;
//             sum1_an[i]=(sum1_an[i-1]+((arrU[i].coord)%mod*(arrU[i].a)%mod)%mod)%mod;
//             sum2_an[i]=(sum2_an[i-1]+((arrV[i].coord)%mod*(arrV[i].a)%mod)%mod)%mod;
//         }
//         ans1=0;
//         ans2=0;
//         long long cur1;
//         long long cur2;
//         for(int i=2;i<=n;i++)
//         {
//             arrU[i].a=arrU[i].a%mod;
//             arrU[i].coord=arrU[i].coord%mod;
//             long long p1=((i-1)*arrU[i].a)%mod;
//             p1=(p1*arrU[i].coord)%mod;
//             long long p2=(arrU[i].a*(sum1[i-1]%mod))%mod;
//             long long p3=(arrU[i].coord*(an1[i-1]%mod))%mod;
//             long long p4=sum1_an[i-1];
//             cur1=(((p1-p2+mod)%mod+p3)%mod-p4+mod)%mod;
//             ans1=(ans1+cur1)%mod;
//             arrV[i].a=arrV[i].a%mod;
//             arrV[i].coord=arrV[i].coord%mod;           
//             p1=((i-1)*arrV[i].a)%mod;
//             p1=(p1*arrV[i].coord)%mod;
//             p2=(arrV[i].a*(sum2[i-1]%mod))%mod;
//             p3=(arrV[i].coord*(an2[i-1]%mod))%mod;
//             p4=sum2_an[i-1];
//             cur2=(((p1-p2+mod)%mod+p3)%mod-p4+mod)%mod;
//             ans2=(ans2+cur2)%mod;
//         }
//         ans=(ans1+ans2)%mod;
//         ans=ans*inv2%mod;
//         printf("%lld\n",ans);        
//     }
//     return 0;
// }


// 小抹爱锻炼
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// int bx[N];
// int cx[N];

// int main()
// {
//     int b,c;
//     int n,m;
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         int tag=1;
//         scanf("%d%d",&n,&m);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&bx[i]);
//         }
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&cx[i]);
//         }
//         int t1=bx[1];
//         int s1=t1;

//         for(int i=2;i<=n;i++)
//         {
//             if(bx[i]>=t1)
//             {
//                 t1=bx[i];             
//             }
//             s1+=t1;
//         }    
//         int t2=cx[n];
//         int s2=t2;

//         for(int i=n-1;i>=1;i--)
//         {
//             if(cx[i]<=t2)
//             {
                
//                 t2=cx[i];           
                
//             }
//             s2+=t2;
//         }   
//         for(int i=1;i<=n;i++)
//         {
//             if(cx[i]<bx[i])
//             {
//                 tag=0;
//             }
            
//         }
//         if(m<s1||m>s2)
//         {
//             tag=0;
//         }
//         if(tag)
//         {
//             printf("YES\n");
//         }
//         else
//         {
//             printf("NO\n");
//         }
//     }
//     return 0;

// }


// 传送门
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// const int M=2e5+5;
// #define INF 1e9
// struct node{
//     int v;
//     int w;
//     int next;
// }a[N*2];
// int last[N];
// int dist[N];
// bool vis[N];
// priority_queue<pair<int,int>> q;
// int tot;
// int n,m;
// void add(int u,int v,int w)
// {
//     tot++;
//     a[tot].v=v;
//     a[tot].w=w;
//     a[tot].next=last[u];
//     last[u]=tot;

// }
// void dijkstra(int s)
// {
//     for(int i=0;i<=n;i++)
//     {
//         dist[i]=INF;
//     }

// }
// int main()
// {
//     int t;
//     int u,v,c;
//     scanf("%d",&t);
//     while(t--)
//     {
//         tot=0;
//         memset(vis,false,sizeof(vis));

//         scanf("%d%d",&n,&m);
//         for(int i=1;i<=m;i++)
//         {
//             scanf("%d%d%d",&u,&v,&c);
//             add(u,v,c);
//             add(v,u,c);

//         }
//         dijkstra(1);

//     }
//     return 0;
// }


// 子集
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// const int M=2e5+5;
// #define INF 1e9
// using LL=long long;
// LL a[55];

// int tot;
// int n,m;


// int main()
// {
//     int t;
//     int u,v,c;
//     scanf("%d",&t);
//     while(t--)
//     {
//         tot=0;

//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",a[i]);
//         }

//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define INF 1e9
// using LL=long long;
// const int N=5e6+5;
// int n,m;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     LL x,y,z;

//     cin>>t;
//     while(t--)
//     {
//         int maxn=0;
//         cin>>n>>x>>y>>z;
//         vector<LL> a(n+10),d(n+10);
//         for(int i=1;i<=n;i++)
//         {
//             cin>>a[i];
//             if(a[i]>maxn)
//             {
//                 maxn=a[i];
//             }
//         }
//         vector<LL> b(maxn+10);
//         for(int i=1;i<=n;i++)
//         {
//             b[a[i]]++;
//         }
//         // sort(a+1,a+n+1);
//         // for(int i=1;i<=n;i++)
//         // {
//         //     b[a[i]]++;
//         //     e[b[a[i]]].push_back(a[i]);            
//         // }
//         LL sum1=1;
//         LL sum=0;
//         LL k=1;
//         for(int i=1;i<=maxn;i++)
//         {
//             d[b[i]]++;

//         }
//         for(int i=1;i<=n;i++)
//         {
//             if(d[i]>=2)
//             {
//                 k=i;
//             }
//         }
//         // printf("{%d}",k);
//         for(int i=1;i<=maxn;i++)
//         {
//             if(b[i]!=0)
//             {
//                 sum+=max(b[i]-k,(LL)0)*y+min(b[i],k)*x;
//                 // printf("([%d])",sum);
//             }
            
//         }
//         // printf("[%d]",sum);
//         sum=sum+(k-1)*z-(k-1)*x;

//         // for(int i=1;i<=4;i++)
//         // {
//         //     printf("[%d]",e[i].size());
//         // }
//         cout<<sum<<'\n';
//     }
//     return 0;
// }


// 最小值
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];
// LL b[N];
// LL c[N];
// LL e[N];
// bool cmp(LL a,LL b)
// {
//     return a>b;

// }
// int main()
// {
//     int t;
//     int n;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&a[i]);
//         }
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&b[i]);
//         }        
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("{%d}",a[i]);
//         // }            
//         int p,q;
//         LL mini=1e18;
//         for(int i=1;i<=n;i++)
//         {
//             c[i]=a[i]-b[i];
//             e[i]=a[i]+b[i];
//         }
//         sort(c+1,c+n+1,cmp);
//         sort(e+1,e+n+1,cmp);
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("[%lld]",e[i]);
//         // }
//         for(int i=1;i<n;i++)
//         {
//             LL d1=c[i]-c[i+1];
//             LL d2=e[i]-e[i+1];
//             // printf("(%lld,%lld)",d1,d2);
//             mini=min(mini,min(d1,d2));
//         }
//         printf("%lld\n",mini);

//     }

//     return 0;
// }



// 随机反馈
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// double dp[N];
// int a[N];
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     int n;
//     while(t--)
//     {
//         double p1,p2,e;
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
//         for(int i=1;i<=n;i++)
//         {
//             dp[i]=1e9;
//         }
//         dp[n]=n;
//         for(int i=n-1;i>=1;i--)
//         {          
//             e=a[i]/1000.0;
//             // p1=1.0*i*(1-a[i]/1000.0);
//             // p2=1.0*(a[i]/1000.0)*(dp[i+1]+20);
//             dp[i]=min(dp[i+1],(1.0-e)*i+e*(dp[i+1]+20.0));
//         }
//         // for(int i=n;i>=1;i--)
//         // {
//         //     printf("%lf\n",dp[i]);
//         // }        
//         printf("%.10lf\n",dp[1]);
//     }
//     return 0;
// }


// 信赖跃迁
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;


// LL a[N];
// int main()
// {
//     LL x;
//     int t;
//     int n;
//     scanf("%d",&t);
//     while(t--)
//     {
//         LL ans=0;
//         LL sum1=0;
//         LL sum2=0;
//         LL maxn=-1e9;
//         LL mini=1e9;
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&x);
//             if(x<0)
//             {
//                 sum1++;
//                 if(x>maxn)
//                 {
//                     maxn=x;
//                 }
//             }
//             else if(x==0)
//             {
//                 sum2++;
//             }
//             else if(x>0)
//             {
//                 if(x<mini)
//                 {
//                     mini=x;
//                 }
//             }

//         }
//         if(sum1%2==1)
//         {
//             if(sum2>0)
//             {
//                 ans=sum2;
//             }
//             else
//             {
                
//                 ans=min(-maxn+1,mini+1);
//             }
//         }
//         else if(sum1%2==0)
//         {
//             ans=sum2;
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }


// 对撞器
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;


// LL a[N];
// int main()
// {
//     LL x;
//     int t;
//     int n;
//     scanf("%d",&t);
//     while(t--)
//     {
//         LL maxn=0;
//         LL ans=0;
//         int pos;
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&x);
//             a[i]=x;
//             if(x>maxn)
//             {
//                 maxn=x;
//                 pos=i;
//             }
//         }
//         if(n<=2)
//         {
//             ans=0;
//         }
//         else
//         {
//             if(pos==1||pos==n)
//             {
//                 ans=(n-2)*maxn;
//             }
//             else
//             {
//                 LL maxn1=max(a[1],a[n]);
//                 ans=(n-3)*maxn+maxn1;
//             }
                        
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<cmath>
// #include<utility>
// #include<string.h>
// using namespace std;
// const int N=205;
// int rt[3000][15][40];
// const int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// const int d1[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     bool isLeap(int y) {
//     return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
//     }
//     int daysInMonth(int y, int m) {
//     return d[m - 1] + (isLeap(y) && m == 2);
//     }
//     int getDay(int y, int m, int d) {
//     int ans = 0;
//     for (int i = 1970; i < y; i++) {
//     ans += 365 + isLeap(i);
//     }
//     for (int i = 1; i < m; i++) {
//       ans += daysInMonth(y, i);
//     }   
//     ans += d;
//     return (ans + 2) % 7 + 1;
// }
// void add(){
//     for(int i=0;i<12;i++){
//       for(int j=1;j<=d1[i];j++){
//         for(int k=2025;k<=2075;k++){
//             if(getDay(k,i+1,j)!=6||getDay(k,i+1,j)!=7||k%4==0){
//                 rt[k][i+1][j]=rt[k-1][i+1][j]+1;
//             }
//         }
//       }
//     }
// }
// void solve(){
//     // memset(rt,0,sizeof(rt));
//     int k,st,end;
//     cin>>k>>st>>end;
//     vector<int>q;
//     for(int i=0;i<12;i++){
//         for(int j=1;j<=d1[i];j++){
//             q.push_back(rt[end][i+1][j]-rt[st][i+1][j]);
//             // printf("[%d %d]",rt[end][i+1][j],rt[st][i+1][j]);
//         }
//     }
//     // auto cmp=[&](const int &a,const int &b)->bool{
//     //     return a>b;
//     // };
//     int r=(end-st+1)*k;
//     int sum=0;
//     sort(q.begin(),q.end());
//     for(int i=0;i<k;i++){
//         sum+=q[i];
//     }
//     cout<<sum<<endl;

// }
// int main(){ 
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t=1;
//     add();
//      cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// LL get_gcd(LL a,LL b)
// {
//     return b!=0?get_gcd(b,a%b):a;
// }
// int main()
// {
//     int t;
//     LL k,n,a,b,c,d;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%lld%lld%lld%lld%lld%lld",&k,&n,&a,&b,&c,&d);
//         LL y1=(k*d)/(c*n);
//         LL y2=y1+1;
//         // printf("%lld,%lld\n",y1,y2);
//         double yy1=1.0*((y1+1)*(c*n))/(k*d);
//         double yy2=1.0*(y2+1)/y2;
//         // printf("%lf,%lf\n",yy1,yy2);
//         LL fz,fmz,fmm,fm;
//         if(yy1>=yy2)
//         {
//             fz=(y1+1)*k*c*n;
//             fm=n*k*d;
//             LL mn=get_gcd(fz,fm);
//             printf("%lld/%lld\n",fz/mn,fm/mn);
//         }
//         else if(yy1<yy2)
//         {
//             fz=(y2+1)*k;
//             fm=y2*n;
//             LL mn=get_gcd(fz,fm);
//             printf("%lld/%lld\n",fz/mn,fm/mn);
//         }
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;

// char s[N];
// int a[N];
// int b[N];

// int main()
// {
//     int t;
//     int n,m;
//     scanf("%d",&t);
//     while(t--)
//     {
//         int sn1=0;
//         int sm1=0;
//         int sn2=0;
//         int sm2=0;
//         scanf("%d%d",&n,&m);
//         getchar();
//         scanf("%s",s+1);
//         for(int i=1;i<=n;i++)
//         {
//             a[i]=s[i]-'0';

//         }
//         getchar();
//         scanf("%s",s+1);
//         for(int i=1;i<+m;i++)
//         {
//             b[i]=s[i]-'0';
//             if()
//         }
//         printf("\n");
//         for(int i=1;i<=n;i++)
//         {
//             if(a[i]==0)
//             {
//                 sn1++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         for(int i=n;i>=1;i--)
//         {
//             if(a[i]==0)
//             {
//                 sn1++;
//             }
//             else
//             {
//                 break;
//             }
//         }    

//         for(int i=1;i<=m;i++)
//         {
//             if(a[i]==0)
//             {

//             }
//         }

        
        
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL =long long;

// int main()
// {
//     int t;
//     LL n,w;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%lld%lld",&n,&w);
//         LL ans1=0;
//         LL ans2=0;
//         LL tot=0;
//         LL m=n;
//         LL p=1;
//         while(m>=w)
//         {
//             tot++;
//             LL num=m/w;
//             m=m-num;
//             ans1+=(2*p+num-1)*num/2;
//             ans2+=ans1;
//             // printf("[%lld]",ans2);
//             p=p+num;
//         }
//         LL s=(tot+1)*(1+n)*n/2;
//         printf("%lld\n",s-ans2);
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// LL get_gcd(LL a,LL b)
// {
//     return b!=0?get_gcd(b,a%b):a;
// }
// int main()
// {
//     int t;
//     LL k,n,a,b,c,d;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%lld%lld%lld%lld%lld%lld",&k,&n,&a,&b,&c,&d);
//         LL y1=(k*d)/(c*n);
//         LL y2=y1+1;
//         LL fz,fm;
//         int tag;
//         double ans1=1.0*(c*(y1+1))/d;
//         double ans2=-1;
//         double ans;
//         double bian=1.0*(b*k)/(a*n);
//         // printf("{%lf}",bian);
//         if(bian>=y2)
//         {
//             ans2=1.0*((y2+1)*k)/(n*y2);
//             // printf("(%lld,%lf)",y1,ans2);
//         }
//         if(ans1>=ans2)
//         {
//             fz=(y1+1)*c;
//             fm=d;
//         }
//         else
//         {
//             fz=(y2+1)*k;
//             fm=n*y2;
//         }        
//         LL gcd=get_gcd(fz,fm);
//         printf("%lld/%lld\n",fz/gcd,fm/gcd);
//     }
//     return 0;
// }


//
#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
using LL=long long;
i128 sum(i128 l,i128 r)
{
    return (l+r)*(r-l+1)/2;
}
int main()
{
    int t;
    LL n,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&w);
        i128 ans=0;
        LL sum;
        LL m=n;
        LL cnt;
        LL p=1;
        LL k;
        LL s1;
        LL s;
        LL s2;
        LL tot=0;
        while(m>=w)
        {
            cnt=n/w;
            sum=cnt*w-1;
            k=(cnt-sum)/cnt+1;
            s1=((1+k)*k*(2*p+cnt-1)*cnt)/4;
            s2=cnt*cnt*((k*k*(1+k))/2-(k*(k+1)*(2*k+1))/6);
            s=s1+s2;
            p=p+k*cnt;
            m=m-cnt*k;
            tot+=k;
        }
    }
    return 0;
}