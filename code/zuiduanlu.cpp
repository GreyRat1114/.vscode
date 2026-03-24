//���·
//A Til the Cows Come Home

//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//#define INF 0xffffff
//using namespace std;
//const int N=1005;
//const int M=2005;
//int n,m;
//struct Node{
//	int v;
//	int w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int dist[N];
//bool vis[N];
//void add(int u,int v,int w)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//void spfa(int s)
//{
//	for(int i=1;i<=n;i++)
//	{
//		dist[i] = INF;
//	}
//		
//	memset(vis,false,sizeof(vis));
//	queue<int> q;
//	q.push(s);
//	dist[s]=0;
//	vis[s]=true;
//	int u,v,w;
//	while(!q.empty())
//	{
//		u=q.front();
//		q.pop();
//		vis[u]=false;
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			v=a[i].v;
//			w=a[i].w;
//			if(dist[u]+w<dist[v])
//			{
//				dist[v]=dist[u]+w;
//				if(vis[v]==false)
//				{
//					q.push(v);		
//					vis[v]=true;			
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	int u,v,w;
//	memset(last,0,sizeof(last));	
//	scanf("%d%d",&m,&n);
//	tot=0;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d%d",&u,&v,&w);
//		add(u,v,w);	
//		add(v,u,w);	
//	}
//	spfa(1);
//	printf("%d",dist[n]);	
//	return 0;
//}

//B Invitation Cards
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=1000005;
//const int M=1000005;
//int p,q;
//struct Node{
//	int v;
//	int w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//long long dist1[N];
//bool vis[N];
//int u[N];
//int v[N];
//int w[N];
//void add(int u,int v,int w)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//void spfa(int s)
//{
//	for(int i=1;i<=p;i++)
//	{
//		dist1[i] = INF;
//	}
//		
//	memset(vis,false,sizeof(vis));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=0;
//	vis[s]=true;
//	int u,v,w;
//	while(!q1.empty())
//	{
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			v=a[i].v;
//			w=a[i].w;
//			if(dist1[u]+w<dist1[v])
//			{
//				dist1[v]=dist1[u]+w;
//				if(vis[v]==false)
//				{
//					q1.push(v);		
//					vis[v]=true;			
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		memset(last,0,sizeof(last));
//		tot=0;
//		
//		scanf("%d%d",&p,&q);
//		for(int j=0;j<q;j++)
//		{
//			scanf("%d%d%d",&u[j],&v[j],&w[j]);
//			add(u[j],v[j],w[j]);						
//		}
//		spfa(1);
//		long long sum=0;
//		for(int i=1;i<=p;i++)
//		{
//			sum+=dist1[i];
//		}
//		memset(last,0,sizeof(last));
//		tot=0;		
//		for(int j=0;j<q;j++)
//		{
//			add(v[j],u[j],w[j]);						
//		}	
//		spfa(1);
//		for(int i=1;i<=p;i++)
//		{
//			sum+=dist1[i];
//		}			
//		printf("%lld\n",sum);
//	}
//	return 0;
//}


//Tram
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=105;
//const int M=10005;
//struct Node{
//	int v;
//	int w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n;
//int dist1[N];
//bool vis[N];
//int b[105][105];
//
//void add(int u,int v)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//void spfa(int s)
//{
//	for(int i=1;i<=n;i++)
//	{
//		dist1[i] = INF;
//	}
//		
//	memset(vis,false,sizeof(vis));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=0;
//	vis[s]=true;
//	int u,v,w;
//	while(!q1.empty())
//	{
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			v=a[i].v;
//			if(v==b[u][1])
//			{
//				w=0;
//			}
//			else
//			{
//				w=1;
//			}
//			if(dist1[u]+w<dist1[v])
//			{
//				dist1[v]=dist1[u]+w;
//				if(vis[v]==false)
//				{
//					q1.push(v);		
//					vis[v]=true;			
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	int x,y;
//	int t;
//	memset(b,0,sizeof(b));	
//	scanf("%d%d%d",&n,&x,&y);
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d",&t);
//		for(int j=1;j<=t;j++)
//		{
//			scanf("%d",&b[i][j]);
//			add(i,b[i][j]);
//			add(b[i][j],i);
//		}
//	}
//	spfa(x);
//	int ans=dist1[y];
//	if(ans==INF)
//	{
//		printf("-1");
//	}
//	else
//	{
//		printf("%d",ans);
//	}	
//	return 0;
//}

//Wormholes
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=505;
//const int M=3005;
//struct Node{
//	int v;
//	int w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n,m,w;
//int dist1[N];
//bool vis[N];
//int d[N];
//void add(int u,int v,int w)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//bool spfa(int s)
//{
//	for(int i=1;i<=n;i++)
//	{
//		dist1[i] = INF;
//	}
//	memset(d,0,sizeof(d));	
//	memset(vis,false,sizeof(vis));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=0;
//	vis[s]=true;
//	int u,v,w;
//	while(!q1.empty())
//	{
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			v=a[i].v;
//			w=a[i].w;
//			if(dist1[u]+w<dist1[v])
//			{
//				dist1[v]=dist1[u]+w;
//				if(vis[v]==false)
//				{
//					q1.push(v);		
//					vis[v]=true;	
//					d[v]++;
//					if(d[v]>=n)
//					{
//						return true;
//					}		
//				}
//			}
//		}
//	}
//	return false;
//}
//int main()
//{
//	int f;
//	int s,e,t;
//	scanf("%d",&f);
//	for(int i=1;i<=f;i++)
//	{
//		memset(last,0,sizeof(last));
//		tot=0;
//		scanf("%d%d%d",&n,&m,&w);
//		for(int j=1;j<=m;j++)
//		{
//			scanf("%d%d%d",&s,&e,&t);
//			add(s,e,t);
//			add(e,s,t);
//		}	
//		for(int j=1;j<=w;j++)
//		{
//			scanf("%d%d%d",&s,&e,&t);
//			add(s,e,-t);			
//		}
//		if(spfa(1))
//		{
//			printf("YES\n");
//		}
//		else
//		{
//			printf("NO\n");
//		}
//	}
//	return 0;
//}

//Currency Exchange
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=105;
//const int M=105;
//struct Node{
//	int v;
//	float r;
//	float c;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n,m;
//float dist1[N];
//bool vis[N];
//int d[N];
//void add(int u,int v,float r,float c)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].r=r;
//	a[tot].c=c;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//bool spfa(int s,float z)
//{
//	memset(dist1,0,sizeof(dist1));
//	memset(vis,false,sizeof(vis));
//	memset(d,0,sizeof(d));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=z;
//	vis[s]=true;
//	int u,v;
//	float w;
//	while(!q1.empty())
//	{
//		
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;		
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			
//			v=a[i].v;
//			w=(dist1[u]-a[i].c)*a[i].r;
//			
//			if(w>dist1[v])
//			{
//				dist1[v]=w;
//				if(vis[v]==false)
//				{
//					q1.push(v);	
//					vis[v]=true;		
//				}
//				d[v]++;
//				if(d[v]>n)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//int main()
//{
//	int s;
//	float v;
//	int x,y;
//	float r1,r2,c1,c2;
//	tot=0;
//	memset(last,0,sizeof(last));
//	scanf("%d%d%d%f",&n,&m,&s,&v);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d%f%f%f%f",&x,&y,&r1,&c1,&r2,&c2);
//		add(x,y,r1,c1);
//		add(y,x,r2,c2);
//	}
//	
//	if(spfa(s,v))
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//
//	return 0;
//}

//Silver Cow Party
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=1005;
//const int M=100005;
//struct Node{
//	int v;
//	int w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n,m,x;
//int dist1[N];
//bool vis[N];
//int p[M];
//int q[M];
//int t[M];
//int dist2[N];
//void add(int u,int v,int w)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//void spfa(int s)
//{
//	for(int i=1;i<=n;i++)
//	{
//		dist1[i] = INF;
//	}	
//	memset(vis,false,sizeof(vis));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=0;
//	vis[s]=true;
//	int u,v,w;
//	while(!q1.empty())
//	{
//		
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;		
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			
//			v=a[i].v;
//			w=a[i].w;			
//			if(dist1[u]+w<dist1[v])
//			{
//				dist1[v]=dist1[u]+w;
//				if(vis[v]==false)
//				{
//					q1.push(v);	
//					vis[v]=true;		
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	memset(last,0,sizeof(last));
//	tot=0;
//	scanf("%d%d%d",&n,&m,&x);
//	for(int i=1;i<=m;i++)
//	{
//		scanf("%d%d%d",&p[i],&q[i],&t[i]);
//		add(p[i],q[i],t[i]);
//	}
//	spfa(x);
//	for(int i=1;i<=n;i++)
//	{
//		dist2[i]=dist1[i];
//	}
//	memset(last,0,sizeof(last));
//	tot=0;
//	for(int i=1;i<=m;i++)
//	{
//		add(q[i],p[i],t[i]);
//	}
//	spfa(x);
//	int ans=0;	
//	for(int i=1;i<=n;i++)
//	{
//		dist2[i]+=dist1[i];
//		if(dist2[i]>ans)
//		{
//			ans=dist2[i];
//		}
//	}
//	printf("%d",ans);				
//	return 0;
//}


//Arbitrage
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=35;
//const int M=1005;
//struct Node{
//	int v;
//	float w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n,m;
//float dist1[N];
//bool vis[N];
//int d[N];
//char name[30][30];
//char namex[30];
//void add(int u,int v,float w)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//bool spfa(int s,float z)
//{
//	memset(dist1,0,sizeof(dist1));
//	memset(vis,false,sizeof(vis));
//	memset(d,0,sizeof(d));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=z;
//	vis[s]=true;
//	int u,v;
//	float w;
//	while(!q1.empty())
//	{
//		
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;		
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			
//			v=a[i].v;
//			w=dist1[u]*a[i].w;			
//			if(w>dist1[v])
//			{
//				dist1[v]=w;
//				if(vis[v]==false)
//				{
//					q1.push(v);	
//					vis[v]=true;		
//				}
//				d[v]++;
//				if(d[v]>n)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//int main()
//{	
//	int u,v;
//	float w;
//	int cnt=1;
//	char g;	
//	while(scanf("%d",&n)!=EOF)
//	{
//			
//		if(n==0)
//		{
//			break;
//		}
//		memset(last,0,sizeof(last));
//		tot=0;
//		for(int i=0;i<n;i++)
//		{
//		
//			g=getchar();
//			scanf("%s",name[i]);
//		}			
//		scanf("%d",&m);
//		for(int i=1;i<=m;i++)
//		{
//			scanf("%s",namex);
//			for(int i=0;i<n;i++)
//			{
//				if(strcmp(name[i],namex)==0)
//				{
//					u=i+1;
//				}
//			}
//			scanf("%f",&w);
//			g=getchar();
//			scanf("%s",namex);
//			for(int i=0;i<n;i++)
//			{
//				if(strcmp(name[i],namex)==0)
//				{
//					v=i+1;
//				}
//			}
//			add(u,v,w);				
//		}
//		printf("Case %d: ",cnt++);	
//		if(spfa(1,100))
//		{
//			printf("Yes\n");
//		}
//		else
//		{
//			printf("No\n");
//		}
//	}
//	return 0;
//}


//Easy SSSP
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=1005;
//const int M=100005;
//struct Node{
//	int v;
//	int w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n,m,s;
//long long dist1[N];
//bool vis[N];
//int d[N];
//void add(int u,int v,int w)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//bool spfa(int s)
//{
//	for(int i=1;i<=n;i++)
//	{
//		dist1[i]=INF;
//	}
//	memset(vis,false,sizeof(vis));
//	memset(d,0,sizeof(d));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=0;
//	vis[s]=true;
//	d[s]++;
//	
//	int u,v;
//	long long w;
//	while(!q1.empty())
//	{
//		
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;		
//		for(int i=last[u];i>0;i=a[i].next)
//		{
//			
//			v=a[i].v;
//			w=a[i].w;			
//			if(dist1[u]+w<dist1[v])
//			{
//				dist1[v]=dist1[u]+w;
//				if(vis[v]==false)
//				{
//					q1.push(v);	
//					vis[v]=true;		
//				}
//				d[v]++;
//				if(d[v]>n)
//				{
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//int main()
//{	
//	int tag=0;
//	memset(last,0,sizeof(last));
//	tot=0;
//	int u,v,w;
//	scanf("%d%d%d",&n,&m,&s);
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d%d",&u,&v,&w);
//		add(u,v,w);
//	}
//	if(spfa(s))
//	{
//		printf("-1");
//		tag=1;			
//	}
//	if(tag==0)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			if(d[i]==0)
//			{
//				if(spfa(i))
//				{
//					printf("-1");
//					tag=1;
//					break;			
//				}
//	
//			}	
//		}	
//	}
//	if(tag==0)
//	{
//		spfa(s);
//		for(int i=1;i<=n;i++)
//		{
//			if(d[i]==0)
//			{
//				printf("NoPath\n");
//			}
//			else
//			{
//				printf("%lld\n",dist1[i]);
//			}				
//		}		
//	}
//	return 0;
//}

//����
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=15;
//const int M=305;
//struct Node{
//	int v;
//	int w;
//	int next;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n;
//long long dist1[N];
//bool vis[N];
//int p[N];
//void add(int u,int v,int w)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//void spfa(int s)
//{
//	for(int i=1;i<=n;i++)
//	{
//		dist1[i]=INF;
//	}
//	memset(vis,false,sizeof(vis));
//	queue<int> q1;
//	q1.push(s);
//	dist1[s]=0;
//	vis[s]=true;	
//	int u,v;
//	long long w;
//	while(!q1.empty())
//	{
//		
//		u=q1.front();
//		q1.pop();
//		vis[u]=false;		
//		for(int i=last[u];i>0;i=a[i].next)
//		{			
//			v=a[i].v;
//			w=a[i].w;			
//			if(dist1[u]+w<dist1[v])
//			{
//				dist1[v]=dist1[u]+w;
//				if(vis[v]==false)
//				{
//					q1.push(v);	
//					vis[v]=true;		
//				}
//			}
//		}
//	}
//}
//int main()
//{	
//	int m; 
//	int v,w;
//	while(scanf("%d",&n)!=EOF)
//	{
//		memset(last,0,sizeof(last));
//		memset(p,0,sizeof(p));
//		tot=0;
//		for(int i=0;i<n;i++)
//		{
//			scanf("%d%d",&m,&p[i+1]);
//			for(int j=1;j<=m;j++)
//			{
//				scanf("%d%d",&v,&w);
//				add(i+1,v+1,w);
//			}
//		}
//		int ans=1e9;
//		spfa(1);
//		for(int i=1;i<=n;i++)
//		{
//			if(p[i]==1)
//			{
//				if(dist1[i]<ans)
//				{
//					ans=dist1[i];
//				}
//			}
//		}
//		printf("%d\n",ans);	
//	}
//
//	return 0;
//}


//Farm Game
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// #define INF 0x3f3f3f3f
// const int N=10010;
// const int M=1000000;
// struct Node{
// 	int v;
// 	double w;
// 	int next;
// };
// Node a[M];
// int last[N];
// int tot;
// int n;
// double dist1[N];
// bool vis[N];
// double p[N];
// double wt[N];
// int d[N];
// void add(int u,int v,double w)
// {
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }

// bool spfa(int s)
// {
// 	memset(vis,false,sizeof(vis));
// 	memset(dist1,0,sizeof(dist1));
// 	memset(d,0,sizeof(d));
// 	queue<int> q1;
// 	q1.push(s);
// 	vis[s]=true;	
// 	int u,v;
// 	double w;
// 	d[s]=1;
// 	while(!q1.empty())
// 	{		
// 		u=q1.front();
// 		q1.pop();
// 		vis[u]=false;		
// 		for(int i=last[u];i!=-1;i=a[i].next)
// 		{			
// 			v=a[i].v;
// 			w=a[i].w;			
// 			if(dist1[u]+w>dist1[v])
// 			{
// 				dist1[v]=dist1[u]+w;
// 				if(vis[v]==false)
// 				{
// 					q1.push(v);	
// 					vis[v]=true;
// 					if(++d[v]>n)
// 					{
// 						return false;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return true;
// }

// int main()
// {	
// 	int m; 
// 	int u,v,k;
// 	double w,ans;
	
// 	while(scanf("%d",&n)!=EOF)
// 	{
		
// 		if(n==0)
// 		{
// 			break;
// 		}
// 		memset(last,-1,sizeof(last));
// 		memset(p,0,sizeof(p));
// 		ans=0;
// 		tot=0;
// 		for(int i=1;i<=n;i++)
// 		{
// 			scanf("%lf%lf",&p[i],&wt[i]);
// 		}
// 		for(int i=1;i<=n;i++)
// 		{
// 			add(0,i,log10(p[i]));
// 		}
// 		scanf("%d",&m);
// 		for(int i=1;i<=m;i++)
// 		{
// 			scanf("%d",&k);
// 			scanf("%d",&u);
// 			for(int j=1;j<k;j++)
// 			{
// 				scanf("%lf%d",&w,&v);
// 				add(v,u,log10(w));
// 				u=v;
// 			}
// 		}
// 		spfa(0);
// 		for(int i=1;i<=n;i++)
// 		{
// 			double x;
// 			x=pow(10.0,dist1[i]);
// 			if(p[i]<x)
// 			{
// 				p[i]=x;
// 				ans+=p[i]*wt[i];
// 			}
// 		}
// 		printf("%.2lf\n",ans);
// 	}
	
// 	return 0;
// }


//˫��·��
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//using namespace std;
//#define INF 0x3f3f3f3f
//const int N=105;
//const int M=10005;
//struct Node{
//	int v;
//	int w;
//	int t;
//	int next;
//};
//struct Path{
//	int pos;
//	int val;
//};
//Node a[2*M];
//int last[N];
//int tot;
//int n,m,s,e;;
//int dp[N][M];
//bool vis[N][M];
//void add(int u,int v,int w,int t)
//{
//	tot++;
//	a[tot].v=v;
//	a[tot].w=w;
//	a[tot].t=t;
//	a[tot].next=last[u];
//	last[u]=tot;
//}
//
//void spfa(int s)
//{
//	memset(vis,false,sizeof(vis));
//	memset(dp,0x3f,sizeof(dp));
//	
//	queue<Path> q1;
//	dp[s][0]=0;
//	Path ss;
//	ss.pos=s;
//	ss.val=0;
//	q1.push(ss);	
//	vis[s][0]=true;	
//	Path u;
//	int v,t,w;
//	while(!q1.empty())
//	{
//		
//		u=q1.front();
//		q1.pop();
//		vis[u.pos][u.val]=false;		
//		for(int i=last[u.pos];i>0;i=a[i].next)
//		{			
//			v=a[i].v;
//			t=a[i].t;
//			w=a[i].w+u.val;
//			if(w<=10000&&dp[v][w]>dp[u.pos][u.val]+t)	
//			{
//				dp[v][w]=dp[u.pos][u.val]+t;
//				if(vis[v][w]==false)
//				{
//					Path u1;
//					u1.pos=v;
//					u1.val=w;
//					vis[v][w]=true;
//					q1.push(u1);					
//				}							
//			}	
//		}
//	}
//}
//int main()
//{	 
//	int u,v,w,t;
//	memset(last,0,sizeof(last));
//	tot=0;
//	scanf("%d%d%d%d",&n,&m,&s,&e);
//	for(int i=1;i<=m;i++)
//	{
//		scanf("%d%d%d%d",&u,&v,&w,&t);
//		add(u,v,w,t);
//		add(v,u,w,t);		
//	}
//	spfa(s);
//	int ans=0;
//	int minn=INF;
//	for(int i=0;i<=10000;i++)
//	{
//		if(dp[e][i]<minn)
//		{
//			minn=dp[e][i];
//			ans++;
//		}
//	}
//	printf("%d",ans);
//	return 0;
//}

//Dijkstra
// #include<bits/stdc++.h>
// #define INF 0xffffff
// using namespace std;
// const int N=100005;
// const int M=200005;
// int n,m;
// struct Node{
// 	int v;
// 	int w;
// 	int next;
// };
// Node a[2*M];
// int last[N];
// int tot;
// int dist[N];
// bool vis[N];
// priority_queue<pair<int,int>> q;
// void add(int u,int v,int w)
// {
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }
// void dijkstra(int s)
// {
// 	for(int i=1;i<=n;i++)
// 	{
// 		dist[i] = 1e9+5;
// 	}
// 	memset(vis,false,sizeof(vis));
// 	dist[s]=0;
// 	vis[s]=true;
// 	q.push(make_pair(0,s));	
// 	int u,v,w;
// 	while(!q.empty())
// 	{
// 		u=q.top().second;
// 		q.pop();
// 		vis[u]=false;
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
// 			v=a[i].v;
// 			w=a[i].w;
// 			if(dist[u]+w<dist[v])
// 			{

// 				dist[v]=dist[u]+w;
// 				if(vis[v]==false)
// 				{
// 					q.push(make_pair(-dist[v],v));
// 					vis[v]=true;
// 				}
				
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	int u,v,w,s;
// 	memset(last,0,sizeof(last));	
// 	scanf("%d%d%d",&n,&m,&s);

// 	tot=0;
// 	for(int i=0;i<m;i++)
// 	{
// 		scanf("%d%d%d",&u,&v,&w);
// 		add(u,v,w);	
// 	}
// 	dijkstra(s);
// 	for(int i=1;i<=n;i++)
// 	{
// 		printf("%d ",dist[i]);

// 	}
// 	return 0;
// }

// Colored Portals
// #include<bits/stdc++.h>
// using namespace std;
// const int N=200005;
// const int M=200005;
// int last[N];
// char cl[N][3];
// struct Node{
// 	int v;
// 	int w;
// 	int next;
// };
// int n,q;
// int tot;
// Node a[N*2];

// void add(int u,int v,int w)
// {
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }

// int main()
// {
// 	int n,m;
// 	int t;
// 	scanf("%d",&t);
// 	while(t--)
// 	{
// 	  scanf("%d%d",&n,&q);
// 	  for(int i=1;i<=n;i++)
// 	  {
// 		scanf("%s",cl[i]);
// 	  }
// 	  for(int i=1;i<=q;i++)
// 	  {
// 		scanf("%d%d",)
// 	  }
// 	}
// 	return 0;
// }

// Arrow Path
// #include<bits/stdc++.h>
// using namespace std;
// const int N=200005;
// const int M=200005;
// int last[N];
// char b[2][N];
// struct Node{
// 	int v;
// 	int w;
// 	int next;
// };
// int n,q;
// int tot;
// Node a[N*2];

// void add(int u,int v,int w)
// {
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }

// int main()
// {
// 	int n,m;
// 	int t;
// 	scanf("%d",&t);
// 	while(t--)
// 	{
// 	  scanf("%d",&n);
// 	  for(int i=0;i<2;i++)
// 	  {
// 		scanf("%s",b[i]);				
// 	  }
// 	}
// 	return 0;
// }


