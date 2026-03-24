// 线性基高斯消元模板
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// int n,k;
// LL a[64];
// void gauss()
// {
//     for(int i=63;i>=0;i--)
//     {
//         for(int j=k;j<n;j++)
//         {
//             if(a[j]>>i&1)
//             {
//                 swap(a[j],a[k]);
//                 break;
//             }
//         }
//         if((a[k]>>i&1)==0)
//         {
//             continue;
//         }
//         for(int j=0;j<n;j++)
//         {
//             if(j!=k&&(a[j]>>i&1))
//             {
//                 a[j]=a[j]^a[k];
//             }
//         }
//         k++;
//         if(k==n)
//         {
//             break;
//         }
//     }
// }
// int main()
// {
//     memset(a,0,sizeof(a));
//     scanf("%d",&n);
//     for(int i=0;i<n;i++)
//     {
//         scanf("%lld",&a[i]);

        
//     }
//     k=0;
//     gauss();
//     LL ans=0;
//     for(int i=0;i<k;i++)
//     {
//         ans^=a[i];

//     }
//     printf("%lld\n",ans);
//     return 0;
// }


// 线性基贪心模板
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// int n,k;
// LL p[64];
// void insert(LL x)
// {
//     for(int i=63;i>=0;i--)
//     {
//         if(x>>i&1)
//         {
//             if(p[i])
//             {
//                 x^=p[i];            
//             }
//             else
//             {
//                 p[i]=x;
//                 break;
//             }
//         }

//     }
// }
// int main()
// {
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);

//     }
//     insert();
//     return 0;
// }


// 米勒拉宾素性检验
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// int a[]={2,3,5,7,11,13,17,19,23,29,31,37};
// LL mul(LL a,LL b,LL mod)
// {
//     a%=mod;
//     b%=mod;
//     LL c=(long double)a*b/mod;
//     LL ans=a*b-c*mod;
//     return (ans%mod+mod)%mod;
// }
// LL pow_mod(LL a,LL b,LL mod)
// {
//     LL res=1;
//     a=a%mod;
//     while(b)
//     {
//         if(b&1)
//         {
//             res=mul(res,a,mod);

//         }
//         a=mul(a,a,mod); 
//         b=b>>1;
               
//     }
//     return (res+mod)%mod;
// }
// bool M_R(LL a,LL n)
// {
//     if(n==2)
//     {
//         return true;
//     }
//     if(!(n&1))
//     {
//         return false;
//     }
//     LL d=n-1;
//     LL r=0;
//     while(!(d&1))
//     {
//         r++;
//         d=d>>1;
        
//     }
//     LL t=pow_mod(a,d,n);
//     if(t==1)
//     {
//         return true;
//     }
//     for(int i=1;i<=r;i++)
//     {
//         t=t*t%n;
//         if(t==n-1)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// bool isprime(LL n)
// {
//     if(n<=1)
//     {
//         return false;
//     }
//     for(int i=0;i<12;i++)
//     {
//         if(n==a[i])
//         {
//             return true;
//         }
//         if(n%a[i]==0)
//         {
//             return false;
//         }
//         if(!M_R(a[i],n))
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int t;
//     LL x;
//     scanf("%d",&t);
//     for(int i=1;i<=t;i++)
//     {
//         scanf("%lld",&x);
//         if(isprime(x))
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


// 【模板】卢卡斯定理/Lucas 定理
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// int main()
// {
//     int n,m,p;
//     int t;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d%d%d",&n,&m,&p);
        
//     }
//     return 0;
// }


// 筛法求欧拉函数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// int phi[N];
// int p[N];
// int vis[N];
// int cnt;
// int phi_(int n)
// {
//     int res=n;
//     for(int i=2;i*i<=n;i++)
//     {
//         if(n%i==0)
//         {
//             res=res*((i-1)/i);
//             while(n%i==0)
//             {
//                 n=n/i;
//             }
//         }
//     }
//     if(n>1)
//     {
//         res=res*((n-1)/n);
//     }
//     return res;

// }
// void get_phi(int n)
// {
//     phi[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         if(!vis[i])
//         {
//             p[cnt++]=i;
//             phi[i]=i-1;

//         }
//         for(int j=0;i*p[j]<=n;j++)
//         {
//             int m=i*p[j];
//             vis[m]=1;
//             if(i%p[j]==0)
//             {
//                 phi[m]=p[j]*phi[i];
//                 break;
//             }
//             else
//             {
//                 phi[m]=(p[j]-1)*phi[i];
//             }
//         }
//     }
// }
// int main()
// {
//     return 0;
// }


// 欧拉筛【模板】线性筛素数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e8+5;
// int vis[N];
// int prim[N];
// int cnt;
// void get_prim(int n)
// {

//     for(int i=2;i<=n;i++)
//     {
//         if(!vis[i])
//         {
//             cnt++;
//             prim[cnt]=i;
//         }        
//         for(int j=1;1ll*prim[j]*i<=n;j++)
//         {
//             vis[i*prim[j]]=1;
//             if(i%prim[j]==0)
//             {
//                 break;
//             }
//         }
//     }
// }
// int main()
// {
//     //关闭C++和C的输入输出流的同步，提高C++的输入输出效率
//     std::ios::sync_with_stdio(false);
//     //解除cin和cout的绑定，让它们可以独立缓冲
//     std::cin.tie(0);
//     std::cout.tie(0);//这一句可以不要，效果一样
//     int n;
//     int q;
//     int k;
//     cin>>n>>q;
//     get_prim(n);
//     for(int i=1;i<=q;i++)
//     {
//         cin>>k;
//         cout<<prim[k]<<'\n';
//     }
//     return 0;
// }


// 筛法求莫比乌斯函数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// int p[N];
// int vis[N];
// int cnt;
// int mu[N];
// void get_mu(int n)
// {
//     mu[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         if(!vis[i])
//         {
//             cnt++;
//             p[cnt]=i;
//             mu[i]=-1;
//         }
//         for(int j=1;i*p[j]<=n;j++)
//         {
//             int m=i*p[j];
//             vis[m]=1;
//             if(i%p[j]==0)
//             {
//                 mu[m]=0;
//                 break;
//             }
//             else
//             {
//                 mu[m]=-mu[i];
//             }
//         }
//     }
// }
// int main()
// {
//     return 0;
// }


// 快速幂
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// LL qpow(LL a,LL b,LL mod)
// {
//     LL ans=1;
//     LL p;
//     while(b)
//     {
//         if(b&1)
//         {
//             ans=ans*a%mod;
//         }
//         a=a*a%mod;
//         b=b>>1;
//     }
//     return ans;
// }
// int main()
// {
//     int a,b,mod;
//     scanf("%d%d%d",&a,&b,&mod);
//     printf("%lld\n",qpow(a,b,mod));
    
//     return 0;
// }


// 同余式 乘法逆元 费马小定理  【模板】模意义下的乘法逆元(未完)
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// LL qpow(LL a,LL b,LL mod)
// {
//     LL ans=1;
//     while(b)
//     {
//         if(b&1)
//         {
//             ans=ans*a%mod;
//         }
//         a=a*a%mod;
//         b=b>>1;

//     }
//     return ans;
// }
// int main()
// {
//     LL n,p;
//     scanf("%lld%lld",&n,&p);
//     for(int i=1;i<=n;i++)
//     {
//         printf("%lld\n",qpow(i,p-2,p));
//     }
//     return 0;
// }


//  剩余系 欧拉定理 扩展欧拉定理  【模板】扩展欧拉定理
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e7+5;

// using LL=long long;
// char b[N];
// LL phi_(LL n)
// {
//     LL ans=n;
//     for(int i=2;i*i<=n;i++)
//     {
//         if(n%i==0)
//         {
//             ans=ans*(i-1)/i;
//             while(n%i==0)
//             {
//                 n=n/i;
//             }
//         }

//     }
//     if(n>1)
//     {
//         ans=ans*(n-1)/n;

//     }
//     return ans;
// }
// int flag;
// LL depow(LL mod,int len)
// {
//     LL x=b[1]-'0';
//     LL y;
//     for(int i=2;i<=len;i++)
//     {
//         y=b[i]-'0';
//         x=x*10+y;
//         if(x>=mod)
//         {
//             flag=1;
//             x=x%mod;
//         }
//     }
//     if(flag)
//     {
//         x+=mod;
//     }
//     return x;
// }
// LL qpow(LL a,LL b,LL mod)
// {
//     LL ans=1;
//     while(b)
//     {
//         if(b&1)
//         {
//             ans=ans*a%mod;
//         }
//         a=a*a%mod;
//         b=b>>1;

//     }
//     return ans;
// }
// int main()
// {
//     LL a,m;
//     scanf("%lld%lld",&a,&m);
//     getchar();
//     scanf("%s",b+1);
//     LL len=strlen(b+1);
//     LL mm=phi_(m);
//     LL x=b[1]-'0';
//     LL y;
//     int tag=0;
//     for(int i=2;i<=len;i++)
//     {
//         y=b[i]-'0';

//         x=x*10+y;
//         if(x>=mm)
//         {
//             tag=1;
//             break;
//         }
//     }
//     // printf("\n%lld,%lld",x,len);
//     if(tag)
//     {
//         LL dm=depow(mm,len);
//         printf("%lld\n",qpow(a,dm,m));
//     }
//     else
//     {
//         printf("%lld\n",qpow(a,x,m));
//     }
//     // printf(" %lld",x);
//     return 0;
// }


// 威尔逊定理
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     return 0;
// }


// 【模板】裴蜀定理
// #include<bits/stdc++.h>
// using namespace std;
// const int N=25;
// using LL=long long;
// LL a[N];
// LL get_gcd(LL a,LL b)
// {
//     LL t;
//     while(b!=0)
//     {
//         t=a%b;
//         a=b;
//         b=t;
//     }
//     return a;


// }
// int main()
// {
//     LL n;
//     LL m;
//     scanf("%lld",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&m);
//         if(m<0)
//         {
//             m=-m;
//         }
//         a[i]=m;

//     }
//     LL gcd_=a[1];

//     for(int i=2;i<=n;i++)
//     {
//         gcd_=get_gcd(gcd_,a[i]);
//     }
//     printf("%lld",gcd_);
//     // printf("\n%lld,%lld",n,m);
//     // scanf("%lld%lld",&n,&m);
//     // printf("%lld",get_gcd(n,m));
//     return 0;
// }


// 拓展欧几里得算法
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// int exgcd(int a,int b,int &x,int &y)
// {
//     if(b==0)
//     {
//         x=1;
//         y=0;
//         return a;
//     }
//     int x1,y1,d;
//     d=exgcd(b,a%b,x1,y1);
//     x=y1;
//     y=x1-a/b*y1;
//     return d;
// }
// int main()
// {
//     return 0;
// }


// 同余方程 乘法逆元 扩展欧几里得算法
// #include<bits/stdc++.h>
// using namespace std;
// int exgcd(int a,int b,int &x,int &y)
// {
//     if(b==0)
//     {
//         x=1;
//         y=0;
//         return a;
//     }
//     int x1,y1,d;
//     d=exgcd(b,a%b,x1,y1);
//     x=y1;
//     y=x1-a/b*y1;
//     return d;
// }
// int main()
// {
//     int a,b,m,x,y;
//     scanf("%d%d%d",&a,&b,&m);
//     int d=exgcd(a,m,x,y);
//     if(b%d==0)
//     {
//         printf("%d",1ll*x*b/d%m);
//     }
//     return 0;
// }


//  [NOIP 2012 普及组] 质因数分解
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// int main()
// {
//     LL n;
//     scanf("%lld",&n);
//     for(int i=2;i*i<=n;i++)
//     {
//         if(n%i==0)
//         {
//             printf("%lld",n/i);
//             return 0;
//         }
//     }
//     return 0;
// }



// 基于值域预处理的快速 GCD
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5005;
// using LL=long long;
// LL aa[N];
// LL bb[N];

// LL qpow(LL a,LL b,LL mod)
// {
//     LL ans=1;
//     while(b)
//     {
//         if(b&1)
//         {
//             ans=ans*a%mod;
//         }
//         a=a*a%mod;
//         b=b>>1;

//     }
//     return ans;

// }
// LL gcd(LL a,LL b)
// {
//     LL t;
//     while(b!=0)
//     {
//         t=a%b;
//         a=b;
//         b=t;
//     }
//     return a;
// }
// int main()
// {
//     LL n;

//     scanf("%lld",&n);
//     for(int i=1;i<+n;i++)
//     {
//         scanf("%lld",&aa[i]);

//     }
//     for(int i=1;i<+n;i++)
//     {
//         scanf("%lld",&bb[i]);
        
//     }
//     for(int i=1;i<=n;i++)
//     {

//     }
//     return 0;
// }


// 中国剩余定理 【模板】中国剩余定理（CRT）/ 曹冲养猪
// #include<bits/stdc++.h>
// using namespace std;
// using LL=__int128;
// const int N=1e6+5;
// LL m[N];
// LL r[N];
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
// LL exgcd(LL a,LL b,LL &x,LL &y)
// {
//     if(b==0)
//     {
//         x=1;
//         y=0;
//         return a;
//     }
//     LL x1,y1,d;
//     d=exgcd(b,a%b,x1,y1);
//     x=y1;
//     y=x1-a/b*y1;
//     return d;
// }
// LL CRT(int n)
// {
//     LL M=1;
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         M*=m[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         LL c=M/m[i];
//         LL x,y;
//         exgcd(c,m[i],x,y);
//         ans=(ans+r[i]*c*x%M)%M;
//     }
//     return (ans%M+M)%M;

// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         m[i]=read();
//         r[i]=read();

//     }
//     LL ans=CRT(n);
//     print(ans);
//     return 0;
// }


// [TJOI2009] 猜数字
// #include<bits/stdc++.h>
// using namespace std;
// using LL=__int128;
// const int N=1e6+5;
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
// LL a[N];
// LL b[N];
// LL exgcd(LL a,LL b,LL &x,LL &y)
// {
//     if(b==0)
//     {
//         x=1;
//         y=0;
//         return a;
//     }
//     LL x1,y1,d;
//     d=exgcd(b,a%b,x1,y1);
//     x=y1;
//     y=x1-a/b*y1;
//     return d;
// }
// LL CRT(int k)
// {
//     LL ans=0;
//     LL M=1;
//     for(int i=1;i<=k;i++)
//     {
//         M*=b[i];
//     }
//     for(int i=1;i<=k;i++)
//     {
//         LL c=M/b[i];
//         LL x,y;
//         exgcd(c,b[i],x,y);
//         ans=(ans+a[i]*c*x%M)%M;


//     }
//     return (ans%M+M)%M;

// }
// int main()
// {
//     int k;
//     scanf("%d",&k);
//     for(int i=1;i<=k;i++)
//     {
//         a[i]=read();
//     }
//     for(int i=1;i<=k;i++)
//     {
//         b[i]=read();
//     }
//     LL ans=CRT(k);
//     print(ans);
//     return 0;
// }



// 扩展中国剩余定理
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;
// LL m[N];
// LL r[N];
// LL exgcd(LL a,LL b,LL &x,LL &y)
// {
//     if(b==0)
//     {
//         x=1;
//         y=0;
//         return a;
//     }
//     LL x1,y1,d;
//     d=exgcd(b,a%b,x1,y1);
//     x=y1;
//     y=x1-a/b*y1;
//     return d;
// }

// LL EXCRT(int n)
// {
//     LL m1,m2,r1,r2,p,q;
//     m1=m[1];
//     r1=r[1];
//     for(int i=2;i<=n;i++)
//     {
//         m2=m[i];
//         r2=r[i];
//         LL d=exgcd(m1,m2,p,q);
//         if((r2-r1)%d)
//         {
//             return -1;
//         }
//         p=p*(r2-r1)/d;
//         p=(p%(m2/d)+m2/d)%(m2/d);
//         r1=m1*p+r1;
//         m1=m1*m2/d;
//     }
//     return (r1%m1+m1)%m1;
// }
// int main()
// {
//     return 0;
// }


// 素数个数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e8+5;
// int prim[N];
// bool vis[N];
// int n,m;
// void get_prim()
// {
//     for(int i=2;i<=n;i++)
//     {
//         if(vis[i]==false)
//         {
//             m++;
//             prim[m]=i;
//         }
//         for(int j=1;1ll*i*prim[j]<=n;j++)
//         {
//             vis[i*prim[j]]=true;
//             if(i%prim[j]==0)
//             {
//                 break;
//             }
//         }
//     }
// }
// int main()
// {
//     m=0;
//     scanf("%d",&n);
//     get_prim();
//     printf("%d",m);
//     return 0;
// }


// 角色属性树
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];
// int fa[N];
// LL gcd(LL x,LL y)
// {
//     LL t;
//     while(y!=0)
//     {
//         t=x;
//         x=y;
//         y=t%y;
//     }
//     return x;
// }
// int main()
// {
//     memset(fa,0,sizeof(fa));
//     LL n,k;
//     int x,y;
//     scanf("%lld%lld",&n,&k);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//     }
//     for(int i=1;i<=n-1;i++)
//     {
//         scanf("%d%d",&x,&y);
//         fa[y]=x;
//     }
//     int s;
    
//     LL u,v;
//     int op;
//     for(int i=1;i<=k;i++)
//     {
//         scanf("%d",&op);
//         if(op==1)
//         {
//             scanf("%lld",&u);
//             int z=u;
//             int ans=0;
//             while(fa[z]!=0)
//             {
//                 z=fa[z];
//                 if(gcd(a[u],a[z])>1)
//                 {
//                     ans=z;
//                     break;
//                 }
//             }
//             if(ans)
//             {
//                 printf("%d\n",ans);
//             }
//             else
//             {
//                 printf("-1\n");
//             }
            
//         }
//         else if(op==2)
//         {

//             scanf("%lld%lld",&u,&v);
//             a[u]=v;
//         }
//     }
//     return 0;
// }



// 缘分
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// int main()
// {
//     int t;
//     LL n;
//     LL x;
//     scanf("%d",&t);
//     for(int i=1;i<=t;i++)
//     {
//         scanf("%lld",&x);
//         if(x==1)
//         {
//             printf("1\n");
//         }
//         else
//         {
//             printf("%lld\n",x*(x-1));
//         }
        
//     }
//     return 0;
// }


// 【XR-3】小道消息
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// bool isprim(LL n)
// {
//     for(int i=2;1ll*i*i<=n;i++)
//     {
//         if(n%i==0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     LL n,k;
//     scanf("%lld%lld",&n,&k);
//     k++;
//     bool ans=isprim(k);
//     if(ans)
//     {
//         if(k*2<=n+1)
//         {
//             printf("2");
//         }
//         else
//         {
//             printf("1");
//         }
//     }
//     else
//     {
//         printf("2");
//     }
//     return 0;
// }


// CF148D Bag of mice
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1005;
// double f[N][N];
// int main()
// {
//     memset(f,0,sizeof(f));
//     int w,b;
//     scanf("%d%d",&w,&b);
//     for(int i=1;i<=w;i++)
//     {
//         f[i][0]=1;
//     }
//     for(int i=1;i<=b;i++)
//     {
//         f[0][i]=0;
//     }
//     for(int i=1;i<=w;i++)
//     {
//         for(int j=1;j<=b;j++)
//         {
//             f[i][j]+=(double)i/(i+j);
//             if(i>=1&&j>=2)
//             {
//                 f[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*f[i-1][j-2];
//             }
//             if(j>=3)
//             {
//                 f[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*f[i][j-3];
//             }
//         }

//     }
//     printf("%.9lf",f[w][b]);
//     return 0;
// }


// Football
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=1e3+5;
// double f[N][N];
// double a[N][N];
// int main()
// {
//     int m;
//     while(scanf("%d",&m)!=EOF)
//     {
//         if(m==-1)
//         {
//             break;
//         }        
//         memset(f,0,sizeof(f));

//         int n=1<<m;

//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 scanf("%lf",&a[i][j]);
//             }
//         }
//         for(int i=1;i<=n;i++)
//         {
//             f[1][i]=(double)1;
//         }
//         for(int i=2;i<=m+1;i++)
//         {
//             int x=1<<(i-2);
//             for(int j=1;j<=n;j++)
//             {
//                 int y=(j-1)/x;
//                 if(y%2==0)
//                 {
//                     for(int k=(y+1)*x+1;k<=(y+2)*x;k++)
//                     {
//                         f[i][j]+=(double)f[i-1][j]*f[i-1][k]*a[j][k];
//                         // printf("ji:k=%d,x=%d,y=%d,f[%d][%d]=%lf\n",k,x,y,i,j,f[i][j]);
//                     }                    
//                 }
//                 else if(y%2==1)
//                 {
//                     for(int k=(y-1)*x+1;k<=y*x;k++)
//                     {
//                         f[i][j]+=(double)f[i-1][j]*f[i-1][k]*a[j][k];
//                         // printf("ou:f[%d][%d]=%lf\n",i,j,f[i][j]);
//                     }                       
//                 }
//             }
//         }
//         // for(int i=1;i<=n+1;i++)
//         // {
//         //     for(int j=1;j<=n;j++)
//         //     {
//         //         printf("%lf,",f[i][j]);
//         //     }
//         //     printf("\n");

//         // }
//         double maxn=-1;
//         int ans;
//         for(int i=1;i<=n;i++)
//         {
//             if(f[m+1][i]>maxn)
//             {
//                 maxn=f[m+1][i];
//                 ans=i;
//             }
//         }
//         printf("%d\n",ans);
//     }
    

//     return 0;
// }



// Collecting Bugs
// #include <cstring>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// using namespace std;
// const int N=1005;
// double f[N][N];
// int main()
// {
//     int n,s;
//     scanf("%d%d",&n,&s);
//     memset(f,0,sizeof(f));
//     f[n][s]=0;
//     for(int i=n;i>=0;i--)
//     {
//         for(int j=s;j>=0;j--)
//         {
//             if(i==n&&j==s)
//             {
//                 continue;
//             }
//             double q1=(1.0*i/n)*(1.0*j/s)*(f[i][j]+1);
//             double q2=(1-1.0*i/n)*(1-1.0*j/s)*(f[i+1][j+1]+1);
//             double q3=(1-1.0*i/n)*(1.0*j/s)*(f[i+1][j]+1);
//             double q4=(1.0*i/n)*(1-1.0*j/s)*(f[i][j+1]+1);
//             f[i][j]=((1.0*i/n)*(1.0*j/s)+q2+q3+q4)/(1-(1.0*i/n)*(1.0*j/s));
//         }
//     }
//     printf("%.4lf",f[0][0]);
//     return 0;
// }


// 换教室
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e3+5;
// const int M=1e6+5;

// double f[N][N][3];
// int c[N];
// int d[N];
// double k[N];
// int tot;
// int last[N];
// bool vis[N];

// double dist[N][N];
// // struct node{
// //     int v;
// //     int w;
// //     int next;
// // }a[M];
// // void add(int u,int v,int w)
// // {
// //     tot++;
// //     a[tot].v=v;
// //     a[tot].w=w;
// //     a[tot].next=last[u];
// //     last[u]=tot;
// // }
// // void spfa(int s)
// // {

// // }
// int main()
// {

//     int n,m,v,e;
//     scanf("%d%d%d%d",&n,&m,&v,&e);
//     for(int i=1;i<=v;i++)
//     {
//         for(int j=1;j<=v;j++)
//         {
//             dist[i][j]=1e9;
//             if(i==j)
//             {
//                 dist[i][j]=0;
//             }
//         }
//     }    
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&c[i]);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&d[i]);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lf",&k[i]);
//     }
//     int u,v1,w;
//     for(int i=1;i<=e;i++)
//     {
//         scanf("%d%d%d",&u,&v1,&w);
//         dist[u][v1]=dist[v1][u]=min(dist[u][v1],1.0*w);
//     }
//     for(int k=1;k<=v;k++)
//     {
//         for(int i=1;i<=v;i++)
//         {
//             for(int j=1;j<=v;j++)
//             {
//                 if(dist[i][k]+dist[k][j]<dist[i][j])
//                 {
//                     dist[i][j]=dist[i][k]+dist[k][j];
//                 }
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             f[i][j][0]=1e9;
//             f[i][j][1]=1e9;
//         }
//     }
//     f[1][0][0]=f[1][1][1]=0;
//     for(int i=2;i<=n;i++)
//     {
//         for(int j=0;j<=min(i,m);j++)
//         {
//             f[i][j][0]=min(f[i-1][j][0]+dist[c[i-1]][c[i]],f[i-1][j][1]+dist[d[i-1]][c[i]]*k[i-1]+dist[c[i-1]][c[i]]*(1-k[i-1]));
//             if(j>0)
//             {
//                 f[i][j][1]=min(f[i-1][j-1][0]+dist[c[i-1]][d[i]]*k[i]+dist[c[i-1]][c[i]]*(1-k[i]),f[i-1][j-1][1]+dist[c[i-1]][c[i]]*(1-k[i-1])*(1-k[i])+dist[c[i-1]][d[i]]*(1-k[i-1])*(k[i])+dist[d[i-1]][c[i]]*(k[i-1])*(1-k[i])+dist[d[i-1]][d[i]]*(k[i-1])*(k[i]));                                    
//             }                                  
//         }
//     }
//     double minn=1e9;
//     for(int i=0;i<=m;i++)
//     {
//         minn=min(minn,f[n][i][0]);
//         minn=min(minn,f[n][i][1]);
        
//     }
//     printf("%.2lf",minn);

//     return 0;
// }



// 绿豆蛙的归宿
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// // double f[N][N];
// int dout[N];
// int din[N];

// int tot;
// int last[N];
// bool vis[N];
// double dist[N];
// double p1[N];
// double p2[N];

// struct node{
//     int v;
//     int w;
//     int next;
// }a[N];
// void add(int u,int v,int w)
// {
//     tot++;
//     a[tot].v=v;
//     a[tot].w=w;
//     a[tot].next=last[u];
//     last[u]=tot;
// }
// void topu(int s)
// {
    
//     queue<int> q;
//     q.push(s);
//     vis[s]=true;
//     dist[s]=0;
//     while(!q.empty())
//     {
//         int u,v,w;
//         u=q.front();

//         q.pop();
//         for(int i=last[u];i>0;i=a[i].next)
//         {
            
//             v=a[i].v;
//             w=a[i].w;
//             din[v]--;
//             p2[v]+=1.0*p2[u]*p1[u];
//             dist[v]+=1.0*dist[u]*p1[u]+1.0*w*p2[u]*p1[u];
//             // printf("%d: %lf,%lf,%d,%lf,%d\n",v,p2[u],dist[v],din[v],p1[u],w);
//             if(din[v]==0)
//             {
//                 q.push(v);
//             }
//         }
//     }
// }
// int main()
// {
//     memset(dout,0,sizeof(dout));
//     memset(p2,0,sizeof(p2));
//     memset(din,0,sizeof(din));
//     memset(last,0,sizeof(last));
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         dist[i]=0;
//     }
//     p2[1]=1;
//     int u,v,w;
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&u,&v,&w);
//         add(u,v,w);

//         dout[u]++;
//         din[v]++;
//     }
//     for(int i=1;i<n;i++)
//     {
//         p1[i]=1.0*1/dout[i];
//     }
//     topu(1);
//     printf("%.2lf",dist[n]);
    
//     return 0;

// }


// 奖励关
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e2+5;
// const int M=(1<<15)+5;
// int p[M];
// int pre[M];


// int tpx[N];
// int cnt=0;

// double f[N][M];
// int main()
// {
//     memset(pre,0,sizeof(pre));
//     memset(f,0,sizeof(f));
//     int k,n;
//     scanf("%d%d",&k,&n);
//     int u,v;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&p[i]);
//         while(1)
//         {
//             scanf("%d",&u);
//             if(u==0)
//             {
//                 break;
//             }
//             pre[i]=pre[i]|(1<<(u-1));
//         }
//     }
//     for(int i=k;i>=1;i--)
//     {
//         for(int j=0;j<=(1<<n);j++)
//         {
//             for(int kk=1;kk<=n;kk++)
//             {
//                 if((pre[kk]&j)!=pre[kk])
//                 {
//                     f[i][j]+=f[i+1][j];
//                 }
//                 else
//                 {
//                     f[i][j]+=max(f[i+1][j],f[i+1][j|(1<<(kk-1))]+p[kk]);
//                 }
//             }
//             f[i][j]/=n;

//         }
//     }
//     printf("%.6lf\n",f[1][0]);
//     return 0;
// }


// 阶乘 乘法逆元 快速幂 牛客河南萌新（二）方案数
// #include<bits/stdc++.h>
// using namespace std;
// const int mod=1e9+7;
// const int N=1e3+5;
// using LL=long long;
// LL f[N];
// LL g[N];

// LL qpow(LL a,LL b)
// {
//     LL ans=1;
//     LL p;
//     while(b)
//     {
//         if(b&1)
//         {
//             ans=ans*a%mod;
//         }
//         a=a*a%mod;
//         b=b>>1;
//     }
//     return ans;
// }
// void init()
// {
//     f[0]=g[0]=1;
//     for(int i=1;i<=N;i++)
//     {
//         f[i]=f[i-1]*i%mod;
//         g[i]=g[i-1]*qpow (i,mod-2)%mod;
//     }
// }
// LL getc(LL n,LL m)
// {
//     return f[n]*g[n-m]%mod*g[m]%mod;
// }

// int main()
// {
//     init();

//     int n,k,m;
//     cin>>n>>k>>m;
//     LL p1=getc(n,k);
//     LL p2=qpow(m,k);
//     LL ans=(p1*p2)%mod;
//     printf("%lld",ans);
//     return 0;
// }


// 分解质因数
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e12;
// int a[N];
// void decompose(int x)
// {
//     for(int i=2;i*i<=x;i++)
//     {
//         while(x%i==0)
//         {
//             a[i]++;
//             x=x/i;
//         }
//     }
//     a[x]++;
// }
// int main()
// {
//     return 0;
// }



// 组合数  非线性求组合数，用于模非质数
// vector<vector<LL>> cul(M,vector<LL>(M,0));

// void init()
// {
    
//     cul[0][0]=1;

//     for(int i=1;i<=5e3;i++)
//     {
//         cul[i][0]=1;

//         for(int j=1;j<=i;j++)
//         {
//             cul[i][j]=(cul[i-1][j-1]+cul[i-1][j])%mod;
//         }
//     }
// }