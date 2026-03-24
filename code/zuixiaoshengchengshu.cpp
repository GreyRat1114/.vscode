//���ǳ�ͨ����
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//#include <cmath>
//using namespace std;
//const int N=5005;
//int fa[N];
//
// void init(int n)
//{
//	for(int i=0;i<=n;i++)
//	{
//		fa[i]=i;
//	}
//}
//int find(int x)
//{
//	int fx,t;
//	fx=x;
//	while(fa[fx]!=fx)
//	{
//		fx=fa[fx];
//		
//	}
//	while(fa[x]!=x)
//	{
//		t=fa[x];
//		fa[x]=fx;
//		x=t;
//	}
//	return fx;
//}
//void merge(int x,int y)
//{
//	int fx,fy;
//	fx=find(x);
//	fy=find(y);
//	if(fx!=fy)
//	{
//		fa[fx]=fy;
//	}
//}
//struct Node{
//	int x;
//	int y;
//	int w;
//};
//Node a[N];
//bool cmp(Node x,Node y)
//{
//	if(x.w<y.w)
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	int n;
//	int x,y,w,ans,d,fx,fy;
//	while(scanf("%d",&n)!=EOF)
//	{
//		if(n==0)
//		{
//			break;
//		}
//		int m=n*(n-1)/2;
//		for(int i=0;i<m;i++)
//		{
//			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
//		}
//		sort(a,a+m,cmp);
//		ans=0;
//		d=0;
//		init(n);
//		for(int i=0;i<m&&d<n-1;i++)
//		{
//			x=a[i].x;
//			y=a[i].y;
//			w=a[i].w;
//			fx=find(x);
//			fy=find(y);
//			if(fx!=fy)
//			{
//				ans+=w;
//				d++;
//				merge(x,y);
//			}
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}


//��ͨ��������
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//#include <cmath>
//using namespace std;
//const int N=105;
//int fa[N];
//int dx[N];
//int dy[N];
// void init(int n)
//{
//	for(int i=0;i<=n;i++)
//	{
//		fa[i]=i;
//	}
//}
//int find(int x)
//{
//	int fx,t;
//	fx=x;
//	while(fa[fx]!=fx)
//	{
//		fx=fa[fx];
//		
//	}
//	while(fa[x]!=x)
//	{
//		t=fa[x];
//		fa[x]=fx;
//		x=t;
//	}
//	return fx;
//}
//void merge(int x,int y)
//{
//	int fx,fy;
//	fx=find(x);
//	fy=find(y);
//	if(fx!=fy)
//	{
//		fa[fx]=fy;
//	}
//}
//struct Node{
//	int x;
//	int y;
//	int w;
//};
//Node a[N*N/2+5];
//bool cmp(Node x,Node y)
//{
//	if(x.w<y.w)
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int n,t;
//	int x,y,w,d,fx,fy;
//	double ans;
//	int dist;
//	int tot;
//	scanf("%d",&t);	
//	while(t--)
//	{
//		int tag=1;
//		tot=0;
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%d%d",&dx[i],&dy[i]);
//			
//		}
//		for(int i=1;i<=n-1;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				
//				dist=(dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]);
//				a[tot].x=i;
//				a[tot].y=j;
//				a[tot].w=dist;
//				tot++;
//			}
//		}
//		sort(a,a+tot,cmp);
//		ans=0;
//		d=0;
//		init(n);
//		for(int i=0;i<tot&&d<n-1;i++)
//		{
//			x=a[i].x;
//			y=a[i].y;
//			w=a[i].w;
//			if(w>1000000||w<100)
//			{
//				continue;
//			}
//			fx=find(x);
//			fy=find(y);
//			if(fx!=fy)
//			{
//				ans+=sqrt(w);
//				d++;
//				merge(x,y);
//			}
//		}
//		int s=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(fa[i]==i)
//			{
//				s++;
//			}
//			if(s>=2)
//			{
//				tag=0;
//				break;
//			}
//		}
//		if(tag)
//		{
//			printf("%.1lf\n",ans*100);
//		}
//		else
//		{
//			printf("oh!\n");
//		}
//	}
//	return 0;
//}


//Networking
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//#include <cmath>
//using namespace std;
//const int N=55;
//const int M=5005;
//int fa[N];
//
// void init(int n)
//{
//	for(int i=0;i<=n;i++)
//	{
//		fa[i]=i;
//	}
//}
//int find(int x)
//{
//	int fx,t;
//	fx=x;
//	while(fa[fx]!=fx)
//	{
//		fx=fa[fx];
//		
//	}
//	while(fa[x]!=x)
//	{
//		t=fa[x];
//		fa[x]=fx;
//		x=t;
//	}
//	return fx;
//}
//void merge(int x,int y)
//{
//	int fx,fy;
//	fx=find(x);
//	fy=find(y);
//	if(fx!=fy)
//	{
//		fa[fx]=fy;
//	}
//}
//struct Node{
//	int x;
//	int y;
//	int w;
//};
//Node a[M];
//bool cmp(Node x,Node y)
//{
//	if(x.w<y.w)
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	int n,m;
//	int x,y,w,ans,d,fx,fy;
//	while(scanf("%d%d",&n,&m)!=EOF)
//	{
//		if(n==0)
//		{
//			break;
//		}
//		for(int i=0;i<m;i++)
//		{
//			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
//		}
//		sort(a,a+m,cmp);
//		ans=0;
//		d=0;
//		init(n);
//		for(int i=0;i<m&&d<n-1;i++)
//		{
//			x=a[i].x;
//			y=a[i].y;
//			w=a[i].w;
//			fx=find(x);
//			fy=find(y);
//			if(fx!=fy)
//			{
//				ans+=w;
//				d++;
//				merge(x,y);
//			}
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}


//Highways
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=755;
// int fa[N];
// int dx[N];
// int dy[N];

// void init(int n)
// {
// 	for(int i=0;i<=n;i++)
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
// void merge(int x,int y)
// {
// 	int fx,fy;
// 	fx=find(x);
// 	fy=find(y);
// 	if(fx!=fy)
// 	{
// 		fa[fx]=fy;
// 	}
// }
// struct Node{
// 	int x;
// 	int y;
// 	int w;
// };
// Node a[N*N/2+5];
// bool cmp(Node x,Node y)
// {
// 	if(x.w<y.w)
// 	{
// 		return true;
// 	}
// 	return false;
// }

// int main()
// {
// 	int n,m;
// 	int x,y,dist;
// 	int fx,fy;
// 	scanf("%d",&n);
// 	int tot=0;
// 	int d=0;
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d%d",&dx[i],&dy[i]);
// 	}
// 	for(int i=1;i<=n-1;i++)
// 	{
// 		for(int j=i+1;j<=n;j++)
// 		{
// 			dist=(dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]);
// 			a[tot].w=dist;
// 			a[tot].x=i;
// 			a[tot].y=j;
// 			tot++;
// 		}
// 	}
// 	init(n);
// 	scanf("%d",&m);
// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d%d",&x,&y);
// 		fx=find(x);
// 		fy=find(y);
// 		if(fx!=fy)	
// 		{
// 			merge(x,y);
// 		}		
// 	}
// 	sort(a,a+tot,cmp);	
// 	for(int i=0;i<tot&&d<n-1;i++)
// 	{
// 		x=a[i].x;
// 		y=a[i].y;
// 		fx=find(x);
// 		fy=find(y);
// 		if(fx!=fy)
// 		{
// 			merge(x,y);
// 			printf("%d %d\n",x,y);
// 		}
// 	}
// 	return 0;
// }

//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//#include <cmath>
//using namespace std;
//const int N=105;
//int fa[N];
//int dx[N];
//int dy[N];
// void init(int n)
//{
//	for(int i=0;i<=n;i++)
//	{
//		fa[i]=i;
//	}
//}
//int find(int x)
//{
//	int fx,t;
//	fx=x;
//	while(fa[fx]!=fx)
//	{
//		fx=fa[fx];
//		
//	}
//	while(fa[x]!=x)
//	{
//		t=fa[x];
//		fa[x]=fx;
//		x=t;
//	}
//	return fx;
//}
//void merge(int x,int y)
//{
//	int fx,fy;
//	fx=find(x);
//	fy=find(y);
//	if(fx!=fy)
//	{
//		fa[fx]=fy;
//	}
//}
//struct Node{
//	int x;
//	int y;
//	int w;
//};
//Node a[N*N/2+5];
//bool cmp(Node x,Node y)
//{
//	if(x.w<y.w)
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int n,t;
//	int x,y,w,d,fx,fy;
//	double ans;
//	int dist;
//	int tot;
//	scanf("%d",&t);	
//	while(t--)
//	{
//		int tag=1;
//		tot=0;
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%d%d",&dx[i],&dy[i]);
//			
//		}
//		for(int i=1;i<=n-1;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				
//				dist=(dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]);
//				a[tot].x=i;
//				a[tot].y=j;
//				a[tot].w=dist;
//				tot++;
//			}
//		}
//		sort(a,a+tot,cmp);
//		ans=0;
//		d=0;
//		init(n);
//		for(int i=0;i<tot&&d<n-1;i++)
//		{
//			x=a[i].x;
//			y=a[i].y;
//			w=a[i].w;
//			if(w>1000000||w<100)
//			{
//				continue;
//			}
//			fx=find(x);
//			fy=find(y);
//			if(fx!=fy)
//			{
//				ans+=sqrt(w);
//				d++;
//				merge(x,y);
//			}
//		}
//		int s=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(fa[i]==i)
//			{
//				s++;
//			}
//			if(s>=2)
//			{
//				tag=0;
//				break;
//			}
//		}
//		if(tag)
//		{
//			printf("%.1lf\n",ans*100);
//		}
//		else
//		{
//			printf("oh!\n");
//		}
//	}
//	return 0;
//}
//Agri-Net
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//#include <cmath>
//using namespace std;
//const int N=105;
//int fa[N];
//int b[N][N];
//void init(int n)
//{
//	for(int i=0;i<=n;i++)
//	{
//		fa[i]=i;
//	}
//}
//int find(int x)
//{
//	int fx,t;
//	fx=x;
//	while(fa[fx]!=fx)
//	{
//		fx=fa[fx];
//		
//	}
//	while(fa[x]!=x)
//	{
//		t=fa[x];
//		fa[x]=fx;
//		x=t;
//	}
//	return fx;
//}
//void merge(int x,int y)
//{
//	int fx,fy;
//	fx=find(x);
//	fy=find(y);
//	if(fx!=fy)
//	{
//		fa[fx]=fy;
//	}
//}
//struct Node{
//	int x;
//	int y;
//	int w;
//};
//Node a[N*N/2+5];
//bool cmp(Node x,Node y)
//{
//	if(x.w<y.w)
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int n;
//	int x,y,w,dist;
//	int fx,fy;
//	while(scanf("%d",&n)!=EOF)
//	{
//		if(n==0)
//		{
//			break;
//		}
//		int tot=0;
//		int ans=0;
//		int d=0;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				scanf("%d",&dist);
//				if(i>=j)
//				{
//					continue;
//				}
//				a[tot].x=i;
//				a[tot].y=j;
//				a[tot].w=dist;
//				tot++;
//			}
//		}
//		sort(a,a+tot,cmp);
//		init(n);
//		for(int i=0;i<tot&&d<n-1;i++)
//		{
//			x=a[i].x;
//			y=a[i].y;
//			w=a[i].w;
//			fx=find(x);
//			fy=find(y);
//			if(fx!=fy)
//			{
//				merge(x,y);
//				d++;
//				ans+=w;
//				
//			}
//		}
//		printf("%d\n",ans);	
//	}
//	return 0;
//}


//������ʷ
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <climits>
//#include <cmath>
//using namespace std;
//const int N=2005;
//int fa[N];
//char c[N][10];
//
//void init(int n)
//{
//	for(int i=0;i<=n;i++)
//	{
//		fa[i]=i;
//	}
//}
//int find(int x)
//{
//	int fx,t;
//	fx=x;
//	while(fa[fx]!=fx)
//	{
//		fx=fa[fx];
//		
//	}
//	while(fa[x]!=x)
//	{
//		t=fa[x];
//		fa[x]=fx;
//		x=t;
//	}
//	return fx;
//}
//void merge(int x,int y)
//{
//	int fx,fy;
//	fx=find(x);
//	fy=find(y);
//	if(fx!=fy)
//	{
//		fa[fx]=fy;
//	}
//}
//struct Node{
//	int x;
//	int y;
//	int w;
//};
//Node a[N*N/2+5];
//bool cmp(Node x,Node y)
//{
//	if(x.w<y.w)
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	int n;
//	int x,y,w;
//	int fx,fy;
//	while(scanf("%d",&n)!=EOF)
//	{
//		if(n==0)
//		{
//			break;
//		}
//		int tot=0;
//		int ans=0;
//		int d=0;
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%s",c[i]);			
//		}
//		int s;
//		for(int i=1;i<=n-1;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				s=0;
//				for(int k=0;k<7;k++)
//				{
//					if(c[i][k]!=c[j][k])
//					{
//						s++;
//					}
//				}
//				a[tot].x=i;
//				a[tot].y=j;
//				a[tot].w=s;
//				tot++;
//			}
//		}
//		sort(a,a+tot,cmp);
//		init(n);
//		for(int i=0;i<tot&&d<n-1;i++)
//		{
//			x=a[i].x;
//			y=a[i].y;
//			w=a[i].w;
//			fx=find(x);
//			fy=find(y);
//			if(fx!=fy)
//			{
//				merge(x,y);
//				d++;
//				ans+=w;				
//			}
//		}
//		printf("The highest possible quality is 1/%d.\n",ans);	
//	}
//	return 0;
//}

//Constructing Roads
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=105;
// int fa[N];
// void init(int n)
// {
// 	for(int i=0;i<=n;i++)
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
// void merge(int x,int y)
// {
// 	int fx,fy;
// 	fx=find(x);
// 	fy=find(y);
// 	if(fx!=fy)
// 	{
// 		fa[fx]=fy;
// 	}
// }
// struct Node{
// 	int x;
// 	int y;
// 	int w;
// };
// Node a[N*N/2+5];
// bool cmp(Node x,Node y)
// {
// 	if(x.w<y.w)
// 	{
// 		return true;
// 	}
// 	return false;
// }

// int main()
// {
// 	int n;
// 	int x,y,w,dist;
// 	int fx,fy;
// 	scanf("%d",&n);
// 	int tot=0;
// 	int ans=0;
// 	int d=0;
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=n;j++)
// 		{
// 			scanf("%d",&dist);
// 			if(i>=j)
// 			{
// 				continue;
// 			}
// 			a[tot].x=i;
// 			a[tot].y=j;
// 			a[tot].w=dist;
// 			tot++;
// 		}
// 	}
// 	init(n);
// 	int q;
// 	scanf("%d",&q);
// 	for(int i=1;i<=q;i++)
// 	{
// 		scanf("%d%d",&x,&y);
// 		merge(x,y);
// 	}
// 	sort(a,a+tot,cmp);
	
// 	for(int i=0;i<tot&&d<n-1;i++)
// 	{
// 		x=a[i].x;
// 		y=a[i].y;
// 		w=a[i].w;
// 		fx=find(x);
// 		fy=find(y);
// 		if(fx!=fy)
// 		{
// 			merge(x,y);
// 			d++;
// 			ans+=w;
			
// 		}
// 	}
// 	printf("%d\n",ans);	
// 	return 0;
// }


// Jungle Roads
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=1005;

// struct Node{
// 	int x,y;
// 	int w;
// };
// Node a[N];
// int n,m;
// int fa[N];
// void init()
// {
// 	for(int i=0;i<=n;i++)
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
// 		fa[x]=fa[fx];
// 		x=t;

// 	}
// 	return fx;
// }
// void merge(int x,int y)
// {
// 	int fx=find(x);
// 	int fy=find(y);
// 	if(fx!=fy)
// 	{
// 		fa[fx]=fy;	
// 	}
// }
// bool cmp(Node x,Node y)
// {
// 	if(x.w<y.w)
// 	{
// 		return true;
// 	}
// 	return false;
// }
// int main()
// {
// 	char na;
// 	char g;
// 	int k;
// 	int xx,yy,ww;
// 	int ans,d;
// 	int s;
// 	while(scanf("%d",&n)!=EOF)
// 	{
// 		m=0;
// 		ans=0;
// 		init();
// 		d=0;
// 		if(n==0)
// 		{
// 			break;
// 		}
// 		s=n;
// 		n--;
// 		while(n--)
// 		{
// 			scanf("\n%c",&na);
// 			xx=na-'A'+1;
// 			scanf("%d",&k);
// 			for(int i=1;i<=k;i++)
// 			{
// 				scanf(" %c",&na);
// 				yy=na-'A'+1;
// 				scanf("%d",&ww);
// 				a[++m].x=xx;
// 				a[m].y=yy;
// 				a[m].w=ww;				
// 			}
// 		}
// 		sort(a+1,a+m+1,cmp);
// 		for(int i=1;i<=m&&d<=s-1;i++)
// 		{
// 			int x=a[i].x;
// 			int y=a[i].y;
// 			int w=a[i].w;
// 			int fx=find(x);
// 			int fy=find(y);
// 			if(fx!=fy)
// 			{
// 				merge(x,y);
// 				d++;
// 				ans+=a[i].w;

// 			}
// 		}
// 		printf("%d\n",ans);

// 	}
// 	return 0;
// }