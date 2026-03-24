// A. Only One Digit
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     int x;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d",&x);
//         int y;
//         int z=1e9;
//         while(x)
//         {
//             y=x%10;
//             x=x/10;
//             if(y<z)
//             {
//                 z=y;
//             }
//         }
//         printf("%d\n",z);
//     }
//     return 0;
// }


// B. No Casino in the Mountains
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// int a[N];
// int main()
// {
//     int t;
//     int n,k;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d%d",&n,&k);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
//         int d=0;
//         int s=0;
//         int tag=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(tag)
//             {
//                 tag=0;
//                 continue;
//             }
//             if(a[i]==0)
//             {
//                 d++;

//             }
//             if(a[i]==1)
//             {
//                 d=0;
//             }
//             if(d==k)
//             {
//                 d=0;
//                 s++;
//                 tag=1;
//             }
//         }
//         printf("%d\n",s);
//     }
//     return 0;
// }


// C. I Will Definitely Make It
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// int a[N];
// int main()
// {
//     int t;
//     int n,k;
//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(a,0,sizeof(a));
//         int tag=1;
//         scanf("%d%d",&n,&k);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
        
//         int h1,h2;
//         h1=a[k]+1;
//         h2=1;
//         sort(a+1,a+n+1);
//         int s=unique(a+1,a+n+1)-a-1;
//         int p=lower_bound(a+1,a+n+1,h1-1)-a;
//         for(int i=p;i<=s-1;i++)
//         {
//             int d=a[i+1]-a[i];
//             if(d>h1-h2)
//             {
//                 tag=0;
//                 break;
//             }
//             h1=a[i]+1;
//             h2+=d;

//         }
//         if(tag)
//         {
//             printf("YES\n");
//         }
//         else
//         {
//             printf("NO\n");
//         }
//         printf("{%d,%d}\n",s,p);
//     }
//     return 0;
// }


// D. This Is the Last Time
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <map>
 
// using namespace std;
 
// typedef long long LL;
// const int N = 2e5 + 10;
 
// pair<pair<int,int>,int> a[N];
 
// bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
//     return a.first.first < b.first.first;  
// }
 
// void _()
// {
//     int n, k; cin >> n >>k;
    
//     for(int i=1; i<=n; i++)
//         cin >> a[i].first.first >> a[i].first.second >> a[i].second;
//     //             li                    ri                  reali
//     sort(a+1,a+n+1,cmp);
    
//     for(int i=1; i<=n; i++){
//         if( k > a[i].first.second )// k > ri 不在区间内
//             continue;
//         if( k > a[i].second) // k > reali 不进入
//             continue;
//         if( k < a[i].first.first ) // 已经无法进入当前和之后的全部赌场了 退出循环
//             break;
//         k = a[i].second;// 进入 k 变成 reali
//     }
//     cout << k <<'\n';
//     return;
// }
 
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
 
//     int t = 1;
//     cin >> t;
//     while (t--)
//         _();
 
//     return 0;
// }

// E. G-C-D, Unlucky!
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// int p[N];
// int s[N];
// int gcd(int x,int y)
// {
//     int temp;
//     while(y)
//     {
//         temp=y;
//         y=x%y;
//         x=temp;
//     }
//     return x;
// }    
// int t;
// int n,k;
// void solve()
// {
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&p[i]);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&s[i]);
//     }
//     int tag=1;
//     if(p[n]!=s[1])
//     {
//         printf("NO\n");
//         return;
//     }
//     for(int i=2;i<=n;i++)
//     {

//         if(p[i-1]%p[i])
//         {
//             printf("NO\n");
//             return;                
//         }
//     }
//     for(int i=1;i<=n-1;i++)
//     {

//         if(s[i+1]%s[i])
//         {
//             printf("NO\n");
//             return;                
//         }
//     }
//     for(int i=1;i<=n-1;i++)
//     {
//         int x=gcd(p[i],s[i+1]);
//         if(x!=p[n])
//         {
//             printf("NO\n");
//             return;
//         }
//     }
//     printf("YES\n");
//     return;    
// }
// int main()
// {

//     scanf("%d",&t);
//     while(t--)
//     {
//         memset(p,0,sizeof(p));
//         memset(s,0,sizeof(s));
//         solve();
//     }
//     return 0;
// }


// F. 1-1-1, Free Tree!
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// int n,q;
// int a[N];
// vector<int> e[N];

// int main()
// {
//     int t;
//     int u,v,c;
//     int x;
//     scanf("%d",&t);
//     while(t--)
//     {
//         scanf("%d%d",&n,&q);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%d",&a[i]);
//         }
//         for(int i=1;i<=n-1;i++)
//         {
//             scanf("%d%d%d",&u,&v,&c);


//         }
//         for(int i=1;i<=q;i++)
//         {
//             scanf("%d%d",&v,&x);
            
//         }
//     }
    

//     return 0;
// }


// C. Make it Equal
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// LL a[N];
// LL b[N];


// int main()
// {
//     int t;
//     int n;
//     LL k;
    
//     scanf("%d",&t);
//     LL x,y;
//     LL z;
//     while(t--)
//     {
//         scanf("%d%lld",&n,&k);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&x);
//             z=min(x%k,(-x)%k+k);
//             a[i]=z;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&y);
//             z=min(y%k,(-y)%k+k);
//             b[i]=z;
//         }
//         sort(a+1,a+n+1);
//         sort(b+1,b+n+1);
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("{%lld}",a[i]);
//         // }
//         // printf("\n");
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("[%lld]",b[i]);
//         // }      
//         int tag=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(a[i]!=b[i])
//             {
//                 tag=1;
//                 break;
//             }
//         }
//         if(tag)
//         {
//             printf("NO\n");
//         }
//         else
//         {
//             printf("YES\n");
//         }
//     }
//     return 0;
// }



// A. Fibonacciness
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin>>t;
//     int a1,a2,a3,a4,a5;
//     while(t--)
//     {
//         set<int> a;
//         cin>>a1>>a2>>a4>>a5;
//         int s=0;

//         int x=a1+a2;
//         a.insert(x);
//         int y=a4-a2;
//         a.insert(y);
//         int z=a5-a4;
//         a.insert(z);
//         if(a.size()==1)
//         {
//             cout<<"3"<<"\n";
//         }
//         else if(a.size()==2)
//         {
//             cout<<"2"<<"\n";
//         }
//         else if(a.size()==3)
//         {
//             cout<<"1"<<"\n";
//         }
//     }
//     return 0;
// }


// B. Farmer John's Card Game
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// struct node{
//     int num;
//     int no;
// }a[N];
// bool cmp(node a,node b)
// {
//     return a.num<b.num;
// }
// int p[N];
// int main()
// {
//     int t;
//     cin>>t;
//     int n,m;
//     while(t--)
//     {
//         cin>>n>>m;
//         int tot=0;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 tot++;
//                 cin>>a[tot].num;
//                 a[tot].no=i;
//             }
//         }
//         sort(a+1,a+tot+1,cmp);
//         // for(int i=1;i<=tot;i++)
//         // {
//         //     cout<<a[i].no<<" ";
            
//         // }
//         // cout<<"\n";
//         int cnt=0;
//         int tag=1;
//         for(int i=1;i<=tot;i++)
//         {
//             if(i<=n)
//             {
//                 cnt++;
//                 p[cnt]=a[i].no;   
                             
//             }
//             else
//             {

//                 if(a[i].no!=p[(i-1)%n+1])
//                 {
//                     // printf("[%d]",i);
//                     tag=0;
//                     break;
//                 }
//             }

//         }
//         // for(int i=1;i<=cnt;i++)
//         // {
//         //     printf("{%d}\n",p[i]);
//         // }
//         // printf("\n");
//         if(tag)
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 cout<<p[i]<<" ";
//             }
//             cout<<"\n";
//         }
//         else
//         {
//             cout<<"-1"<<"\n";
//         }
//     }
//     return 0;
// }


// D. Subtract Min Sort
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// int x[N];
// int main()
// {
//     int t;
//     cin>>t;
//     int n,k;

//     while(t--)
//     {
//         cin>>n;
//         for(int i=1;i<=n;i++)
//         {
//             cin>>x[i];
//         }
//         for(int i=2;i<=n;i++)
//         {
//             int y=min(x[i-1],x[i]);
//             x[i]-=y;
//             x[i-1]-=y;

//         }
//         int tag=1;
//         for(int i=2;i<=n;i++)
//         {
//             if(x[i-1]>x[i])
//             {
//                 tag=0;
//                 break;
//             }
//         }
//         if(tag)
//         {
//             cout<<"YES"<<"\n";
//         }
//         else
//         {
//             cout<<"NO"<<"\n";
//         }
//     }
//     return 0;
// }


// E. Graph Composition
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// vector<int> e1[N];
// vector<int> e2[N];

// int main()
// {
//     int t;
//     cin>>t;
//     int n,m1,m2;

//     while(t--)
//     {
//         cin>>n>>m1>>m2;

//     }

//     return 0;
// }


// C. Prefix Min and Suffix Max
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// int a[N];
// int b1[N];
// int b2[N];
// int ans[N];
// int main()
// {int t,n;

//     cin>>t;

//     while(t--)
//     {
//         memset(ans,0,sizeof(ans));
//         cin>>n;
//         int min1=1e9;
//         int max2=-1;
//         for(int i=1;i<=n;i++)
//         {
//             cin>>a[i];
//             min1=min(a[i],min1);
//             b1[i]=min1;
//         }
//         for(int i=n;i>=1;i--)
//         {
//             max2=max(a[i],max2);
//             b2[i]=max2;
//         }
//         b1[0]=1e9;
//         b2[n+1]=-1;

//         // int s=0;
//         // ans[1]=1;
//         // ans[0]=1;
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("%d,",b1[i]);
            
//         // }
//         // printf("\n");
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("%d,",b2[i]);
            
//         // }        
//         // printf("\n");
//         for(int i=1;i<=n;i++)
//         {
//             if(a[i]<=b1[i-1]||a[i]>=b2[i+1])
//             {
//                 printf("1");
//             }
//             else
//             {
//                 printf("0");
//             }
//         }
//         printf("\n");
        
//     }
//     return 0;
// }


// E. Split  E. 分割
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// int a[N];
// int cnt[N];
// int s[N];
// int t;
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));
//     int n,k;
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         cnt[a[i]]++;

//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(cnt[i]%k!=0)
//         {
//             printf("0\n");
//             return;
//         }
//         cnt[i]=cnt[i]/k;

//     }
//     int lp=1;
//     int rp=1;
//     LL ans=0;
//     while(lp<=rp&&rp<=n)
//     {
//         s[a[rp]]++;

//         while(s[a[rp]]>cnt[a[rp]])
//         {
//             s[a[lp]]--;
//             lp++;

//         }
//         ans+=(rp-lp+1);
//         rp++;
//     }
//     printf("%lld\n",ans);
// }
// int main()
// {
    
//     cin>>t;
//     while(t--)
//     {
//         memset(s,0,sizeof(s));
//         solve();


//     }
//     return 0;
// }


// D. Destruction of the Dandelion Fields
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// int a[N];
// int a1[N];
// int a2[N];

// int t;
// bool cmp(int a,int b)
// {
//     return a>b;
// }
// void solve()
// {
//     int n;
//     cin>>n;
//     int x;
//     int tag=0;
//     int tot1=0;
//     int tot2=0;
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         if(x%2==1)
//         {
//             tag=1;
//             tot1++;
//             a1[tot1]=x;
//         }
//         else
//         {
//             tot2++;
//             a2[tot2]=x;
//             ans+=x;
//         }
//     }
//     if(tag==0)
//     {
//         printf("0\n");
//         return;
//     }
//     sort(a1+1,a1+tot1+1,cmp);
//     int m=(tot1-1)/2+1;
//     for(int i=1;i<=m;i++)
//     {
//         ans+=a1[i];
//     }
//     printf("%lld\n",ans);
// }
// int main()
// {
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }


// A. Cake Assignment
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// void solve()
// {
//     stack<int> q;
//     LL k,x;
//     cin>>k>>x;
//     LL y=1ll<<k;
//     LL z=1ll<<(k+1);
//     if (!x||x==y*2) {cout<<"-1\n"; return;}
//     LL a=x;
//     LL b=z-x;
//     while(a!=y)
//     {
//         if(a>b)
//         {
//             b=b*2;
//             a=z-b;
//             q.push(2);
//         }
//         else if(a<b)
//         {
//             a=a*2;
//             b=z-a;
//             q.push(1);
//         }
//     }
//     cout<<q.size()<<"\n";
//     while(!q.empty())
//     {
//         cout<<q.top()<<" ";
//         q.pop();
//     }
    

//     cout<<"\n";

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


// E. Split Into Two Sets
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// int a[N];
// int b[N];
// int cnt[N];
// int fa[N];
// void init(int n)
// {
//     for(int i=0;i<=n;i++)
//     {
//         fa[i]=i;
//     }
// }
// int find(int x)
// {
//     int t;
//     int fx=x;
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
// void add(int x,int y)
// {
//     int fx,fy;
//     fx=find(x);
//     fy=find(y);
//     if(fx!=fy)
//     {
//         fa[fx]=fy;
//     }
// }
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));
//     int n;
//     cin>>n;
//     init(n);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i]>>b[i];

//         cnt[a[i]]++;
//         cnt[b[i]]++;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]==b[i])
//         {
//             printf("No\n");
//             return;           
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(cnt[i]==1||cnt[i]>2)
//         {
//             printf("No\n");
//             return;
//         }
//     }
//     memset(cnt,0,sizeof(cnt));
//     for(int i=1;i<=n;i++)
//     {
//         int fx=find(a[i]);
//         int fy=find(b[i]);
//         if(fx!=fy)
//         {
//             add(a[i],b[i]);
//         }

//     }
//     for(int i=1;i<=n;i++)
//     {
//         cnt[find(a[i])]++;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(cnt[i]>1&&cnt[i]%2==1)
//         {
//             printf("No\n");
//             return;
//         }

//     }  
//     printf("Yes\n");
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



// C. Menorah
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// char s1[N];
// char s2[N];

// void solve()
// {
//     int n;
//     cin>>n;
//     scanf("%s",s1+1);
//     scanf("%s",s2+1);
//     int a,b,c,d;
//     a=b=c=d=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(s1[i]=='0'&&s2[i]=='0')
//         {
//             a++;
//         }
//         if(s1[i]=='1'&&s2[i]=='0')
//         {
//             b++;
//         }
//         if(s1[i]=='0'&&s2[i]=='1')
//         {
//             c++;
//         }
//         if(s1[i]=='1'&&s2[i]=='1')
//         {
//             d++;
//         }        
//     }
//     int ans=1e9;
//     // printf("{%d %d %d %d}\n",a,b,c,d);
//     if(b==c)
//     {
//         ans=min(ans,b+c);
//     }
//     if(d==a+1)
//     {
//         ans=min(ans,a+d);
//     }
//     if(ans==1e9)
//     {
//         printf("-1\n");
//     }
//     else
//     {
//         printf("%d\n",ans);

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
// }


// E. Mexification
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// int n,k;
// int a[N];
// int vis[N];

// void solve()
// {
//     memset(vis,0,sizeof(vis));
//     for(int i=1;i<=n;i++)
//     {
//         vis[a[i]]++;
//     }
//     sort(a+1,a+1+n);
//     LL p=n+1;

//     for(int i=0;i<=n;i++)
//     {
//         if(vis[i]==0)
//         {
//             p=i;
//             break;
//         }
//     }
//     LL ans=0;
//     LL q;
//     int tag=1;
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]>p||vis[a[i]]>1)
//         {
//             a[i]=p;
//         }
//     }
//     return;
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         memset(vis,0,sizeof(vis));
//         memset(a,0,sizeof(a));

//         cin>>n>>k;
//         for(int i=1;i<=n;i++)
//         {
//             cin>>a[i];
//         }
//         if(k>=1)
//         {
//             solve();
//         }
//         if(k>=2)
//         {
//             solve();
//         }
//         if(k>=3)
//         {
//             solve();
//             if(k%2==0)
//             {
//                 solve();
//             }            
//         }

//         LL ans=0;

//         for(int i=1;i<=n;i++)
//         {
//             ans+=a[i];
//             // printf("%d ",a[i]);
//         }
//         printf("%lld\n",ans);

//     }
// }


// D. From 1 to Infinity
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL d[100];
// LL s[100];
// void init()
// {
//     LL x=1;
//     LL y=9;

//     int tot=0;
//     d[tot]=0;
//     s[0]=45;
//     while(x<=1e14)
//     {
//         tot++;
//         d[tot]=(10*x-x)*tot+d[tot-1];
//         s[tot]=9*x/10*45+s[tot-1];
//         x=x*10;
//     }    

//     for(int i=1;i<=15;i++)
//     {
//         printf("{%lld,%lld}",d[i],s[i]);
//     }
//     printf("\n");    
// }
// void solve()
// {
//     LL k;
//     cin>>k;
//     LL y=0;
//     LL x;
//     int p;
//     for(int i=15;i>=1;i--)
//     {
//         if(k>=d[i])
//         {
//             k=k-d[i];
//             p=i+1;
//             break;
//         }
//     }
    


// }
// int main()
// {
//     int t;
//     cin>>t;
//     init();
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// B. Stay or Mirror
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e3+10;
// using LL=long long;
// int p[N];
// int n,m,s[N*2];
// int cnt[N];

// int lowbit(int x)
// {
//     return x&-x;
// }
// void change(int x,int k)
// {
//     while(x<=m)
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
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));
//     memset(s,0,sizeof(s));

//     cin>>n;
//     m=2*n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>p[i];
//     }
//     for(int i=n;i>=1;i--)
//     {
//         cnt[i]=query(n)-query(p[i]); 

//         // printf("{%d}",cnt[i]);
//         change(p[i],1);
        
//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%d ",cnt[i]);

//     // }
//     LL ans=0;
//     memset(s,0,sizeof(s));    
//     for(int i=1;i<=n;i++)
//     {
//         change(p[i],1);
//         int p1=query(p[i]);
//         int p2=query(m);
//         ans+=min(p2-p1,cnt[i]);
//         // printf("[%d]",p2-p1);
//     }
//     printf("%lld\n",ans);

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



// D. Sum of LDS
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// using LL=long long;
// int p[N];
// LL dp[N];

// void solve()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>p[i];
//         dp[i]=1;

//     }
    
//     if(p[2]<p[1])
//     {
//         dp[2]=3;

//     }
//     else
//     {
//         dp[2]=2;

//     }
//     LL ans=dp[1]+dp[2];
//     for(int i=3;i<=n;i++)
//     {
        
//         int k;
//         if(p[i-1]>p[i])
//         {
//             k=i-1;
//         }
//         else 
//         {
//             k=i-2;
//             dp[i]++;

//         }
//         dp[i]+=dp[k]+k;
//         ans+=dp[i];

//     }
//     printf("%lld\n",ans);

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


// D. Segments Covering 
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// LL l[N];
// LL r[N];
// LL p[N];
// LL q[N];

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
// void solve()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>l[i]>>r[i]>>p[i]>>q[i];

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



// A. Be Positive
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;

// int cnt[N];
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));
//     int n;
//     cin>>n;
//     int a;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a;
//         a++;
//         cnt[a]++;
//     }
//     int ans=0;
//     ans+=cnt[1];
//     if(cnt[0]%2==1)
//     {
//         ans+=2;
//     }
//     printf("%d\n",ans);
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



// B. Unconventional Pairs
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// LL a[N];
// void solve()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     LL maxn=0;
//     sort(a+1,a+n+1);
//     for(int i=2;i<=n;i+=2)
//     {
//         LL d=a[i]-a[i-1];
//         if(d<0)
//         {
//             d=-d;
//         }
//         maxn=max(maxn,d);
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



// C. MEX rose
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// LL a[N];
// void solve()
// {
//     set<int> st1;
//     set<int> st2;
//     int n,k;
//     cin>>n>>k;
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         if(a[i]<k)
//         {
//             st1.insert(a[i]);

//         }
//         else if(a[i]==k)
//         {
//             cnt++;
//         }
//         else
//         {
//             st2.insert(a[i]);
//         }

//     }
//     if(k==st1.size())
//     {
//         if(cnt==0)
//         {
//             cout<<'0'<<'\n';
//         }
//         else
//         {
//             cout<<cnt<<'\n';
//         }
//     }
//     else if(k>st1.size())
//     {
        
//         int d=k-st1.size();
//         if(cnt>=d)
//         {
//             cout<<cnt<<'\n';
//         }
//         else if(cnt<d)
//         {
//             cout<<d<<'\n';
//         }
//     }
//     // else if(k<st1.size())
//     // {

//     // }
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


// D. A and B
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];
// string s;
// void solve()
// {
//     int n,k;
//     // cin>>n;
//     cin>>n;
//     vector<LL> l(n+10);
//     vector<LL> r(n+10);
//     vector<LL> sum(n+10);
//     vector<LL> dsum(n+10);
//     cin>>s;
//     // cin>>s;
//     a[1]=1;
//     int tot=1;

//     for(int i=1;i<n;i++)
//     {
//         if(s[i]==s[i-1])
//         {
//             a[tot]++;
//         }
//         else
//         {
//             tot++;
//             a[tot]=1;

//         }
//     }
//     n=tot;
//     sum[1]=a[1];
//     sum[2]=a[2];

//     for(int i=3;i<=n;i++)
//     {
//         sum[i]=sum[i-2]+a[i];
//     }    
//     dsum[n]=a[n];
//     dsum[n-1]=a[n-1];

//     for(int i=n-2;i>=1;i--)
//     {
//         dsum[i]=dsum[i+2]+a[i];
//     }       

//     for(int i=3;i<=n;i++)
//     {
//         l[i]=l[i-2]+a[i-1]*sum[i-2];
//     }
//     for(int i=n-2;i>=1;i--)
//     {
//         r[i]=r[i+2]+a[i+1]*dsum[i+2];
//     }
//     LL minn=1e18;
//     for(int i=1;i<=tot;i++)
//     {
//         minn=min(minn,l[i]+r[i]);
//     }
//     // printf("%lld\n",minn);

//     cout<<minn<<'\n';
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


// E. Hidden Knowledge of the Ancients
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// int a[N];
// void solve()
// {
//     int n,k,l,r;
//     cin>>n>>k>>l>>r;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
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


// F. Nezuko in the Clearing
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5;
// LL a[N+1000];
// void solve()
// {
//     LL h,d;
//     cin>>h>>d;
//     LL p=0;
//     LL x;
//     LL s=0;
//     if(h==1)
//     {
//         s+=d*2;
//         cout<<s<<'\n';
//     }
//     else
//     {
//         if(h==2)
//         {
//             s+=d*2;
//         }
//         else if(h==3)
//         {
//             if(d<=2)
//             {
//                 s+=d*2;
//             }
//             else
//             {
//                 s+=d*2;
//                 s--;
//             }
//         }
//         else if(h>=4)
//         {
//             while(h>=4)
//             {
//                 s++;
//                 x=lower_bound(a+1,a+1+100000,h)-a;
//                 x--;
//                 h=h-(x*(x+1)/2);
//                 s+=x;
//                 p+=x;
//                 // printf("{%d,%d,%d}",s,h,p);
//             }   
//             s+=(d-p)*2;

//         }        
//         s--;
//         cout<<s<<'\n'; 
//     }
// }
// int main()
// {

//     for(LL i=1;i*i<=1e10;i++)
//     {
//         a[i]=i*(i+1)/2;
//     }
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// E. Hidden Knowledge of the Ancients
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// LL a[N];
// void solve()
// {
//     set<int> s;
//     map<LL,int> b;
//     int n,k,L,R;
//     cin>>n>>k>>L>>R;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     for(int i=1;i<=L;i++)
//     {
//         if(b[a[i]])
//         {
//             s.erase(b[a[i]]);
//         }
//         b[a[i]]=i;
//         s.insert(b[a[i]]);
//     }
//     int l=1;
//     int r=L;
//     LL ans=0;
//     while(r<=n)
//     {
//         if(r-l+1>R)
//         {
//             if(s.count(l))
//             {
//                 s.erase(l);  
//             }
//             l++;
//         }
//         while(s.size()>k)
//         {
//             if(s.count(l))
//             {
//                 s.erase(l);  
//             }
//             l++;
//         }
//         if(s.size()==k&&r-l+1>=L)
//         {
//             int fir=*s.begin();
//             fir=min(fir,r-L+1);
//             ans+=fir-l+1;

//         }
//         r++;
//         if(b[a[r]])
//         {
//             s.erase(b[a[r]]);
//         }
//         b[a[r]]=r;
//         s.insert(r);
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


// D. Replace with Occurrences
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
//     vector<int> a(N+10);
//     vector<int> b(N+10);
//     vector<int> ans[N];    
//     vector<int> cnt(N+10);
// void solve()
// {
//     int n;
//     cin>>n;
//     a.clear();
//     b.clear();
//     ans->clear();
//     cnt.clear();


//     for(int i=1;i<=n;i++)
//     {
//         cin>>b[i];
//         cnt[b[i]]++;



//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(cnt[i]%i!=0)
//         {
//             cout<<"-1"<<'\n';
//             return;
//         }
//     }
//     int tot=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=cnt[i];j++)
//         {
//             if((j-1)%i==0)
//             {
//                 tot++;
//             }
//             ans[i].push_back(tot);
//         }
//         for(auto j:ans[i])
//         {
//             cout<<j<<' ';
//         }
//     }
//     cout<<'\n';
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