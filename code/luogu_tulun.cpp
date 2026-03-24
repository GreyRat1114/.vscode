// #include<bits/stdc++.h>
// using namespace std;
// const int N=200005;
// const int M=200005;
// char b[5][N];
// int n,m;
// int tag;
// bool vis[5][N];
// int dx[4]={-1,0,0,1};
// int dy[4]={0,-1,1,0};
// void dfs(int x,int y)
// {
// 	int x1=x;
// 	int y1=y;
// 	if(b[x1][y1]=='>')
// 	{
// 		y1=y1+1;
// 	}
// 	else if(b[x1][y1]=='<')
// 	{
// 		y1=y1-1;
// 	}		
//     if(x1==2&&y1==n)
//     {
// 		tag=1;
//         return;
//     }
// 	if(x1>2||x1<1||y1<1||y1>n)
// 	{
// 		return;
// 	}
// 	if(vis[x1][y1])
// 	{
// 		return;
// 	}
// 	vis[x1][y1]=true;
// 	dfs(x1+1,y1);
// 	if(tag)
// 	{
// 		return;
// 	}
// 	dfs(x1-1,y1);
// 	if(tag)
// 	{
// 		return;
// 	}
// 	dfs(x1,y1+1);
// 	if(tag)
// 	{
// 		return;
// 	}	
// 	dfs(x1,y1-1);
// 	return;
// }
// int main()
// {
// 	int t;
// 	scanf("%d",&t);
// 	while(t--)
// 	{
// 		tag=0;
// 		memset(vis,false,sizeof(vis));
// 		scanf("%d",&n);
// 		for(int i=1;i<=2;i++)
// 		{
// 			scanf("%s",b[i]+1);				
// 		}   
// 		dfs(1,2);
// 		dfs(2,1);
// 		if(tag==1)
// 		{
// 			printf("YES\n");
// 		}
// 		else
// 		{
// 			printf("NO\n");
// 		}
// 	}
// 	return 0;
// }

// Did We Get Everything Covered?
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1000005;
// const int M=200005;
// char b[1005];
// int c[30];
// char ans[1005];
// int tot;
// int n,k,m;
// int tag;

// int main()
// {
// 	int t;
// 	scanf("%d",&t);
// 	while(t--)
// 	{
// 		memset(c,0,sizeof(c));
// 		tot=0;
// 		scanf("%d%d%d",&n,&k,&m);
// 		scanf("%s",b);
// 		int sum=0;
// 		int s=0;
// 		for(int i=0;i<m;i++)
// 		{
// 			int w=b[i]-'a';
// 			if(c[w]==0)
// 			{
// 				sum++;				
// 			}
// 			c[w]++;
// 			if(sum==k)
// 			{
// 				memset(c,0,sizeof(c));
// 				sum=0;
// 				s++;
// 				ans[tot]=b[i];
// 				tot++;
// 			}
// 		}
// 		if(s<n)
// 		{
// 			printf("NO\n");
// 			int x;
// 			for(int i=0;i<26;i++)
// 			{
// 				if(c[i]==0)
// 				{
// 					x=i;
// 					break;
// 				}
// 			}
// 			for(int i=0;i<tot;i++)
// 			{
// 				printf("%c",ans[i]);
// 			}
// 			printf("");
// 			while(s<n)
// 			{
// 				printf("%c",x+'a');
// 				s++;
// 			}
// 			printf("\n");
// 		}
// 		else
// 		{
// 			printf("YES\n");
// 		}
		
// 	}

// 	return 0;
// }

// Johnson
// #include<bits/stdc++.h>
// using namespace std;
// const int N=3005;
// const int M=6005;
// #define INF 1e9

// struct Node{
// 	int v,w;
// 	int next;
// }a[2*M];
// int last[N];
// bool vis[M*2];
// long long dist[N];
// long long dist2[N];
// int cnt[N];
// int n,m;
// int tot;
// void add(int u,int v,int w)
// {
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }
// bool spfa(int s)
// {
// 	queue<int>q;
// 	memset(vis,false,sizeof(vis));
// 	memset(cnt,0,sizeof(cnt));
// 	for(int i=0;i<=n;i++)
// 	{
// 		dist[i]=INF;
// 	}
// 	dist[s]=0;
// 	vis[s]=true;
// 	q.push(s);
// 	int u,v,w;

// 	while(!q.empty())
// 	{
// 		u=q.front();
// 		q.pop();
// 		vis[u]=false;
// 		for(int i=last[u];i;i=a[i].next)
// 		{
// 			v=a[i].v;
// 			w=a[i].w;
// 			if(dist[u]+w<dist[v])
// 			{
// 				dist[v]=dist[u]+w;
// 				if(vis[v]==false)
// 				{
// 					q.push(v);
// 					vis[v]=true;	
// 					cnt[v]++;
// 					if(cnt[v]==n+1)
// 					{
// 						return 1;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return 0;

// }
// void dijkstra(int s)
// {
// 	memset(vis,false,sizeof(vis));
// 	for(int i=0;i<=n;i++)
// 	{
// 		dist2[i]=INF;
// 	}
// 	priority_queue<pair<int ,int>> q1;
// 	dist2[s]=0;
// 	q1.push(make_pair(0,s));	
// 	int u,v,w;
// 	while(!q1.empty())
// 	{
// 		u=q1.top().second;
// 		q1.pop();
// 		if(vis[u])
// 		{
// 			continue;
// 		}
// 		vis[u]=true;
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
// 			v=a[i].v;
// 			w=a[i].w;
// 			if(dist2[u]+w<dist2[v])
// 			{
// 				dist2[v]=dist2[u]+w;
// 				q1.push(make_pair(-dist2[v],v));
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	memset(last,0,sizeof(last));
// 	tot=0;
// 	scanf("%d%d",&n,&m);
// 	int u,v,w;
// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d%d%d",&u,&v,&w);
// 		add(u,v,w);

// 	}
// 	for(int i=1;i<=n;i++)
// 	{
// 		add(0,i,0);

// 	}
// 	if(spfa(0))
// 	{
// 		printf("-1\n");
// 		return 0;
// 	}
// 	for(int u=1;u<=n;u++)
// 	{
// 		for(int i=last[u];i;i=a[i].next)
// 		{
// 			int v=a[i].v;
// 			a[i].w+=dist[u]-dist[v];
// 		} 
// 	}
// 	for(int i=1;i<=n;i++)
// 	{
// 		dijkstra(i);
// 		long long ans=0;
// 		for(int j=1;j<=n;j++)
// 		{
// 			if(dist2[j]==INF)
// 			{
// 				ans+=(long long)j*INF;
// 			}
// 			else
// 			{
// 				ans+=(long long)j*(dist2[j]+dist[j]-dist[i]);
// 			}
			
// 		}
// 		printf("%lld\n",ans);
// 	}
// 	return 0;
// }

// 最短路计数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1000006;
// const int M=2000005;
// #define INF 1e9;

// int n,m;
// struct Node{
// 	int v,w;
// 	int next;
// }a[M*2];
// int dist[N];
// long long ans[N];
// int last[N];
// bool vis[N];
// int tot;
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
// 	priority_queue<pair<int ,int>>q;
// 	for(int i=0;i<=n;i++)
// 	{
// 		dist[i]=INF;
// 	}
// 	memset(vis,false,sizeof(vis));
// 	memset(ans,0,sizeof(ans));
// 	dist[s]=0;
// 	q.push(make_pair(0,s));
// 	int u,v,w;
// 	ans[s]=1;
// 	while(!q.empty())
// 	{
		
// 		u=q.top().second;
// 		q.pop();
// 		if(vis[u])
// 		{
// 			continue;
// 		}
// 		vis[u]=true;
		
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
			

// 			v=a[i].v;
// 			w=a[i].w;
// 			if(dist[u]+w<dist[v])
// 			{
// 				ans[v]=ans[u];
// 				dist[v]=dist[u]+w;
// 				q.push(make_pair(-dist[v],v));
// 			}
// 			else if(dist[u]+w==dist[v])
// 			{
// 				ans[v]+=ans[u];
// 				ans[v]=ans[v]%100003;
// 			}
// 		}
// 	}

// }
// int main()
// {
// 	int x,y;
// 	scanf("%d%d",&n,&m);
// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d%d",&x,&y);
// 		add(x,y,1);	
// 		add(y,x,1);
// 	}
// 	dijkstra(1);
// 	for(int i=1;i<=n;i++)
// 	{
// 		printf("%lld\n",ans[i]);
// 	}
// 	return 0;
// }

// 通往奥格瑞玛的道路
// #include<bits/stdc++.h>
// using namespace std;
// const int N=10005;
// const int M=50005;
// #define INF 1e9;
// struct Node{
// 	int v,w;
// 	int b;
// 	int next;
// }a[M*2];
// int last[N];
// long long dist[N];
// long long pay[N];
// bool vis[N];
// int tot;
// int n,m;
// void add(int u,int v,int w)
// {
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }
// void dijkstra(int s,int mid)
// {
// 	priority_queue<pair<int ,int>>q;
// 	for(int i=0;i<=n;i++)
// 	{
// 		dist[i]=INF;
// 	}
// 	memset(vis,false,sizeof(vis));
// 	dist[s]=0;
// 	q.push(make_pair(0,s));
// 	int u,v,w;
// 	while(!q.empty())
// 	{	
// 		u=q.top().second;
// 		q.pop();
// 		if(vis[u])
// 		{
// 			continue;
// 		}
// 		vis[u]=true;	
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
// 			v=a[i].v;
// 			w=a[i].w;
// 			if(pay[v]>mid)
// 			{
// 				continue;
// 			}
// 			if(dist[u]+w<dist[v])
// 			{
// 				dist[v]=dist[u]+w;
// 				q.push(make_pair(-dist[v],v));
// 			}
// 		}
// 	}
// }

// int main()
// {
// 	int b;
// 	int u,v,w;
// 	long long lt,rt,mid;
// 	lt=1e9;
// 	rt=1;
// 	scanf("%d%d%d",&n,&m,&b);
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d",&pay[i]);
// 		if(pay[i]<lt)
// 		{
// 			lt=pay[i];
// 		}
// 		if(pay[i]>rt)
// 		{
// 			rt=pay[i];
// 		}
// 	}
// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d%d%d",&u,&v,&w);
// 		add(u,v,w);
// 		add(v,u,w);
// 	}
// 	while(lt<=rt)
// 	{
// 		mid=(lt+rt)/2;
// 		dijkstra(1,mid);
// 		if(dist[n]>=b)
// 		{
// 			lt=mid+1;
// 		}
// 		else
// 		{
// 			rt=mid-1;
// 		}
// 	}
// 	dijkstra(1,1e9);
// 	if(dist[n]>b)
// 	{
// 		printf("APK\n");
// 	}
// 	else
// 	{
// 		printf("%lld\n",rt+1);
// 	}
// 	return 0;
// }

// Cow Tours
// #include<bits/stdc++.h>
// using namespace std;
// const int N=200;
// const int M=200;
// struct Node{
// 	long long v,w;
// 	int next;
// }a[M*2];
// long long dist[N];
// int xx[N],yy[N];
// char c[200];

// int n,m;
// int tot;
// int last[N];
// void add(int u,int v)
// {
// 	long long w=(xx[u]-xx[v])*(xx[u]-xx[v])+(yy[u]-yy[v])*(yy[u]-yy[v]);
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;

// }
// void dijkstra(int s)
// {

// }
// int main()
// {
// 	int g;
// 	scanf("%d",&n);
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d%d",&xx[i],&yy[i]);

// 	}
// 	for(int i=1;i<=n;i++)
// 	{
// 		g=getchar();
// 		scanf("%s",c+1);
// 		for(int j=1;j<=n;j++)
// 		{
// 			if(c[j]=='1')
// 			{
// 				add(i,j);

// 			}
// 		}
// 	}

// 	return 0;
// }

// 树
// #include<bits/stdc++.h>
// using namespace std;
// char a[2000];
// int n;
// int dfs(int lt,int rt)
// {
// 	if(lt==rt)
// 	{
// 		if(a[rt]=='1')
// 		{
// 			printf("I");
// 			return 1;
// 		}
// 		else if(a[rt]=='0')
// 		{
// 			printf("B");
// 			return 0;
// 		}
// 	}
// 	int x,y;
// 	int mid=(lt+rt)/2;
// 	x=dfs(lt,mid);
// 	y=dfs(mid+1,rt);
// 	if(x==1&&y==1)
// 	{
// 		printf("I");
// 		return 1;
// 	}
// 	else if(x==0&&y==0)
// 	{
// 		printf("B");
// 		return 0;
// 	}
// 	else
// 	{
// 		printf("F");
// 		return 2;
// 	}
// }
// int main()
// {
// 	scanf("%d",&n);
// 	int m=1;
// 	for(int i=1;i<=n;i++)
// 	{
// 		m=m*2;
// 	}
// 	char g=getchar();
// 	scanf("%s",a+1);
// 	dfs(1,m);
// 	return 0;
// }

// 求先序排列
// #include<bits/stdc++.h>
// using namespace std;
// string s,t;
// void dfs(string a,string b)
// {
// 	if(a.length()==0)
// 	{
// 		return;
// 	}
// 	int len=b.length();
// 	char c=b[len-1];
// 	printf("%c",c);
// 	int p=a.find(c);
// 	dfs(a.substr(0,p),b.substr(0,p));
// 	dfs(a.substr(p+1),b.substr(p,a.length()-p-1));

// }
// int main()
// {
// 	cin>>s;
// 	cin>>t;
// 	dfs(s,t);


// 	return 0;
// }

// 新二叉树
// #include<bits/stdc++.h>
// using namespace std;
// char b[5];
// struct node{
// 	int lc,rc,fa;
// 	int tag1,tag2;
// }a[30];

// void dfs(int s)
// {
	
// 	if(a[s].tag1==1)
// 	{
// 		printf("%c",a[s].lc-1+'a');
// 		dfs(a[s].lc);
// 	}
	
	
// 	if(a[s].tag2==1)
// 	{
// 		printf("%c",a[s].rc-1+'a');
// 		dfs(a[s].rc);
// 	}
	

// }
// int main()
// {
// 	memset(a,0,sizeof(a));

// 	int n;
// 	scanf("%d",&n);
// 	char s;
// 	for(int i=1;i<=n;i++)
// 	{
// 		char g=getchar();

// 		scanf("%s",b);
// 		int x=b[0]-'a'+1;
// 		int y=b[1]-'a'+1;
// 		int z=b[2]-'a'+1;
// 		if(i==1)
// 		{
// 			s=b[0];
// 		}
// 		if(b[1]!='*')
// 		{
// 			a[x].lc=y;
// 			a[y].fa=x;
// 			a[x].tag1=1;
// 		}
// 		if(b[2]!='*')
// 		{
// 			a[x].rc=z;
// 			a[z].fa=x;
// 			a[x].tag2=1;
// 		}
			
// 	}
// 	printf("%c",s);
// 	dfs(s-'a'+1);

// 	return 0;
// }


// 遍历问题
// #include<bits/stdc++.h>
// using namespace std;
// char a[100005];
// char b[100005];

// int main()
// {
// 	long long s=1;
// 	scanf("%s",a);
// 	char g=getchar();
// 	scanf("%s",b);
// 	for(int i=0;i<strlen(a);i++)
// 	{
// 		for(int j=1;j<strlen(b);j++)
// 		{
// 			if(a[i]==b[j]&&a[i+1]==b[j-1])
// 			{
// 				s*=2;
// 			}
// 		}
// 	}
// 	printf("%lld",s);

// 	return 0;
// }

// 对称二叉树
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1000005;
// int n;
// int ans;
// int val[N];
// int cs[N];

// struct node{
// 	int lc,rc;
// 	int fa;
// }a[N*4];
// int count(int s)
// {
// 	if(s==-1)
// 	{
// 		return 0;
// 	}
// 	int x=count(a[s].lc);
// 	int y=count(a[s].rc);
// 	cs[s]=x+y+1;
// 	return x+y+1;
// }
// bool dfs(int l,int r)
// {
// 	if(l==-1&&r==-1)
// 	{
// 		return true;
// 	}
// 	if(l==-1||r==-1)
// 	{
// 		return false;
// 	}
// 	if(val[l]!=val[r])
// 	{
// 		return false;
// 	}
// 	return dfs(a[l].lc,a[r].rc)&&dfs(a[l].rc,a[r].lc);
// }
// int main()
// {
// 	memset(a,0,sizeof(a));

// 	scanf("%d",&n);
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d",&val[i]);

// 	}
// 	int x,y;
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d%d",&x,&y);
// 		a[i].lc=x;
// 		a[i].rc=y;
// 		a[x].fa=i;
// 		a[y].fa=i;
// 	}
// 	ans=0;
// 	count(1);
// 	int sum=0;
	
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(dfs(i,i))
// 		{
// 			sum=max(sum,cs[i]);
// 		}
// 	}
// 	printf("%d\n",sum);
// 	return 0;
// }

// HXY造公园
// #include<bits/stdc++.h>
// using namespace std;
// const int N=300005;
// const int M=300005;
// struct node{
// 	int v,w,next;
// }a[M*2];
// int mxd,p;
// int n,m,q;
// int last[N];
// int tot;
// int dist[N];

// int fa[N];
// bool vis[N];
// bool vis2[N];
// int st;
// void init()
// {
// 	for(int i=1;i<=n;i++)
// 	{
// 		fa[i]=i;
// 	}
// }
// int find(int x)
// {
// 	int fx,t;
// 	fx=x;
// 	while(fa[fx]!=fx)
// 	{
// 		fx=fa[fx];

// 	}
// 	while(fa[x]!=x)
// 	{
// 		t=fa[x];
// 		fa[x]=fx;
// 		x=t;
// 	}
// 	return fx;
// }
// void merge(int x,int y){
// 	int xx=find(x);
// 	int yy=find(y);
// 	fa[xx]=yy;
// }
// void add(int u,int v)
// {
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }
// void dfs(int s,int val)
// {
// 	if(mxd<val)
// 	{
// 		mxd=val;
// 		p=s;
// 	}
// 	int v;
// 	for(int i=last[s];i>0;i=a[i].next)
// 	{
// 		v=a[i].v;	
// 		if(!vis[v])
// 		{
// 			vis[v]=true;
// 			dfs(v,val+1);
// 		}
// 	}
// 	vis[s]=false;
// }
// void dfs2(int s,int val)
// {
// 	if(mxd<val)
// 	{
// 		mxd=val;
// 	}
// 	int v;
// 	for(int i=last[s];i>0;i=a[i].next)
// 	{
// 		v=a[i].v;	
// 		if(!vis[v])
// 		{
// 			vis[v]=true;
// 			dfs2(v,val+1);
// 		}
// 	}
// 	vis[s]=false;
// }
// int main()
// {
// 	int x,y;
	
// 	tot=0;
// 	memset(last,0,sizeof(last));
// 	memset(vis,0,sizeof(vis));
// 	memset(vis2,0,sizeof(vis2));
// 	scanf("%d%d%d",&n,&m,&q);
// 	init();
// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d%d",&x,&y);
// 		add(x,y);
// 		add(y,x);
// 		merge(x,y);
		
// 	}

// 	for(int i=1;i<=n;i++)
// 	{
// 		int x=find(i);
// 		if(vis2[x])
// 		{
// 			continue;
// 		}
// 		mxd=-1;
// 		vis[x]=true;
// 		dfs(x,0);
// 		mxd=-1;
// 		vis[p]=true;
// 		dfs2(p,0);
// 		vis2[x]=true;
// 		dist[x]=mxd;
// 	}
// 	for(int i=1;i<=q;i++)
// 	{
// 		int g;
// 		scanf("%d",&g);
// 		if(g==1)
// 		{
// 			scanf("%d",&x);
// 			printf("%d\n",dist[find(x)]);

// 		}
// 		else
// 		{
// 			scanf("%d%d",&x,&y);
// 			int xx=find(x);
// 			int yy=find(y);
// 			if(xx==yy)
// 			{
// 				continue;
// 			}
// 			dist[yy]=max(max((dist[xx]+1)/2+(dist[yy]+1)/2+1,dist[xx]),dist[yy]);
// 			merge(x,y);

// 		}

// 	}
// 	return 0;
// }

//杂务
// #include<bits/stdc++.h>
// using namespace std;
// const int N=10005;
// const int M=1000005;
// struct node{
// 	int v,w;
// 	int next;
// }a[M];
// int tot,tot2;
// int last[N];
// int tx[N];
// int sx[N];
// int topux[N];
// int dist[N];

// void add(int u,int v,int w)
// {
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].w=w;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }
// void topu(int s)
// {
// 	memset(dist,0,sizeof(dist));

// 	queue<int> q;
// 	q.push(s);
// 	int u,v,w;
// 	while(!q.empty())
// 	{
		
// 		u=q.front();
// 		q.pop();
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
// 			v=a[i].v;
// 			w=a[i].w;
// 			sx[v]--;
// 			if(dist[u]+w>dist[v])
// 			{
// 				dist[v]=dist[u]+w;
// 			}
// 			if(sx[v]==0)
// 			{
// 				q.push(v);			
// 			}

// 		}

// 	}
// }


// int main()
// {
// 	int n,num,t,m;
// 	scanf("%d",&n);
// 	memset(last,0,sizeof(last));
// 	memset(sx,0,sizeof(sx));
// 	tot=0;
// 	tot2=0;
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d%d%d",&num,&t,&m);
// 		tx[num]=t;
// 		while(m!=0)
// 		{
// 			sx[num]++;
// 			add(m,num,tx[m]);
// 			scanf("%d",&m);
// 		}
// 	}
// 	int p;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(sx[i]==0)
// 		{
// 			p=i;
// 			add(0,p,0);
// 			sx[p]++;
			
// 		}
// 	}
// 	topu(0);
	
// 	// for(int i=1;i<=tot;i++)
// 	// {
// 	// 	printf("%d %d %d\n",a[i].v,a[i].w,a[i].next);
// 	// }
// 	int ans=0;
// 	int pos;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(dist[i]>ans)
// 		{
// 			ans=dist[i];
// 			pos=i;
// 		}
// 	}
// 	printf("%d",ans+tx[pos]);
// 	return 0;
// }

// 车站分级
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1005;
// const int M=2000005;
// struct node{
// 	int v,next;
// }a[M*2];
// bool lj[1005][1005];
// int sx[N];
// int last[N];
// int topu[N];
// int dist[N];
// int tot1;
// int tot;
// int n,m;
// bool vis[N];
// void add(int u,int v)
// {
// 	tot++;
// 	a[tot].v=v;
// 	a[tot].next=last[u];
// 	last[u]=tot;
// }
// int main()
// {
// 	int s;
// 	int p;
// 	int lt,rt;
// 	tot=0;
// 	memset(last,0,sizeof(last));

// 	scanf("%d%d",&n,&m);


// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d",&s);
// 		memset(vis,false,sizeof(vis));
// 		for(int j=1;j<=s;j++)
// 		{

// 			scanf("%d",&p);
// 			if(j==1)
// 			{
// 				lt=p;
// 			}
// 			if(j==s)
// 			{
// 				rt=p;
// 			}
// 			vis[p]=true;
// 		}
// 		for(int j=lt;j<=rt;j++)
// 		{
// 			if(vis[j]==false)
// 			{
// 				for(int k=lt;k<=rt;k++)
// 				{
// 					if(vis[k]==true&&lj[j][k]==false)
// 					{
						
// 						add(j,k);
// 						lj[j][k]=true;
// 						sx[k]++;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	queue<int>q;

// 	for(int i=1;i<=n;i++)
// 	{
// 		if(sx[i]==0)
// 		{
// 			q.push(i);
// 		}
// 	}
// 	tot1=0;
// 	memset(dist,0,sizeof(dist));
// 	while(!q.empty())
// 	{
// 		int u=q.front();
// 		q.pop();
// 		tot1++;
// 		topu[tot1]=u;
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
// 			int v=a[i].v;
// 			sx[v]--;
// 			if(dist[u]+1>dist[v])
// 			{
// 				dist[v]=dist[u]+1;
// 			}
// 			if(sx[v]==0)
// 			{
// 				q.push(v);
// 			}
// 		}
// 	}
//     int maxDist = 0;
//     for(int i=1; i<=n; i++) {
//         if(dist[i] > maxDist) {
//             maxDist = dist[i];
//         }
//     }
    
//     printf("%d", maxDist+1);
//     return 0;
// }

// 最近公共祖先（模版）
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// int n,m,s,f[N][33],dep[N];

// vector <int> e[N];
// bool vis[N];
// void dfs(int u,int fa)
// {
//     f[u][0]=fa;
//     dep[u]=dep[fa]+1;
//     for(auto v:e[u])
//     {
//         if(v!=fa)
//         {
//             dfs(v,u);
//         }
//     }
// }
// int lca(int u,int v)
// {
//     if(dep[u]<dep[v])
//     {
//         swap(u,v);
//     }
//     for(int i=22;i>=0;i--)
//     {
//         if(dep[f[u][i]]>=dep[v])
//         {
//             u=f[u][i];
//         }

//     }
//     if(u==v)
//     {
//         return u;
//     }
//     for(int i=22;i>=0;i--)
//     {
//         if(f[u][i]!=f[v][i])
//         {
//             u=f[u][i];
//             v=f[v][i];

//         }
//     }
//     return f[u][0];
// }
// void init()
// {
//     for(int j=1;(1<<j)<=n;j++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             f[i][j]=f[f[i][j-1]][j-1];

//         }
//     }
// }
// int main()
// {
//     int x,y;
//     int a,b;
//     scanf("%d%d%d",&n,&m,&s);

//     for(int i=1;i<n;i++)
//     {
//         scanf("%d%d",&x,&y);
//         e[x].push_back(y);
//         e[y].push_back(x);
//     }
//     dfs(s,0);
//     init();
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&a,&b);
//         printf("%d\n",lca(a,b));
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

// 最近公共祖先_Tarjan
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// vector<int> e[N];
// vector<pair<int,int>>query[N];
// int fa[N];
// int vis[N];
// int ans[N];
// int find(int u)
// {
//     if(u==fa[u])
//     {
//         return u;
//     }
//     return fa[u]=find(fa[u]);
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
//     for(auto q:query[u])
//     {
//         int v=q.first;
//         int i=q.second;
//         if(vis[v])
//         {
//             ans[i]=find(v);
//         }
//     }
// }
// int main()
// {
//     int n,m,s;
//     int x,y;
//     int a,b;
//     scanf("%d%d%d",&n,&m,&s);
//     for(int i=1;i<n;i++)
//     {
//         scanf("%d%d",&x,&y);
//         e[x].push_back(y);
//         e[y].push_back(x);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&a,&b);
//         query[a].push_back({b,i});
//         query[b].push_back({a,i});
//     }
//     for(int i=1;i<=n;i++)
//     {
//         fa[i]=i;

//     }
//     tarjan(s);
//     for(int i=1;i<=m;i++)
//     {
//         printf("%d\n",ans[i]);
//     }
//     return 0;
// }

// 货车运输
// #include<bits/stdc++.h>
// #define INF 1e9
// using namespace std;
// const int N=1e4+5;
// const int M=5e4+5;
// int dep[N];
// int f[N][20];
// int w[N][20];
// bool vis[N];
// int n,m;
// struct node1{
//     int x;
//     int y;
//     int w;
// }a[M*2];
// int fa[N];
// struct node2{
//     int v;
//     int w;
//     int next;
// }b[M*2];
// int tot,last[N];

// void add(int u,int v,int w)
// {
//     tot++;
//     b[tot].v=v;
//     b[tot].w=w;
//     b[tot].next=last[u];
//     last[u]=tot;
// }
// int find(int x)
// {
//     int fx,t;
//     fx=x;
//     while(fa[fx]!=fx)
//     {
//         fx=fa[fx];
//     }
//     while(fa[x]!=x)
//     {
//         t=fa[x];
//         fa[x]=fx;
//         x=t;
//     }
//     return fx;
// }
// void merge(int x,int y)
// {
//     int fx,fy;
//     fx=find(x);
//     fy=find(y);
//     if(fx!=fy)
//     {
//         fa[fx]=fy;
//     }
// }
// bool cmp(node1 a,node1 b)
// {
//     if(a.w>b.w)
//     {
//         return true;
//     }
//     return false;
// }
// void kruskal()
// {
//     sort(a+1, a+m+1, cmp); 
//     for(int i=1; i<=n; i++)
//         fa[i]=i;  //并查集初始化 
//     for(int i=1; i<=m; i++)
//         if(find(a[i].x)!=find(a[i].y)){
//             fa[find(a[i].x)]=find(a[i].y);
//             add(a[i].x, a[i].y, a[i].w);
//             add(a[i].y, a[i].x, a[i].w);  //无向图，双向加边 
//         }
//     return ;
// }
// void dfs(int u)
// {
//     vis[u]=true;
//     int v;
//     for(int i=last[u];i>0;i=b[i].next)
//     {
//         v=b[i].v;
//         if(vis[v])
//         {
//             continue;
//         } 
//         dep[v]=dep[u]+1;
//         f[v][0]=u;
//         w[v][0]=b[i].w;
//         dfs(v);             
//     }
//     return;
// }
// int lca(int u,int v)
// {
//     if(find(u)!=find(v))
//     {
//         return -1;
//     }
//     int ans=INF;

//     if(dep[u]<dep[v])
//     {

//         swap(u,v);
//     }
//     for(int i=20;i>=0;i--)
//     {
//         if(dep[f[u][i]]>=dep[v])
//         {
//             ans=min(ans,w[u][i]);
//             u=f[u][i];

//         }

//     }
//     if(u==v)
//     {
//         return ans;
//     }
//     for(int i=20;i>=0;i--)
//         if(f[u][i]!=f[v][i])
//         {
//             u=f[u][i];
//             v=f[v][i];
//             ans=min(ans,min(w[u][i],w[v][i]));

//         }  
//     ans=min(ans,min(w[u][0],w[v][0]));
//     return ans;
// }
// void init1()
// {
//     for(int i=1;i<=N;i++)
//     {
//         fa[i]=i;
//     }
// }
// int main()
// {
//     int x,y,w1;
//     int tot=0;
//     memset(vis,false,sizeof(vis));
//     tot=0;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&x,&y,&w1);

//         a[i].x=x;
//         a[i].y=y;
//         a[i].w=w1;
//     }
//     kruskal();
//     for(int i=1; i<=n; i++)
//     {
//         if(!vis[i]){ 
//             dep[i]=1; 
//             dfs(i);
//             f[i][0]=i;
//             w[i][0]=INF;
//         }
//     }
//     for(int i=1;i<=20;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             f[j][i]=f[f[j][i-1]][i-1]; 
//             w[j][i]=min(w[j][i-1],w[f[j][i-1]][i-1]);
//         }
//     }
//     int q;
//     scanf("%d",&q);
//     for(int i=1;i<=q;i++)
//     {
//         scanf("%d%d",&x,&y);
//         printf("%d\n",lca(x,y));

//     }
//     return 0;
// }


// The Cow Prom S_Tarjan模板
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e4+5;
// const int M=5e4+5;
// int n,m;
// int nx[N];
// int dfn[N];
// int low[N];
// int tot;
// bool instk[N];
// int scc[N];
// int siz[N];
// int cnt;
// bool used[N];
// stack<int> stk;
// vector<int> e[N];
// void tarjan(int x)
// {
//     int y;
//     tot++;
//     dfn[x]=low[x]=tot;
//     stk.push(x);
//     instk[x]=true;
//     for(auto y:e[x])
//     {
//         if(!dfn[y])
//         {
//             tarjan(y);
//             low[x]=min(low[x],low[y]);
//         }
//         else if(instk[y])
//         {
//             low[x]=min(low[x],dfn[y]);

//         }
//     }
//     if(low[x]==dfn[x])
//     {
//         int y;
//         cnt++;
//         do{
//             y=stk.top();
//             stk.pop();
//             instk[y]=false;
//             scc[y]=cnt;
//             siz[cnt]++;
//         }while(x!=y);
//     }
// }
// int main()
// {
//     int u,v;
//     int a,b;
//     tot=0;
//     cnt=0;
//     memset(instk,false,sizeof(instk));
//     memset(dfn,0,sizeof(dfn));  
//     memset(siz,0,sizeof(siz));  
//     memset(scc,0,sizeof(scc));  
//     memset(used,false,sizeof(used));  
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&a,&b);
//         e[a].push_back(b);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             tarjan(i);
//         }
//     }
//     tarjan(1);
//     int sum=0;
//     for(int i=1;i<=cnt;i++)
//     {
//         if(siz[i]>1)
//         {
//             sum++;
//         }
//     }
//     printf("%d",sum);
//     return 0;
// }


// 缩点模板
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// const int M=1e5+5;
// int n,m;
// int u,v;
// int dfn[N];
// int low[N];
// int scc[N];
// int siz[N];
// int din[N];
// int dout[N];

// bool instk[N];
// bool used[N];
// vector<int>e[N];
// vector<int>w[N];
// stack<int>stk;

// int tot;
// int cnt;

// int nx[N];
// void tarjan(int x)
// {
//     int y;
//     tot++;
//     low[x]=dfn[x]=tot;
//     // printf("(%d,%d,%d)",low[x],dfn[x],x);
//     stk.push(x);
//     instk[x]=true;
//     for(auto y:e[x])
//     {
//         if(!dfn[y])
//         {
//             tarjan(y);
//             low[x]=min(low[x],low[y]);
//         }
//         else if(instk[y])
//         {
//             low[x]=min(low[x],dfn[y]);
//         }
//     }
//     // printf("[%d,%d,%d]\n",low[x],dfn[x],x);
//     if(low[x]==dfn[x])
//     {
//         // printf("{%d}",x);
//         int y;
//         cnt++;
//         do{
//             y=stk.top();
//             stk.pop();
//             instk[y]=false;
//             scc[y]=cnt;
//             if(!used[y])
//             {
//                 siz[cnt]+=nx[y];
//                 used[y]=true;
//             }
//         }while(x!=y);
//     }
// }
// int maxn;
// int dist[N];
// int dp[N];
// int main()
// {
//     tot=0;
//     cnt=0;
//     memset(dfn,0,sizeof(dfn));
//     memset(instk,false,sizeof(instk));
//     memset(used,false,sizeof(used));
//     memset(siz,0,sizeof(siz));
//     memset(din,0,sizeof(din));
//     memset(dout,0,sizeof(dout));

//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&nx[i]);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&u,&v);
//         e[u].push_back(v);
          
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             tarjan(i);
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {

//         for(auto j:e[i])
//         {
//             if(scc[i]!=scc[j])
//             {
//                 w[scc[i]].push_back(scc[j]);
//             }
//         }
//     }
//     for(int i=cnt;i;i--)
//     {
//         if(dp[i]==0)
//         {
//             dp[i]=siz[i];
//         }
//         for(auto j:w[i])
//         {
//             dp[j]=max(dp[j],dp[i]+siz[j]);
//         }
//     }
//     int maxnn=0;
//     for(int i=1;i<=cnt;i++)
//     {
//         maxnn=max(maxnn,dp[i]);
//     }
//     printf("%d\n",maxnn);

//     return 0;
// }


// Network of Schools加强版
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// const int M=1e5+5;
// int n,m;
// vector<int> e[N];
// stack<int>stk;
// int a[N];
// int dfn[N];
// bool instk[N];
// int low[N];
// int scc[N];
// int siz[N];
// int din[N];
// int dout[N];
// int tot;
// int cnt;

// void tarjan(int x)
// {
//     int y;
//     tot++;
//     low[x]=dfn[x]=tot;
//     stk.push(x);
//     instk[x]=true;
//     for(auto y:e[x])
//     {
//         if(!dfn[y])
//         {
//             tarjan(y);
//             low[x]=min(low[x],low[y]);

//         }
//         else if(instk[y])
//         {
//             low[x]=min(low[x],dfn[y]);
//         }
//     }
//     if(low[x]==dfn[x])
//     {
//         int y;
//         cnt++;
//         do{
//             y=stk.top();
//             stk.pop();
//             instk[y]=false;
//             scc[y]=cnt;
//         }while(x!=y);
//     }
// }

// int main()
// {
//     int x,y;
//     int u,v;
//     tot=0;
//     cnt=0;
//     memset(instk,false,sizeof(instk));
//     memset(dfn,0,sizeof(dfn));  
//     memset(siz,0,sizeof(siz));  
//     memset(scc,0,sizeof(scc));  
//     memset(din,0,sizeof(din));
//     memset(dout,0,sizeof(dout));
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&x);
//         while(x!=0)
//         {
//             e[i].push_back(x);
//             scanf("%d",&x);
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             tarjan(i);
//         }
//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%d,",scc[i]);
//     // }
//     for(int i=1;i<=n;i++)
//     {
//         for(auto j:e[i])
//         {
//             if(scc[i]!=scc[j])
//             {
//                 din[scc[j]]++;
//                 dout[scc[i]]++;

//             }
//         }
//     }
//     int a=0;
//     int b=0;
//     for(int i=1;i<=cnt;i++)
//     {
//         if(!din[i])
//         {
//             a++;
//         }
//         if(!dout[i])
//         {
//             b++;
//         }
//     }
//     printf("%d\n",a);
//     if(cnt==1)
//     {
//         printf("0");
//     }
//     else
//     {
//         printf("%d",max(a,b));
//     }
//     return 0;
// }

// 割点(割顶)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e4+5;
// const int M=1e5+5;
// int n,m;
// int dfn[N];
// int low[N];
// int cut[N];

// bool instk[N];
// vector<int> e[N];
// stack<int> stk;
// int tot;
// int root;
// int s;
// void tarjan(int x)
// {
//     int y;
//     tot++;
//     dfn[x]=low[x]=tot;
//     int child=0;
//     for(auto y:e[x])
//     {
//         if(!dfn[y])
//         {
//             tarjan(y);
//             low[x]=min(low[x],low[y]);
//             if(low[y]>=dfn[x])
//             {
//                 child++;
//                 if(x!=root||child>1)
//                 {
//                     cut[x]=true;
//                 }
//             }
//         }
//         else
//         {
//             low[x]=min(low[x],dfn[y]);

//         }
//     }

// }
// int main()
// {
//     int x,y;
//     tot=0;
//     s=0;
//     memset(instk,false,sizeof(instk));
//     memset(dfn,0,sizeof(dfn));

//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&x,&y);
//         e[x].push_back(y);
//         e[y].push_back(x);

//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             root=i;
//             tarjan(i);
//         }

//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(cut[i])
//         {
//             s++;
//         }
//     }
//     printf("%d\n",s);
//     for(int i=1;i<=n;i++)
//     {
//         if(cut[i])
//         {
//             printf("%d ",i);
//         }
//     }
//     return 0;
// }


// Roadblocks G
// #include<bits/stdc++.h>
// #define INF 99999999
// using namespace std;
// const int N=5005;
// const int M=1e5+5;

// struct node{
//     int v;
//     int w;
//     int next;
// }c[M*2];
// int last[N];
// int dist1[N];
// int dist2[N];
// bool vis[N];
// queue<int> q1;
// int tot;
// int n,r;
// void add(int u,int v,int w)
// {
//     tot++;
//     c[tot].v=v;
//     c[tot].w=w;
//     c[tot].next=last[u];
//     last[u]=tot;
// }
// void spfa1(int s)
// {
//     int u,v,w;
//     for(int i=0;i<=n;i++)
//     {
//         dist1[i]=INF;
//         dist2[i]=INF;
//     }
//     dist1[s]=0;
//     q1.push(s);
//     while(!q1.empty())
//     {
//         u=q1.front();
//         // printf("{%d}",u);
//         q1.pop();
//         for(int i=last[u];i>0;i=c[i].next)
//         {
//             v=c[i].v;
//             w=c[i].w;
//             if(dist1[u]+w<dist1[v])
//             {
//                 dist2[v]=dist1[v];
//                 dist1[v]=dist1[u]+w;
//                 q1.push(v);
//             }
//             if(dist1[u]+w<dist2[v]&&dist1[u]+w>dist1[v])
//             {
//                 dist2[v]=dist1[u]+w;
//                 q1.push(v);

//             }
//             if(dist2[u]+w<dist2[v])
//             {
//                 dist2[v]=dist2[u]+w;
//                 q1.push(v);
//             }
//         }        
//     }

// }
// int main()
// {
//     int a,b,d;
//     memset(vis,false,sizeof(vis));
//     memset(last,0,sizeof(last));
//     scanf("%d%d",&n,&r);
//     for(int i=1;i<=r;i++)
//     {
//         scanf("%d%d%d",&a,&b,&d);
//         add(a,b,d);
//         add(b,a,d);
//     }
//     spfa1(1);
//     printf("%d",dist2[n]);
//     return 0;
// }

// 飞行路线
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {

//     return 0;
// }

// 受欢迎的牛 G 极大连通分量
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// const int M=5e4+5;
// int low[N];
// int dfn[N];
// int scc[N];
// int siz[N];
// int din[N];
// int dout[N];

// bool instk[N];
// vector<int> e[N];
// stack<int> stk;
// int tot;
// int cnt;
// void tarjan(int x)
// {
//     int y;
//     tot++;
//     low[x]=dfn[x]=tot;
//     stk.push(x);
//     instk[x]=true;
//     for(auto y:e[x])
//     {
//         if(!dfn[y])
//         {
//             tarjan(y);
//             low[x]=min(low[x],low[y]);

//         }
//         else if(instk[y])
//         {
//             low[x]=min(low[x],dfn[y]);
//         }
//     }
//     if(low[x]==dfn[x])
//     {
//         int y;
//         cnt++;
//         do
//         {
//             y=stk.top();
//             stk.pop();
//             instk[y]=false;
//             scc[y]=cnt;
//             siz[cnt]++;

//         }while(y!=x);
//     }
// }
// int main()
// {
//     cnt=0;
//     tot=0;
//     int x,y;
//     memset(instk,false,sizeof(instk));
//     memset(dfn,0,sizeof(dfn));
//     memset(siz,0,sizeof(siz));
//     memset(din,0,sizeof(din));
//     memset(dout,0,sizeof(dout));
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&x,&y);
//         e[x].push_back(y);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             tarjan(i);
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(auto j:e[i])
//         {
//             if(scc[i]!=scc[j])
//             {
//                 din[j]++;
//                 dout[scc[i]]++;                
//             }
            
//         }
//     }
//     int sum=0;
//     int zeros=0;
//     for(int i=1;i<=cnt;i++)
//     {
//         if(dout[i]==0)
//         {
//             sum=siz[i];
//             zeros++;
//         }
//         if(zeros>1)
//         {
//             sum=0;
//         }
        
//     }
//     printf("%d",sum);
//     return 0;
// }

// 炸铁路（割边）
// #include<bits/stdc++.h>
// using namespace std;
// const int N=150+5;
// const int M=5000+5;
// struct edge{
//     int u;
//     int v;
// };
// int low[N];
// int dfn[N];
// int scc[N];
// int siz[N];
// edge bri[M];
// bool instk[N];
// vector<edge> e;
// vector<int> h[N];
// int tot;
// int cnt;
// void add(int a,int b)
// {
//     e.push_back({a,b});
//     h[a].push_back(e.size()-1);

// }
// bool cmp(edge a,edge b)
// {
//     if(a.u<b.u)
//     {
//         return 1;
//     }
//     else if(a.u==b.u)
//     {
//         if(a.v<b.v)
//         {
//             return 1;
//         }
//     }
//     return 0;
// }
// void tarjan(int x,int in_edg)
// {
//     tot++;
//     low[x]=dfn[x]=tot;
//     for(int i=0;i<h[x].size();i++)
//     {
//         int j=h[x][i];
//         int y=e[j].v;
//         if(!dfn[y])
//         {
//             tarjan(y,j);
//             low[x]=min(low[x],low[y]);
//             if(low[y]>dfn[x])
//             {
//                 cnt++;
//                 bri[cnt]={x,y};
//             }
//         }
//         else if(j!=(in_edg^1))
//         {
//             low[x]=min(low[x],dfn[y]);
//         }
//     }
// }
// int main()
// {
//     int n,m;
//     int a,b;
//     cnt=0;
//     memset(instk,false,sizeof(instk));
//     memset(dfn,false,sizeof(dfn));
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&a,&b);
//         add(a,b);
//         add(b,a);

//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             tarjan(i,h[i].front());
//         }
//     }
//     sort(bri+1,bri+cnt+1,cmp);

//     for(int i=1;i<=cnt;i++)
//     {
//         int x=bri[i].u;
//         int y=bri[i].v;
//         printf("%d %d\n",x,y);

//     }
//     return 0;
// }


// 【模板】重链剖分/树链剖分
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


// 【模板】网络最大流 EK
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1205;
// const int M=120005;
// using LL=long long;
// int S,T;
// int n,m;
// int h[N];
// LL mf[N];
// LL pre[2*M];
// int idx=1;
// struct node{
//     LL v,c,ne;

// }e[M*2];
// void add(int a,int b,int c)
// {
//     idx++;
//     e[idx]={b,c,h[a]};
//     h[a]=idx;
// }

// bool bfs()
// {
//     memset(mf,0,sizeof(mf));
//     queue<int> q;
//     q.push(S);
//     mf[S]=1e9;
//     while(q.size())
//     {
//         int u=q.front();
//         q.pop();
//         for(int i=h[u];i>0;i=e[i].ne)
//         {
//             LL v=e[i].v;
//             if(mf[v]==0&&e[i].c)
//             {
//                 mf[v]=min(mf[u],e[i].c);
//                 pre[v]=i;
//                 q.push(v);
//                 if(v==T)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// LL EK()
// {
//     LL flow=0;
//     while(bfs())
//     {
//         int v=T;
//         while(v!=S)
//         {
//             int i=pre[v];
//             e[i].c-=mf[T];
//             e[i^1].c+=mf[T];
//             v=e[i^1].v;
//         }
//         flow+=mf[T];
//     }
//     return flow;
// }

// int main()
// { 
//     int u,v,w;
//     int a,b,c;
//     memset(h,0,sizeof(h));

//     scanf("%d%d%d%d",&n,&m,&S,&T);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&u,&v,&w);
//         add(u,v,w);
//         add(v,u,0);

//     }
//     printf("%lld\n",EK());

//     return 0;
// }


// 【模板】最大流 加强版  Dinic
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// const int M=2e5+5;
// using LL=long long;

// int last[N];
// int tot=1;
// int d[N];
// int cur[N];
// int s,t;
// int n,m;

// struct node{
//     int v;
//     LL c;
//     int next;
// }a[M*2];
// void add(int u,int v,int w)
// {
//     tot++;
//     a[tot]={v,w,last[u]};
//     last[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));
//     queue<int>q;
//     q.push(s);
//     d[s]=1;
//     while(q.size())
//     {
//         int u=q.front();
//         q.pop();
//         for(int i=last[u];i>0;i=a[i].next)
//         {
//             int v=a[i].v;
//             if(d[v]==0&&a[i].c)
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
//     for(int i=cur[u];i;i=a[i].next)
//     {
//         cur[u]=i;
//         int v=a[i].v;
//         if(d[v]==d[u]+1&&a[i].c)
//         {
//             LL f=dfs(v,min(mf,a[i].c));
//             a[i].c-=f;
//             a[i^1].c+=f;
//             sum+=f;
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

// int main()
// { 
//     int u,v,w;
//     memset(last,0,sizeof(last));

//     scanf("%d%d%d%d",&n,&m,&s,&t);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&u,&v,&w);
//         add(u,v,w);
//         add(v,u,0);

//     }
//     printf("%lld\n",dinic());

//     return 0;
// }


// 地震逃生
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e4+5;
// const int M=1e5+5;
// int d[N];
// int h[N];
// int cur[N];

// int tot=1;
// int n,m,s,t;
// struct node{
//     LL v,c,next;

// }a[M*2];
// void add(int u,int v,int c)
// {
//     tot++;
//     a[tot]={v,c,h[u]};
//     h[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));
//     queue<int> q;
//     q.push(s);
//     d[s]=1;
//     while(!q.empty())
//     {
//         int u=q.front();
//         q.pop();
//         for(int i=h[u];i;i=a[i].next)
//         {
//             int v=a[i].v;
//             if(d[v]==0&&a[i].c)
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
//     for(int i=cur[u];i;i=a[i].next)
//     {
//         cur[u]=i;
//         int v=a[i].v;
//         if(d[v]==d[u]+1&&a[i].c)
//         {
//             LL f=dfs(v,min(mf,a[i].c));
//             a[i].c-=f;
//             a[i^1].c+=f;
//             sum+=f;
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
//         memcpy(cur,h,sizeof(h));
//         flow+=dfs(s,1e18);
//     }
//     return flow;
// }
// int main()
// {
//     int u,v,c;
//     int x;
//     scanf("%d%d%d",&n,&m,&x);
//     s=1;
//     t=n;
//     memset(h,0,sizeof(h));
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&u,&v,&c);
//         add(u,v,c);
//         add(v,u,0);

//     }
//     LL ans1=dinic();
//     if(ans1==0)
//     {
//         printf("Orz Ni Jinan Saint Cow!\n");
//     }
//     else
//     {
//         LL ans2=x/ans1;
//         if(x%ans1!=0)
//         {
//             ans2++;
//         }
//         printf("%lld %lld\n",ans1,ans2);        
//     }

//     return 0;
// }


//  [USACO4.4] 追查坏牛奶 Pollutant Control
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// const int M=1e5+5;
// using LL=long long;
// int d[N];
// int h[N];
// int cur[N];
// bool vis[N];
// int ux[N];
// int vx[N];
// int tot=1;
// int n,m,s,t;
// struct node{
//     LL v,c,next;

// }a[M*2];
// void add(int u,int v,int c)
// {
//     tot++;
//     a[tot]={v,c,h[u]};
//     h[u]=tot;
// }
// bool bfs()
// {
//     memset(d,0,sizeof(d));
//     queue<int> q;
//     q.push(s);
//     d[s]=1;
//     while(!q.empty())
//     {
//         int u=q.front();
//         q.pop();
//         for(int i=h[u];i;i=a[i].next)
//         {
//             int v=a[i].v;
//             if(d[v]==0&&a[i].c)
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
//     for(int i=cur[u];i;i=a[i].next)
//     {
//         cur[u]=i;
//         int v=a[i].v;
//         if(d[v]==d[u]+1&&a[i].c)
//         {
//             LL f=dfs(v,min(mf,a[i].c));
//             a[i].c-=f;
//             a[i^1].c+=f;
//             sum+=f;
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
//         memcpy(cur,h,sizeof(h));
//         flow+=dfs(s,1e18);
//     }
//     return flow;
// }
// void mincut(int u)
// {
//     vis[u]=1;
//     for(int i=h[u];i;i=a[i].next)
//     {
//         int v=a[i].v;
//         if(!vis[v]&&a[i].c)
//         {
//             mincut(v);
//         }
//     }
// }
// int main()
// {
//     int u,v,c;
//     scanf("%d%d",&n,&m);
//     s=1;
//     t=n;
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&u,&v,&c);
//         ux[i]=u;
//         vx[i]=v;
//         add(u,v,c);
//         add(v,u,0);
//     }
//     printf("%lld ",dinic());
//     mincut(s);
//     for(int i=1;i<=m;i++)
//     {
//         add(ux[i],vx[i],1);
//         add(vx[i],ux[i],0);
//     }
//     printf("%lld",dinic());
//     return 0;
// }



//  间谍网络
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=3005;
// #define INF 0x3f3f3f3f
// int n,m;
// vector<int > e[N];
// stack<int>stk;
// int dfn[N];
// int low[N];
// bool instk[N];
// int scc[N];
// int siz[N];
// int din[N];
// int dout[N];
// int cost[N];
// int a[N];
// int tot;
// int cnt;
// void tarjan(int x)
// {
//     int y;
//     tot++;
//     low[x]=dfn[x]=tot;
//     stk.push(x);
//     instk[x]=true;
//     for(int y:e[x])
//     {
//         if(!dfn[y])
//         {
//             tarjan(y);
//             low[x]=min(low[x],low[y]);
//         }
//         else if(instk[y])
//         {
//             low[x]=min(low[x],dfn[y]);

//         }
//     }
//     if(low[x]==dfn[x])
//     {
//         int y;
//         int tag=0;
//         int mini=INF;
//         cnt++;
//         do{
//             y=stk.top();
//             stk.pop();
//             instk[y]=false;
//             scc[y]=cnt;
//             mini=min(mini,a[y]);
//         }while(x!=y);
//         cost[cnt]=mini;
//     }

// }



// int main()
// {    
//     tot=0;
//     cnt=0;
//     memset(instk,false,sizeof(instk));
//     memset(dfn,0,sizeof(dfn));  
//     memset(siz,0,sizeof(siz));  
//     memset(scc,0,sizeof(scc));  
//     memset(din,0,sizeof(din));
//     memset(dout,0,sizeof(dout));


//     int n;
//     scanf("%d",&n);
//     int p;
//     scanf("%d",&p);
//     int x,y;
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=INF;
//     }    
//     for(int i=1;i<=p;i++)
//     {
//         scanf("%d%d",&x,&y);
//         a[x]=y;
//     }
//     int r;
//     scanf("%d",&r);
//     for(int i=1;i<=r;i++)
//     {
//         scanf("%d%d",&x,&y);
//         e[x].push_back(y);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(dfn[i]==0&&a[i]!=INF)
//         {
//             tarjan(i);
//         }
//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(dfn[i]==0)
//         {
//             printf("NO\n%d",i);
//             return 0;
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(auto j:e[i])
//         {
//             if(scc[i]!=scc[j])
//             {
//                 din[scc[j]]++;
//             }
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=cnt;i++)
//     {
//         if(din[i]==0)
//         {
//             ans+=cost[i];
//         }
//     }
//     printf("YES\n%d",ans);
//     return 0;
// }


// 【模板】二分图最大匹配_匈牙利算法
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e4+5;
// using LL =long long;
// int last[N];
// int match[N];
// int vis[N];

// int tot;
// struct node{
//     int v;
//     int next;
// }a[N];
// void add(int u,int v)
// {
//     tot++;
//     a[tot]={v,last[u]};
//     last[u]=tot;
// }
// bool dfs(int u)
// {
//     for(int i=last[u];i>0;i=a[i].next)
//     {
//         int v=a[i].v;
//         if(vis[v])
//         {
//             continue;
//         }
//         vis[v]=1;
//         if(!match[v]||dfs(match[v]))
//         {
//             match[v]=u;
//             return 1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int n,m,e;
//     int u,v;

//     scanf("%d%d%d",&n,&m,&e);
//     for(int i=1;i<=e;i++)
//     {
//         scanf("%d%d",&u,&v);
//         add(v,u);
//     }
//     int ans=0;
//     for(int i=1;i<=m;i++)
//     {
//         memset(vis,0,sizeof(vis));
//         if(dfs(i))
//         {
//             ans++;
//         }
//     }
//     printf("%d",ans);
//     return 0;
// }



// 飞行员配对方案问题
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+5;
// using LL=long long;
// int tot;
// int last[N];
// int match[N];
// int vis[N];
// struct node{
//     int v;
//     int next;
// }a[N];
// void add(int u,int v)
// {
//     tot++;
//     a[tot]={v,last[u]};
//     last[u]=tot;
// }
// bool dfs(int u)
// {
//     // printf("(%d)",u);
//     for(int i=last[u];i>0;i=a[i].next)
//     {
//         int v=a[i].v;
//         if(vis[v])
//         {
//             continue;
//         }
//         vis[v]=1;
//         if(!match[v]||dfs(match[v]))
//         {
//             match[v]=u;
//             // printf("{%d}",match[v]);
//             return 1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     tot=0;
//     memset(last,0,sizeof(last));
//     memset(match,0,sizeof(match));
//     int n,m;
//     int u,v;
//     scanf("%d%d",&m,&n);
//     do{
//         scanf("%d%d",&u,&v);
        
//         if(u==-1&v==-1)
//         {
//             break;
//         }

//         add(u,v);
    
//     }while(1);
//     int ans=0;
//     for(int i=1;i<=m;i++)
//     {
//         memset(vis,0,sizeof(vis));
//         if(dfs(i))
//         {
//             ans++;
//         }
//     }
//     printf("%d\n",ans);
//     for(int i=m+1;i<=n;i++)
//     {
//         if(match[i])
//         {
//             printf("%d %d\n",match[i],i);
//         }
//     }
//     return 0;
// }



// 速递限制
// #include<bits/stdc++.h>
// using namespace std;
// const int N=155;
// const int M=22505;
// int n,m;

// int tot;
// int last[N];
// double dist[N][4*N];
// bool vis[N][4*N];
// struct node{
//     int pre;
//     int w;
// };
// node pre[N][4*N];

// struct edge{
// 	int v,w,next,l;
// }a[M*2];

// void add(int u,int v,int w,int l)
// {
// 	tot++;
// 	a[tot]={v,w,last[u],l};
// 	last[u]=tot;
// }
// void spfa(int s)
// {
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=500;j++)
//         {
//             dist[i][j]=1e9;
//         }
        
//     }
//     queue<pair<int,int>>q;
//     q.push(make_pair(s,70));
//     dist[s][70]=0;
//     vis[s][70]=true;
//     while(!q.empty())
//     {
//         int u=q.front().first;
//         int oldw=q.front().second;
//         vis[u][oldw]=false;
//         q.pop();
//         for(int i=last[u];i>0;i=a[i].next)
//         {
//             int v=a[i].v;
//             int l=a[i].l;
//             int w=a[i].w;
//             if(w==0)
//             {
//                 w=oldw;
//             }
//             double t=1.0*l/w;
//             if(dist[u][oldw]+t<dist[v][w])
//             {
//                 dist[v][w]=dist[u][oldw]+t;
//                 pre[v][w].pre=u;
//                 pre[v][w].w=oldw;

//                 if(vis[v][w]==false)
//                 {
//                     q.push(make_pair(v,w));
//                     vis[v][w]=true;
//                 }
//             }
//         }
//     }
    
// }
// int ans[N];
// void dfs(int pos,int w)
// {
//     if(pre[pos][w].pre!=-1)
//     {
//         dfs(pre[pos][w].pre,pre[pos][w].w);
//     }
//     printf("%d ",pos-1);
// }
// int main()
// {
//     tot=0;
//     memset(vis,false,sizeof(vis));

// 	int d;
// 	scanf("%d%d%d",&n,&m,&d);
//     d++;
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=500;j++)
//         {
//             pre[i][j].pre=-1;
//         }
//     }    
// 	int a,b,w,l;
// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d%d%d%d",&a,&b,&w,&l);
// 		add(a+1,b+1,w,l);
// 	}
//     spfa(1);
//     double mini=1e9;
//     int id;
//     for(int i=0;i<=500;i++)
//     {
//         if(mini>dist[d][i])
//         {
//             mini=dist[d][i];
//             id=i;
//         }
//     }
//     dfs(d,id);
//     // printf("%lf\n",dist[d+1]);

//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%d ",dist[i].pre);
//     // }
// 	return 0;
// }


// 飞行路线
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e4+5;
// const int M=5e4+5;
// struct line{
//     int v,w,next;
// }a[M*2];
// int last[N];
// int dist[N][15];
// bool vis[N][15];
// int tot;
// int n,m,x;
// void add(int u,int v,int w)
// {
//     tot++;
//     a[tot]={v,w,last[u]};
//     last[u]=tot;

// }
// priority_queue<pair<int,pair<int,int>>> q;
// void dijkstra(int s)
// {
// 	for(int i=1;i<=n;i++)
// 	{
//         for(int j=0;j<=15;j++)
//         {
//             dist[i][j] = 1e9+5;
//         }
		
// 	}
// 	memset(vis,false,sizeof(vis));
// 	dist[s][0]=0;
// 	vis[s][0]=true;
// 	q.push(make_pair(0,make_pair(s,0)));	
// 	int u,v,w,k;
// 	while(!q.empty())
// 	{
// 		u=q.top().second.first;
//         k=q.top().second.second;
// 		q.pop();
// 		vis[u][k]=false;
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
// 			v=a[i].v;
// 			w=a[i].w;
// 			if(dist[u][k]+w<dist[v][k])
// 			{
// 				dist[v][k]=dist[u][k]+w;
// 				if(vis[v][k]==false)
// 				{
// 					q.push(make_pair(-dist[v][k],make_pair(v,k)));
// 					vis[v][k]=true;
// 				}
// 			}
//             if(k>=x)
//             {
//                 continue;
//             }
//             if(dist[v][k+1]>dist[u][k])
//             {
//                 dist[v][k+1]=dist[u][k];
//                 if(vis[v][k+1]==false)
//                 {
//                     q.push(make_pair(-dist[v][k+1],make_pair(v,k+1)));
//                     vis[v][k+1]=true;          
//                 }
//             }
// 		}
// 	}
// }
// int main()
// {
//     scanf("%d%d%d",&n,&m,&x);
//     tot=0;
//     memset(vis,false,sizeof(vis)) ;
//     int s,t;
//     scanf("%d%d",&s,&t);
//     int u,v,w;
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&u,&v,&w);
//         add(u+1,v+1,w);
//         add(v+1,u+1,w);

//     }
//     dijkstra(s+1);
//     int mini=1e9;
//     for(int i=0;i<=x;i++)
//     {
//         mini=min(mini,dist[t+1][i]);
//     }
//     printf("%d",mini);
//     return 0;
// }


//  [GXOI/GZOI2019] 旅行者
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// const int M=5e5+5;
// using LL=long long;
// #define mp make_pair
// int last[N];
// int dist[N];
// bool vis[N];
// int b[N];

// struct node{
//     int v,w,next;
// }a[2*M];
// int tot;
// int n,m,k;
// void add(int u,int v,int w)
// {
//     tot++;
//     a[tot]={v,w,last[u]};
//     last[u]=tot;
// }
// priority_queue<pair<int,pair<int,int>>> q;

// void dijkstra(int s)
// {

// }
// int main()
// {
//     int t;
//     int u,v,w;
//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(vis,false,sizeof(vis));
//         scanf("%d%d%d",&n,&m,&k);
//         for(int i=1;i<=m;i++)
//         {
//             scanf("%d%d%d",&u,&v,&w);
//             add(u,v,w);
//         }
//         for(int i=1;i<=k;i++)
//         {
//             scanf("%d",&b[i]);
//         } 
//     }
//     return 0;
// }


// 最大半连通子图
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// const int M=1e6+5;

// using LL=long long;
// LL scc[N];
// LL siz[N];
// LL dfn[N];
// LL low[N];
// LL tot;
// LL cnt;
// bool instk[N];
// vector<int> e[M];
// vector <int> w[M];
// stack<int> stk;
// void tarjan(int x)
// {
//     tot++;
//     dfn[x]=low[x]=tot;
//     stk.push(x);
//     instk[x]=true;
//     for(auto y:e[x])
//     {
//         if(!dfn[y])
//         {
//             tarjan(y);
//             low[x]=min(low[x],low[y]);
//         }
//         else if(instk[y])
//         {
//             low[x]=min(low[x],dfn[y]);

//         }
//     }
//     if(dfn[x]==low[x])
//     {
//         int y;
//         cnt++;
        
//         do{
//             // printf("%d,",cnt);
//             y=stk.top();
//             stk.pop();
//             instk[y]=false;
//             scc[y]=cnt;
//             siz[cnt]++;
//         }while(y!=x);
//     }
// }
// LL dp1[N];
// LL dp2[N];
// int main()
// {
//     memset(dfn,0,sizeof(dfn));
//     memset(instk,false,sizeof(instk));
//     memset(scc,0,sizeof(scc));
//     memset(siz,0,sizeof(siz));
//     tot=0;
//     cnt=0;
//     int n,m;
//     LL x;
//     scanf("%d%d%lld",&n,&m,&x);
//     int a,b;
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&a,&b);
//         e[a].push_back(b);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!dfn[i])
//         {
//             tarjan(i);
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(auto j:e[i])
//         {
//             if(scc[i]!=scc[j])
//             {
//                 w[scc[i]].push_back(scc[j]);
//             }
//         }
//     }
//     for(int i=cnt;i;i--)
//     {
//         if(dp1[i]==0)
//         {
//             dp1[i]=siz[i];
//         }
//         for(auto j:w[i])
//         {
//             dp1[j]=max(dp1[j],dp1[i]+siz[j]);
//         }
        
//     }

//     LL maxn1=0;
//     LL maxn2=0;

//     for(int i=1;i<=cnt;i++)
//     {
//         maxn1=max(maxn1,dp1[i]);
//     }
//     for(int i=cnt;i;i--)
//     {
//         if(dp1[i]==0)
//         {
//             dp1[i]=siz[i];
//         }
//         for(auto j:w[i])
//         {
//             dp1[j]=max(dp1[j],dp1[i]+siz[j]);
//         }
        
//     }    
//     printf("%lld",maxn1);
//     return 0;
// }


//  [USACO4.2] 草地排水 Drainage Ditches
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// const int N=1e3+5;
// int last[N];
// int tot;
// bool vis[N];
// struct node{
//     int v;
//     LL c;
//     int next;

// }a[N];
// int d[N];
// int cur[N];
// int s,t;
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
//     while(!q.empty())
//     {
//         int u=q.front();
//         q.pop();
//         for(int i=last[u];i>0;i=a[i].next)
//         {
//             int v=a[i].v;
//             if(d[v]==0&&a[i].c)
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
//     for(int i=cur[u];i>0;i=a[i].next)
//     {
//         cur[u]=i;
//         int v=a[i].v;
//         if(d[v]==d[u]+1&&a[i].c)
//         {
//             LL f=dfs(v,min(a[i].c,mf));
//             a[i].c-=f;
//             a[i^1].c+=f;
//             sum+=f;
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
// int main()
// {
    
//     memset(last,0,sizeof(last));
//     memset(vis,false,sizeof(vis));
//     tot=1;

//     int n,m;
//     int u,v;;
//     LL c;
//     scanf("%d%d",&n,&m);
//     // cin>>n>>m;
//     s=1;
//     t=m;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d%lld",&u,&v,&c);
//         add(u,v,c);
//         add(v,u,0);
//         // cout<<"{"<<u<<","<<v<<","<<w<<"}"<<"\n";

//     }
//     printf("%lld",dinic());

//     return 0;
// }



//  [TJOI2011] 试题库问题
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+5;
int last[N];
int cur[N];
int b[N];
int r[N];
int vx[N];
int d[N];

int tot;
struct node{
    int v;
    LL c;
    int next;
}a[N];
int k,n;
int s,t;

void add(int u,int v,LL c)
{
    tot++;
    a[tot]={v,c,last[u]};
    last[u]=tot;

}
bool bfs()
{
    memset(d,0,sizeof(d));

    queue<int >q;
    q.push(s);
    d[s]=1;

    while(!q.empty())
    {
        int u,v,c;
        u=q.front();
        q.pop();

        for(int i=last[u];i>0;i=a[i].next)
        {
            v=a[i].v;
            c=a[i].c;

            if(!d[v]&&c)
            {
                d[v]=d[u]+1;
                q.push(v);
                if(t==v)
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
    if(t==u)
    {
        return mf;
    }
    LL sum=0;
    for(int i=cur[u];i>0;i=a[i].next)
    {
        cur[u]=i;
        int v=a[i].v;
        if(d[v]==d[u]+1&&a[i].c)
        {
            LL f=dfs(v,min(mf,a[i].c));
            sum+=f;
            a[i].c-=f;
            a[i^1].c+=f;
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
        flow+=dfs(s,2e9);
    }
    return flow;
}
int main()
{
    tot=1;
    int sum=0;
    memset(last,0,sizeof(last));
    memset(d,0,sizeof(d));
    tot=1;
    cin>>k>>n;
    for(int i=1;i<=k;i++)
    {
        cin>>b[i];
        sum+=b[i];
        add(i+2000,4000,b[i]);
        add(4000,i+2000,0);

    }
    int m;
    int u,v,w;

    for(int i=2;i<=n+1;i++)
    {
        add(1,i,1);
        add(i,1,0);
        u=i;
        cin>>m;
        for(int j=1;j<=m;j++)
        {
            cin>>v;
            v=v+2000;

            add(u,v,1);
            add(v,u,0);
        }

    }
    s=1;
    t=4000;
    // printf("{%d}",last[4001]);
    if(sum==dinic())
    {
        for(int i=1;i<=k;i++)
        {
            printf("%d: ",i);
            int ct=0;
            for(int j=last[i+2000];j>0;j=a[j].next)
            {
                // printf("^");
                int v=a[j].v;

                if(a[j].c&&v<=n+1)
                {
                    ct++;
                    if(ct!=1)
                    {
                        printf(" ");
                    }
                    printf("%d",v-1);
                }
                
            }
            printf("\n");
        }

    }
    else
    {
        printf("No Solution!");
    }
    return 0;
}


// [TJOI2011] 卡片
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+6;
// const int M=1e7+5;
// using LL=long long;
// int last[N];
// int cur[N];
// int tot;
// int d[N];
// int s,t;
// int b[N];
// int r[N];
// struct node{
//     int v;
//     LL c;
//     int next;
// }a[N];

// void add(int u,int v,LL c)
// {
//     tot++;
//     a[tot].v=v;
//     a[tot].c=c;
//     a[tot].next=last[u];
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

//         for(int i=last[u];i>0;i=a[i].next)
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
//     for(int i=cur[u];i>0;i=a[i].next)
//     {
//         cur[u]=i;
//         v=a[i].v;
//         c=a[i].c;
//         if(d[v]==d[u]+1&&c)
//         {
//             LL f=dfs(v,min(mf,c));
//             a[i].c-=f;
//             a[i^1].c+=f;
//             sum+=f;
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
// int gcd(int a,int b)
// {
//     int t;
//     while(b!=0)
//     {
//         t=a%b;
//         a=b;
//         b=t;

//     }
//     return a;
// }
// int p[N];
// bool isp[M];
// bool vis[M];
// int cnt;
// void isprim(int n)
// {
//     for(int i=2;i<=n;i++)
//     {
//         if(!vis[i])
//         {
//             cnt++;
//             p[cnt]=i;
//         }
//         for(int j=1;1ll*p[j]*i<=n&&j<=cnt;j++)
//         {
//             vis[p[j]*i]=true;
//             if(i%p[j]==0)
//             {
//                 break;
//             }
//         }
//     }
// }
// int main()
// {
//     int T;
//     cin>>T;
//     int m,n;
//     cnt=0;
//     memset(isp,false,sizeof(isp));
//     isprim(M);
//     while(T--)
//     {
//         memset(last,0,sizeof(last));
//         tot=1;
//         s=1;
//         t=4000;
//         cin>>m>>n;
//         for(int i=1;i<=m;i++)
//         {
//             cin>>b[i];
//             add(1,i+1,1);
//             add(i+1,1,0);

//         }
//         for(int i=1;i<=n;i++)
//         {
//             cin>>r[i];
//             add(i+600,t,1);     
//             add(t,i+600,0);

//         }        
//         for(int i=1;i<=m;i++)
//         {
//             for(int j=1;j<=cnt&&p[j]<=b[i];j++)
//             {
//                 if(b[i]%p[j]==0)
//                 {
//                     add(i+1,j+2000,1);
//                     add(j+2000,i+1,0);
//                 }
//             }
//         }
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=cnt&&p[j]<=r[i];j++)
//             {
//                 if(r[i]%p[j]==0)
//                 {
//                     add(j+2000,i+600,1);
//                     add(i+600,j+2000,0);
                    
//                 }
//             }
//         }
//         // for(int i=1;i<=m;i++)
//         // {

//         //     for(int j=1;j<=n;j++)
//         //     {
//         //         int x=b[i];
//         //         int y=r[i];
//         //         int z=x>y?x:y;

//         //         if(isp[z]&&x!=y)
//         //         {
//         //             // printf("{%d,%d:%d}\n",i,j,gcd(b[i],r[j]));
//         //             int bb=i+1;
//         //             int rr=j+600;
//         //             add(bb,rr,1);
//         //             add(rr,bb,0);

//         //         }
//         //     }
//         // }
//         cout<<dinic()<<"\n";
//     }
//     return 0;
// }


// P2472 [SCOI2007] 蜥蜴
// #include<bits/stdc++.h>
// using namespace std;
// const int N=405;
// using LL=long long;
// int last[N];
// int tot;
// int cur[N];
// int d[N];
// int s,t;
// struct node{
//     int v,next;
//     LL c;
// }a[N];
// void add(int u,int v,LL c)
// {
//     tot++;
//     a[tot].v=v;
//     a[tot].c=c;
//     a[tot].next=last[u];
//     last[u]=tot;

// }
// char str[N];
// int pos[N][N];
// int ps[N][N];
// queue<pair<int,int>> q;
// void bfs(int d,int c,int r)
// {
//     while(!q.empty())
//     {
//         int x=q.front().first;
//         int y=q.front().second;
//         for(int i=x-d;i<=x+d;i++)
//         {
//             for(int j=y-d;j<=y+d;j++)
//             {
//                 if(i<1||i>c||j<1||j>r)
//                 {
                    
//                 }
//             }
//         }
//         q.pop();

//     }
// }
// int main()
// {
//     int r,c,d;
//     scanf("%d%d%d",&r,&c,&d);
//     for(int i=1;i<=r;i++)
//     {
//         scanf("%s",str+1);
//         for(int j=1;j<=c;j++)
//         {
//             pos[i][j]=str[j]-'0';

//         }
//     }
//     for(int i=1;i<=r;i++)
//     {
//         scanf("%s",str+1);
//         for(int j=1;j<=c;j++)
//         {
//             if(str[j]=='.')
//             {
//                 ps[i][j]=0;
//             }
//             else if(str[j]=='L')
//             {
//                 ps[i][j]=1;
//                 q.push(make_pair(i,j));
//             }
            
//         }
//     }
//     return 0;
// }


// 【模板】最小费用最大流
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;

// int n,m,s,t;
// struct node{
//     int v,next;
//     LL w,c;

// }a[N];
// int last[N];
// int tot;
// int dist[N];
// bool vis[N];
// LL mf[N];
// int pre[N];
// LL flow;
// LL cost;


// void add(int u,int v,LL w,LL c)
// {
//     tot++;
//     a[tot]={v,last[u],w,c};
//     last[u]=tot;
// }

// bool spfa()
// {
//     memset(dist,0x3f,sizeof(dist));
//     memset(mf,0,sizeof(mf));
//     queue<int> q;
//     q.push(s);
//     dist[s]=0;
//     vis[s]=1;
//     mf[s]=1e18;

//     while(!q.empty())
//     {
//         int u,v;
//         LL w,c;
//         u=q.front();
//         q.pop();
//         vis[u]=0;
//         for(int i=last[u];i>0;i=a[i].next)
//         {
//             v=a[i].v;
//             w=a[i].w;
//             c=a[i].c;
//             if((dist[v]>dist[u]+w)&&c)
//             {
//                 mf[v]=min(mf[u],c);
//                 pre[v]=i;
//                 dist[v]=dist[u]+w;
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
//         cost+=mf[t]*dist[t];

//     }
// }
// int main()
// {
//     tot=1;
//     cost=0;
//     flow=0;
//     memset(last,0,sizeof(last));
//     memset(vis,false,sizeof(vis));

//     cin>>n>>m>>s>>t;
//     int u,v;
//     LL wi,ci;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>u>>v>>ci>>wi;
//         add(u,v,wi,ci);
//         add(v,u,-wi,0);

//     }
//     EK();
//     cout<<flow<<" "<<cost<<"\n";
//     return 0;

// }



// 小明的游戏
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+5;
// using LL=long long;
// #define mp make_pair
// int n,m;
// int g[N][N];
// int dx[4]={-1,0,0,1};
// int dy[4]={0,1,-1,0};
// bool vis[N][N];
// int dist[N][N];
// void solve()
// {
//     memset(dist,0x3f,sizeof(dist));
//     memset(vis,false,sizeof(vis));
//     vector<string> str(N);
//     deque<pair<int,int>> q;

//     for(int i=0;i<n;i++)
//     {
//         cin>>str[i];
//     }
//     int x1,y1,x2,y2;
//     cin>>x1>>y1>>x2>>y2;
//     q.push_front(mp(x1,y1));
//     dist[x1][y1]=0;
//     int x,y;
//     int xx,yy;
//     while(!q.empty())
//     {
//         x=q.front().first;
//         y=q.front().second;
//         q.pop_front();
//         if(vis[x][y]==true)
//         {
//             continue;
//         }
//         vis[x][y]=true;

//         // printf("{%d %d}",x,y);
//         for(int i=0;i<4;i++)
//         {
//             int w=1;
//             xx=x+dx[i];
//             yy=y+dy[i];
           
//             if(xx<0||xx>=n||yy<0||yy>=m)
//             {
//                 continue;
//             }
// //  printf("[%d %d]",xx,yy);
//             if(str[x][y]==str[xx][yy])
//             {
//                 w=0;
//             }
//             if(dist[x][y]+w<dist[xx][yy])
//             {
//                 dist[xx][yy]=dist[x][y]+w;
//                 if(w==0)
//                 {
//                     q.push_front(mp(xx,yy));
//                 }
//                 else if(w==1)
//                 {
//                     q.push_back(mp(xx,yy));

//                 }
//             }
//         }
//     }
//     cout<<dist[x2][y2]<<'\n';
//     // for(int i=0;i<n;i++)
//     // {
//     //     cout<<str[i]<<'\n';
//     // }


// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0); 
//     cout.tie(0); 
//     while(1)
//     {
//         cin>>n>>m;
//         if(n==0&&m==0)
//         {
//             break;
//         }
//         solve();        
//     }

//     return 0;
// }



// P3128 [USACO15DEC] Max Flow P
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e4+5;
// using LL=long long;
// vector<int> e[N];
// int f[N][50];
// int fa[N];
// int dep[N];
// int ans[N];
// int dx[N];

// void dfs(int u,int fa)
// {
//     f[u][0]=fa;
//     dep[u]=dep[fa]+1;
//     for(auto v:e[u])
//     {
//         if(v!=fa)
//         {
//             dfs(v,u);
//         }
//     }
// }
// int lca(int u,int v)
// {
//     if(dep[u]<dep[v])
//     {
//         swap(u,v);
//     }
//     for(int i=22;i>=0;i--)
//     {
//         if(dep[f[u][i]]>=dep[v])
//         {
//             u=f[u][i];
//         }

//     }
//     if(u==v)
//     {
//         return u;
//     }
//     for(int i=22;i>=0;i--)
//     {
//         if(f[u][i]!=f[v][i])
//         {
//             u=f[u][i];
//             v=f[v][i];

//         }
//     }
//     return f[u][0];
// }
// void init(int n)
// {
//     for(int j=1;(1<<j)<=n;j++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             f[i][j]=f[f[i][j-1]][j-1];

//         }
//     }
// }
// void lkf(int u,int ff)
// {
//     for(auto v:e[u])
//     {
//         if(v==ff)
//         {
//             continue;
//         }
//         lkf(v,u);
//         dx[u]+=dx[v];

//     }
// }
// void solve()
// {
//     memset(dx,0,sizeof(dx));
//     int maxn;
//     maxn=0;
//     int n,k;
//     cin>>n>>k;
//     int x,y;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>x>>y;
//         e[x].push_back(y);
//         e[y].push_back(x);

//     }

//     dfs(1,1);
//     init(n);
//     for(int i=1;i<=k;i++)
//     {
//         cin>>x>>y;
//         int lc=lca(x,y);
//         dx[x]++;
//         dx[y]++;
//         dx[lc]--;
//         dx[f[lc][0]]--;

//     }


//     lkf(1,1);    
//     // for(int i=1;i<=n;i++)
//     // {
//     //     for(auto j:q[i])
//     //     {
//     //         printf("(%d %d)\n",i,j);
//     //     }
//     // }
//     for(int i=1;i<=n;i++)
//     {
//         maxn=max(maxn,dx[i]);
        
//     }
//     cout<<maxn<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }