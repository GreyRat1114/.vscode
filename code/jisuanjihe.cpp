// 圆
// #include<bits/stdc++.h>
// using namespace std;
// int x[55];
// int y[55];
// int r[55];
// int main()
// {
//     int n;
//     int tag1=0;
//     int tag2=0;
//     int s=0;
//     int x1,x2,y1,y2;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&x[i]);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&y[i]);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&r[i]);
//     }
//     scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//     for(int i=1;i<=n;i++)
//     {
//         tag1=0;
//         tag2=0;
//         int d1,d2;
//         d1=(x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i]);
//         d2=(x2-x[i])*(x2-x[i])+(y2-y[i])*(y2-y[i]);
//         if(r[i]*r[i]>d1)
//         {
//             tag1=1;
//         }
//         if(r[i]*r[i]>d2)
//         {
//             tag2=1;
//         }        
//         if(tag1&&!tag2)
//         {
//             s++;
//         }
//         else if(!tag1&&tag2)
//         {
//             s++;
//         }
//     }
//     if(s<0)
//     {
//         s=-s;
//     }
//     printf("%d\n",s);
//     return 0;
// }


// 对角线
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     long long s=0;
//     scanf("%d",&n);
//     for(int i=1;i<=n-2;i++)
//     {
//         s+=(n-i)*(n-i-1)/2;
//     }
//     printf("%lld",s);
//     return 0;
// }

// 平面上最接近的点
// #include<bits/stdc++.h>
// using namespace std;
// int x[10005];
// int y[10005];

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&x[i],&y[i]);
//     }
//     double ans=1e10;
//     for(int i=1;i<=n-1;i++)
//     {
//         for(int j=i+1;j<=n;j++)
//         {
//             long long a=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
//             double ans1=sqrt(a);
//             if(ans1<ans)
//             {
//                 ans=ans1;
//             }
//         }
//     }
//     printf("%.4lf",ans);
//     return 0;
// }

// 轰炸
// #include<bits/stdc++.h>
// using namespace std;
// int x[705];
// int y[705];

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&x[i],&y[i]);

//     }
//     int ans=0;
    
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i+1;j<=n;j++)
//         {
//             int s=0;
//             for(int k=1;k<=n;k++)
//             {
//                 if((x[j]-x[i])*(y[k]-y[i])==(x[k]-x[i])*(y[j]-y[i]))
//                 {
//                     s++;
//                 }
//             }
//             if(s>ans)
//             {
//                 ans=s;          
//             }
//         }
//     }
//     printf("%d",ans);
//     return 0;
// }

// 摆石子
// #include<bits/stdc++.h>
// using namespace std;
// int x[705];
// int y[705];

// int main()
// {
//     int n,m,k;
//     scanf("%d%d%d",&n,&m,&k);
//     if(n>m)
//     {
//         swap(n,m);
//     }
//     long long ans=0;
//     long long x;
//     long long y;
//     for(int i=1;i<=n;i++)
//     {
//         if(k%i==0&&k/i>m)
//         {
//             continue;
//         }
//         if(k%i!=0&&k/i>m-1)
//         {
//             continue;
//         }
//         x=k/i;
//         y=k%i;
//         ans=max(ans,x*(x-1)/2*i*(i-1)/2+y*(y-1)/2*x);
//     }
//     printf("%lld",ans);
//     return 0;
// }

// 神秘大三角


// Fencing the Cows
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005;
// struct Node{
//     double x,y;
// };
// Node p[N];
// Node s[N];
// double check(Node a1,Node a2,Node b1,Node b2)
// {
//     return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
// }
// double d(Node p1,Node p2)
// {
//     return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));

// }
// bool cmp(Node p1,Node p2)
// {
//     double tmp=check(p[1],p1,p[1],p2);
//     if(tmp>0)
//     {
//         return 1;
//     }
//     if(tmp==0&&d(p[0],p1)<d(p[0],p2))
//     {
//         return 1;
//     }
//     return 0;

// }
// int main()
// {
//     int n;
//     double mid;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lf%lf",&p[i].x,&p[i].y);
//         if(i!=1&&p[i].y<p[1].y||(p[i].y==p[1].y&&p[i].x<p[1].x))
//         {
//             mid=p[1].y;
//             p[1].y=p[i].y;
//             p[i].y=mid;
//             mid=p[1].x;
//             p[1].x=p[i].x;
//             p[i].x=mid;                    
//         }
//     }
//     sort(p+2,p+1+n,cmp);
//     s[1]=p[1];
//     int cnt=1;
//     for(int i=2;i<=n;i++)
//     {
//         while(cnt>1&&check(s[cnt-1],s[cnt],s[cnt],p[i])<=0)
//         {
//             cnt--;
//         }
//         cnt++;
//         s[cnt]=p[i];
//     }
//     s[cnt+1]=p[1];
//     double ans=0;
//     for(int i=1;i<=cnt;i++)
//     {
//         ans+=d(s[i],s[i+1]);
        
//     }
//     printf("%.2lf\n",ans);
//     return 0;
// }

//Beauty Contest G
// #include<bits/stdc++.h>
// using namespace std;
// const int N=50005;
// struct Node{
//     int x;
//     int y;
//     int num;

// };
// Node p[N];
// Node s[N];
// int n;
// int cnt =1;
// int check(Node a1,Node a2,Node b1,Node b2)
// {
//     return (a1.x-a2.x)*(b1.y-b2.y)-(b1.x-b2.x)*(a1.y-a2.y);
// }
// int dist(Node p1,Node p2)
// {
//     return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
// }
// int cmp(Node a,Node b)
// {
//     return a.x!=b.x?a.x<b.x:a.y<b.y;

// }
// int rotating_calipers()
// {
//     int res=0;
//     for(int i=1,j=2;i<=n;i++)
//     {
//         while(check(s[i],s[(i+1)],s[(i+1)],s[j])<check(s[i],s[(i+1)],s[(i+1)],s[(j+1)]))
//         {
//             j=j%n+1;
//         }
//         res=max(res,max(dist(s[i],s[j]),dist(s[(i+1)],s[j])));
        
//     }
//     return res;
// }
// void Andrew()
// {
//     sort(p+1,p+n+1,cmp);
//     int t=0;
//     for(int i=1;i<=n;i++)
//     {
//         while(t>1&&check(s[t-1],s[t],s[t],p[i])<=0)
//         {
//             t--;
//         }
//         s[++t]=p[i];

//     }
//     int k=t;
//     for(int i=n-1;i>=1;i--)
//     {
//         while(t>k&&check(s[t-1],s[t],s[t],p[i])<=0)
//         {
//             t--;
//         }
//         s[++t]=p[i];
//     }
//     n=t-1;
// }
// int main()
// {
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&p[i].x,&p[i].y);
//     }
//     Andrew();
//     int ans=rotating_calipers();
//     printf("%d",ans);
//     return 0;
// }

// 凸多边形
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5005;
// const double eps=1e-13;
// struct Point{
//     double x,y;
//     Point(double xval=0,double yval=0): x(xval),y(yval){}
// }p[N];
// struct Line{
//     Point s,e;
// }a[N],q[N];
// int n,m;
// int cnt =0;
// Point operator +(Point a,Point b) { return Point(a.x+b.x,a.y+b.y); }
// Point operator -(Point a,Point b) { return Point(a.x-b.x,a.y-b.y); }
// Point operator *(Point a,double b) { return Point(a.x*b,a.y*b); }
// double angle(Line a){
//     return atan2(a.e.y-a.s.y,a.e.x-a.s.x);
// }
// double cross(Point A,Point B){
//     return A.x*B.y - A.y*B.x;
// }
// int cmp(Line a,Line b)
// {
//     double A=angle(a),B=angle(b);
//     return fabs(A-B)>eps?A<B:cross(a.e-a.s,b.e-a.s)<0;
// }
// Point Cross(Line a,Line b)
// {
//     Point u=a.s-b.s,v=a.e-a.s,w=b.e-b.s;
//     double t=cross(u,w)/cross(w,v);
//     return a.s+v*t;
// }
// bool right (Line a,Line b,Line c){
//     Point p=Cross(b,c);
//     return cross(a.e-a.s,p-a.s)<0;
// }
// double half_plane()
// {
//     sort(a+1,a+cnt+1,cmp);
//     int h=1,t=1;
//     q[1]=a[1];
//     for(int i=2;i<=cnt;i++)
//     {
//         if(angle(a[i])-angle(a[i-1])<eps)
//         {
//             continue;
//         }
//         while(h<t&&right(a[i],q[t],q[t-1]))t--;
//         while(h<t&&right(a[i],q[h],q[h+1]))h++;
//         q[++t]=a[i];
//     }
//     while(h<t&&right(q[h],q[t],q[t-1]))t--;
//     q[++t]=q[h];
    
//     int k=0;
//     double res=0;
//     for(int i=h;i<t;i++)
//     {
//         p[++k]=Cross(q[i],q[i+1]);
//     }
//     for(int i=2;i<k;i++)
//     {
//         res+=cross(p[i]-p[1],p[i+1]-p[1]);
//     }
//     return res/2;
// }
// int main()
// {
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&m);
//         for(int j=1;j<=m;j++)
//         {
//             scanf("%lf%lf",&p[j].x,&p[j].y);
//         }
//         for(int j=1;j<=m;j++)
//         {
//             a[++cnt]={p[j],p[j%m+1]};
//         }       
//     }
//     printf("%.3lf\n",half_plane());
//     return 0;
// }

//水平可见直线
// #include<bits/stdc++.h>
// using namespace std;
// const int N=50005;
// const double eps=1e-13;
// struct Point{
//     double x,y;
//     Point(double xval=0,double yval=0): x(xval),y(yval){}
// }p[N];
// struct Line{
//     Point s,e;
//     int num;
// }a[N],q[N];
// int n,m;
// int cc[N];
// int cnt =0;
// Point operator +(Point a,Point b) { return Point(a.x+b.x,a.y+b.y); }
// Point operator -(Point a,Point b) { return Point(a.x-b.x,a.y-b.y); }
// Point operator *(Point a,double b) { return Point(a.x*b,a.y*b); }
// double angle(Line a){
//     return atan2(a.e.y-a.s.y,a.e.x-a.s.x);
// }
// double cross(Point A,Point B){
//     return A.x*B.y - A.y*B.x;
// }
// int cmp(Line a,Line b)
// {
//     double A=angle(a),B=angle(b);
//     return fabs(A-B)>eps?A<B:cross(a.e-a.s,b.e-a.s)<0;
// }
// Point Cross(Line a,Line b)
// {
//     Point u=a.s-b.s,v=a.e-a.s,w=b.e-b.s;
//     double t=cross(u,w)/cross(w,v);
//     return a.s+v*t;
// }
// bool right (Line a,Line b,Line c){
//     Point p=Cross(b,c);
//     return cross(a.e-a.s,p-a.s)<=0;
// }
// void half_plane()
// {
//     sort(a+1,a+n+1,cmp);
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%lf,%lf,%lf,%lf,%d\n",a[i].e.x,a[i].e.y,a[i].s.x,a[i].s.y,a[i].num);

//     // }
//     int h=1,t=1;
//     q[1]=a[1];
//     for(int i=2;i<=n;i++)
//     {
//         if(angle(a[i])-angle(a[i-1])<eps)
//         {
//             continue;
//         }
//         while(h<t&&right(a[i],q[t],q[t-1]))t--;
//         while(h<t&&right(a[i],q[h],q[h+1]))h++;
//         q[++t]=a[i];
//     }
//     q[++t]=q[h];
//     for(int i=h;i<t;i++)
//     {
//         cc[q[i].num]=1;

//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(cc[i]==1)
//         {
//             printf("%d ",i);
//         }     
//     }  
// }
// int main()
// {
//     double aa,bb;
//     memset(cc,0,sizeof(cc));

//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lf%lf",&aa,&bb);
//         Point p1,p2;
//         p1={0,bb};
//         p2={1,aa+bb};
//         a[i]={p1,p2,i};    
//     }
//     half_plane();
//     return 0;
// }

// 最近最远点对
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005;
// struct Node{
//     double x;
//     double y;
//     int num;
// };
// Node p[N];
// Node s[N];
// int n;
// double res1=0;
// double res2=0;
// int cnt =1;
// double check(Node a1,Node a2,Node b1,Node b2)
// {
//     return (a1.x-a2.x)*(b1.y-b2.y)-(b1.x-b2.x)*(a1.y-a2.y);
// }
// double dist(Node p1,Node p2)
// {
//     return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
// }
// int cmp(Node a,Node b)
// {
//     return a.x!=b.x?a.x<b.x:a.y<b.y;
// }
// void rotating_calipers()
// {
//     for(int i=1,j=2;i<=n;i++)
//     {
//         while(check(s[i],s[(i+1)],s[(i+1)],s[j])<check(s[i],s[(i+1)],s[(i+1)],s[(j+1)]))
//         {
//             j=j%n+1;
//         }
//         res1=max(res1,max(dist(s[i],s[j]),dist(s[(i+1)],s[j])));
        
//     }
// }
// void Andrew()
// {
//     sort(p+1,p+n+1,cmp);
// 	for(int i=1;i<n;i++)
//     {
//         for(int j=1;j<=10&&i+j<=n;j++)
//         {
//             res2=min(res2,dist(p[i],p[i+j]));//最小值相近但不一定相邻，往后多推几个，减小偶然性
//         }
//     }	    
//     int t=0;
//     for(int i=1;i<=n;i++)
//     {
//         while(t>1&&check(s[t-1],s[t],s[t],p[i])<=0)
//         {
//             t--;
//         }
//         s[++t]=p[i];

//     }
//     int k=t;
//     for(int i=n-1;i>=1;i--)
//     {
//         while(t>k&&check(s[t-1],s[t],s[t],p[i])<=0)
//         {
//             t--;
//         }
//         s[++t]=p[i];
//     }
//     n=t-1;
// }
// int main()
// {
//     res1=0;
//     res2=1e9;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lf%lf",&p[i].x,&p[i].y);
//     }
//     Andrew();
//     rotating_calipers();
//     printf("%.2lf %.2lf",sqrt(res2),sqrt(res1));
//     return 0;
// }

// Convex Hull
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005;
// struct Node{
//     double x;
//     double y;
//     int num;
// };
// Node p[N],s[N];
// int n;
// int cnt =0;
// double check(Node a1,Node a2,Node b1,Node b2)
// {
//     return (a1.x-a2.x)*(b1.y-b2.y)-(b1.x-b2.x)*(a1.y-a2.y);
// }
// double dist(Node p1,Node p2)
// {
//     return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
// }
// int cmp(Node a,Node b)
// {
//     return a.x!=b.x?a.x<b.x:a.y<b.y;
// }
// void Andrew()
// {
//     sort(p+1,p+n+1,cmp);    
//     int t=0;
//     for(int i=1;i<=n;i++)
//     {
//         while(t>1&&check(s[t-1],s[t],s[t],p[i])<0)
//         {
//             t--;
//         }
//         s[++t]=p[i];

//     }
//     int k=t;
//     for(int i=n-1;i>=1;i--)
//     {
//         while(t>k&&check(s[t-1],s[t],s[t],p[i])<0)
//         {
//             t--;
//         }
//         s[++t]=p[i];
//     }
//     n=t-1; 
// }
// int main()
// {
//     int tt;
//     scanf("%d",&tt);
//     while(tt--)
//     {
//         scanf("%d",&n);
//         double xx,yy;
//         char tag;
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lf%lf %c",&p[i].x,&p[i].y,&tag);
//         }
//         Andrew();
//         printf("%d\n",n);
//         for(int i=1;i<=n;i++)
//         {
//             printf("%.0lf %.0lf\n",s[i].x,s[i].y);
//         }                
//     }
//     return 0; 
// }

// Largest Fence G
#include<bits/stdc++.h>
using namespace std;
const int N=255;
struct node{
    int from,to;
    double x,y;
}a[N],e[N*N];
int n,m;
int cnt;
int cmp(node a,node b)
{
    return atan2(a.x,a.y)<atan2(b.x,b.y);
}
int f[N*N];
bool vis[N*N];
int ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            e[++cnt].from=i;
            e[cnt].to=j;
            e[cnt].x=a[j].x-a[i].x;
            e[cnt].y=a[j].y-a[i].y;
        }
    }
    sort(e+1,e+1+cnt,cmp);
    for(int i=1;i<=n;i++)
    {
        memset(f,-2,sizeof(f));
        memset(vis,false,sizeof(vis));
        vis[i]=true;
        f[i]=0;
        for(int j=1;j<=cnt;j++)
        {
            if(vis[e[j].from])
            {
                f[e[j].to]=max(f[e[j].to],f[e[j].from]+1);
                vis[e[j].to]=true;
            }
        }
        ans=max(ans,f[i]);

    }
    printf("%d",ans);
    return 0;
}