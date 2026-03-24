// // 板子xianduanshu
// #include<bits/stdc++.h>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e6+5;
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
// int n,m,q;
// int main()
// {
//     int op;
//     int x,y,z;
//     scanf("%d%d",&n,&q);
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
//             scanf("%d%d%d",&x,&y,&z);
//             update(1,x,y,z);
//         }
//         else if(op==2)
//         {
//             scanf("%d%d",&x,&y);
//             printf("%lld\n",query(1,x,y));
//         }
//     }
//     return 0;
// }

// Count Color
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e6+5;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
// }tr[N*4];
// long long w[N];
// void pushup(int u)
// {
//     tr[u].sum=tr[lc].sum|tr[rc].sum;
// }
// void pushdown(int u)
// {
//     if(tr[u].add)
//     {
//         tr[lc].sum=tr[u].add;
//         tr[rc].sum=tr[u].add;
//         tr[lc].add=tr[u].add;
//         tr[rc].add=tr[u].add;
//         tr[u].add=0;
//     }
// }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,0,0};
//     if(l==r)
//     {
//         tr[u].sum=1;
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
//         tr[u].sum=k;
//         tr[u].add=k;
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
//         sum=sum|query(lc,l,r);
//     }
//     if(r>m)
//     {
//         sum=sum|query(rc,l,r);
//     }
//     return sum;
// }
// int n,m,q;
// int main()
// {
//     char op;
//     int x,y,z;
//     scanf("%d%d%d",&n,&m,&q);
//     build(1,1,n);
//     for(int i=1;i<=q;i++)
//     {
//         op=getchar();
//         scanf("%c",&op);
//         if(op=='C')
//         {
//             scanf("%d%d%d",&x,&y,&z);
//             if(x>y)
//             {
//                 swap(x,y);
//             }
//             long long k=1<<(z-1);
//             update(1,x,y,k);
//         }
//         else if(op=='P')
//         {
//             scanf("%d%d",&x,&y);
//             if(x>y)
//             {
//                 swap(x,y);
//             }
//             long long p=query(1,x,y);
//             int s=0;
//             while(p)
//             {
//                 s+=p&1;
//                 p=p>>1;
//             }
//             printf("%d\n",s);
//         }     
//         // for(int i=1;i<=13;i++)
//         // {
//         //     printf("{%d,%d},",tr[i].sum,tr[i].add);
//         // }
//         // printf("\n");
//     }
//     return 0;
// }


// Just a Hook
// #include<bits/stdc++.h>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e6+5;
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
//         tr[lc].sum=tr[u].add*(tr[lc].r-tr[lc].l+1);
//         tr[rc].sum=tr[u].add*(tr[rc].r-tr[rc].l+1);
//         tr[lc].add=tr[u].add;
//         tr[rc].add=tr[u].add;
//         tr[u].add=0;
//     }
// }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,0,0};
//     if(l==r)
//     {
//         tr[u].sum=1;
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
//         tr[u].sum=(tr[u].r-tr[u].l+1)*k;
//         tr[u].add=k;
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
// int n,m,q;
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     for(int k=1;k<=t;k++)
//     {
//         int op;
//         int x,y,z;
//         scanf("%d",&n);
//         scanf("%d",&q);
//         build(1,1,n);
//         for(int i=1;i<=q;i++)
//         {
//             scanf("%d%d%d",&x,&y,&z);
//             if(x>y)
//             {
//                 swap(x,y);
//             }
//             update(1,x,y,z);
//         }      
//         printf("Case %d: The total value of the hook is %lld.\n",k,query(1,1,n));
//     }

//     return 0;
// }


// Mayor's posters
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e7+5;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
// }tr[N*4];
// long long w[N];
// int s;
// int lx[N];
// int rx[N];
// bool vis[N];
// void pushdown(int u)
// {
//     if(tr[u].add)
//     {
//         tr[lc].sum=tr[u].add;
//         tr[rc].sum=tr[u].add;
//         tr[lc].add=tr[u].add;
//         tr[rc].add=tr[u].add;
//         tr[u].add=0;
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
// void update(int u,int l,int r,int k)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].sum=k;
//         tr[u].add=k;
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
// void pushpush(int u,int l,int r)
// {
//     if(l==r)
//     {
//         if(vis[tr[u].sum]==false)
//         {
//             s++;
//             vis[tr[u].sum]=true;
//         }
//         return;
//     }
//     pushdown(u);
//     int m=l+r>>1;
//     pushpush(lc,l,m);
//     pushpush(rc,m+1,r);
// }
// int n,m,q;
// int main()
// {
//     int t;
//     int ll,rr;
//     int op;
//     int x,y,z;
//     scanf("%d",&t);
//     while(t--)
//     {
//         s=0;
//         memset(vis,false,sizeof(vis));
//         scanf("%d",&n);
//         build(1,1,N);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d%d",&lx[i],&rx[i]);
//             if(lx[i]<ll)
//             {
//                 ll=lx[i];
//             }
//             if(rx[i]>rr)
//             {
//                 rr=rx[i];
//             }
//             update(1,lx[i],rx[i],i);
            
//         }    
//         pushpush(1,ll,rr); 
//         printf("%d\n",s);   
//     }

//     return 0;
// }


// A Simple Problem with Integers
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e5+5;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
// }tr[N*6];
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
//     tr[u]={l,r,0,0};
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
// int n,m,q;
// int main()
// {
//     char op;
//     long long x,y,z;
//     scanf("%d%d",&n,&q);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&w[i]);
//     }
//     build(1,1,n);
//     for(int i=1;i<=q;i++)
//     {
//         op=getchar();
//         scanf("%c",&op);
//         if(op=='C')
//         {
//             scanf("%lld%lld%lld",&x,&y,&z);
//             if(x>y)
//             {
//                 swap(x,y);
//             }
//             update(1,x,y,z);
//         }
//         else if(op=='Q')
//         {
//             scanf("%d%d",&x,&y);
//             if(x>y)
//             {
//                 swap(x,y);
//             }
//             printf("%lld\n",query(1,x,y));
//         }
//     }
//     return 0;
// }


// Panda
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #include<climits>
// using namespace std;
// int const N=50005;
// int a[N];
// char b[N];
// long long f[N*4];
// void pushup(int root)
// {
// 	int rt;
// 	rt=root<<1;
// 	f[root]=f[rt]+f[rt+1];
// }

// void build(int root,int left,int right)
// {
// 	if(left==right)
// 	{
// 		f[root]=a[right];
// 		return;
// 	}
// 	int mid,rt;
// 	mid=(left+right)>>1;
// 	rt=root<<1;
	
// 	build(rt,left,mid);
// 	build(rt+1,mid+1,right);
// 	pushup(root);
// }

// void update(int root,int left,int right,int pos,int val)
// {
// 	if(left==right)
// 	{
// 		f[root]=val;
// 		return;
// 	}
// 	int mid,rt;
// 	mid=(left+right)>>1;
// 	rt=root<<1;
// 	if(pos<=mid)
// 	{
// 		update(rt,left,mid,pos,val);
// 	}
// 	else
// 	{
// 		update(rt+1,mid+1,right,pos,val);
		
// 	}
// 	pushup(root);	
// }

// int query(int root,int left,int right,int qleft,int qright)
// {
// 	if(qleft>qright)
// 	{
// 		return 0;
// 	}
// 	if(qleft<=left&&qright>=right)
// 	{
// 		return f[root];
// 	}
// 	int mid,rt;
// 	mid=(left+right)>>1;
// 	rt=root<<1;	
// 	int ans=0;
// 	if(qleft<=mid)
// 	{
// 		ans=query(rt,left,mid,qleft,qright);
// 	}
// 	if(qright>mid)
// 	{
// 		ans+=query(rt+1,mid+1,right,qleft,qright);	
// 	}
// 	return ans;			
// }
// int main()
// {
// 	int t,n,m,x,y,z,s,k;
// 	char u;
// 	scanf("%d",&t);
// 	k=1;
// 	while(t--)
// 	{
// 		printf("Case %d:\n",k++);
// 		scanf("%d%d",&n,&m);
// 		for(int i=0;i<=n;i++)
// 		{
// 			a[i]=0;
// 		}
// 		u=getchar();
// 		scanf("%s",b);
// 		for(int i=1;i<n-1;i++)
// 		{
// 			if(b[i-1]=='w'&&b[i]=='b'&&b[i+1]=='w')
// 			{			
// 				a[i]=1;
// 			}
// 			else
// 			{
// 				a[i]=0;
// 			}
// 		}
// 		build(1,1,n);
// 		for(int i=1;i<=m;i++)
// 		{
// 			scanf("%d",&x);
// 			if(x==0)
// 			{
// 				scanf("%d%d",&y,&z);
// 				y++;
// 				z--;
// 				s=query(1,1,n,y,z);
// 				printf("%d\n",s);
// 			}
// 			else
// 			{
// 				scanf("%d",&x);
// 				u=getchar();
// 				scanf("%c",&u);
// 				b[x]=u;
// 				for(int j=x-1;j<=x+1;j++)
// 				{
// 					if(j-1<0||j+1>n-1)
// 					{
// 						continue;
// 					}
// 					if(b[j-1]=='w'&&b[j]=='b'&&b[j+1]=='w')
// 					{			
// 						update(1,1,n,j,1);
// 					}
// 					else
// 					{
// 						update(1,1,n,j,0);
// 					}					
// 				}
// 			}
// 		}	
// 	}

// 	return 0;
// }


// Mayor's posters
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e5+5;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
// }tr[N*4];
// int lx[N];
// int rx[N];
// int a[N];

// long long w[N];
// void pushup(int u)
// {
//     tr[u].sum=tr[lc].sum+tr[rc].sum;
// }
// void pushdown(int u)
// {
//     if(tr[u].add)
//     {
//         tr[lc].sum=tr[u].add*(tr[lc].r-tr[lc].l+1);
//         tr[rc].sum=tr[u].add*(tr[rc].r-tr[rc].l+1);
//         tr[lc].add=tr[u].add;
//         tr[rc].add=tr[u].add;
//         tr[u].add=0;
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
//     pushup(u);

// }
// void update(int u,int l,int r,long long k)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].sum=k;
//         tr[u].add=k;
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
// bool vis[N];
// int ans;
// void query(int u,int x)
// {
//     if(tr[u].l==tr[u].r)
//     {
//         if(tr[u].sum==0)
//         {
//             return;
//         }
//         if(vis[tr[u].sum]==false)
//         {
//             ans++;
//             vis[tr[u].sum]=true;
//             // printf("[%d],%d\n",tr[u].sum,tr[u].l);
//         }
//         return;
//     }
//     int m=tr[u].l+tr[u].r>>1;
//     pushdown(u);
//     if(x<=m)
//     {
//         query(lc,x);
//     }
//     if(x>m)
//     {
//         query(rc,x);
//     }
// }
// int n,m,q;


// int main()
// {
//     int tot;
//     int t;

//     int op;
//     int x,y,z;
//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(vis,false,sizeof(vis));
//         memset(a,0,sizeof(a));
//         ans=0;
//         tot=0;
//         scanf("%d",&n);
//         build(1,1,10*n);        
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d%d",&lx[i],&rx[i]);
//             a[++tot]=lx[i];
//             a[++tot]=rx[i];
//         }
//         // for(int i=1;i<=tot;i++)
//         // {
//         //     printf("(%d)",a[i]);
//         // }
//         // printf("\n");
//         sort(a+1,a+tot+1);
//         // for(int i=1;i<=tot;i++)
//         // {
//         //     printf("(%d)",a[i]);
//         // }
//         // printf("\n");
//         int pos=unique(a+1,a+tot+1)-a-1;
//         // for(int i=1;i<=pos;i++)
//         // {
//         //     printf("{%d}",a[i]);
//         // }
//         // printf("\n");      
//         for(int i=2;i<=pos;i++)
//         {
//             if((a[i]-a[i-1])>1)
//             {
//                 a[++tot]=a[i-1]+1;
//             }
//         }
//         // for(int i=1;i<=tot;i++)
//         // {
//         //     printf("(%d)",a[i]);
//         // }
//         // printf("\n");
//         sort(a+1,a+1+tot);
//         pos=unique(a+1,a+tot+1)-a-1;
//         // for(int i=1;i<=tot;i++)
//         // {
//         //     printf("(%d)",a[i]);
//         // }
//         // printf("\n");
//         for(int i=1;i<=n;i++)
//         {
//             int p1=lower_bound(a+1,a+pos+1,lx[i])-a;
//             int p2=lower_bound(a+1,a+pos+1,rx[i])-a;
//             // printf("|%d,%d|\n",p1,p2);
//             update(1,p1,p2,i);
//         }
//         for(int i=1;i<=pos;i++)
//         {
//             query(1,i);
//         }
//         printf("%d\n",ans);
        
//     }

//     return 0;
// }


// 旅馆
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// #include <stack>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e5+5;
// struct node{
//     int l,r;
//     int lsum;
//     int rsum;
//     int sum;
//     int add;
// }tr[N*4];
// void pushup(int u)
// {
//     tr[u].sum=max(max(tr[lc].sum,tr[rc].sum),tr[lc].rsum+tr[rc].lsum);
//     tr[u].lsum=tr[lc].lsum;
//     tr[u].rsum=tr[rc].rsum;
//     int m=tr[u].l+tr[u].r>>1;

//     if(tr[u].lsum==m-tr[u].l+1)
//     {
//         tr[u].lsum+=tr[rc].lsum;

//     }
//     if(tr[u].rsum==tr[u].r-m)
//     {
//         tr[u].rsum+=tr[lc].rsum;
//     }
// }
// void pushdown(int u)
// {
//     if(tr[u].add!=-1)
//     {
//         tr[lc].add=tr[u].add;
//         tr[rc].add=tr[u].add;    
//         tr[lc].sum=tr[lc].lsum=tr[lc].rsum=(tr[u].add?0:tr[lc].r-tr[lc].l+1);
//         tr[rc].sum=tr[rc].lsum=tr[rc].rsum=(tr[u].add?0:tr[rc].r-tr[rc].l+1);
//         tr[u].add=-1;
//     }
// }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,r-l+1,r-l+1,r-l+1,-1};
//     if(l==r)
//     {
//         return;
//     }
//     int m=l+r>>1;
//     build(lc,l,m);
//     build(rc,m+1,r);

// }
// void update(int u,int l,int r,int k)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].sum=tr[u].lsum=tr[u].rsum=(k?0:tr[u].r-tr[u].l+1);
//         tr[u].add=k;
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
// int query(int u,int x)
// {
//     if(tr[u].l==tr[u].r&&x==1)
//     {
//         return 1;
//     }
//     int m=tr[u].r+tr[u].l>>1;
//     pushdown(u);
//     if(tr[u].sum>=x)
//     {
//         if(tr[lc].sum>=x)
//         {
//             return query(lc,x);
//         }
//         else if(tr[lc].rsum+tr[rc].lsum>=x)
//         {
//             return m-tr[lc].rsum+1;
//         }
//         else
//         {
//             return query(rc,x);
//         }
//     }

//     return 0;
// }
// int n,m,q;
// int main()
// {
//     int op;
//     int x,y,z;
//     scanf("%d%d",&n,&m);
//     build(1,1,n);
//     for(int i=1;i<=m;i++)
//     {
    
//         scanf("%d",&op);
//         if(op==1)
//         {
//             scanf("%d",&x);
//             int s=query(1,x);
//             printf("%d\n",s);
//             if(s)
//             {
//                 update(1,s,s+x-1,1);
//             }
//         }
//         else if(op==2)
//         {
//             scanf("%d%d",&x,&y);
//             update(1,x,x+y-1,0);


//         }
        
//     }
//     return 0;
// }


// Horizontally Visible Segments
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// #include <stack>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=1e6+5;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
//     double px;
//     double py;
// }tr[N*4];
// double w[N];
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
//     tr[u]={l,r,0,0,0,w[l]};
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
// int n,m,q;
// int main()
// {
//     int op;
//     int x,y,z;
//     int c;
//     while(scanf("%d%d",&n,&c)!=EOF)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lf",&w[i]);
//         }
//         build(1,1,n);
//         for(int i=1;i<=q;i++)
//         {
//             scanf("%d%d",&x,&y);
//             // update(1,x,y,z);
//         }
//         printf("\n");
//     }

//     return 0;
// }


// Can you answer these queries?
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
//     if(tr[lc].add==1&&tr[rc].add==1)
//     {
//         tr[u].add=1;
//     }
// }
// // void pushdown(int u)
// // {
// //     if(tr[u].add)
// //     {
// //         tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
// //         tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
// //         tr[lc].add+=tr[u].add;
// //         tr[rc].add+=tr[u].add;
// //         tr[u].add=0;
// //     }
// // }
// void build(int u,int l,int r)
// {
//     tr[u]={l,r,w[l],0};
//     if(l==r)
//     {
//         if(tr[u].sum<=1)
//         {
//             tr[u].add=1;
//         }
        
//         return;
//     }
//     int m=l+r>>1;
//     build(lc,l,m);
//     build(rc,m+1,r);
//     pushup(u);

// }
// void update(int u,int l,int r)
// {
//     if(tr[u].add==1)
//     {
//         return;
//     }
//     if(tr[u].l==tr[u].r)
//     {
//         long long k=sqrt(tr[u].sum);
//         // printf("[%lld]",k);
//         tr[u].sum=k;
//         if(k<=1)
//         {
//             tr[u].add=1;
//         }
//         return;
//     }
//     int m=tr[u].l+tr[u].r>>1;
//     // pushdown(u);

//     if(l<=m)
//     {
//         update(lc,l,r);

//     }
//     if(r>m)
//     {
//         update(rc,l,r);
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
//     // pushdown(u);
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
// int n,m,q;
// int main()
// {
//     int op;
//     int x,y,z;
//     int t=0;
//     while(scanf("%d",&n)!=EOF)
//     {
//         memset(tr,0,sizeof(tr));
//         t++;
//         printf("Case #%d:\n",t);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&w[i]);
//         }
//         scanf("%d",&m);

//         build(1,1,n);
//         // printf("(%d   %d)",n,m);
//         for(int i=1;i<=m;i++)
//         {
//             scanf("%d",&op);
//             if(op==0)
//             {
//                 scanf("%d%d",&x,&y);
//                 if(x>y)
//                 {
//                     swap(x,y);
//                 }
//                 update(1,x,y);
                
//             }
//             else if(op==1)
//             {
//                 scanf("%d%d",&x,&y);
//                 if(x>y)
//                 {
//                     swap(x,y);
//                 }
//                 printf("%lld\n",query(1,x,y));
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }


// Horizontally Visible Segments
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// #define lc u<<1
// #define rc u<<1|1
// const int N=16000;
// struct node{
//     int l,r;
//     long long sum;
//     long long add;
// }tr[N*8];
// struct line{
//     int y1,y2;
//     int x;
//     int id;

// }L[N];
// bool vis[8005][8005];
// long long w[N];
// // void pushup(int u)
// // {
// //     tr[u].sum=tr[lc].sum+tr[rc].sum;
// // }
// void pushdown(int u)
// {
//     if(tr[u].add!=0)
//     {
//         tr[lc].add=tr[u].add;
//         tr[rc].add=tr[u].add;
//         tr[u].add=0;
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
// void update(int u,int l,int r,long long k)
// {
//     if(l<=tr[u].l&&r>=tr[u].r)
//     {
//         tr[u].add=k;
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
// }
// bool cmp(line a,line b)
// {
//     return a.x<b.x;
// }
// void query(int u,int l,int r,int k)
// {
//     if(tr[u].add!=0)
//     {
//         vis[k][tr[u].add]=true;
//         return;
//     }
//     if(tr[u].l==tr[u].r)
//     {
//         return;
//     }
//     int m=tr[u].r+tr[u].l>>1;
//     long long sum=0;
//     if(l<=m)
//     {
//         query(lc,l,r,k);
//     }
//     if(r>m)
//     {
//         query(rc,l,r,k);
//     }
// }
// int n,m,q;
// int main()
// {
//     int op;
//     int x,y1,y2,z;
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&n);
//         memset(vis,false,sizeof(vis));
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d%d%d",&y1,&y2,&x);
//             L[i].y1=y1*2;
//             L[i].y2=y2*2;
//             L[i].x=x;
//             L[i].id=i;
//         }    
//         build(1,1,16000);    
//         sort(L+1,L+n+1,cmp);
//         for(int i=1;i<=n;i++)
//         {
//             query(1,L[i].y1,L[i].y2,L[i].id);
//             update(1,L[i].y1,L[i].y2,L[i].id);
//         }
//         int s=0;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(vis[i][j])
//                 {
//                     for(int k=1;k<=n;k++)
//                     {
//                         if(vis[i][k]&&vis[j][k])
//                         {
//                             s++;
//                         }
//                     }
//                 }
//             }
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     for(int j=1;j<=n;j++)
//         //     {
//         //         printf("%d,",vis[i][j]);
//         //     }
//         // }
//         printf("%d\n",s);
//     }

//     return 0;
// }


// Parade  
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
#define lc u<<1
#define rc u<<1|1
const int N=1e5+5;
struct node{
    int l,r;
    long long sum;
    long long add;
}tr[N*4];
struct L{
    int num;
    long long x1;
    long long x2;
    long long y;
}line[N];
long long xx[N*2];
void pushup(int u)
{
    tr[u].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(int u)
{
    if(tr[u].add)
    {
        tr[lc].sum=tr[u].add;
        tr[rc].sum=tr[u].add;
        tr[lc].add=tr[u].add;
        tr[rc].add=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,int l,int r)
{
    tr[u]={l,r,0,0};
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
        tr[u].sum=(tr[u].r-tr[u].l+1)*k;
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
long long query(int u,int k)
{
    if(tr[u].l==tr[u].r)
    {
        return tr[u].sum;
    }
    int m=tr[u].r+tr[u].l>>1;
    pushdown(u);
    long long sum=0;
    if(k<=m)
    {
        sum+=query(lc,k);
    }
    if(k>m)
    {
        sum+=query(rc,k);
    }
    return sum;
}
bool cmp(L a,L b)
{
    return a.y<b.y;
}
long long p;
vector<pair<long long,long long>> ans;
void get_ans()
{
    long long pre=0;
    long long cur=0;
    for(int i=1;i<=p;i++)
    {
        cur=query(1,i);
        if(pre!=cur)
        {
            // printf("{%d,%d}\n",i,cur);
            ans.push_back(make_pair(xx[i],pre));
            ans.push_back(make_pair(xx[i],cur));
            pre=cur;
        }
    }
    if(cur!=0)
    {
        ans.push_back(make_pair(xx[p-1],cur));
        ans.push_back(make_pair(xx[p-1],0));

    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int op;
    int x,y,z;
    long long l,r,h;
    int n;
    while(~scanf("%d",&n))
    {
        p=0;
        ans.clear();

        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&h,&l,&r);
            line[i].num=i;
            line[i].x1=l;
            line[i].x2=r;
            line[i].y=h;
            xx[i]=l;
            xx[i+n]=r;
        }
        sort(xx+1,xx+2*n+1);
        p=unique(xx+1,xx+2*n+1)-xx-1;
        sort(line+1,line+n+1,cmp);
        build(1,1,p);
        for(int i=1;i<=n;i++)
        {
            long long lt=lower_bound(xx+1,xx+p+1,line[i].x1)-xx;
            long long rt=lower_bound(xx+1,xx+p+1,line[i].x2)-xx;
            update(1,lt,rt-1,line[i].y);
        }
        get_ans();
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf("%lld %lld\n",ans[i].first,ans[i].second);
        }        
    }
    

    return 0;
}