// 方案数
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


// 连续合规子串
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// char s[N];
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     scanf("%s",s+1);
//     int maxn=0;
//     int p=0;
//     int len=0;
//     if(n==1)
//     {
//         maxn=1;
//     }
//     else if(n==2)
//     {
//         if(s[1]!=s[2])
//         {
//             maxn=2;
//         }
//         else
//         {
//             maxn=1;
//         }
//     }
//     else
//     {
//         while(p<n)
//         {
//             p++;
//             if(s[p]==s[p-1]&&p>=2)
//             {
//                 len=0;
//             }
//             if(s[p]==s[p-2]&&p>=3)
//             {
//                 len=0;
//             }
//             len++;
//             maxn=max(maxn,len);
//             // printf("{%d %d %d}\n",p,len,maxn);
//         }        
//     }

//     printf("%d",maxn);
//     return 0;
// }


// 魔法音符
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// int a[N];
// int b[N];
// int c[N];

// int main()
// {
    
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     int lmax=0;
//     int rmax=0;

//     for(int i=1;i<=n;i++)
//     {
//         b[i]=lmax;
//         lmax=max(lmax,a[i]);
//     }
//     for(int i=n;i>=1;i--)
//     {
//         c[i]=rmax;
//         rmax=max(rmax,a[i]);
//     }
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         int minn=min(b[i],c[i]);

//         if(minn>a[i])
//         {
//             ans+=minn-a[i];
//         }
//     }
//     printf("%lld",ans);
//     return 0;
// }


// 上海保卫战
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// bool isprime(LL x)
// {
//     int y=0;
//     for(int i=2;1ll*i*i<=x;i++)
//     {
//         if(x%i==0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int decompose(LL x)
// {
//     for(int i=2;1ll*i*i<=x;i++)
//     {
//         if(x%i==0)
//         {
//             if(isprime(i))
//             {
//                 return i;

//             }
//         }
//     }
//     return 1;

// }

// int main()
// {
//     LL n;
//     scanf("%lld",&n);
//     bool tag=isprime(n);
//     LL x=0;
//     LL y=0;

//     if(tag)
//     {
//         y=2;
//     }
//     else
//     {
//         if(n%2==0)
//         {
//             y=n/2+1;
//         }
//         else
//         {
//             x=decompose(n);
//             n-=x;
//             y=n/2+2;

//         }
//     }
//     printf("%lld",y);
//     return 0;

// }


// 星际争霸
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// using LL=long long;

// int a[N];
// struct node{
//     int d;
//     int g;
// }ys[N];
// LL sum[N];

// bool cmp(node x,node y)
// {
//     return x.d<y.d;
// }
// int main()
// {
//     int s;
//     int b;
//     scanf("%d%d",&s,&b);
//     for(int i=1;i<=s;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     for(int i=1;i<=b;i++)
//     {
//         scanf("%d%d",&ys[i].d,&ys[i].g);
//     }  
//     sort(ys+1,ys+1+b,cmp);
//     sum[0]=0;

//     for(int i=1;i<=b;i++)
//     {
//         sum[i]=sum[i-1]+ys[i].g;

//     }
//     for(int i=1;i<=s;i++)
//     {
//         int lt=1;
//         int rt=b;
//         while(lt<=rt)
//         {
//             int mid=(lt+rt)/2;
//             if(a[i]>=ys[mid].d)
//             {
//                 lt=mid+1;
//             }
//             else
//             {
//                 rt=mid-1;

//             }
//         }
//         printf("%lld ",sum[lt-1]);
//     }
    
//     return 0;
// }


// 检讨
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// const int M=1e5;
// LL a[N];
// LL sum[N];

// void solve()
// {
//     memset(sum,0,sizeof(sum));
//     int n,l;
//     cin>>n>>l;    
//     LL ax;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>ax;
//         a[i]=ax*M;
//     }
//     LL lt=-1e9;
//     LL rt=1e9;
//     while(lt<=rt)
//     {
//         int tag=0;
//         LL mid=(lt+rt)>>1;
//         sum[0]=0;
//         LL minn=1e18;
//         for(int i=1;i<=n;i++)
//         {
//             sum[i]=sum[i-1]+a[i]-mid;
//             if(i>=l)
//             {
//                 minn=min(minn,sum[i-l]);
//             }
//             if(sum[i]>=minn)
//             {
//                 tag=1;
//             }
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
//     double ans=1.0*(lt-1)/M;
//     printf("%lf\n",ans);

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();

//     }

//     return 0;
// }


// 神魔大战
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// int a[N];
// int b[N];
// int d[N];
// int w[N];

// int dp[N];
// int g[N];

// void solve()
// {
//     int n;
//     cin>>n;    
//     int sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cin>>b[i];

//     }    
//     int maxn=0;
//     int minn=0;
//     for(int i=1;i<=n;i++)
//     {
//         maxn+=a[i];
//         minn-=b[i];
//         d[i]=a[i]-b[i];
//         w[i]=a[i];

//     }
//     memset(dp,-0x3f,sizeof(dp));
//     dp[-minn]=0;
//     for(int i=1;i<=n;i++)
//     {
//         memcpy(g,dp,sizeof(dp));
//         printf("%d:\n",i);
//         for(int k=minn;k<=maxn;k++)
//         {
//             printf("{%d} ",dp[k-minn]);
//         }
//         printf("\n");        
//         for(int j=minn;j<=maxn;j++)
//         {
//             if(j-d[i]-minn>=0)
//             {
//                 dp[j-minn]=max(g[j-minn],g[j-d[i]-minn]+w[i]);
//             }
//             else
//             {
//                 dp[j-minn]=g[j-minn];
//             }


//         }

//     }
//     printf("%d",dp[-minn]);

// }
// int main()
// {
//     solve();
//     return 0;
// }


// 木桶效应
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];

// int main()
// {
//     LL n,m,k,h;
//     cin>>n>>m>>k>>h;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     sort(a+1,a+n+1);
//     LL lt=0;
//     LL rt=1e18;
//     while(lt<=rt)
//     {
//         int tag=1;
//         LL mm=m;
//         LL kk=k;
//         LL mid=(rt+lt)>>1;
//         for(int i=1;i<=n;i++)
//         {
//             LL aa=a[i];
//             if(aa<mid)
//             {
//                 if(kk>0)
//                 {
//                     aa+=h;
//                     kk--;
//                 }
//             }
//             if(aa<mid)
//             {
//                 int d=mid-aa;
//                 if(mm>=d)
//                 {
//                     mm-=d;
//                     aa+=d;  
//                 }
//                 else
//                 {
//                     aa+=mm;
//                     mm=0;
//                 }                            
//             }
    
//             if(aa<mid)
//             {
//                 tag=0;
//             }             
//         }
//         // printf("{%lld,%lld,%lld}\n",lt,rt,mid);
//         if(tag)
//         {
//             lt=mid+1;
//         }
//         else
//         {
//             rt=mid-1;
//         }
//     }
//     printf("%lld",lt-1);
//     return 0;
// }



// 完美序列
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// int a[N];
// int cnt[N];
// int ans[N];
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));
//     int n;
//     cin>>n;

//     int minn=1e9;
//     int maxn=0;

//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         maxn=max(maxn,a[i]);
//         minn=min(minn,a[i]);
//         cnt[a[i]]++;
//     }
//     // if(n<=3)
//     // {
//     //     printf("0");
//     //     return;
//     // }    
//     for(int i=minn*2;i<=maxn*2;i++)
//     {
//         for(int j=minn;j<=maxn;j++)
//         {
//             if(i-j==j)
//             {
//                 ans[i]=ans[i]+cnt[j]/2*2;
//                 // printf("{%d %d}",i,j);
//             }
//             else
//             {
//                 ans[i]+=min(cnt[j],cnt[i-j]);
//                 // printf("(%d %d %d %d %d)",i,j,cnt[j],cnt[i-j],ans[i]);
//                 // cnt[j]=min(cnt[j]--,0);
//                 // cnt[i-j]=min(cnt[i-j]--,0);

//             }
            
//         }
//     }
//     int ans0=0;
//     for(int i=0;i<=2*maxn;i++)
//     {
//         // printf("%d,",ans[i]);
//         ans0=max(ans0,ans[i]);
//     }
//     printf("%d",ans0);    
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 封闭运算
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// int a[N];

// void solve()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i;j<=n;j++)
//         {
//             int tag=0;
//             for(int k=1;k<=n;k++)
//             {
//                 if((a[i]|a[j])==a[k])
//                 {
//                     tag=1;
//                     // printf("{%d %d %d}",i,j,k);
//                 }
//             }
//             if(tag==0)
//             {
//                 // printf("%d %d,",i,j);
//                 printf("NO");
//                 return;
//             }
//         }
//     }
//     printf("YES");
//     return;
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 合并石子
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;


// LL a[N];
// LL lt[N];
// LL rt[N];

// void solve()
// {
//     int n,k;
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     lt[1]=0;
//     rt[n]=0;
//     LL s=a[1];
//     for(int i=2;i<=n;i++)
//     {
//         lt[i]=lt[i-1]+(s-1)/k+1;
//         s+=a[i];
//         // printf("%d ",lt[i]);
//     }
//     s=a[n];
//     for(int i=n-1;i>=1;i--)
//     {
//         rt[i]=rt[i+1]+(s-1)/k+1;
//         s+=a[i];
//         // printf("%d ",rt[i]);
//     }    
//     LL ans=1e18;
//     for(int i=1;i<=n;i++)
//     {
//         ans=min(ans,rt[i]+lt[i]);
//     }
//     printf("%lld",ans);
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 故障机器人的完美牌组
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e6+5;
// using LL=long long;
// LL a[N];
// bool vis[N];
// LL prim[N];
// LL cnt;

// void get_prim(int n)
// {
//     vis[1]=1;
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
// LL con(LL x)
// {
//     if(x==1)
//     {
//         return 1;

//     }
//     LL c=1;
//     for(int i=1;i<=cnt;i++)
//     {
//         LL p=prim[i];
//         if(p*p>x)
//         {
//             break;
//         }
//         if(x%p==0)
//         {
//             LL d=0;
//             while(x%p==0)
//             {
//                 x/=p;
//                 d++;

//             }
//             c*=(2*d+1);

//         }
//     }
//     if(x>1)
//     {
//         c*=3;

//     }
//     return c;
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));
//     cnt=0;
//     int n;
//     cin>>n;    
//     get_prim(N);
//     LL sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         LL x=a[i];
//         LL ii=sqrt(x);
//         if(ii*ii!=x)
//         {
//             continue;
//         }
//         LL f=con(ii);
//         if(vis[f]==false&&f>2)
//         {
//             sum+=x;
//         }
//     }
//     printf("%lld",sum);
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 故障机器人的完美牌组
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// LL a[N];
// void solve()
// {
//     int n;
//     cin>>n;

//     LL maxn=0;
//     int maxnp=N+10;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         if(i>=2)
//         {
//             if(a[i]>=maxn)
//             {
//                 maxn=a[i];
//                 maxnp=i;
//             }
//         }
//     }
//     if(n==1)
//     {
//         printf("1\n%lld",a[1]);
//         return;
//     }    

//     a[1]+=maxn;
//     if(maxn==0)
//     {
//         printf("%d\n",n);
//     }
//     else
//     {
//         printf("%d\n",n-1);
//     }    
    
    
//     for(int i=1;i<=n;i++)
//     {
//         if(i==maxnp&&maxn>=1)
//         {
//             continue;
//         }
//         printf("%lld ",a[i]);
//     }    
// }
// int main()
// {
//     solve();
//     return 0;
// }



// 箭头谜题Ⅰ(错)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// #define mp make_pair

// const int INF=0x3f3f3f3f;
// struct node{
//     int v;
//     LL w;
//     int next;
// }a[N];
// bool vis[N];
// int last[N];
// int tot;
// LL dist[N];
// char str[N];

// void add(int u,int v,LL w)
// {
//     tot++;
//     a[tot]={v,w,last[u]};
//     last[u]=tot;
// }

// void dijkstra(int s)
// {
//     // memset(dist,0x3f,sizeof(dist));
//     for(int i=1;i<=N;i++)
//     {
//         dist[i]=1e18;
//     }
//     memset(vis,false,sizeof(vis));
//     priority_queue<pair<LL,int>> q;
//     dist[s]=0;
//     vis[s]=true;
//     q.push(mp(dist[s],s));
//     int u,v,w;
//     while(!q.empty())
//     {
//         u=q.top().second;
//         // printf("{%d}",u);
//         q.pop();
//         vis[u]=false;
//         for(int i=last[u];i>=1;i=a[i].next)
//         {
//             v=a[i].v;
//             w=a[i].w;
//             if(dist[u]+w<dist[v])
//             {
//                 dist[v]=dist[u]+w;
//                 if(vis[v]==false)
//                 {
//                     q.push(mp(-dist[v],v));
//                     vis[v]=true;
//                 }
//             }
//         }
//     }
// }
// void solve()
// {
//     int n,m;
//     LL k;
//     int u,v;
//     LL w;
//     tot=0;
//     memset(a,0,sizeof(a));
//     memset(last,0,sizeof(last));
//     scanf("%d%d%d",&n,&m,&k);

//     for(int i=1;i<=n;i++)
//     {
//         getchar();
//         scanf("%s",str+1);
//         for(int j=1;j<=m;j++)
//         {
//             u=(i-1)*m+j;
//             for(int ij=0;ij<4;ij++)
//             {
//                 if(ij==0)
//                 {
//                     v=u-m;
//                     if(v<1||v>n*m)
//                     {
//                         continue;
//                     }
//                     if(str[m]=='U')
//                     {
//                         w=0;
//                     }
//                     else
//                     {
//                         w=1;
//                     }
//                     add(u,v,w);
//                     // printf("(%d %d %d)",u,v,ij);
//                 }
//                 else if(ij==1)
//                 {
//                     v=u+m;
//                     if(v<1||v>n*m)
//                     {
//                         continue;
//                     }
//                     if(str[m]=='D')
//                     {
//                         w=0;
//                     }
//                     else
//                     {
//                         w=1;
//                     }
//                     add(u,v,w);
//                     // printf("(%d %d %d)",u,v,ij);
//                 }
//                 else if(ij==2)
//                 {
//                     v=u-1;
//                     if(v<1||v>m*n)
//                     {
//                         continue;
//                     }   
//                     if(str[m]=='L')
//                     {
//                         w=0;
//                     }
//                     else
//                     {
//                         w=1;
//                     }     
//                     add(u,v,w);    
//                     // printf("(%d %d %d)",u,v,ij);      
//                 }
//                 else if(ij==3)
//                 {
//                     v=u+1;
//                     if(v<1||v>m*n)
//                     {
//                         continue;
//                     }
//                     if(str[m]=='R')
//                     {
//                         w=0;
//                     }
//                     else
//                     {
//                         w=1;
//                     }
//                     add(u,v,w);
//                     // printf("(%d %d %d)",u,v,ij);
//                 }

//             }
//         }
//     }
//     dijkstra(1);
//     // for(int i=1;i<=n*m;i++)
//     // {
//     //     printf("%d ",dist[i]);
//     // }
//     // printf("%d ",dist[n*m]);
//     if(dist[n*m]<=k)
//     {
//         printf("YES\n");
//     }
// }
// int main()
// {

//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// 箭头谜题Ⅰ
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair
// const int N=1e6+5;
// int dx[]={0,1,-1,0};
// int dy[]={-1,0,0,1};
// string f="LDUR";
// void solve()
// {
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<string> str(N);
//     vector<vector<bool>> vis(n,vector<bool>(m,false));
//     vector<vector<int>> dist(n,vector<int>(m,1e9));
//     deque<pair<int,int>> q;
//     for(int i=0;i<n;i++)
//     {
//         cin>>str[i];
//     }
//     q.push_front(mp(0,0));
//     dist[0][0]=0;
//     int x,y;
//     int x1,y1;
//     while(!q.empty())
//     {
//         x=q.front().first;
//         y=q.front().second;
//         q.pop_front();
//         if(vis[x][y])
//         {
//             continue;
//         }
//         // printf("{%d %d}",x,y);
//         vis[x][y]=true;
        
//         for(int i=0;i<4;i++)
//         {
//             int w=1;
//             x1=x+dx[i];
//             y1=y+dy[i];
//             if(x1<0||y1<0||x1>=n||y1>=m)
//             {
//                 continue;
//             }
//             if(str[x][y]==f[i])
//             {
//                 w=0;
//             }
//             if(dist[x][y]+w<dist[x1][y1])
//             {
//                 dist[x1][y1]=dist[x][y]+w;
//                 if(w==0)
//                 {
//                     q.push_front(mp(x1,y1));
//                 }
//                 else if(w==1)
//                 {
//                     q.push_back(mp(x1,y1));
//                 }
//             }
//         }
//     }
//     if(dist[n-1][m-1]<=k)
//     {
//         cout<<"YES"<<'\n';
//     }
//     else
//     {
//         cout<<"NO"<<'\n';
//     }
    
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// Minecraft
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];
// LL mid;
// vector<int> e[N];
// int din[N];
// int cpy[N];
// bool vis[N];

// bool topu(int s)
// {
//     vector<LL> need(N);
//     queue<int> q;
//     q.push(s);
//     vis[s]=true;
//     need[s]=mid;
//     int x;
//     while(!q.empty())
//     {
//         x=q.front();
//         q.pop();
//         vis[x]=false;
//         if(e[x].empty()&&need[x]>a[x])
//         {
//             return false;
//         }
//         // printf("[%d]",x);
//         for(auto y:e[x])
//         {
//             cpy[y]--;
//             if(need[x]-a[x]>0)
//             {
//                 need[y]=need[y]+(need[x]-a[x]);
//             }
//             if(cpy[y]==0)
//             {
//                 q.push(y);
//                 vis[y]=true;
//             }
//             if(need[y]>1e16||need[y]<0)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// void solve()
// {
//     memset(din,0,sizeof(din));
//     memset(vis,false,sizeof(vis));
//     int n,m,u,v,k;
//     int x;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     for(int i=1;i<=m;i++)
//     {
//         cin>>u>>k;
//         for(int j=1;j<=k;j++)
//         {
//             cin>>v;
//             // printf("<%d,%d>",u,v);
//             e[u].push_back(v);
//             din[v]++;
//         }
//     }
//     int s=1;
//     LL lt=0;
//     LL rt=1e15;
//     while(lt<=rt)
//     {
//         memcpy(cpy,din,sizeof(din));
//         mid=(lt+rt)>>1;
//         // printf("{%lld %lld %lld}\n",lt,rt,mid);
//         if(topu(s))
//         {
//             lt=mid+1;
//         }
//         else
//         {
//             rt=mid-1;
//         }
        
//     }

//     cout<<lt-1<<'\n';
//     // for(int i=0;i<e[3].size();i++)
//     // {
//     //     printf("%d,",e[3][i]);
//     // }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%d,",din[i]);
//     // }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// 杀戮尖塔第四厉害高手（未完）
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// int a[N];
// int b[N];
// vector<int> e[N];
// int dist[N][5];
// void solve()
// {
//     int n,m,k;
//     cin>>n>>m>>k;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i]>>b[i];
//     }
//     int u,v;

//     for(int i=1;i<=m;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//     }
//     int b[10][10];
// }
// int main()
// {
//     solve();
//     return 0;
// }


// Icon Design
// #include<bits/stdc++.h>
// using namespace std;
// const int N=505;
// using LL=long long;
// int mp[N][N];

// void solve()
// {
//     memset(mp,0,sizeof(mp));
//     int n;
//     cin>>n;

//     for(int i=1;i<=13*n+19;i++)
//     {
//         mp[1][i]=1;
//         mp[4*n+5][i]=1;
//     }
//     for(int i=1;i<=4*n+5;i++)
//     {
//         mp[i][1]=1;
//         mp[i][13*n+19]=1;
//     }
//     for(int i=2+n;i<=2*n+4+n;i++)
//     {
//         mp[i][1+n+2]=2;
//     }
//     for(int i=2+n;i<=2*n+4+n;i++)
//     {
//         mp[i][n+2+2*n+3]=2;
//     }    
//     for(int i=2+n;i<=2*n+4+n;i++)
//     {
//         mp[i][n+2+2*n+3+n+2]=2;
//     }  
//     for(int i=2+n;i<=2*n+4+n;i++)
//     {
//         mp[i][n+2+2*n+3+n+2+n+1+2*n+3]=2;
//     }  
//     for(int i=2+n;i<=2+n+(2*n+3)/2;i++)
//     {
//         mp[i][n+2+2*n+3+n+2+n+1+2*n+3+n+1+2*n+3]=2;
//     }  
//     for(int i=2+n+(2*n+3)/2;i<=2+n+2*n+3-1;i++)
//     {
//         mp[i][n+2+2*n+3+n+2+n+1+2*n+3+n+1+2*n+3+2*n+3-1]=2;
//     }  
//     for(int i=1+n+1+2*n+3+n+1+1;i<=1+n+1+2*n+3+n+1+2*n+3;i++)
//     {
//         mp[1+n+1][i]=2;
//     }
//     for(int i=1+n+1+2*n+3+n+1+1;i<=1+n+1+2*n+3+n+1+2*n+3;i++)
//     {
//         mp[1+n+1+(2*n+3)/2][i]=2;
//     }
//     for(int i=1+n+1+2*n+3+n+1+1+n+1+2*n+3;i<=1+n+1+2*n+3+n+1+2*n+3+n+1+2*n+3;i++)
//     {
//         mp[1+n+1+2*n+3-1][i]=2;
//     } 
//     for(int i=1+n+1+2*n+3+n+1+1+2*(n+1)+2*(2*n+3);i<=1+n+1+2*n+3+n+1+1+2*(n+1)+2*(2*n+3)+2*n+3-1;i++)
//     {
//         mp[1+n+1][i]=2;
//     }
//     for(int i=1+n+1+2*n+3+n+1+1+2*(n+1)+2*(2*n+3);i<=1+n+1+2*n+3+n+1+1+2*(n+1)+2*(2*n+3)+2*n+3-1;i++)
//     {
//         mp[1+n+1+(2*n+3)/2][i]=2;
//     }
//     for(int i=1+n+1+2*n+3+n+1+1+2*(n+1)+2*(2*n+3);i<=1+n+1+2*n+3+n+1+1+2*(n+1)+2*(2*n+3)+2*n+3-1;i++)
//     {
//         mp[1+n+1+2*n+3-1][i]=2;
//     }
//     int x=1+n+1;
//     int y=1+n+1+1;
//     for(int i=0;i<=2*n+3-1;i++)
//     {
//         mp[x+i][y+i]=2;
//     }
//     for(int i=1;i<=4*n+5;i++)
//     {
//         for(int j=1;j<=13*n+19;j++)
//         {
//             if(mp[i][j]==0)
//             {
//                 printf(".");
//             }
//             else if(mp[i][j]==1)
//             {
//                 printf("*");
//             }
//             else if(mp[i][j]==2)
//             {
//                 printf("@");
//             }
//         }
//         printf("\n");
//     }
    
// }
// int main()
// {
//     solve();
//     return 0;
// }


// Number Game
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=100;
// void solve()
// {
//     vector<LL> num(N);
//     int tot=0;
//     LL a,b,c,k;
//     cin>>a>>b>>c>>k;
//     LL x=b;
//     LL y=a-b;
//     if(c==k)
//     {
//         cout<<"Yes"<<'\n';
//         return;
//     }
//     if(x==y)
//     {
//         if(b-c==k)
//         {
//             cout<<"Yes"<<'\n';
//             return;            
//         }
//     }
//     else
//     {
//         if((k-c)%(y-x)==0||(c+k-x)%(x-y)==0)
//         {
//             cout<<"Yes"<<'\n';
//             return;                  
//         }
//     }
//     cout<<"No"<<'\n';
//     return;
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// 打瓦
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     cout<<"gugugaga"<<'\n';
//     return 0;
// }


// 约数个数和
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5;
// using LL=long long;
// void solve()
// {
//     LL n;
//     cin>>n;
//     LL ans=0;
//     LL l,r,k;
//     l=0;

//     for(int i=1;i<=n;i++)
//     {
//         k=n/i;
//         r=n/k;
//         ans+=(r-l)*k;
//         i=r;
//         l=r;
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// 米娅逃离断头台
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// using LL=long long;
// const double pi=3.1415926535;
// void solve()
// {

//     double n;
//     cin>>n;
//     double ans=1.0*pi*n*n/8;
    
//     printf("%.2lf",ans);

// }
// int main()
// {
//     solve();
//     return 0;
// }


// 开罗尔网络的备用连接方案
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using namespace std;
// int a[N];
// int cnt[N];
// bool vis[N];
// vector<int> e[N];
// void dfs(int f,int u)
// {
//     a[u]=a[f]&a[u];
//     int num=a[u];
//     int s=0;
//     while(num!=0)
//     {
//         if(num&1==1)
//         {
//             s++;
//         }
//         num=num>>1;
//     }
//     cnt[s]++;    
//     vis[u]=true;
//     for(auto v:e[u])
//     {
//         if(!vis[v])
//         {
//             dfs(u,v);
//         }
//     }
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));
//     memset(cnt,0,sizeof(cnt));
//     int n,q;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     int u,v;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);
//     }
//     dfs(1,1);
//     int qx;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>qx;

//         printf("%d\n",cnt[qx]);

//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 咕咕嘎嘎!!!(easy)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=4e7+5;
// using LL=long long;
// const int mod=1e9+7;

// int vis[N];
// int prim[N];
// int cnt;
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

// void get_prim(int n)
// {
//     cnt=0;
//     vis[1]=1;
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

// void solve()
// {
//     init();
//     memset(vis,false,sizeof(vis));
//     memset(prim,0,sizeof(prim));
//     LL n,m;
//     cin>>n>>m;
//     get_prim(n);

//     LL x,y;
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(vis[i]==0)
//         {
//             x=n/i;
//             if(x>=m)
//             {
//                 ans=(ans+getc(x,m))%mod;
//             }
//         }
//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("{%lld %lld}\n",f[i],g[i]);
//     // }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// Eezie and Pie
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e6+5;
// using LL=long long;
// vector<int> e[N];
// int f[N][50];
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
// int lca(int u,int dis)
// {
//     int t=dep[u]-dis;
//     for(int i=22;i>=0;i--)
//     {
//         if(t<=dep[f[u][i]])
//         {
//             u=f[u][i];
//         }
//         // if(dep[u])
//     }
//     // printf("{%d}",u);
//     return u;

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
//     cin>>n;
//     int x,y;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>x>>y;
//         e[x].push_back(y);
//         e[y].push_back(x);

//     }

//     dfs(1,1);
//     init(n);
//     int dist;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>dist;
//         x=i;
//         y=dist;
//         int lc=lca(x,y);
//         dx[x]++;
//         dx[lc]++;
//         dx[lc]--;
//         if(f[lc][0]!=lc)
//         {
//             dx[f[lc][0]]--;
//         }
        
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
//         // maxn=max(maxn,dx[i]);
//         cout<<dx[i]<<' ';
//     }
//     cout<<'\n';
    
// }
// int main()
// {
//     solve();
//     return 0;
// }



// ICPC Regionals
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// void solve()
// {
//     int n,k;
//     cin>>n>>k;
//     int a1=(n-1)/10+1;
//     int a2=a1*2;
//     int a3=a1*3;
//     if(k<=a1)
//     {
//         cout<<"Gold Medal"<<'\n';

//     }
//     else if(k<=a2+a1)
//     {
//         cout<<"Silver Medal"<<'\n';
//     }
//     else if(k<=a3+a2+a1)
//     {
//         cout<<"Bronze Medal"<<'\n';
//     }
//     else 
//     {
//         cout<<"Da Tie"<<'\n';
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// Card Game
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// int a[N];

// void solve()
// {
//     int n,k;
//     cin>>n;
//     int maxn=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         maxn=max(maxn,a[i]);
//     }
//     if(n-1>=maxn)
//     {
//         maxn=n;
//     }
//     cout<<maxn<<'\n';

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }


// Digital Pairing
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;
// LL a[N];
// void solve()
// {
//     int n,k;
//     cin>>n;
//     for(int i=1;i<=2*n;i++)
//     {
//         cin>>a[i];
//     }
//     LL ans=0;

//     for(int i=40;i>=0;i--)
//     {
//         LL c=ans|(1<<i);

//         int cnt=0;
//         for(int j=1;j<=2*n;j++)
//         {
//             if((a[j]&c)==c)
//             {
//                 cnt++;
//             }
//         }
//         if(cnt>=n)
//         {
//             ans=c;
//         }
        
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }



// Palindrome Coloring
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;
// char s[N];
// void solve()
// {
//     int n,k;
//     scanf("%s",s+1);
//     int s1=0;
//     int s2=0;
//     int len=strlen(s+1);
//     int lt=1;
//     int rt=len;
//     int tag=1;
//     while(lt<=rt)
//     {
//         if(s[lt]!=s[rt])
//         {
//             tag=0;
//             break;
//         }
//         lt++;
//         rt--;
//     }
//     if(tag)
//     {
//         cout<<'1'<<'\n';
//         return;
//     }
//     for(int i=1;i<=len;i++)
//     {
//         if(s[i]=='0')
//         {
//             s1++;
//         }
//         else
//         {
//             s2++;
//         }

//     }
//     if(s1==0||s2==0)
//     {
//         cout<<'1'<<'\n';
//     }
//     else
//     {
//         cout<<'2'<<'\n';
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// Beautiful Sequence
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;
// const LL mod=998244353;
// LL a[N];
// LL cnt[N];
// LL bcnt[N];

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

// void solve()
// {
//     memset(cnt,0,sizeof(cnt));
//     memset(bcnt,0,sizeof(bcnt));
//     LL n;
//     cin>>n;
//     LL ans=(qpow((LL)2,n)-1+mod)%mod;


//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         cnt[a[i]]++;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         LL cnt1=0;
//         for(int j=i;j<=n;j+=i)
//         {
//             cnt1+=cnt[j];
//         }
//         bcnt[i]+=cnt1;
//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("{%d}",bcnt[i]);
//     // }
//     for(int i=1;i<=n;i++)
//     {
//         ans=(ans+qpow((LL)2,bcnt[i]-cnt[i]))%mod-qpow((LL)2,bcnt[i])%mod;
//     }
//     cout<<ans<<'\n';

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// 小红取模
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int mod=9;
// void solve()
// {
//     int n;
//     cin>>n;
//     int x,y;
//     int ans=0;
//     while(n!=0)
//     {
//         x=n%10;
//         ans+=x;
//         n=n/10;
//     }
//     ans=ans%mod;
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// 小红的复数
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int mod=1000000007;
// const int N=2e5+5;

// LL a[N];
// LL b[N];
// void solve()
// {
//     int n;
//     cin>>n;
//     LL ai,bi;
//     LL x,y;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i]>>b[i];
//     }
//     x=a[1];
//     y=b[1];
//     for(int i=2;i<=n;i++)
//     {
//         LL xi=x;
//         LL yi=y;
//         ai=a[i];
//         bi=b[i];
//         x=((xi*ai)%mod-(yi*bi)%mod)%mod;
//         x=(x+mod)%mod;
//         y=((xi*bi)%mod+(yi*ai)%mod)%mod;
//         y=(y+mod)%mod;
//     }
    
    

//     cout<<x<<' '<<y<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 小红的k次方
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int mod=1000000007;
// const int N=2e5+5;
// int cnt[10];
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));

//     int n;
//     cin>>n;
//     LL a;
//     LL x,y,z;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a;
//         while(a%2==0)
//         {
//             a=a/2;
//             x++;
//         }
//         while(a%3==0)
//         {
//             a=a/3;
//             y++;
//         }
//         while(a%5==0)
//         {
//             a=a/5;
//             z++;
//         }
//     }
//     LL ans=min(x,min(y,z));
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



//小红模5
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int mod=1000000007;
// const int N=2e5+5;
// int cnt[10];
// int num[10];
// LL f[N];

// void init(int n)
// {
//     f[0]=1;
//     for(int i=1;i<=n;i++)
//     {
//         f[i]=f[i-1]*i%mod;
//     }
// }
// void solve()
// {
//     LL n;
//     cin>>n;
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         ans=ans+i%5;
//     }

//     init(n);
//     LL fx=(f[n-1]+mod)%mod;
//     ans=ans*fx;
//     ans=ans%mod;
//     cout<<ans<<'\n';

// }
// int main()
// {
//     solve();
//     return 0;
// } 


// 二小姐取数
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=505;
// LL dp[N][N];
// int a[N];
// int b[N];
// void solve()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cin>>b[i];
//     }
//     for(int i=1;i<=)
// }
// int main()
// {
//     solve();
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     vector<int> cnt(100);
//     int x;
//     for(int i=1;i<=6;i++)
//     {
//         cin>>x;
//         cnt[x]++;
//     }
//     for(int i=1;i<=6;i++)
//     {
//         cin>>x;
//         cnt[x]++;
//     }

//     int a,b;
//     cin>>a>>b;
//     if(cnt[b]<a)
//     {
//         cout<<"win"<<'\n';
//     }    
//     else
//     {
//         cout<<"lose"<<'\n';
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// max-mid
// #include<bits/stdc++.h>
// using namespace std;
// int a[1005];
// void solve()
// {
//     int n,k;
//     cin>>n>>k;
//     int s1=0;
//     int s2=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         if(a[i]==0)
//         {
//             s1++;
//         }
//         else
//         {
//             s2++;
//         }
//     }
//     int p=(k+1)/2;
//     if(s2>=k/2+1||s1>=k)
//     {
//         cout<<'0'<<'\n';
//     }
//     else
//     {
//         cout<<'1'<<'\n';
//     }

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// 糟糕的手法
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// LL a[1005];
// void solve()
// {
//     int n,m;
//     cin>>n>>m;
//     int cnt1=0;
//     int cnt2=0;
//     int cnt3=0;
    
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         if(a[i]==0)
//         {
//             cnt3++;
//         }
//         else if(a[i]>0)
//         {
//             cnt1++;
//         }
//         else if(a[i]<0)
//         {
//             cnt2++;
//         }
//     }

//     if(cnt1==m)
//     {
//         cout<<'0'<<'\n';
//     }
//     else if(cnt1>m)
//     {
//         if(cnt2>0||cnt3>0)
//         {
//             cout<<cnt1-m<<'\n';
//         }
//         else 
//         {
//             cout<<'0'<<'\n';
//         }
//     }
//     else
//     {
//         int d=m-cnt1;
//         int s=cnt2-1;
//             if(s>=d)
//             {
//                 cout<<d<<'\n';
//             }
//             else
//             {
//                 cout<<"-1"<<'\n';
//             }
//     }

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// x_to_y_2
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// LL a[1005];
// void solve()
// {
//     int n,m;
//     LL x,y;
//     cin>>x>>y;
//     LL z;
//     int cnt=0;
//     if(x==y)
//     {
//         cout<<'0'<<'\n';
//         return;
//     }

//     while(x!=0)
//     {
//         if(x^(x&y))
//         {
//             cnt++;
//             x=x>>1;
//         }
//         else
//         {
//             break;
//         }
//     }
//     if(x!=y)
//     {
//         cnt++;
//     }
//     cout<<cnt<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// AsubB
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// LL a[2005];
// void solve()
// {
//     int n,m;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cout<<'%';
//     }
//     cout<<'\n';
// }
// int main()
// {

//         solve();

//     return 0;
// }



// 运动世界校园
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// LL a[2005];
// void solve()
// {
//     int n,m;
//     double p;

//     cin>>p;
//     double ans=p;
//     ans=p+(1-p)*p+(1-p)*(1-p)*p;
//     printf("%lf",ans);
// }
// int main()
// {

//         solve();

//     return 0;
// }


// 翻转硬币
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// char a[10000];
// void solve()
// {
//     int n,m;
//     scanf("%s",a+1);
//     int len=strlen(a+1);
//     int s0=0;
//     int s1=0;
//     for(int i=1;i<=len;i++)
//     {
//         if(a[i]=='0')
//         {
//             s0++;
//         }
//     }
//     if(s0%2==0)
//     {
//         printf("Yes\n");
//     }
//     else
//     {
//         printf("No\n");
//     }
// }
// int main()
// {

//         solve();

//     return 0;
// }


// 我不吃水果
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e3+5;
// int a[N][N];
// void solve()
// {
//     int n,m;
//     cin>>n;
//     int tag=1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin>>a[i][j];
//             if(a[i][j]==1)
//             {
//                 tag=0;
//             }
//         }
//     }
//     if(tag==1)
//     {
//         cout<<n*n<<'\n';
//         return;
//     }
//     int x,y;
//     int tag1=1;
//     int tag2=1;
//     int ans=0;
//     int mx=n;
//     int my=n;
//     for(int i=1;i<=mx;i++)
//     {
//         for(int j=1;j<=my;j++)
//         {
//             if(a[i][j]==1)
//             {
//                 x=i;
//                 y=j;
//                 my=j-1;
//                 int ans1=(x-1)*y;
//                 int ans2=(y-1)*x;
                
//                 ans=max(ans,max(ans2,ans1));
//                 // printf("{%d,%d,%d}",x,y,ans);
//                 break;
//             }
//             if(j==my)
//             {
//                 ans=max(ans,i*j);
//             }
//         }
//         if(i==n)
//         {
//             ans=max(ans,i*my);
//         }
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {

//         solve();

//     return 0;
// }



// 字符消消乐
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// char s[N];
// int a[N];
// int cnt[1000];
// bool cmp(int x,int y)
// {
//     return x>y;
// }
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));
//     int n,k;
//     cin>>n>>k;

//     scanf("%s",s+1);
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=s[i];
//         cnt[a[i]]++;
//     }
//     // sort(a+1,a+1+n);
//     int d=0;
//     sort(cnt+1,cnt+1000,cmp);
//     for(int i=1;i<=k;i++)
//     {
//         if(cnt[i]>=3)
//         {
//             d+=cnt[i];
//         }
//         else if(cnt[i]<3)
//         {
//             break;
//         }
//     }
//     int len=n;
//     len=len-d;
//     printf("%d",len);
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%d,",a[i]);
//     // }    
    
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 新田忌赛马
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=5e5+5;
// using LL=long long;
// LL a[N];
// LL b[N];

// bool cmp(LL x,LL y)
// {
//     return x>y;
// }
// void solve()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%lld",&a[i]);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%lld",&b[i]);
//     }
//     sort(a+1,a+n+1,cmp);
    
//     LL ans=0;
//     // if(n>=m)
//     // {
//     //     int p1,p2;
//     //     p1=1;
//     //     p2=1;
//     //     LL s=0;   
//     //     int l1=n;     
//     //     while(p1<=l1&&p2<=m)
//     //     {
//     //         if(a[p1]>b[p2])
//     //         {

//     //             s+=b[p2];
//     //             // printf("{%d,%d}",s,p2);
//     //             p1++;
//     //             p2++;            
//     //         }
//     //         else
//     //         {
//     //             l1--;
//     //             p2++;
//     //         }

//     //     }        
//     //     ans=s;     
//     // }
//     // else
//     // {
//     //     for(int i=0;i+n<=m;i++)
//     //     {
//     //         int p1,p2;
//     //         p1=1;
//     //         p2=1+i;
//     //         LL s=0;        
//     //         int l1=n;
//     //         while(p1<=l1&&p2<=m)
//     //         {
//     //             if(a[p1]>b[p2])
//     //             {

//     //                 s+=b[p2];
//     //                 // printf("{%d,%d}",s,p2);
//     //                 p1++;
//     //                 p2++;            
//     //             }
//     //             else
//     //             {
//     //                 l1--;
//     //                 p2++;
//     //             }

//     //         }   
//     //         ans=max(ans,s);
//     //     }

//     // }

//     int p1,p2;
//     p1=1;
//     p2=1;
//     LL s=0;   
//     int l1=n;     
//     while(p1<=l1&&p2<=m)
//     {
//         if(a[p1]>b[p2])
//         {

//             s+=b[p2];
//             // printf("{%d,%d}",s,p2);
//             p1++;
//             p2++;            
//         }
//         else
//         {
//             while(a[p1]<=b[p2])
//             {
//                 p2++;
//             }
            
            
//         }

//     }        
//     ans=s;   
//     printf("%lld",ans);
// }
// int main()
// {
//     solve();
//     return 0;
// }



// 逃出生天
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// #define mp make_pair
// const int N=1e3+5;
// LL a[N][N];
// LL b[N];
// int dx[]={-1,1,0,0};
// int dy[]={0,0,-1,1};
// int n,m;
// bool vis[N][N];
// bool ans;
// void dfs(int x,int y)
// {
//     vis[x][y]=true;
//     if(x==n+2&&y==1)
//     {
//         ans=true;
//         return;
//     }    
//     int x1,y1;

//     for(int i=0;i<4;i++)
//     {
//         x1=x+dx[i];
//         y1=y+dy[i];
//         if(vis[x1][y1])
//         {
//             continue;
//         }
//         if(x1<1||x1>n+2||y1<1||y1>m)
//         {
//             continue;
//         }
//         if(a[x1][y1])
//         {
//             continue;
//         }
//         dfs(x1,y1);
//     }    

// }

// void solve()
// {
//     ans=false;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         int c;
//         char d;
//         cin>>c>>d;
//         if(d=='L')
//         {
//             for(int j=1;j<=c;j++)
//             {
//                 a[i+1][j]=1;
//             }
//         }
//         else if(d=='R')
//         {
//             for(int j=c;j<=m;j++)
//             {
//                 a[i+1][j]=1;
//             }            
//         }

//     }
//     dfs(1,m);
//     if(ans)
//     {
//         cout<<"YES"<<'\n';
//     }
//     else
//     {
//         cout<<"NO"<<'\n';
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// 最不上升也不下降序列
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// #define mp make_pair
// const int N=4e6+5;
// int a[N];
// void solve()
// {
//     int n;
//     cin>>n;
//     if(n==1)
//     {
//         cout<<'1'<<'\n';
//         return;
//     }
//     if(n==2)
//     {
//         cout<<"1 2"<<'\n';
//         return;
//     } 
//     if(n==3)
//     {
//         cout<<"1 2 3"<<'\n';
//         return;
//     }   
    
    
//     int yu;
//     int minn=10000;
//     int minl=1e9;
//     int mini=1e9;
//     int minyu=1e9;
//     for(int i=1;i<=n;i++)
//     {
//         int len=n/i;
//         int l=len;
//         yu=n%i;
//         if(yu!=0)
//         {
//             l++;
//         }
//         if(l+i<minn)
//         {
//             minn=i+l;
//             mini=i;
//             minl=l;
//             minyu=yu;
//         }
//     }    
    
//     int tot=0;
//     if(minyu!=0)
//     {
//         minl=minl-1;
//     }
//     int num=0;
//     for(int j=1;j<=minl;j++)
//     {
//         num=mini*j;
//         for(int k=0;k<=mini-1;k++)
//         {
//             tot++;
//             a[tot]=mini*j-k;
            
//         }
//     }
//     // cout<<num<<'\n';
//     stack<int> st;
//     for(int i=1;i<=mini;i++)
//     { 
//         num++;
//         st.push(num);
       
//     }
//     while(st.size()!=minyu)
//     {
//         // printf("<%d>",st.top());
//         st.pop();
//     }
//     tot++;
//     for(;tot<=n;tot++)
//     {
//         a[tot]=st.top();
//         st.pop();

//     }    
//     for(int i=1;i<=n;i++)
//     {
//         cout<<a[i]<<' ';
//     }
//     cout<<'\n';
//     // cout<<mini<<' '<<minl<<'\n';

// }
// int main()
// {
//     solve();
//     return 0;
// }



// 雪莉的预言
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const LL N=2e7+5;
// LL a[N];
// struct node{
//     LL s;
//     LL num;
// }cnt[N],cnt1[N];
// LL seed;
// LL read() {
//     seed = (seed * 13331 + 23333) % 1000000007;
//     return seed;
// }
// bool cmp(LL a,LL b)
// {
//     return a>b;
// }
// bool cmp1(node a,node b)
// {
//     return a.s>b.s;
// }
// set<LL> e[N];
// LL sum[N];
// void solve()
// {
//     memset(sum,0,sizeof(sum));
//     memset(cnt,0,sizeof(cnt));
//     LL m,n,q,b,k;
//     cin>>seed>>k>>n>>m>>q>>b;
//     for(int i=0;i<=m+5;i++)
//     {
//         cnt[i].num=i;
//         cnt[i].s=0;
//         cnt1[i].num=i;
//         cnt1[i].s=0;        
//     }
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=read()%m;
//         cnt[a[i]].s++;
//         cnt1[a[i]].s++;
//     }
//     sort(a+1,a+1+n,cmp);
//     sort(cnt1,cnt1+m,cmp1);
//     for(int i=0;i<m;i++)
//     {
//         e[cnt[i].s].insert(cnt[i].num);
//         sum[cnt[i].s]+=cnt[i].num;
//     }
//     for(int i=0;i<m;i++)
//     {
//         for(auto j=e[i].begin();j!=e[i].end();j++)
//         {
//             cout<<*j<<' ';
//         }
//         cout<<'\n';
//     }
//     LL op;
//     LL ans=0;
//     for(int i=0;i<m;i++)
//     {
//         printf("%lld ",sum[i]);
//     }
//     for(int i=1;i<=q;i++)
//     {
//         op=read();
//         // printf("(%lld)",op%m);
//         if(op>=b)
//         {
//             op=read()%m;
//             // printf("(%lld)",op%m);            
//             LL s=cnt[op].s;
//             e[s].erase(op);
//             e[s+1].insert(op);
//             sum[s]-=op;
//             sum[s+1]+=op;
//         }
//         else
//         {
//             op=read()%m;
//             // printf("(%lld)",op%m);             
//             LL s=cnt[op].s;
//             e[s].erase(op);
//             e[s-1].insert(op);
//             sum[s]-=op;
//             sum[s+1]+=op;
//         }
//         int p=cnt1[k].s;
//         ans=ans^sum[p];
//         printf("{%lld}",sum[k]);
//     }
//     cout<<ans<<' ';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// 雪莉的预言
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e7+5;
// long long seed;
// long long read() {
//     seed = (seed * 13331 + 23333) % 1000000007;
//     return seed;
// }
// LL cnt[N];
// struct node{
//     int num;
//     LL s;
// }a[N];
// bool cmp(node a,node b)
// {
//     return a.s>b.s;
// }
// LL sum[N];
// LL cnts[N];
// void solve()
// {
//     memset(cnts,0,sizeof(cnts));
//     memset(sum,0,sizeof(sum));
//     memset(cnt,0,sizeof(cnt));
//     LL k,n,m,q,b;
//     cin>>seed>>k>>n>>m>>q>>b;
//     LL x;
//     for(int i=0;i<=n;i++)
//     {
//         a[i].num=i;
//         a[i].s=0;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         x=read()%m;
//         cnt[x]++;
//         a[x].s++;
//     }
//     for(int i=0;i<m;i++)
//     {
//         cnts[cnt[i]]++;
//     }
//     sort(a,a+m,cmp);
//     for(int i=0;i<m;i++)
//     {
//         sum[a[i].s]+=a[i].num;


//     }
//     for(int i=0;i<m;i++)
//     {
//         printf("{%lld}\n",cnts[i]);
//     }
//     LL y=a[k-1].s;
//     LL ct=0;
//     for(int i=0;a[i].s!=y;i++)
//     {
//         ct++;
//     }
//     LL op;
//     LL ans=0;

//     for(int i=1;i<=q;i++)
//     {
//         op=read()%m;
//         if(op>=b)
//         {
//             op=read()%m;
//             cnt[op]++;
//             LL z=cnt[op];
//             cnts[z]++;
//             cnts[z-1]--;
//             sum[z]+=op;
//             sum[z-1]-=op;
//             if(z-1==y)
//             {
//                 ct++;
//                 if(ct==k)
//                 {
//                     y=z;
//                     ct=k-cnts[y];
//                 }
//             }
//         }
//         else
//         {
//             op=read()%m;
//             cnt[op]--;
//             LL z=cnt[op];
//             cnts[z]++;
//             cnts[z+1]--;
//             sum[z]+=op;
//             sum[z+1]-=op;
//             if(z+1==y)
//             {
//                 if(ct==k)
//                 {
//                     y=z;
//                     ct=k+
//                 }
//             }
//         }
//     }
//     printf("(%lld %lld)",ct,y);
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 缩花
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// vector<int> e[N];
// int dp[N][2];
// int d[N];

// void solve()
// {
//     memset(d,0,sizeof(d));

//     int n;
//     cin>>n;

//     int u,v;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>u>>v;
//         d[u]++;
//         d[v]++;        
//     }
 
//     int k=0;
//     int p1,p2;
//     for(int i=1;i<=n;i++)
//     {
//         if(d[i]==1)
//         {
//             k++;
//         }
//         if(d[i]>1)
//         {
//             p1=i;
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(d[i]>1&&i!=p1)
//         {
//             p2=i;
//         }
//     }    
//     if(n-k-1<=0)
//     {
//         cout<<'0'<<'\n';
//     }       
//     else
//     {
//         cout<<n-k-1<<'\n';
//         cout<<p1<<' '<<p2<<'\n';
//     }
    

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;

// }


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int l,r;
//     cin>>l>>r;
//     int s=0;
//     for(int i=l;i<=r;i++)
//     {
//         s=s+(i*i);
//     }
//     s=(s+935192215)%935192215;
//     cout<<s<<'\n';
// return 0;
// }



// ICPC Penalty
// #include<bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     string s;
//     cin>>s;
//     int n,t;
//     cin>>n>>t;
//     if(s=="Accepted")
//     {
//         cout<<t+(n-1)*20<<'\n';
//     } 
//     else if(s=="Rejected")
//     {
//         cout<<0<<'\n';
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }


// 小苯的无限数组
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// void solve()
// {
//     int n,k;
//     cin>>n>>k;
//     LL x=1<<k;
//     LL y=1ll*n*x;
//     cout<<y<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }



// 小苯的真假游戏
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;\
// const int N=1e6+5;

// int a[N];

// void solve()
// {
    
//     int n,k;
//     cin>>n;
//     vector<bool> st(n+10);
//     string s;
//     cin>>s;
//     if(n==1)
//     {
//         cout<<0<<'\n';
//         return;
//     }
//     int m=s.size();
//     int sum=0;
//     for(int i=0;i<m;i++)
//     {
//         if(s[i]=='0')
//         {
//             sum++;
//         }
//     }
//     if(sum%2==0)
//     {
//         cout<<2<<'\n';
//     }
//     else
//     {
//         cout<<0<<'\n';
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }


// 小苯的区间选数2.0
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// #define mk make_pair
// void solve()
// {
//     int n;
//     cin>>n;
//     vector<pair<int,int>> a(n+10);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i].first>>a[i].second;


//     }
//     sort(a.begin()+1,a.begin()+n+1);
//     priority_queue<int> pq;
//     int mex=0;
//     int cnt=1;
//     while(1)
//     {
//         while(cnt<=n&&a[cnt].first<=mex)
//         {
//             pq.push(-a[cnt].second);
//             cnt++;

//         }
//         while(pq.size()&&-pq.top()<mex)
//         {
//             pq.pop();
//         }
//             if(!pq.size())
//             {
//                 break;
//             }
//             mex++;
//             pq.pop();
            
        
//     }
//     cout<<mex<<'\n';

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// 小苯的GCD疑问1.0
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// void solve()
// {
//     LL l,r;
//     int k;
//     cin>>l>>r>>k;
//     cout<<((l+r)*(r-l+1))/2-r<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// 小苯的GCD疑问2.0
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// void solve()
// {
//     LL n,k;
//     cin>>n>>k;
//     LL l,r;
//     l=1;
//     LL ans=0;
//     while(l<=n)
//     {
//         r=min(n,n/(n/l));
//         LL cnt=n/l;
//         if(cnt<k)
//         {
//             break;
//         }
//         ans=max(ans,(r*r*cnt*(cnt+1))/2);
//         l=r+1;
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// 赤
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// void solve()
// {
//     int n;
//     cin>>n;

//     cout<<n<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// void solve()
// {
//     int n;
//     int a,b,c,d;
//     cin>>a>>b>>c>>d;
//     if(a>=c&&b<=d)
//     {
//         cout<<"A"<<'\n';
//         return;
//     }
//     cout<<"B"<<'\n';
// }
// int main()
// {
//     // int t;
//     // cin>>t;
//     // while(t--)
//     // {
//         solve();
//     // }
    
//     return 0;
// }


// 小红的区间判断
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// void solve()
// {
//     int n;
//     int a,b,c,d;
//     cin>>a>>b>>c>>d;
//     if((a>c&&b<d)||(a<c&&b>d))
//     {
//         cout<<"A"<<'\n';

//     }
//     else if(b<c||a>d)
//     {
//         cout<<"B"<<'\n';
//     }
//     else
//     {
//         cout<<"C"<<'\n';
//     }

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }



// 小红的区间查询
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// #define mp make_pair
// struct node{
//     LL l;
//     LL r;
//     int num;
// }a[N];
// bool cmp(node a,node b)
// {
//     return a.l<b.l;
// }
// void solve()
// {
//     int n,q;
//     cin>>n>>q;
//     LL l,r;
//     a[0].num=-1;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>l>>r;
//         a[i].l=l;
//         a[i].r=r;
//         a[i].num=i;
//     }
//     sort(a+1,a+n+1,cmp);
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("{%d %d %d}",a[i].l,a[i].r,a[i].num);
//     // }
//     LL x;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>x;
//         LL lt=1;
//         LL rt=n;
//         while(lt<=rt)
//         {
//             LL mid=(lt+rt)/2;
//             if(a[mid].l<=x)
//             {
//                 lt=mid+1;
//             }
//             else
//             {
//                 rt=mid-1;
//             }
//         }
//         // printf("{%d}",lt-1);
//         if(a[lt-1].r>=x)
//         {
//             cout<<a[lt-1].num<<'\n';
//         }
//         else if(a[lt-1].r<x)
//         {
//             cout<<-1<<'\n';
//         }
        

//     }
// }
// int main()
// {
//     solve();
    
//     return 0;
// }



// 小红的区间相交
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// struct node{
//     LL l;
//     LL r;
// }a[N];
// int b[N];
// int ans[N];
// void solve()
// {
//     memset(ans,0,sizeof(ans));

//     int n;
//     cin>>n;
//     LL l,r;
//     int tot=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>l>>r;
//         a[i].l=l;
//         a[i].r=r;
//         tot++;
//         b[tot]=l;
//         tot++;
//         b[tot]=r;

//     }
//     sort(b+1,b+1+n);
//     int m=unique(b+1,b+1+tot)-b;
//     for(int i=1;i<=n;i++)
//     {
//         int lt=a[i].l;
//         int rt=a[i].r;
//         int p1=lower_bound(b+1,b+1+m,lt)-b;
//         int p2=lower_bound(b+1,b+1+m,rt)-b;
//         ans[p1]++;
//         ans[p2+1]--;

//     }
    
//     LL s=0;
//     int tag=0;
//     for(int i=1;i<=m;i++)
//     {
//         s+=ans[i];
//         if(s==n)
//         {
//             tag=1;
//         }

//     }
//     if(tag)
//     {
//         cout<<"Yes"<<'\n';
//     }
//     else
//     {
//         cout<<"No"<<'\n';

//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }


// 小红的区间相交
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair
// mt19937_64 rnd(time(0));
// using LL=long long;

// void solve()
// {
//     int n;
//     cin>>n;
//     vector<pair<int,int>> node;
//     vector<LL> hsh(n+10),rec1(n+10);

//     int l,r;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>l>>r;
//         hsh[i]=rnd();
//         node.push_back({l,i});
//         node.push_back({r,i+n});
//     }
//     sort(node.begin(),node.end());
//     LL h=0;
//     LL g=0;
//     for(int i=1;i<=n;i++)
//     {
//         g^=hsh[i];
//     }
//     for(auto [x,y]:node)
//     {
//         if(y<=n)
//         {
//             rec1[y]=h;
//             h^=hsh[y];
//         }
//         else
//         {
//             rec1[y-n]^=h;
//             h^=hsh[y-n];
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(rec1[i]!=g)
//         {
//             cout<<"No"<<'\n';
//             return;
//         }
//     }
//     cout<<"Yes"<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }


// 迷星叫
// #include<bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int a[]={0,1,1,2,1,1,2};
//     string s1="Kato_Shoko";
//     string s2="koishiYun";
//     int t;
//     cin>>t;
//     int x;
//     for(int i=1;i<=t;i++)
//     {
//         cin>>x;
//         if(a[x]==1)
//         {
//             cout<<s1<<'\n';
//         }
//         else
//         {
//             cout<<s2<<'\n';
//         }
//     }
// }
// int main()
// {

//     // while(t--)
//     // {
//         solve();
//     // }
//     return 0;
// }


// 焚音打
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;
// LL d[N];
// void solve()
// {
//     int n;
//     cin>>n;
//     LL a,b; 
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a>>b;
//         ans=ans+a+b;
//         d[i]=b;
//     }
//     sort(d+1,d+1+n);
    
//     for(int i=n;i>=1;i--)
//     {
//         ans=ans-(d[i]*(n-i+1));
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// 诗超绊
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// void solve()
// {
//     int n;
//     LL m;
//     cin>>n>>m;
//     vector<LL> a(n+10);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     int tag1=1;
//     for(int i=2;i<=n;i++)
//     {
//         if(a[i]<=a[i-1])
//         {
//             tag1=0;
//         }
//     }
//     if(tag1)
//     {
//         cout<<0<<'\n';
//         return;
//     }
//     if(m==0)
//     {
//         cout<<-1<<'\n';
//         return;
//     }
//     LL lt=1;
//     LL rt=1e18;
//     LL ans=-1;
//     while(lt<=rt)
//     {
//         LL c=0;
//         LL cnt=0;
//         LL mid=(lt+rt)/2;
//         for(int i=2;i<=n;i++)
//         {
//             if(a[i]<=a[i-1])
//             {
//                 LL d=a[i-1]-a[i]+1;
//                 c=(d+mid-1)/mid;
//                 cnt+=c;

//             }
//             if(c>m)
//             {
//                 break;
//             }            
//             // printf("<%lld,%lld>",d,c);
//         } 
//         // printf("{%lld,%lld,%lld,%lld,%lld}\n",lt,rt,mid,cnt,s);
//         if(cnt<=m)
//         {
//             ans=mid;
//             rt=mid-1;
//         }       
//         else
//         {
//             lt=mid+1;
//         }             
//     }
//     cout<<ans<<'\n';

// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// 春日影
#include<bits/stdc++.h>
using namespace std;
void solve()
{

}
int main()
{
    solve();
    return 0;
}