// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// const int T=1005;
// int tx[N];
// int vx[N];
// int dp[T];

// int main()
// {
//     memset(dp,0,sizeof(dp));
//     int t,m;
//     scanf("%d%d",&t,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&tx[i],&vx[i]);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=t;j>=0;j--)
//         {
//             if(tx[i]<=j)
//             {
//                 dp[j]=max(dp[j],dp[j-tx[i]]+vx[i]);
//             }
//             else
//             {
//                 dp[j]=dp[j];
//             }
//         }
//     }
//     // for(int i=1;i<=m;i++)
//     // {
//     //     for(int j=0;j<=t;j++)
//     //     {
//     //         printf("%d ",dp[i][j]);
//     //     }
//     //     printf("\n");
//     // }   
//     printf("%d",dp[t]);
//     return 0;
// }   

// 装箱
// #include<bits/stdc++.h>

// using namespace std;
// int const N=2000005;
// using LL=long long;
// LL dp[N];
// LL vx[N];
// int main()
// {
//     LL v;
//     LL n;
//     scanf("%lld",&v);
//     scanf("%lld",&n);
//     for(int i=0;i<=v;i++)
//     {
//         dp[i]=v;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&vx[i]);
//     }
//     LL w=0;
//     for(int i=1;i<=1e9;i++)
//     {
//         w++;
//     }

//     for(int i=1;i<=n;i++)
//     {       
//         for(int j=v;j>=0;j--)
//         {
//             if(j>=vx[i])
//             {
//                 dp[j]=max((LL)0,min(dp[j],dp[j-vx[i]]-vx[i]));
                
//             }
//         }
//     }
//     printf("%lld",dp[v]);
//     return 0;
// }


// 开心的今明
// #include<bits/stdc++.h>
// using namespace std;
// const int N=3e4+5;
// int v[N];
// int p[N];
// int dp[N];
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d",&v[i],&p[i]);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=n;j>=0;j--)
//         {
//             if(j>=v[i])
//             {
//                 dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]);
//             }
            
//         }
//     }
//     printf("%d",dp[n]);
//     return 0;
// }


// 乌龟棋
// #include<bits/stdc++.h>
// using namespace std;
// const int N=355;
// int dp[45][45][45][45];

// int w[N];
// int s[6];
// int main()
// {
//     int n,m;
//     int x;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&w[i]);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d",&x);
//         s[x]++;
//     }
//     dp[0][0][0][0]=w[1];
//     int maxn;
//     int now;

//     for(int i1=0;i1<=s[1];i1++)
//     {   
//         for(int i2=0;i2<=s[2];i2++)
//         {
//             for(int i3=0;i3<=s[3];i3++)
//             {
//                 for(int i4=0;i4<=s[4];i4++)
//                 {
//                     if(i1==0&&i2==0&&i3==0&&i4==0)
//                     {
//                         continue;
//                     }
//                     maxn=0;
//                     now=1+i1+i2*2+i3*3+i4*4;
//                     if(i1!=0)maxn=max(maxn,dp[i1-1][i2][i3][i4]+w[now]);
//                     if(i2!=0)maxn=max(maxn,dp[i1][i2-1][i3][i4]+w[now]);
//                     if(i3!=0)maxn=max(maxn,dp[i1][i2][i3-1][i4]+w[now]);
//                     if(i4!=0)maxn=max(maxn,dp[i1][i2][i3][i4-1]+w[now]);
//                     dp[i1][i2][i3][i4]=max(maxn,dp[i1][i2][i3][i4]);

//                 }
//             }
//         }
//     } 
//     printf("%d",dp[s[1]][s[2]][s[3]][s[4]]);
//     return 0;
// }


// [IOI1999] 花店橱窗布置
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=105;
// int a[N][N];
// int dp[N][N];
// int inf=999999999;
// int main()
// {
//     int t;
//     int f,v;
//     scanf("%d%d",&f,&v);
//     for(int i=1;i<=f;i++)
//     {
//         for(int j=1;j<=v;j++)
//         {
//             scanf("%d",&a[i][j]);
//             dp[i][j]=-inf;
//         }
//     }
//     for(int i=0;i<=v;i++)
//     {
//         dp[0][i]=0;
//     }
    
//     for(int i=1;i<=f;i++)
//     {
//         for(int j=1;j<=v;j++)
//         {
//             for(int l=i;l<=j;l++)
//             {
//                 t=dp[i-1][l-1]+a[i][l];
//                 if(dp[i][j]<t)
//                 {
//                     dp[i][j]=t;
//                 }
//             }
//         }
//     }
//     for(int i=1;i<=f;i++)
//     {
//         for(int j=1;j<=v;j++)
//         {
//             printf("%d ",dp[i][j]);
//         }
//         printf("\n");
//     }    
//     printf("%d\n",dp[f][v]);
//     return 0;
// }


// [NOIP 2004 提高组] 合唱队形
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;

// int main()
// {
//     return 0;
// }


// 石子合并
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=405;
// LL sum[N];
// LL a[N];
// LL dp1[N][N];
// LL dp2[N][N];
// int main()
// {
//     int n;
//     int x;
//     scanf("%d",&n);
//     memset(sum,0,sizeof(sum));
//     for(int i=1;i<=n*2;i++)
//     {
//         for(int j=1;j<=n*2;j++)
//         {
//             dp1[i][j]=0;
//             dp2[i][j]=1e9;
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&a[i]);
//         a[i+n]=a[i];
//     }
//     for(int i=1;i<=2*n;i++)
//     {
//         sum[i]=sum[i-1]+a[i];
//         dp1[i][i]=0;
//         dp2[i][i]=0;

//     }
//     for(int len=2;len<=n;len++)
//     {
//         for(int l=1;l+len-1<=2*n;l++)
//         {
//             int r=l+len-1;
//             for(int k=l;k<r;k++)
//             {
//                 dp1[l][r]=max(dp1[l][r],dp1[l][k]+dp1[k+1][r]+sum[r]-sum[l-1]);
//                 dp2[l][r]=min(dp2[l][r],dp2[l][k]+dp2[k+1][r]+sum[r]-sum[l-1]);
//             }
//         }
//     }
//     LL maxn=0;
//     LL minn=1e9;
//     for(int i=1;i<=n;i++)
//     {
//         maxn=max(maxn,dp1[i][i+n-1]);
//         minn=min(minn,dp2[i][i+n-1]);
//     }
//     printf("%lld\n%lld",minn,maxn);
//     return 0;
// }


// 能量项链
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=205;
// LL a[N];
// LL dp[N][N];
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=2*n;i++)
//     {
//         for(int j=1;j<=2*n;j++)
//         {
//             dp[i][j]=0;
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//         a[i+n]=a[i];
//     }
//     for(int len=2;len<=n;len++)
//     {
//         for(int l=1;l+len-1<=2*n;l++)
//         {
//             int r=l+len-1;
//             for(int k=l;k<r;k++)
//             {
//                 dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]+a[l]*a[k+1]*a[r+1]);
//             }
//         }
//     }
//     LL maxn=0;
//     for(int i=1;i<=n;i++)
//     {
//         maxn=max(maxn,dp[i][i+n-1]);
//     }
//     printf("%lld",maxn);
//     return 0;
// }


// 括号配对
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=205;
// LL dp[N][N];
// char s[N];
// bool vis[N];

// int main()
// {
//     scanf("%s",s+1);
//     int n=strlen(s+1);
//     // printf("<%d>",n);
//     for(int len=1;len<=n;len++)
//     {
//         for(int i=1;i+len-1<=n;i++)
//         {
//             int j=i+len-1;
//             if((s[i]=='('&&s[j]==')')||s[i]=='['&&s[j]==']')
//             {
//                 dp[i][j]=dp[i+1][j-1]+1;

//             }
//             for(int k=i;k<j;k++)
//             {
//                 dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
//             }
//         }
//     }
//     printf("%d",n-2*dp[1][n]);
//     return 0;
// }


// 凸多边形的划分
// #include<bits/stdc++.h>
// using namespace std;
// using LL=__int128;
// const int N=105;
// LL dp[N][N][N];
// LL a[N];
// LL inf=1e38;
// void print(__int128 x) {
//     if (x < 0) {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9) print(x / 10);
//     putchar(x % 10 + '0');
// }
// LL read() {
//     LL x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9') {
//         if (ch == '-') f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9') {
//         x = x * 10 + ch - '0';
//         ch = getchar();
//     }
//     return x * f;
// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=read();
//         a[i+n]=a[i];
//     }
//     for(int i=1;i<=2*n;i++)
//     {
//         for(int j=1;j<=2*n;j++)
//         {
//             for(int k=1;k<=2*n;k++)
//             {
//                 dp[i][j][k]=inf;
//             }

//         }
//     }
//     for(int i=1;i<=2*n;i++)
//     {
//         for(int j=i+1;j<2*n;j++)
//         {
//             dp[i][j][j+1]=a[i]*a[j]*a[j+1];

//         }
//     }
//     for(int len=3;len<=n;len++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int l=i+1;l+len-1<=2*n;l++)
//             {
//                 int r=l+len-1;
//                 for(int k=l+1;k<=r-1;k++)
//                 {
//                     dp[i][l][r]=min(dp[i][l][r],dp[i][l][k]+dp[i][k][r]);
//                 }
//             }
//         }
//     }
//     LL mini=1e38;
//     for(int i=1;i<=n;i++)
//     {
//         if(dp[i][i+1][i+n-1]<mini)
//         {
//             mini=dp[i][i+1][i+n-1];
//         }
//     }
//     if(n<=2)
//     {
//         printf("0");
//     }
//     else
//     {
//         print(mini);
//     }
    
//     return 0;
// }

// 凸多边形的划分
// #include<bits/stdc++.h>
// using namespace std;
// using LL=__int128;
// const int N=105;
// LL dp[N][N];
// LL a[N];
// LL inf=1e38;
// LL read() {
//     LL x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9') {
//         if (ch == '-') f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9') {
//         x = x * 10 + ch - '0';
//         ch = getchar();
//     }
//     return x * f;
// }
// void print(__int128 x) {
//     if (x < 0) {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9) print(x / 10);
//     putchar(x % 10 + '0');
// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=read();
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             j-i<2?dp[i][j]=0:dp[i][j]=inf;
//         }
//     }
//     for(int len=3;len<=n;len++)
//     {
//         for(int i=1;i+len-1<=n;i++)
//         {
//             int j=i+len-1;
//             for(int k=i+1;k<j;k++)
//             {
//                 dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
//             }
//         }
//     }
//     print(dp[1][n]);
//     return 0;
// }


// Palindrome
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=5005;
// int dp[3][N];
// char s[N];

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     getchar();
//     scanf("%s",s+1);
//     // for(int i=1;i<=3;i++)
//     // {
//     //     for(int j=1;j<=n;j++)
//     //     {
//     //         printf("%d,",dp[i][j]);
//     //     }
//     //     printf("\n");
//     // }
//     for(int l=n;l>=1;l--)
//     {
//         for(int r=l;r<=n;r++)
//         {
//             if(s[l]==s[r])
//             {
//                 dp[l%2][r]=dp[(l+1)%2][r-1];
//             }            
//             else
//             {
//                 dp[l%2][r]=min(dp[(l+1)%2][r],dp[l%2][r-1])+1;
//             }
//         }
//     }
//     printf("%d",dp[1][n]);
//     return 0;
// }


// 矩阵取数游戏
// #include<bits/stdc++.h>
// using namespace std;
// using LL=__int128;
// const int N=105;
// LL dp[N][N];
// LL a[N][N];
// void out (__int128 x) {
//     if(x>9) out(x/10);
//     putchar(x%10+'0');
// }
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             scanf("%lld",&a[i][j]);
//         }
//     }
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         memset(dp,0,sizeof(dp));
//         for(int len=1;len<=m;len++)
//         {
//             for(int l=1;l+len-1<=m;l++)
//             {
//                 int r=l+len-1;
//                 dp[l][r]=max(dp[l+1][r]+a[i][l],dp[l][r-1]+a[i][r])*2;
//             }
//         }    
//         ans+=dp[1][m];    
//     }
//     out(ans);
//     return 0;
// }


// 棋盘分割
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=
// int main()
// {
//     return 0;
// }


// Flood Fill  
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=5005;
// LL dp[N][N];
// int c[N];
// int e[N];
// int main()
// {
//     int n;
//     int tot=0;
//     scanf("%d",&n);
//     c[0]=-1;
//     for(int i=1;i<=n;i++)
//     {

//         scanf("%d",&c[i]);
//         if(c[i]!=c[i-1])
//         {
//             tot++;
//             e[tot]=c[i];
//         }
//     }
//     // for(int i=1;i<=tot;i++)
//     // {
//     //     printf("%d,",e[i]);
//     // }
//     for(int i=1;i<=n;i++)
//     {
//         dp[i][i]=0;
//     }
//     for(int i=tot;i>=1;i--)
//     {
//         for(int j=i+1;j<=tot;j++)
//         {
//             if(e[i]==e[j])
//             {
//                 dp[i][j]=dp[i+1][j-1]+1;
//             }
//             else
//             {
//                 dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
//             }
//             // printf("%lld:%d,%d\n",dp[i][j],i,j);
//         }
//     }    
//     printf("%lld\n",dp[1][tot]);
//     return 0;
// }


// Alice’s Stamps
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2005;
// int a[N];
// int dp[N][N];

// int main()
// {
//     int t;
//     int n,m,k;
//     int l,r;
//     int s=0;
//     scanf("%d",&t);
//     while(t--)
//     {
//         s++;
//         memset(a,0,sizeof(a));
//         memset(dp,0,sizeof(dp));

//         scanf("%d%d%d",&n,&m,&k);
//         for(int i=1;i<=m;i++)
//         {
//             scanf("%d%d",&l,&r);
//             for(int i=l;i<=r;i++)
//             {
//                 a[i]=max(a[i],r);

//             }
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("%d,",a[i]);
//         // }
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=k;j++)
//             {
//                 dp[i][j]=max(dp[i][j],dp[i-1][j]);
//                 if(a[i])
//                 {
//                     dp[a[i]][j]=max(dp[a[i]][j],dp[i-1][j-1]+a[i]-i+1);

//                 }
//             }
//         }
//         printf("Case #%d: %d\n",s,dp[n][k]);
//     }
//     return 0;
// }



// 棋盘分割
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// int const N=20;
// double dp[N][N][N][N][N];
// int a[N][N];
// int b[N][N];
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=8;i++)
//     {
//         for(int j=1;j<=8;j++)
//         {
//             scanf("%d",&a[i][j]);
//         }
//     }
//     for(int i=1;i<=8;i++)
//     {
//         for(int j=1;j<=8;j++)
//         {
//             b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
//             // printf("%d ",b[i][j]);
//         }
//         // printf("\n");
//     }   
//     double ave=(1.0*b[8][8])/(1.0*n);
//     // printf("{%lf}\n",ave);
//     for(int k=1;k<=n;k++)
//     {
//         for(int i1=1;i1<=8;i1++)
//         {
//             for(int j1=1;j1<=8;j1++)
//             {
//                 for(int i2=1;i2<=8;i2++)
//                 {
//                     for(int j2=1;j2<=8;j2++)
//                     {
//                         if(k==1)
//                         {   
//                             int ss=b[i2][j2]-b[i1-1][j2]-b[i2][j1-1]+b[i1-1][j1-1];
//                             double s=ss*1.0;

//                             dp[i1][j1][i2][j2][k]=(s-ave)*(s-ave);

//                         }
//                         else
//                         {           
//                             dp[i1][j1][i2][j2][k]=1e9;
//                             for(int m=i1;m<i2;m++)
//                             {
//                                 dp[i1][j1][i2][j2][k]=min(dp[i1][j1][m][j2][k-1]+dp[m+1][j1][i2][j2][1],min(dp[i1][j1][m][j2][1]+dp[m+1][j1][i2][j2][k-1],dp[i1][j1][i2][j2][k]));                                
//                             }
//                             for(int m=j1;m<j2;m++)
//                             {
//                                 dp[i1][j1][i2][j2][k]=min(dp[i1][j1][i2][m][k-1]+dp[i1][m+1][i2][j2][1],min(dp[i1][j1][i2][m][1]+dp[i1][m+1][i2][j2][k-1],dp[i1][j1][i2][j2][k]));

//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     double nn=n;
//     double ans=dp[1][1][8][8][n];
//     printf("%.3lf",sqrt(ans/(1.0*nn)));

//     return 0;
// }


// 分离与合体
// #include<bits/stdc++.h>
// using namespace std;
// const int N=305;
// int a[N];
// int dp[N][N];
// int p[N][N];
// int f,h;
// void dfs(int x,int y,int end)
// {
//     if(x>=y)
//     {
//         return;
//     }
//     if(end==h)
//     {
//         printf("%d ",p[x][y]);
//         f=1;
//         return;
//     }
//     dfs(x,p[x][y],end+1);
//     dfs(p[x][y]+1,y,end+1);


// }
// void dfs1(int x,int y)
// {
//     if(x==y)
//     {
//         return;
//     }
//     printf("%d",p[x][y]);
//     dfs1(x,p[x][y]);
//     dfs1(p[x][y]+1,y);
    
// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&a[i]);

//     }
//     for(int len=1;len<=n;len++)
//     {
//         for(int l=1;l+len-1<=n;l++)
//         {
//             int r=l+len-1;
//             for(int k=l;k<r;k++)
//             {
//                 if((a[l]+a[r])*a[k]+dp[l][k]+dp[k+1][r]>dp[l][r])
//                 {
//                     dp[l][r]=(a[l]+a[r])*a[k]+dp[l][k]+dp[k+1][r];
//                     p[l][r]=k;
//                 }
                
//             }
//         }
//     }
//     printf("%d\n",dp[1][n]);

//     f=1;
//     h=0;
//     while(f)
//     {
//         f=0;
//         h++;
//         dfs(1,n,1);

//     }
//     return 0;
// }


// 滑动窗口
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// typedef long long LL;
// LL a[N];
// LL q1[N];
// LL q2[N];

// int main()
// {
//     int n,k;
//     scanf("%d%d",&n,&k);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//     }
//     int t=0;
//     int h=1;
//     for(int i=1;i<=n;i++)
//     {
//         while(t>=h&&a[q1[t]]>=a[i])
//         {
//             t--;
//         }
//         t++;
//         q1[t]=i;
//         if(q1[h]<i-k+1)
//         {
//             h++;
//         }
//         if(i>=k)
//         {
//             printf("%lld ",a[q1[h]]);
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("%lld,",a[q1[i]]);
//         // }
//         // printf("\n");
//     }    
//     printf("\n");
//     t=0;
//     h=1;
//     for(int i=1;i<=n;i++)
//     {
//         while(t>=h&&a[q1[t]]<=a[i])
//         {
//             t--;
//         }
//         t++;
//         q1[t]=i;
//         if(q1[h]<i-k+1)
//         {
//             h++;
//         }
//         if(i>=k)
//         {
//             printf("%lld ",a[q1[h]]);
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("%lld,",a[q1[i]]);
//         // }
//         // printf("\n");
//     }    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// typedef long long LL;
// LL a[N];
// LL q1[N];
// LL q2[N];

// int main()
// {
//     int n,k;
//     scanf("%d%d",&n,&k);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//     }
//     int t=0;
//     int h=1;
//     for(int i=1;i<=n;i++)
//     {
//         while(t>=h&&a[q1[t]]>=a[i])
//         {
//             t--;
//         }
//         t++;
//         q1[t]=i;
//         if(q1[h]<i-k+1)
//         {
//             h++;
//         }
//         if(i>=k)
//         {
//             printf("%lld ",a[q1[h]]);
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("%lld,",a[q1[i]]);
//         // }
//         // printf("\n");
//     }    
//     printf("\n");
//     t=0;
//     h=1;
//     for(int i=1;i<=n;i++)
//     {
//         while(t>=h&&a[q1[t]]<=a[i])
//         {
//             t--;
//         }
//         t++;
//         q1[t]=i;
//         if(q1[h]<i-k+1)
//         {
//             h++;
//         }
//         if(i>=k)
//         {
//             printf("%lld ",a[q1[h]]);
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("%lld,",a[q1[i]]);
//         // }
//         // printf("\n");
//     }    
//     return 0;
// }



// 最大连续和
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;

// LL a[N];
// LL s[N];
// int p[N];
// int main()
// {
    
//     int n,m;
//     scanf("%d%d",&n,&m);
//     s[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//         s[i]=s[i-1]+a[i];
//     }
//     int t=0;
//     int h=0;
//     LL maxn=-1e9;
//     for(int i=1;i<=n;i++)
//     {
//         while(h<=t&&s[p[t]]>=s[i-1])
//         {
//             t--;
//         }
//         t++;
//         p[t]=i-1;
//         if(p[h]<i-m)
//         {
//             h++;
//         }
//         if((s[i]-s[p[h]])>maxn)
//         {
//             maxn=s[i]-s[p[h]];
//         }

//     }
//     printf("%lld",maxn);
//     return 0;
// }


// 修剪草坪
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;

// using LL=long long;
// typedef pair<int,LL> pil;

// LL dp[N];
// LL a[N];
// pil q[N];
// int main()
// {
//     int n,k;
//     LL ans=0;
//     scanf("%d%d",&n,&k);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//         ans+=a[i];
//     }
//     for(int i=0;i<=n;i++)
//     {
//         dp[i]=0;
//         q[i].first=0;
//     }
//     dp[0]=0;
//     int t=0;
//     int h=1;
//     for(int i=1;i<=n;i++)
//     {

//         while(h<=t&&dp[i-1]<=dp[q[t].first])
//         {
//             t--;
//         }
//         t++;
//         q[t].second=
//         q[t].first=i-1;
//         if(q[h].first<i-k-1)
//         {
//             h++;
//         }
//         // if(i>k)
//         // {
//             dp[i]=dp[q[h].first]+a[i];
//         // }
//         printf("[%d,%d,%d,%d,%d]\n",h,t,dp[i],q[t].first,q[h].first);
//     }
//     LL mini=1e18;
//     if(k>=n)
//     {
//         ans=0;
//     }
//     else
//     {
//         for(int i=n-k;i<=n;i++)
//         {
//             mini=min(mini,dp[i]);
//         }        
//     }
//     printf("%lld",ans-mini);
//     return 0;
// }


// 烽火传递
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// LL dp[N];
// LL a[N];
// int q[N];

// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//     }
//     int t=0;
//     int h=1;
//     for(int i=1;i<=n;i++)
//     {
//         while(h<=t&&dp[q[t]]>=dp[i-1])
//         {
//             t--;
//         }
//         t++;
//         q[t]=i-1;
//         if(q[h]<i-m)
//         {
//             h++;
//         }
//         dp[i]=dp[q[h]]+a[i];
//     }
//     LL mini=1e18;
//     if(m>n)
//     {
//         mini=0;
//     }
//     else
//     {
//         for(int i=n-m+1;i<=n;i++)
//         {
//             mini=min(mini,dp[i]);
//         }        
//     }
//     printf("%lld",mini);

//     return 0;
// }


// Banknotes
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// LL dp[N];
// int q[N];
// LL a[N];
// int main()
// {

//     return 0;
// }


// 旅行问题 
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;

// LL dp[N];
// LL p[N];
// LL d[N];
// int q[N];
// LL cha[N];
// LL s[N];
// bool vis[N];
// int main()
// {
//     memset(vis,true,sizeof(vis));
//     int n;
//     scanf("%d",&n);
//     s[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&p[i],&d[i]);
//         cha[i]=p[i]-d[i];
//         cha[i+n]=cha[i];
//     }
//     for(int i=1;i<=2*n;i++)
//     {
//         s[i]=s[i-1]+cha[i];
    
//     }
//     int t=0;
//     int h=1;

//     s[2*n+1]=0;
//     for(int i=1;i<=2*n>;i++)
//     {
//         while(h<=t&&s[i-1]<=s[q[t]])
//         {
//             t--;

//         }
//         t++;
//         q[t]=i+1;
//         if(q[h]>i+n)
//         {
//             h++;
//         }
//         if(i<=n)
//         {
//             if(s[i]>s[q[h]])
//             {
//                 vis[i]=false;
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(vis[i])
//         {
//             printf("TAK\n");
//         }
//         else
//         {
//             printf("NIE\n");
//         }
       
//     }
//     return 0;
// }



// 绿色通道
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// const int N=1e5+5;
// LL dp[N];
// LL a[N];
// int q[N];
// int main()
// {
//     int n;
//     LL k;
//     scanf("%d%lld",&n,&k);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//     }
//     LL lt=0;
//     LL rt=1e8;
//     LL mid;
//     while(lt<=rt)
//     {
//         mid=lt+rt>>1;
//         int t=0;
//         int h=1;
//         dp[0]=0;
//         for(int i=1;i<=n;i++)
//         {
//             while(h<=t&&dp[q[t]]>=dp[i-1])
//             {
//                 t--;
//             }
//             t++;
//             q[t]=i-1;
//             if(q[h]<i-mid-1)
//             {
//                 h++;
//             }
//             dp[i]=dp[q[h]]+a[i];

//         }
//         LL mini=1e18;
//         if(mid>=n)
//         {
//             mini=0;
//         }
//         else
//         {
//             for(int i=n-mid;i<=n;i++)
//             {
//                 mini=min(mini,dp[i]);
//             }            
//         }
//         // printf("[%lld,%lld,%lld]\n",mid,lt,rt);

//         if(mini>k)
//         {
//             lt=mid+1;
//         }
//         else
//         {
//             rt=mid-1;
//         }
//     }
//     printf("%lld",rt+1);
//     return 0;
// }


// Banknotes
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e4+5;
// LL dp[N];
// LL g[N];
// int q[N];
// LL b[N];
// LL c[N];
// int main()
// {
//     int n;
//     LL m;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&b[i]);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&c[i]);

//     }
//     scanf("%lld",&m);
//     for(int i=1;i<=m;i++)
//     {
//         dp[i]=1e18;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         int v=b[i];
//         int s=c[i];
//         memcpy(g,dp,sizeof(dp));

//         for(int j=0;j<v;j++)
//         {
//             int h=0;
//             int t=-1;            
//             for(int k=j;k<=m;k=k+v)
//             {
//                 if(h<=t&&q[h]<(k-s*v))
//                 {
//                     h++;
//                 }
//                 if(h<=t)
//                 {
//                     dp[k]=min(g[k],g[q[h]]+(k-q[h])/v);    
//                 }
// //                 printf("%lld,%lld\n",g[k],g[q[h]]+(k-q[h])/v);
// // printf("[%d,%d,%d,%d,%lld,%d,%d]\n",i,j,h,t,dp[k],q[h],q[t]);
//                 while(h<=t&&(g[k]<=g[q[t]]+(k-q[t])/v))
//                 {
//                     t--;
//                 }
//                 t++;
//                 q[t]=k;

                
//                 // for(int i=0;i<=m;i++)
//                 // {
//                 //     printf("{%lld}",dp[i]);
//                 //    }
//                 // printf("\n");
//             }
//         }
//     }
//     printf("%lld",dp[m]);
//     return 0;
// }


// 理想的正方形
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e3+5;
// LL c[N][N];
// struct node{
//     LL maxn;
//     LL mini;
// }dp[N][N],d[N][N];

// int q[N];
// int main()
// {
//     int h,t;

//     int a,b,n;
//     scanf("%d%d%d",&a,&b,&n);

//     for(int i=1;i<=a;i++)
//     {
//         for(int j=1;j<=b;j++)
//         {
//             scanf("%lld",&c[i][j]);

//         }
//     }
//     // for(int i=1;i<=a;i++)
//     // {
//     //     for(int j=1;j<=b;j++)
//     //     {
//     //         printf("%lld,",c[i][j]);
//     //     }
//     //     printf("\n");

//     // }
//     for(int i=1;i<=a;i++)
//     {
//         h=1;
//         t=0;

//         for(int j=1;j<=b;j++)
//         {
//             while(h<=t&&c[i][q[t]]<=c[i][j])
//             {
//                 t--;
//             }
//             t++;
//             q[t]=j;            
//             if(t>=h&&q[h]<j-n+1)
//             {
//                 h++;
//             }
//             if(t>=h)
//             {
//                 d[i][j].maxn=c[i][q[h]];

//             }

//         }
//         h=1;
//         t=0;
//         for(int j=0;j<=b;j++)
//         {
//             while(h<=t&&c[i][q[t]]>=c[i][j])
//             {
//                 t--;
//             }
//             t++;
//             q[t]=j;            
//             if(t>=h&&q[h]<j-n+1)
//             {
//                 h++;
//             }
//             if(t>=h)
//             {
//                 d[i][j].mini=c[i][q[h]];

//             }

//         }        
//     }
//     // printf("\n");
//     // for(int i=1;i<=a;i++)
//     // {
//     //     for(int j=1;j<=b;j++)
//     //     {
//     //         printf("%lld,",d[i][j].maxn);
//     //     }
//     //     printf("\n");

//     // }
//     for(int j=1;j<=b;j++)
//     {
//         h=1;
//         t=0;
//         for(int i=0;i<=a;i++)
//         {
//             while(h<=t&&d[q[t]][j].maxn<=d[i][j].maxn)
//             {
//                 t--;
//             }
//             t++;
//             q[t]=i;            
//             if(t>=h&&q[h]<i-n+1)
//             {
//                 h++;
//             }
//             if(t>=h)
//             {
//                 dp[i][j].maxn=d[q[h]][j].maxn;

//             }

//         }
//         h=1;
//         t=0;
//         for(int i=0;i<=a;i++)
//         {
//             while(h<=t&&d[q[t]][j].mini>=d[i][j].mini)
//             {
//                 t--;
//             }
//             t++;
//             q[t]=i;            
//             if(t>=h&&q[h]<i-n+1)
//             {
//                 h++;
//             }
//             if(t>=h)
//             {
//                 dp[i][j].mini=d[q[h]][j].mini;

//             }

//         }
//     }
//     // printf("\n");

//     // for(int i=1;i<=a;i++)
//     // {
//     //     for(int j=1;j<=b;j++)
//     //     {
//     //         printf("%lld,",dp[i][j].maxn);
//     //     }
//     //     printf("\n");

//     // }
//     LL mini=1e18;
//     for(int i=n;i<=a;i++)
//     {
//         for(int j=n;j<=b;j++)
//         {
//             mini=min(mini,dp[i][j].maxn-dp[i][j].mini);
//         }
//     }
//     printf("%lld",mini);
//     return 0;
// }


// 股票交易
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;
// LL ap[N];
// LL bp[N];
// LL as[N];
// LL bs[N];

// int main()
// {
//     LL t,maxp,w;
//     scanf("%lld%lld%lld",&t,&maxp,&w);
//     for(int i=1;i<=t;i++)
//     {
//         scanf("%lld%lld%lld%lld",&ap[i],&bp[i],&as[i],&bs[i]);
//     }

//     return 0;
// }


// 旅行问题
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;
// LL dp[N];
// int q[N];
// LL a[N];
// LL b[N];
// LL p[N];
// LL d[N];
// bool vis[N];
// int main()
// {
//     memset(vis,false,sizeof(vis));

//     LL x,y;
//     int n;
//     scanf("%d",&n);
//     a[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld%lld",&x,&y);
//         a[i]=x-y;
//         a[i+n]=a[i];
//         p[i]=x;
//         d[i]=y;
//     }
//     d[0]=d[n];

//     for(int i=1;i<=n;i++)
//     {
//         b[i]=p[n-i+1]-d[n-i];
//         b[i+n]=b[i];
//     }
//     for(int i=1;i<=2*n;i++)
//     {
//         a[i]+=a[i-1];
//         b[i]+=b[i-1];
//     } 
//     // for(int i=1;i<=2*n;i++)
//     // {
//     //     printf("%lld ",b[i]);
//     // }     
//     int h=1;
//     int t=0;
//     a[0]=0;
//     for(int i=1;i<=2*n;i++)
//     {
//         if(h<=t&&q[h]<i-n+1)
//         {
//             h++;
//         }
//         if(h<=t&&i>=n)
//         {
//             LL dist=a[q[h]]-a[i-n];
//             if(dist>=0)
//             {
//                 vis[i-n+1]=true;
//             }
//         }
//         while(h<=t&&a[i]<=a[q[t]])
//         {
//             t--;
//         }
//         t++;
//         q[t]=i;

//     }
//     h=1;
//     t=0;
//     b[0]=0;

//     for(int i=1;i<=2*n;i++)
//     {
//         if(h<=t&&q[h]<i-n+1)
//         {
//             h++;
//         }
//         if(h<=t&&i>=n)
//         {
//             LL dist=b[q[h]]-b[i-n];
//             if(dist>=0)
//             {
//                 vis[2*n-i]=true;
//             }
//         }
//         while(h<=t&&b[i]<=b[q[t]])
//         {
//             t--;
//         }
//         t++;
//         q[t]=i;

//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(vis[i])
//         {
//             printf("TAK\n");
//         }
//         else
//         {
//             printf("NIE\n");
//         }
//     }
//     return 0;
// }


// Cash Machine
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=1e5+5;
// int dx[N];
// int nx[N];
// int q[N];
// int dp[N];
// int g[N];
// int main()
// {
//     int cash;
//     int n;
//     while(scanf("%d",&cash)!=EOF)
//     {
//         memset(dp,0,sizeof(dp));
//         scanf("%d",&n);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d%d",&nx[i],&dx[i]);

//         }
//         for(int i=1;i<=n;i++)
//         {
//             int s=nx[i];
//             int v=dx[i];
//             int w=dx[i];
//             memcpy(g,dp,sizeof(dp));
//             for(int j=0;j<v;j++)
//             {
//                 int h=0;
//                 int t=-1;
//                 for(int k=j;k<=cash;k=k+v)
//                 {
//                     if(t>=h&&q[h]<k-(s*v))
//                     {
//                         h++;
//                     }
//                     if(t>=h)
//                     {
//                         dp[k]=max(g[k],g[q[h]]+(k-q[h])/v*w);
//                     }
//                     while(t>=h&&g[k]>=g[q[t]]+(k-q[t])/v*w)
//                     {
//                         t--;
//                     }
//                     t++;
//                     q[t]=k;
//                 }
//             }
//         }
//         int maxn=0;

//         for(int i=1;i<=cash;i++)
//         {
//             maxn=max(maxn,dp[i]);
//         }
//         printf("%d\n",maxn);        
//     }
//     return 0;
// }



// Coins
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=1e5+5;
// int dp[N];
// int g[N];
// int a[N];
// int c[N];
// int q[N];
// int main()
// {
//     int n,m;
//     while(1)
//     {
//         memset(dp,0,sizeof(dp));
//         scanf("%d%d",&n,&m);
//         if(n==0&&m==0)
//         {
//             break;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);

//         }
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&c[i]);
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("{%d,%d}\n",a[i],c[i]);
//         // }
//         for(int i=0;i<=m;i++)
//         {
//             dp[i]=0;

//         }
//         dp[0]=1;
//         for(int i=1;i<=n;i++)
//         {
//             int s=c[i];
//             int w=a[i];
//             if(s==1)
//             {
//                 for(int j=m;j>=w;j--)
//                 {
//                     if(!dp[j]&&dp[j-w])
//                     {
//                         dp[j]=1;

//                     }
//                 }
//             }            
//             else if(s*w>=m)
//             {
//                 for(int j=w;j<=m;j++)
//                 {
//                     if(!dp[j]&&dp[j-w])
//                     {
//                         dp[j]=1;

//                     }
//                 }
//             }
//             else
//             {
//                 for(int j=0;j<w;j++)
//                 {
//                     int h=0;
//                     int t=-1;
//                     int sum=0;
                    
//                     for(int k=j;k<=m;k+=w)
//                     {
//                         if(t-h==s)
//                         {
//                             sum-=q[h];
//                             h++;
//                         }
//                         t++;
//                         q[t]=dp[k];
//                         sum+=dp[k];

//                         if(!dp[k]&&sum)
//                         {
//                             dp[k]=1;
//                         }
//                     }
//                 }                
//             }

//         }
//         int ans=0;
//         for(int i=1;i<=m;i++)
//         {   
//             ans+=dp[i];

//         }
//         printf("\n%d\n",ans);
//     }
//     return 0;
// }


// fence
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
    
//     return 0;
// }


// Fence
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=2e4+5;
// struct node{
//     int l,p,s;
// }a[N];
// int dp[N];
// int g[N];

// int q[N];

// bool cmp(node a,node b)
// {
//     return a.s<b.s;
// }
// int jisuan(int i,int k)
// {
//     return dp[i-1][k]-a[i].p*k;

// }
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&a[i].l,&a[i].p,&a[i].s);
//     }
//     sort(a+1,a+1+m,cmp);

//     for(int i=1;i<=m;i++)
//     {
//         memcpy(g,dp,sizeof(dp));

//         int h=0;
//         int t=-1;
//         for(int k=max(0,a[i].s-a[i].l);k<=a[i].s-1;k++)
//         {
//             while(h<=t&&jisuan(i,k)>jisuan(i,q[t]))
//             {
//                 t--;
//             }
//             t++;
//             q[t]=k;
//         }

//         for(int j=0;j<=n;j++)
//         {

//             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             if(j>=a[i].s)
//             {
//                 while(h<=t&&q[h]<j-a[i].l)
//                 {
//                     h++;

//                 }
//                 if(h<=t)
//                 {
//                     dp[i][j]=max(dp[i][j],jisuan(i,q[h])+a[i].p*j);

//                 }
//             }

//         }
//     }
//     printf("%d\n",dp[m][n]);

//     return 0;
// }


// 悼念512汶川大地震遇难同胞――珍惜现在，感恩生活
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// int pi[N];
// int hi[N];
// int ci[N];
// int dp[N];
// int q[N];
// int g[N];

// void solve()
// {
//     memset(dp,0,sizeof(dp));

//     int n,m;
//     scanf("%d%d",&n,&m);

//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&pi[i],&hi[i],&ci[i]);
        
//     }    
//     for(int i=1;i<=m;i++)
//     {
//         memcpy(g,dp,sizeof(dp));

//         int s=ci[i];
//         int v=pi[i];
//         int w=hi[i];
//         for(int j=0;j<v;j++)
//         {
            
//             int h=0;
//             int t=-1;
//             for(int k=j;k<=n;k+=v)
//             {
//                 if(h<=t&&q[h]<k-s*v)
//                 {
//                     h++;
//                 }
//                 if(h<=t)
//                 {
//                     dp[k]=max(g[k],g[q[h]]+(k-q[h])/v*w);

//                 }
//                 while(h<=t&&g[k]>=g[q[t]]+(k-q[t])/v*w)
//                 {
//                     t--;

//                 }
//                 t++;
//                 q[t]=k;
//             }
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         ans=max(ans,dp[i]);
//     }
//     printf("%d\n",ans);
// }
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }


// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=2e4+5;
// struct node{
//     int l,p,s;
// }a[N];
// int dp[N];
// int g[N];

// int q[N];

// bool cmp(node a,node b)
// {
//     return a.s<b.s;
// }
// int jisuan(int i,int k)
// {
//     return dp[i-1][k]-a[i].p*k;

// }
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&a[i].l,&a[i].p,&a[i].s);
//     }
//     sort(a+1,a+1+m,cmp);

//     for(int i=1;i<=m;i++)
//     {
//         memcpy(g,dp,sizeof(dp));

//         int h=0;
//         int t=-1;
//         for(int j=0;j<=n;j++)
//         {
//             if()
//         }
//     }


//     return 0;
// }



// Dividing the Path
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=1e3+5;
// const int M=1e6+5;

// int dp[M];
// int q[M];

// int main()
// {
//     int n,l;
//     scanf("%d%d",&n,&l);
//     int a,b;
//     scanf("%d%d",&a,&b);
//     // printf("{%d,%d,%d,%d}\n",n,l,a,b);

//     for(int i=1;i<=l;i++)
//     {
//         dp[i]=1e9;

//     }
//     int si;
//     int ei;

//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d%d",&si,&ei);


//         for(int j=si+1;j<=ei-1;j++)
//         {
//             dp[j]=1e9+1;
//         }
//     }
//     dp[0]=0;

//     int size=2*b-2*a;
//     int t=-1;
//     int h=0;

//     for(int i=2*a;i<=l;i+=2)
//     {
//         while(h<=t&&dp[i-2*a]<=dp[q[t]])
//         {
//             t--;
//         }
//         t++;
//         q[t]=i-a*2;      

//         while(h<=t&&i-2*a-q[h]>size)
//         {
//             h++;
//         }

//         if(h<=t&&dp[i]<=1e9)
//         {
//             // printf("*");
//             dp[i]=dp[q[h]]+1;
//             // for(int k=0;k<=l;k++)
//             // {
//             //     printf("%d,",dp[k]);
//             // }    
//             // printf("\n");

//         }

//         // printf("[%d,%d,%d] ",q[t],h,t);
//     }
//     if(dp[l]<=1e9)
//     {
//         printf("%d",dp[l]);
//     }
//     else
//     {
//         printf("-1");
//     }
//     return 0;
// }


// Cut the Sequence(错误)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];
// LL s[N];
// LL f[N][30];
// LL q[N];
// LL dp[N];
// void st(int n)
// {
//     for(int j=1;j<=21;j++)
//     {
//         for(int i=1;i<=n-(1<<j)+1;i++)
//         {
//             f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//             // printf("{%d}",f[i][j]);
//         }
//         // printf("\n");
//     }
// }
// LL find(int x,int y)
// {
//     int l;
//     l=log2(y-x+1);
//     LL ans=max(f[x][l],f[y-(1<<l)+1][l]);
//     return ans;

// }
// void solve()
// {
//     memset(s,0,sizeof(s));
//     memset(dp,0,sizeof(dp));
//     memset(f,0,sizeof(f));
//     memset(q,0,sizeof(q));
//     LL n,m;
//     cin>>n>>m;
    
//     s[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         f[i][0]=a[i];
//         s[i]=s[i-1]+a[i];
//     }
//     st(n);
//     LL lt=0;
//     LL rt=n;
//     LL mid;
//     while(lt<=rt)
//     {
//         int tag=1;
//         mid=lt+rt>>1;
//         for(int i=mid;i<=n;i++)
//         {
//             if(s[i]-s[i-mid]>m)
//             {
//                 tag=0;
//             }
//             // printf("[%lld]",s[i]-s[i-mid]);
//         }
//         if(tag)
//         {
//             lt=mid+1;
//         }
//         else
//         {
//             rt=mid-1;
//         }
//     }

//     LL len=lt-1;
//     if(len==0)
//     {
//         cout<<"-1"<<'\n';
//     }
//     // printf("{%lld}",len);
//     int h=0;
//     int t=-1;
//     for(int i=1;i<=n;i++)
//     {
//         if(h<=t&&q[h]<i-len)
//         {
//             h++;
//         }
//         LL maxn=find(q[h]+1,i);
//         // printf("<%lld,%d,%d>",maxn,q[h]+1,i);
//         if(h<=t)
//         {
//             dp[i]=dp[q[h]]+maxn;
//         }
        
//         while(h<=t&&dp[i]<=dp[q[t]])
//         {
//             t--;
//         }
//         t++;
//         q[t]=i;
//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%lld,",dp[i]);
//     // }
//     cout<<dp[n]<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }


// Cut the Sequence
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];
// LL s[N];
// LL q[N];
// LL dp[N];

// void solve()
// {

//     memset(s,0,sizeof(s));
//     memset(dp,0,sizeof(dp));
//     memset(q,0,sizeof(q));
//     LL n,m;
//     cin>>n>>m;
    
//     s[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         s[i]=s[i-1]+a[i];
//     }
//     int h=0;
//     int t=-1;
//     LL sum=0;

//     for(int i=1,j=1;i<=n;i++)
//     {
//         sum+=a[i];
//         while(sum>m)
//         {
//             sum-=a[j++];
            
//         }
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }


//  没有上司的舞会
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=6e3+5;
// int r[N];
// int fa[N];
// int dp[N][10];
// bool vis[N];
// vector<int> e[N];
// void dfs(int u)
// {
//     vis[u]=true;
//     dp[u][1]=r[u];
//     dp[u][0]=0;
//     // printf("{%d}",u);
//     for(auto v:e[u])
//     {
//         if(!vis[v])
//         {
//             dfs(v);
//             dp[u][0]+=max(dp[v][0],dp[v][1]);
//             dp[u][1]+=dp[v][0];
//             // printf("{%d %d %d %d}\n",u,v,dp[u][0],dp[u][1]);            
//         }

//     }

// }
// void solve()
// {
//     e->clear();
//     memset(vis,false,sizeof(vis));
//     int n;
//     cin>>n;
//     vector<int> dout(n+10);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>r[i];
//     }
//     int l,k;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>l>>k;
//         e[l].push_back(k);
//         e[k].push_back(l);
//         dout[l]++;
//     }
//     int s;
//     for(int i=1;i<=n;i++)
//     {
//         if(dout[i]==0)
//         {
//             s=i;
//         }
//     }
//     dfs(s);
//     int ans=max(dp[s][1],dp[s][0]);
//     // printf("(%d)",ans);
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }


// P1040 [NOIP 2003 提高组] 加分二叉树
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=100+5;
// LL dp[N][N];
// int root[N][N];
// void dfs(int l,int r)
// {
//     int k=root[l][r];
//     cout<<k<<' ';
//     int l1=l;
//     int r1=k-1;
//     int l2=k+1;
//     int r2=r;
//     if(l1<=r1)
//     {
//         dfs(l1,r1);
//     }
//     if(l2<=r2)
//     {
//         dfs(l2,r2);
//     }
// }
// void solve()
// {
    
//     int n;
//     LL p;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>p;
//         dp[i][i]=p;
//         root[i][i]=i;
//     }
//     for(int len=2;len<=n;len++)
//     {
//         for(int l=1;l+len-1<=n;l++)
//         {
//             int r=l+len-1;
//             for(int k=r;k>=l;k--)
//             {
//                 int l1=l;
//                 int r1=k-1;
//                 int l2=k+1;
//                 int r2=r;
//                 LL ans=0;
//                 LL lans=1;
//                 LL rans=1;
//                 if(l1<=r1)
//                 {
//                     lans=dp[l1][r1];
//                 }
//                 if(l2<=r2)
//                 {
//                     rans=dp[l2][r2];
//                 }
//                 if(lans*rans+dp[k][k]>dp[l][r])
//                 {
//                     dp[l][r]=lans*rans+dp[k][k];
//                     root[l][r]=k;
//                 }
//             }
//         }
//     }
//     LL anss=dp[1][n];
//     cout<<anss<<'\n';    
//     dfs(1,n);

// }
// int main()
// {
//     solve();
//     return 0;
// }


// P1122 最大子树和
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// LL dp[N];
// int a[N];
// vector<int> e[N];
// bool vis[N];
// LL maxn;
// void dfs(int u)
// {
//     vis[u]=true;
//     dp[u]=a[u];
//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }
//         dfs(v);
//         int x,y,z;
//         dp[u]=max(dp[u],dp[v]+dp[u]);
//         maxn=max(dp[u],maxn);
//     }
// }
// void solve()
// {
//     maxn=-1e9;
//     memset(vis,false,sizeof(vis));
//     e->clear();

//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     int x,y;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>x>>y;
//         e[x].push_back(y);
//         e[y].push_back(x);

//     }
//     dfs(1);
//     cout<<maxn<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }


// P1273 有线电视网
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=4005;
// LL dp[N][N];
// int pay[N];
// int siz[N];
// bool vis[N];
// int n,m;
// int last[N];
// struct node{
//     int v,w,next;
// }a[2*N];
// int tot;
// void add(int u,int v,int w)
// {
//     tot++;
//     a[tot]={v,w,last[u]};
//     last[u]=tot;
// }
// void dfs(int u)
// {
//     if(u>=n-m+1)
//     {
//         siz[u]=1;
//         return;
//     }
//     vis[u]=true;
//     for(int h=last[u];h>=1;h=a[h].next)
//     {
//         int v=a[h].v;
//         int w=a[h].w;

//         if(vis[v])
//         {
//             continue;
//         }
//         dfs(v);
//         siz[u]+=siz[v];

//         for(int i=siz[u];i>=0;i--)
//         {
//             for(int j=0;j<=siz[v]&&j<=i;j++)
//             {
//                 dp[u][i]=max(dp[u][i-j]+dp[v][j]-w,dp[u][i]);
//             }
//         }
//     }
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));
//     memset(siz,0,sizeof(siz));
//     memset(last,0,sizeof(last));
//     tot=0;

//     cin>>n>>m;
//     int k,c;
//     int w;
//     for(int i=1;i<=n-m;i++)
//     {
//         cin>>k;
//         while(k--)
//         {
//             cin>>w>>c;
//             add(i,w,c);
//             add(w,i,c);
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             dp[i][j]=-1e9;
//         }
//     }
//     for(int i=n-m+1;i<=n;i++)
//     {
//         cin>>dp[i][1];
//     }
    
//     dfs(1);
//     for(int i=siz[1];i>=0;i--)
//     {
//         if(dp[1][i]>=0)
//         {
//             cout<<i<<'\n';
//             break;
//         }
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }


// P2014 [CTSC1997] 选课
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=305;
// int k[N];
// int dp[N][N];
// int siz[N];

// vector<int> topu;
// vector<int> e[N];
// bool vis[N];
// int din[N];
// int dinx[N];
// int n,m;
// void dfs(int u)
// {
//     // printf("{%d}",u);
//     vis[u]=true;
//     siz[u]=1;
//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }
//         dfs(v);
//         for(int i=m;i>0;i--)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
//                 // printf("<%d %d %d %d %d>",i,j,dp[u][i],u,v);

//             }
//         }        
//         // printf("\n");
//     }

// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));
//     memset(din,0,sizeof(din));
//     memset(siz,0,sizeof(siz));

//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             dp[i][j]=-1;
//         }
//     }
//     cin>>n>>m;
//     m++;
//     int s;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>s>>k[i];
//         dp[i][1]=k[i];
//         if(s==0)
//         {
//             continue;
//         }
//         din[i]++;
//         e[s].push_back(i);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(din[i]==0)
//         {
//             e[0].push_back(i);
//         }
//     }
//     dfs(0);
//     // for(int i=0;i<=n;i++)
//     // {
//     //     // for(int j=0;j<=m;j++)
//     //     // {
//     //         printf("[%d],",siz[i]);
//     //     // }
//     //     printf("\n");

//     // }
//     cout<<dp[0][m]<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }


// P2585 [ZJOI2006] 三色二叉树
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=5e5+5;
// string s;
// int a[N];
// int dp[N][5];
// int pd[N][5];

// vector<int> e[N];
// int p;
// void ct(int u)
// {
//     // cout<<p<<' ';
//     int x=a[p];
//     for(int i=1;i<=x;i++)
//     {
//         p++;
//         e[u].push_back(p);
        
//         ct(p);
        
//     }
// }
// bool vis[N];
// void dfs(int u)
// {
//     // printf("{%d}",u);
//     vis[u]=true;
//     vector<int> ch;
//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }
//         ch.push_back(v);
//         dfs(v);
//     }
//     // for(int i=0;i<ch.size();i++)
//     // {
//     //     printf("(%d %d)",u,ch[i]);
//     // }
//     if(ch.size()==1)
//     {
//         dp[u][2]=max(dp[ch[0]][0],dp[ch[0]][1])+1;
//         dp[u][0]=max(dp[ch[0]][1],dp[ch[0]][2]);
//         dp[u][1]=max(dp[ch[0]][2],dp[ch[0]][0]);
//         pd[u][2]=min(pd[ch[0]][0],pd[ch[0]][1])+1;
//         pd[u][0]=min(pd[ch[0]][1],pd[ch[0]][2]);
//         pd[u][1]=min(pd[ch[0]][2],pd[ch[0]][0]);        
//     }
//     else if(ch.size()==2)
//     {
//         dp[u][2]=max(dp[ch[0]][1]+dp[ch[1]][0],dp[ch[0]][0]+dp[ch[1]][1])+1;
//         dp[u][0]=max(dp[ch[0]][1]+dp[ch[1]][2],dp[ch[0]][2]+dp[ch[1]][1]);
//         dp[u][1]=max(dp[ch[0]][0]+dp[ch[1]][2],dp[ch[0]][2]+dp[ch[1]][0]);
//         pd[u][2]=min(pd[ch[0]][1]+pd[ch[1]][0],pd[ch[0]][0]+pd[ch[1]][1])+1;
//         pd[u][0]=min(pd[ch[0]][1]+pd[ch[1]][2],pd[ch[0]][2]+pd[ch[1]][1]);
//         pd[u][1]=min(pd[ch[0]][0]+pd[ch[1]][2],pd[ch[0]][2]+pd[ch[1]][0]);
//     }
    
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));
//     p=1;
//     cin>>s;
//     int len=s.length();
//     for(int i=1;i<=len;i++)
//     {
//         dp[i][2]=1;
//         dp[i][0]=0;
//         dp[i][1]=0;
//         pd[i][2]=1;
//         pd[i][0]=0;
//         pd[i][1]=0;        
//     }
//     for(int i=0;i<len;i++)
//     {
//         int x=i+1;
//         a[x]=s[i]-'0';

//     }
//     ct(1);
//     dfs(1);
//     int maxn=0;
//     int minn=1e9;
//     maxn=max(dp[1][2],max(dp[1][1],dp[1][0]));
//     minn=min(pd[1][2],min(pd[1][0],pd[1][1]));
//     cout<<maxn<<' '<<minn<<'\n';

// }
// int main()
// {
//     solve();
//     return 0;
// }



// P3047 [USACO12FEB] Nearby Cows G
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// vector<int> e[N];
// bool vis[N];
// int dp1[N][30];
// int dp2[N][30];
// int c[N];
// int n,k;
// void dfs1(int u)
// {
//     // printf("(%d)",u);
//     vis[u]=true;
//     // if(e[u].empty())
//     // {
//     //     dp1[u][0]=c[u];
//     // }
//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }

//         dfs1(v);
//         for(int i=k;i>=1;i--)
//         {
//             dp1[u][i]+=dp1[v][i-1];
//             // printf("{%d %d}",u,dp1[u][i]);
//         }
//     }
// }
// void dfs2(int u)
// {

//     vis[u]=true;
//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }
//         for(int i=k;i>=1;i--)
//         {
//             if(i==1)
//             {
//                 dp2[v][i]=dp2[u][i-1]+dp1[v][i];
//             }
//             else
//             {
//                 dp2[v][i]=dp2[u][i-1]+dp1[v][i]-dp1[v][i-2];
//             }
//             // printf("{%d %d}",u,dp2[u][i]);
//         }    
//         dfs2(v);
//     }
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));
//     memset(dp1,0,sizeof(dp1));
//     memset(dp2,0,sizeof(dp2));
//     cin>>n>>k;
//     int u,v;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);

//     }
//     int x;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         for(int j=0;j<=k;j++)
//         {
//             dp1[i][j]=x;
            
//         }
//         dp2[i][0]=x;
//     }
//     dfs1(1);
//     memset(vis,false,sizeof(vis));
//     for(int i=0;i<=k;i++)
//     {
//         dp2[1][i]=dp1[1][i];

//     }

//     dfs2(1);
//     for(int i=1;i<=n;i++)
//     {
//         cout<<dp2[i][k]<<'\n';
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }


// P3698 [CQOI2017] 小Q的棋盘
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+5;
// using LL=long long;
// vector<int> e[N];
// bool vis[N];
// int n,k;
// int dp[N][N];
// int siz[N];
// void dfs(int u)
// {
//     vis[u]=true;
//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }
//         dfs(v);
//         int sizu=siz[u];
//         siz[u]+=siz[v];
//         for(int i=1;i<=k;i++)
//         {
//             if(i<=2*(sizu-1))
//             {
//                 dp[u][i]=max(dp[v][i-1]+1,dp[u][i]);
//             }
//             else if(i>=2*(siz[u]-1))
//             {
//                 dp[u][i]=siz[u];
//             }
//             else
//             {
//                 int j=i-2*(sizu-1);

//                 dp[u][i]=sizu+dp[v][j-1];
//             }
//             // printf("{%d %d %d,%d}",u,v,dp[u][i],sizu);
            
//         }
        
//     }
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));

//     cin>>n>>k;
//     int u,v;

//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);

//     }
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=k;j++)
//         {
//             dp[i][j]=1;
//         }
        
//         siz[i]=1;
//     }
//     dfs(0);

//     cout<<dp[0][k]<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// P2704 [NOI2001] 炮兵阵地
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=110;
// const int M=(1<<11)+5;
// int n,m;
// char a[N];
// int b[N];
// int num[M];
// int s[M];
// int f[2][M][M];
// void solve()
// {
//     memset(b,0,sizeof(b));
//     memset(s,0,sizeof(s));
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%s",a+1);
//         for(int j=1;j<=m;j++)
//         {
//             b[i]=b[i]<<1;
//             if(a[j]=='P')
//             {
//                 // printf("[%d]",j);
//                 b[i]=b[i]|1;
//             }
//         }
//         // printf("(%d)",b[i]);
//     }
//     int cnt=0;
//     for(int i=0;i<=(1<<m);i++)
//     {
//         if(!(i&(i<<1)) && !(i&(i<<2)))
//         {
//             // printf("<%d>",i);
//             cnt++;
//             s[cnt]=i;
//             int x=i;
//             while(x!=0)
//             {
//                 if((x&1)==1)
//                 {
//                     num[i]++;
//                 }
//                 x=x>>1;
//             }            
//         }

//     }
//     int maxn=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int x=1;x<=cnt;x++)
//         {
//             for(int y=1;y<=cnt;y++)
//             {
//                 for(int z=1;z<=cnt;z++)
//                 {
//                     if(!(s[x]&s[y])&&!(s[x]&s[z])&&!(s[z]&s[y])&&(b[i]&s[x])==s[x]&&(b[i-1]&s[y])==s[y])
//                     {
//                         f[i&1][x][y]=max(f[i&1][x][y],f[(i-1)&1][y][z]+num[s[x]]);
//                         maxn=max(maxn,f[i&1][x][y]);
//                     }
//                 }
//             }
//         }
//     }
    

//     // for(int i=1;i<=cnt;i++)
//     // {
//     //     for(int j=1;j<=cnt;j++)
//     //     {

            
//     //     }
//     //     cout<<'\n';
//     // }
//     cout<<maxn<<'\n';

// }
// int main()
// {
//     solve();

//     return 0;
// }



// P1879 [USACO06NOV] Corn Fields G
// #include<bits/stdc++.h>
// using namespace std;
// const int M=20;
// const int N=(1<<12)+5;
// const int mod=1e8;
// using LL=long long;
// LL a[M];
// LL dp[M][N];
// LL s[N];
// LL mp[N];
// void solve()
// {
//     memset(mp,0,sizeof(mp));
//     int n,m;
//     cin>>m>>n;
//     LL b,c;
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin>>b;
//             mp[i]=mp[i]<<1;
//             if(b==1)
//             {
//                 mp[i]=mp[i]|1;
                
//             }
            
//         }
//         // cout<<mp[i]<<'\n';

//     }
//     int cnt=0;
//     for(int i=0;i<=(1<<n);i++)
//     {
//         if(!(i&(i<<1)))
//         {
//             cnt++;
//             s[cnt]=i;
//         }
//     }

//     // printf("(%d)",cnt-1);
//     // mp[0]=(1<<n)-1;
//     for(int i=1;i<=cnt-1;i++)
//     {
//         if(((s[i]&mp[1])==s[i]))
//         {
//             dp[1][i]=1;
//         }
        
//     }
//     for(int i=2;i<=m;i++)
//     {
//         for(int j=1;j<=cnt-1;j++)
//         {
//             for(int k=1;k<=cnt-1;k++)
//             {
                
//                 if(!(s[j]&s[k])&&((s[j]&mp[i])==s[j])&&((s[k]&mp[i-1])==s[k]))
//                 {
//                     // printf("<%d,%d,%d,%lld,%lld>",i,j,k,s[j],s[k]);
//                     dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
//                     // printf("{%lld}",dp[i][j]);
//                 }
            
//             }
//         }
//     }
//     LL ans=0;
//     for(int i=1;i<=cnt-1;i++)
//     {
//         ans+=dp[m][i];
        
//     }
//     ans=ans%mod;
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// P1896 [SCOI2005] 互不侵犯
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=10;
// const int M=(1<<N)+5;
// const int K=100;
// LL dp[N][M][K];
// LL s[M];
// LL num[M];

// void solve()
// {
//     memset(num,0,sizeof(num));
//     LL n,kx;
//     cin>>n>>kx;
//     int cnt=0;
//     for(int i=0;i<=(1<<n);i++)
//     {
//         if(!(i&(i<<1)))
//         {
//             cnt++;
//             s[cnt]=i;
//             int y=i;
//             while(y!=0)
//             {
//                 if(y&1)
//                 {
//                     num[i]++;
//                 }
//                 y=y>>1;
//             }
//         }
//     }
//     // for(int i=1;i<=cnt-1;i++)
//     // {
//     //     printf("{%d}",s[i]);
//     // }
//     for(int i=1;i<=cnt-1;i++)
//     {
//         LL ss=num[s[i]];
//         // for(int l=0;l<=num[ss];l++)
//         // {
//             dp[1][i][ss]=1;
//         // }
        
        
//     }
//     for(int i=2;i<=n;i++)
//     {
//         for(int j=1;j<=cnt-1;j++)
//         {
//             for(int k=1;k<=cnt-1;k++)
//             {
//                 for(int l=0;l<=kx;l++)
//                 {
//                     if(!(s[j]<<1&s[k]<<1)&&!(s[j]<<2&s[k]<<1)&&!(s[j]&s[k]<<1))
//                     {
//                         if(l-num[s[j]]>=0)
//                         {
//                             dp[i][j][l]+=dp[i-1][k][l-num[s[j]]];                            
//                         }

//                         // printf("{%d %d %d %d %d}\n",i,j,k,l,dp[i][j][l]);
//                         // printf("|%d,%d|\n",s[j],s[k]);
//                     }                    
//                 }

                
//             }
//         }
//     }
//     LL ans=0;
//     for(int i=0;i<=cnt-1;i++)
//     {
//         ans+=dp[n][i][kx];
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }


// P3092 [USACO13NOV] No Change G
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int K=16;
// const int N=2e5+5;
// const int M=(1<<K)+10;
// LL a[N];
// LL b[N];
// LL s[N];
// LL dp[M];
// LL f[M];

// void solve()
// {
//     memset(f,0,sizeof(f));
//     memset(dp,0,sizeof(dp));
//     memset(s,0,sizeof(s));
//     LL n,k;
//     cin>>k>>n;
//     LL x,y,z;
//     LL ss=0;
//     for(int i=0;i<k;i++)
//     {
//         cin>>a[i];
//         ss+=a[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cin>>b[i];
//     }
//     s[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         s[i]=s[i-1]+b[i];

//     }
//     LL minn=1e9;

//     for(int i=1;i<(1<<k);i++)
//     {
//         for(int j=0;j<k;j++)
//         {
//             if(i&(1<<j))
//             {

//                 x=(i-(1<<j));
//                 y=j;
//                 // f[i]=f[x]+a[j];
//                 // printf("%lld",f[i]);
//                 int p=lower_bound(s+1,s+1+n,a[j]+s[dp[x]]+1)-s;
//                 z=p-1;
                
//                 // if(s[p]>a[j]+s[dp[x]])
//                 // {
//                 //     z=p-1;
//                 // }
//                 dp[i]=max(dp[i],min(z,n));
//                 // if(z!=0)
//                 // {
//                 //     f[i]=s[z];                    
//                 // }
//                 // else
//                 // {
//                 //     f[i]=f[x];
//                 // }
//                 f[i]=f[x]+a[j];
//                 // printf("{%d %d %d %d %lld %d}\n",i,j,z,x,f[i],dp[i]);
//                 if(z>=n)
//                 {
//                     // LL s1=0;
//                     // for(int l=0;l<k;l++)
//                     // {
//                     //     if(i&(1<<l))
//                     //     {
//                     //         s1+=a[l];
//                     //     }
//                     // }
//                     minn=min(minn,f[i]);
//                 }
//             }

//         }
//     }
//     if(minn==1e9)
//     {
//         cout<<"-1"<<'\n';
//     }
//     else
//     {
//         cout<<ss-minn<<'\n';
//     }
    
// }
// int main()
// {
//     solve();

//     return 0;
// }


// P3694 邦邦的大合唱站队
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e5+5;
const int M=(1<<20)+5;
LL s[N][25];

LL dp[M];
LL num[25];

void solve()
{
    memset(num,0,sizeof(num));

    memset(s,0,sizeof(s));
    for(int i=0;i<=M;i++)
    {
        dp[i]=1e18;
    }
    int n,m;
    cin>>n>>m;
    LL x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        num[x]++;
        for(int j=1;j<=m;j++)
        {
            s[i][j]=s[i-1][j];
        }
        s[i][x]++;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout<<s[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for(int i=1;i<=m;i++)
    // {
    //     printf("<%lld>",num[i]);
    // }
    dp[0]=0;
    for(int i=1;i<(1<<m);i++)
    {
        LL sum=0;
        for(int j=0;j<m;j++)
        {
            if(i&(1<<j))
            {
                sum+=num[j+1];

            }
        }
        for(int j=0;j<m;j++)
        {
            if(i&(1<<j))
            {
                x=i^(1<<j);
                LL l,r;
                r=sum;
                l=sum-num[j+1];
                y=s[r][j+1]-s[l][j+1];

                dp[i]=min(dp[i],num[j+1]-y+dp[x]);
                // printf("{%lld,%lld}",y,num[j+1]);
                // printf("{%d %d %d %d %d %lld}\n",i,j,x,l,r,dp[i]);
            }
        }        
    }
    cout<<dp[(1<<m)-1]<<'\n';
}
int main()
{
    solve();
    return 0;
}