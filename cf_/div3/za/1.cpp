// A. Pizza Time
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// void solve()
// {
//     LL n;
//     cin>>n;
//     LL x,y;
//     LL ans=0;
//     while(n>2)
//     {
        
//         y=n/3;
//         x=n-y*2;
//         ans+=y;
//         n=x;
//         // printf("{%lld}",n);
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


// B. Strange Machine
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e5+5;

// string s;
// int ss[N];
// LL a[N];
// LL ck[N];
// void solve()
// {
//     int n,q;
//     cin>>n>>q;
//     cin>>s;
//     int s1=0;
//     int s2=0;

//     for(int i=0;i<n;i++)
//     {
//         if(s[i]=='A')
//         {
//             ss[i]=1;
//             s1++;
//         }
//         else if(s[i]=='B')
//         {
//             ss[i]=2;
//             s2++;
//         }
//     }
//     LL qx;    
//     if(s2==0)
//     {
//         for(int i=1;i<=q;i++)
//         {
//             cin>>qx;
//             cout<<qx<<'\n';
//         }
//         return;
        
//     }


//     ck[0]=0;
//     int tot=0;
//     // for(int i=1;;i++)
//     // {
//     //     ck[i]=ck[i-1];

//     //     for(int j=n-1;j>=0;j--)
//     //     {
//     //         if(ss[j]==1)
//     //         {
//     //             ck[i]++;
//     //         }
//     //         else
//     //         {
//     //             ck[i]=ck[i]*2+1;

//     //         }
//     //     }
//     //     if(ck[i]>=3e9)
//     //     {
//     //         tot=i;
//     //         break;
//     //     }
        
//     // }
//     // LL x=1;
//     // while(ck[tot]<=2e9)
//     // {
//     //     for(int j=0;j<n;j++)
//     //     {
//     //         tot++;
//     //         ck[tot]=ck[tot-1]+x;
            
//     //         if(ss[j]==2)
//     //         {
//     //             x=x*2;
//     //         }
//     //     }        
//     // }
//     // for(int i=1;i<=tot;i++)
//     // {
//     //     printf("{%lld}",ck[i]);
//     // }    

//     LL ans=0;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>qx;

//         // int p=lower_bound(ck+1,ck+1+tot,qx)-ck;
//         // if(ck[p]==qx)
//         // {
//         //     ans=p*n;
//         // }
//         // else
//         // {

//         // }
//         // printf("(%d)",p);
//         // cout<<p<<'\n';
//         int cnt=0;
//         int p=0;
//         while(qx>0)
//         {

//             if(ss[p]==1)
//             {
//                 qx--;
//             }
//             else
//             {
//                 qx=qx/2;
//             }
//             cnt++;
//             p=cnt%n;
//         }
//         cout<<cnt<<'\n';
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



// C. Maximum GCD on Whiteboard
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// LL mp[N];
// LL a[N];
// LL s[N];
// void solve()
// {
//     memset(mp,0,sizeof(mp));

//     int k,n;
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         mp[a[i]]++;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         s[i]=s[i-1]+mp[i];
//     }
//     int maxn=0;
//     for(int i=1;i<=n;i++)
//     {
//         LL sum=0;
//         int t=min(4*i-1,n);
//         LL ans=s[t];

//         ans-=mp[i];
//         if(i*2<=n)
//         {
//             ans-=mp[i*2];
//         }
//         if(i*3<=n)
//         {
//             ans-=mp[i*3];
//         }
//         if(ans<=k)
//         {
//             maxn=max(maxn,i);
//         }
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


// A. El fucho
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int n;
//     cin>>n;
//     cout<<2*(n-1)<<'\n';
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



// B. Abraham's Great Escape
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// int a[N][N];
// void solve()
// {
//     memset(a,0,sizeof(a));
//     string s=" UDLR";
//     int n,k;
//     cin>>n>>k;
//     if(n*n-k==1)
//     {
//         cout<<"NO"<<'\n';
//         return;

//     }
//     int x=k/n;
//     int y=k%n;
//     for(int i=1;i<=x;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             a[i][j]=1;
//         }
//     }
//     for(int i=1;i<=y;i++)
//     {
//         a[x+1][i]=1;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(a[i][j]==0)
//             {
//                 if(j+1<=n)
//                 {
//                     a[i][j]=4;
//                     j++;
//                     a[i][j]=3;                    
//                 }

//                 // if((n-j+1)%2==1)
//                 // {
//                 //     if(i==n)
//                 //     {

//                 //     }
//                 //     else
//                 //     {
//                 //         a[i][j]=2;
//                 //         a[i+1][j]=1;

//                 //     }
//                 // }
//                 // else
//                 // {
                    

//                 // }
//             }

//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i][n]==0)
//         {
//             if(i+1<=n)
//             {
//                 a[i][n]=2;
//                 i++;
//                 a[i][n]=1;                
//             }
//             else if(i==n)
//             {
//                 a[i][n]=1;
//             }

//         }
//     }
//     cout<<"Yes"<<'\n';
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cout<<s[a[i][j]];
//         }
//         cout<<'\n';
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



// 
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// int a[N];
// int dp[N][2];
// bool st[N];

// bool check(int n)
// {
//     vector<int> l(n+10);
//     vector<int> r(n+10);
//     l[1]=!st[1];
//     for(int i=1;i<=n;i++)
//     {
//         l[i]=l[i-1]+(!st[i]);
//     }
//     r[n]=st[n];
//     for(int i=n-1;i>=1;i--)
//     {
//         r[i]=r[i+1]+st[i];
//     }    
//     // for(int i=1;i<=n;i++)
//     // {
//     //     // printf("(%d,%d)",l[i],r[i]);
//     // }
//     for(int i=1;i<=n;i++)
//     {
//         if(l[i-1]+r[i+1]+1!=a[i])
//         {
//             // printf("<%d>",i);
//             return 0;
//         }
//     }
//     return 1;

// }
// void solve()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     int ans=0;
//     st[1]=0;
//     for(int i=2;i<=n;i++)
//     {
//         if(a[i]==a[i-1])
//         {
//             st[i]=!st[i-1];
//         }
//         else
//         {
//             st[i]=st[i-1];
//         }
//         // printf("{%d}",st[i]);
//     }
    
//     ans+=check(n);
//     st[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         if(a[i]==a[i-1])
//         {
//             st[i]=!st[i-1];
//         }
//         else
//         {
//             st[i]=st[i-1];
//         }
//     }    
//     ans+=check(n);
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



// A. Painting With Two Colors
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int n,a,b;
//     cin>>n>>a>>b;
//     if(n%2==0)
//     {
//         if(b>=a)
//         {
//             if(b%2==0)
//             {
//                 cout<<"Yes"<<'\n';
//             }
//             else
//             {
//                 cout<<"No"<<'\n';
//             }
//         }
//         else
//         {
//             if(b%2==0&&a%2==0)
//             {
//                 cout<<"Yes"<<'\n';
//             }
//             else
//             {
//                 cout<<"No"<<'\n';
//             }            
//         }
//     }
//     else
//     {
//         if(b>=a)
//         {
//             if(b%2==1)
//             {
//                 cout<<"Yes"<<'\n';
//             }
//             else
//             {
//                 cout<<"No"<<'\n';
//             }
//         }
//         else
//         {
//             if(b%2==1&&a%2==1)
//             {
//                 cout<<"Yes"<<'\n';
//             }
//             else
//             {
//                 cout<<"No"<<'\n';
//             }            
//         }
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


// B. Add 0 or K
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;

// LL a[N];

// void solve()
// {
//     int n;
//     LL k;
//     cin>>n>>k;
//     LL g=k+1;
//     LL x,y;
//     LL maxn=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         maxn=max(maxn,a[i]);
//     }


//     for(int i=1;i<=n;i++)
//     {
//         x=a[i];

//         y=x%g;
//         if(y==0)
//         {
//             continue;
//         }
//         else
//         {
//             a[i]=x+y*k;
//         }
        
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cout<<a[i]<<' ';
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


// C. Even Larger
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;

// LL a[N];
// void solve()
// {
//     memset(a,0,sizeof(a));
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];

//     }
//     LL ans=0;
//     if(n<=2)
//     {
//         if(a[1]>a[2])
//         {
//             cout<<a[1]-a[2]<<'\n';

//         }
//         else
//         {
//             cout<<0<<'\n';
//         }
//         return;
//     }
//     for(int i=2;i<=n;i+=2)
//     {
//         if(a[i-1]+a[i+1]>a[i])
//         {
//             LL d=a[i-1]+a[i+1]-a[i];
//             // printf("{%d %d}",i,d);

//             ans+=d;
//             a[i+1]=max(1ll*0,a[i+1]-d);
//         }
//     }
//     cout<<ans<<'\n';
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


// D. Sliding Tree（树的直径）
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;

// vector<int> e[N];
// bool vis[N];
// int f[N];
// int g[N][3];
// int ans;
// int node;
// bool od[N];
// void dfs(int u)
// {
//     f[u]=0;

//     vis[u]=true;
//     int d1=0;
//     int d2=0;

//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }
//         dfs(v);
//         if(f[v]+1>d1)
//         {
//             d2=d1;
//             g[u][2]=g[u][1];
//             d1=f[v]+1;
//             g[u][1]=v;            
//         }
//         else if(f[v]+1>d2)
//         {
//             d2=f[v]+1;
//             g[u][2]=v;
//         }
//         f[u]=max(f[u],f[v]+1);
//     }
//     if(d1+d2>ans)
//     {
//         ans=d1+d2;
//         node=u;
//     }

// }
// void solve()
// {
//     memset(od,false,sizeof(od));
//     memset(vis,false,sizeof(vis));
//     memset(f,0,sizeof(f));
//     memset(g,0,sizeof(g));


//     ans=0;
//     int n;
//     cin>>n;
//     for(int i=0;i<=n+5;i++)
//     {
//         e[i].clear();
//     }
//     int u,v;
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);
//     }
//     dfs(1);
//     if(ans==n-1)
//     {
//         cout<<"-1"<<'\n';
//         return;
//     }    
//     int p=node;
//     while(p)
//     {
//         // printf("%d ",p);
//         od[p]=true;
//         p=g[p][1];
//     }
//     p=g[node][2];
//     while(p)
//     {
//         // printf("%d ",p);
//         od[p]=true;
//         p=g[p][1];
//     }    
//     int a,b,c;

//     for(int i=1;i<=n;i++)
//     {
//         for(int j:e[i])
//         {
//             if(od[i]&&!od[j])
//             {
//                 a=g[i][1];
//                 b=i;
//                 c=j;
//                 cout<<a<<' '<<b<<' '<<c<<'\n';
//                 return;
//             }
//         }
//     }

//     // printf("\n%d,%d",ans,node);

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



// A. Beautiful Average
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;

// void solve()
// {
//     int n;
//     cin>>n;
//     LL maxn=0;
//     LL x;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         maxn=max(maxn,x);
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



// B. Beautiful String
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;

// void solve()
// {
//     string s;
//     int n;
//     cin>>n;
//     cin>>s;
//     int s0=0;
//     int s1=0;
//     vector<int> e[2];
//     int tag=1;
//     for(int i=0,j=n-1;i<=j;i++,j--)
//     {
//         if(s[i]!=s[j])
//         {
//             tag=0;
//             break;
//         }
//     }
//     if(tag)
//     {
//         cout<<0<<'\n';
//         cout<<'\n';
//         return;
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(s[i]=='0')
//         {
//             e[0].push_back(i);
//             s0++;
//         }
//         else if(s[i]=='1')
//         {
//             e[1].push_back(i);
//             s1++;

//         }

//     }
//     if(s0==0||s1==0)
//     {
//         cout<<0<<'\n';
//         return;
//     }
//     cout<<e[0].size()<<'\n';
//     for(int i:e[0])
//     {
//         cout<<i+1<<' ';

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



// C. Beautiful XOR
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;

// void solve()
// {
//     LL a,b;
//     cin>>a>>b;
//     LL x,y;
//     x=a;
//     y=0;

//     while(x!=0)
//     {

//         y++;
//         x=x>>1;

//     }

//     if(b>=(1<<y))
//     {
//         cout<<-1<<'\n';
//         return;
//     }
//     cout<<2<<'\n';
//         x=(a^((1<<y)-1));
//         cout<<x<<' '<<(((1<<y)-1)^b)<<'\n';



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



// E. Beautiful Palindromes
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// using LL=long long;
// int a[N];
// int cnt[N];
// void solve()
// {
//     memset(cnt,0,sizeof(cnt));

//     int n,k;
//     cin>>n>>k;
//     int x,y,z;

//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         a[i]=x;
//         cnt[x]++;

//     }
//     int tag=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(cnt[i]==0)
//         {
//             tag=1;
//             x=i;
//             break;
//         }
//     }
//     if(tag)
//     {
//         z=a[n];
//         for(int i=1;i<=n;i++)
//         {
//             if(i!=x&&i!=a[n])
//             {
//                 y=i;
//                 break;
//             }
//         }


//     }
//     else
//     {
//         x=a[1];
//         y=a[2];
//         z=a[3];

//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     cout<<a[i]<<' ';

//     // }
//     for(int i=0;i<k;i++)
//     {
//         if(i%3==0)
//         {
//             cout<<x<<' ';
//         }
//         else if(i%3==1)
//         {
//             cout<<y<<' ';
//         }
//         else
//         {
//             cout<<z<<' ';
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


// A. Bear and Prime
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// int pm[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
// void solve()
// {
//     string s;
//     int cnt=0;
//     int p;
//     for(int i=0;i<15;i++)
//     {
//         cout<<pm[i]<<'\n';
//         fflush(stdout);
//         cin>>s;
//         if(s[0]=='y')
//         {
//             cnt++;
//             p=pm[i];
//         }
//     }
//     if(cnt==0)
//     {
//         cout<<"prime"<<'\n';
//         fflush(stdout);
//         return;
//     }
//     else if(cnt==1)
//     {
//         for(int i=p*p;i<=100;i=i*p)
//         {
//             cout<<i<<'\n';
//             fflush(stdout);
//             cin>>s;
//             if(s[0]=='y')
//             {
//                 cout<<"composite"<<'\n';
//                 fflush(stdout);
//                 return;
//             }
//         }
//         cout<<"prime"<<'\n';
//         fflush(stdout);
//         return;        
//     }
//     else
//     {
//         cout<<"composite"<<'\n';
//         fflush(stdout);
//         return;
//     }
// }
// int main()
// {

//         solve();

//     return 0;
// }



// F. Beautiful Intervals
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e4+5;
// int n,m;


// void fill(vector<int> &ans)
// {
//     vector<bool> used(n,false);
//     for(int i=0;i<=n;i++)
//     {
//         if(ans[i]!=-1)
//         {
//             used[ans[i]]=true;
//         }
//     }
//     int p=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(ans[i]==-1)
//         {
//             while(used[p])
//             {
//                 p++;
//             }
//             ans[i]=p;
//             used[p]=true;

//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cout<<ans[i]<<" \n"[i==n];

//     }
// }
// void solve()
// {

//     cin>>n>>m; 

//     vector<int> ans(n+10,-1);
//     vector<int> cntl(n+10,0);
//     vector<int> cntr(n+10,0);
//     vector<int> cnt(n+10,0);
//     int l,r;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>l>>r;
//         cntl[l]++;
//         cntr[r]++;
//         cnt[l]++;
//         cnt[r+1]--;

//     }
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("%d ",cnt[i]);
//     // }
//     int s=0;
//     int tag=0;
//     int p;
//     for(int i=1;i<=n;i++)
//     {
//         s+=cnt[i];
//         if(s==m)
//         {
//             // printf(")))");
//             p=i;
//             ans[i]=0;
//             fill(ans);
//             return;
//         }
//     }

//     for(int i=1;i<n;i++)
//     {
//         if(cntr[i]==0)
//         {
            
//             ans[i]=0;
//             ans[i+1]=1;
//             fill(ans);
//             return;
//         }
//         if(cntl[i+1]==0)
//         {
//             ans[i]=1;
//             ans[i+1]=0;
//             fill(ans);
//             return;
//         }
//     }
//     if(n>=3)
//     {
//         ans[1]=0;
//         ans[2]=2;
//         ans[3]=1;
//     }
//     fill(ans);
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



// D. Beautiful Permutation
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e4+5;
// using LL=long long;
// int lx,rx;
// void dfs(int l,int r,int d)
// {
//     if(l==r)
//     {
//         lx=l;
//         rx=l;
//         return;
//     }
//     int s1,s2;
//     int d1=0;
//     int d2=0;
//     int mid=(l+r)>>1;
//     cout<<1<<' '<<mid+1<<' '<<r<<'\n';
//     fflush(stdout);
//     cin>>s1;
//     cout<<2<<' '<<mid+1<<' '<<r<<'\n';
//     fflush(stdout);    
//     cin>>s2;
//     d1=s2-s1;
//     d2=d-d1;

//     if(d1==0)
//     {
//         dfs(l,mid,d2);
//     }
//     else if(d1==d)
//     {
//         dfs(mid+1,r,d1);
//     }
//     else
//     {
//         rx=mid+d1;
//         lx=mid-d2+1;
//         return;        
//     }
// }
// void solve()
// {

//     int s1,s2;
//     int n;
//     cin>>n;
//     int l=1;
//     int r=n;
//     cout<<1<<' '<<l<<' '<<r<<'\n';
//     fflush(stdout);
//     cin>>s1;
//     cout<<2<<' '<<l<<' '<<r<<'\n';
//     fflush(stdout);    
//     cin>>s2;
//     int d=s2-s1;    
//     dfs(1,n,d);
//     cout<<"! "<<lx<<' '<<rx<<'\n';
//     fflush(stdout);
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



// A. Square Year
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// void solve()
// {
//     string s;
//     cin>>s;
//     LL num=0;
//     for(int i=0;i<4;i++)
//     {
//         LL d=s[i]-'0';
//         num*=10;
//         num+=d;
//     }
//     int tag=0;
//     for(int i=1;1ll*i*i<=num;i++)
//     {
//         if(num%i==0)
//         {
//             if(i*i==num)
//             {
//                 tag=i;
//             }
//         }
//     }
//     if(num==0)
//     {
//         cout<<0<<' '<<0<<'\n';
//         return;
//     }
//     if(tag)
//     {
//         cout<<1<<' '<<tag-1<<'\n';
//     }
//     else
//     {
//         cout<<-1<<'\n';
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



// B. Not Quite a Palindromic String
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// void solve()
// {
//     string s;
//     int n,k;
//     cin>>n>>k;
//     cin>>s;
//     int s1=0;
//     int s0=0;

//     for(int i=0;i<n;i++)
//     {
//         if(s[i]=='0')
//         {
//             s0++;
//         }
//         else if(s[i]=='1')
//         {
//             s1++;
//         }
//     }
//     int x,y;
//     int maxn=max(s1,s0);
//     int low=maxn-n/2;

//     x=s0/2;
//     y=s1/2;
//     int top=x+y;

//     if(k<low||k>top)
//     {
//         cout<<"No"<<'\n';
//         return;
//     }
//     if((x+y-k)%2==0)
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



// C. Need More Arrays
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// void solve()
// {
//     int n;
//     cin>>n;
//     int x;
//     int y=-100;
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
        
//         if(x>=y)
//         {
//             y=x+2;
//             cnt++;
//         }
        
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



// D. Come a Little Closer
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// #define mp make_pair
// struct node{
//     int x,y;
// }a[N],b[N];

// void solve()
// {
//     int n;
//     cin>>n;
//     int x,y;
//     pair<int,int> xmin(1e9,1e9),xmax(0,0);
//     pair<int,int> ymin(1e9,1e9),ymax(0,0);
//     a[0].x=0;
//     a[0].y=0;
//     a[n+1].x=1e9+5;
//     a[n+1].y=1e9+5;
//     xmin=mp(n+1,n+1);
//     xmax=mp(0,0);
//     ymin=mp(n+1,n+1);
//     ymax=mp(0,0);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x>>y;
//         a[i].x=x;
//         a[i].y=y;

//         if(x<a[xmin.first].x)
//         {
//             xmin.second=xmin.first;
//             xmin.first=i;
//         }
//         else if(x<a[xmin.second].x)
//         {
//             printf("(%d)",i);
//             xmin.second=i;
//         }


//         if(x>a[xmax.first].x)
//         {
//             xmax.second=xmax.first;
//             xmax.first=i;
//         }
//         else if(x>a[xmax.second].x)
//         {
//             xmax.second=i;
//         }  
            

//         if(y<a[ymin.first].y)
//         {
//             ymin.second=ymin.first;
//             ymin.first=i;
//         }
//         else if(y<a[ymin.second].y)
//         {
//             ymin.second=i;
//         }


//         if(y>a[ymax.first].y)
//         {
//             ymax.second=ymax.first;
//             ymax.first=i;
//         }
//         else if(y>a[ymax.second].y)
//         {
//             ymax.second=i;
//         }  
//     }    
//     // printf("{%d %d %d %d}{%d %d %d %d}\n",xmin.first,xmin.second,xmax.first,xmax.second,ymin.first,ymin.second,ymax.first,ymax.second);
//     if(xmin.first==ymin.first||xmax.first==ymax.first)
//     {

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



// E. Kirei Attacks the Estate
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// LL a[N];
// vector<int> e[N];
// bool vis[N];
// LL ans[N];
// void dfs(int u,LL minn,LL maxn)
// {
//     vis[u]=true;
//     for(int v:e[u])
//     {
//         if(vis[v])
//         {
//             continue;
//         }
//         LL maxn2,minn2;
//         maxn2=max(a[v],a[v]-minn);
//         minn2=min(a[v],a[v]-maxn);
//         ans[v]=maxn2;
//         // printf("<%d: %d %d>",v,maxn2,minn2);
//         dfs(v,minn2,maxn2);
//     }
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));
//     memset(ans,0,sizeof(ans));
//     memset(a,0,sizeof(a));
//     int n;
//     cin>>n;
//     for(int i=0;i<=n;i++)
//     {
//         e[i].clear();
//     }    
//     int u,v;

//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     for(int i=1;i<=n-1;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);

//     }
//     dfs(1,a[1],a[1]);
//     ans[1]=a[1];
//     for(int i=1;i<=n;i++)
//     {
//         printf("%lld ",ans[i]);
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


// F. Small Operations
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
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

// int gcd(int a,int b)
// {
//     int t;
//     while(b)
//     {
//         t=b;
//         b=a%b;
//         a=t;
//     }
//     return a;
// }
// int get_ans(int x,int k)
// {
//     if(x==1)
//     {
//         return 0;
//     }
//     vector<int> d;
//     for(int i=1;i*i<=x;i++)
//     {
//         if(x%i==0)
//         {
//             d.push_back(i);
//             d.push_back(x/i);
//         }
//     }
//     sort(d.begin(),d.end());
//     int n=d.size();

//     vector<int> dp(n+10,1000);
//     dp[0]=0;
//     for(int i=1;i<n;i++)
//     {
//         for(int j=i-1;j>=0;j--)
//         {
//             if(d[i]/d[j]>k)
//             {
//                 break;
//             }
//             if(d[i]%d[j]==0)
//             {
//                 dp[i]=min(dp[i],dp[j]+1);
//             }
//         }
//     }
//     return dp[n-1]==1000?-1:dp[n-1];
// }
// void solve()
// {
//     int n;
//     int x,y,k;
    
//     cin>>x>>y>>k;
//     int g=gcd(x,y);
//     x=x/g;
//     y=y/g;
//     int ax=get_ans(x,k);
//     int ay=get_ans(y,k);
//     if(ax==-1||ay==-1)
//     {
//         cout<<-1<<'\n';
//     }
//     else
//     {
//         cout<<ax+ay<<'\n';

//     }
// }
// int main()
// {
//     cnt=0;
//     get_prim(N);

//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }



// A. New World, New Me, New Array
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int n,k,p;
//     cin>>n>>k>>p;
//     int x;
//     x=k/p;
//     int y;
//     // if(k==0)
//     // {
//     //     if(n%2==0)
//     //     {
//     //         cout<<n<<'\n';
//     //     }
//     //     else
//     //     {
//     //         cout<<-1<<'\n';
//     //     }
//     //     return;
//     // }
//     if(k-x*p==0)
//     {
//         x=abs(x);

//         y=x;
//     }
//     else
//     {
//         x=abs(x);
//         y=x+1;
//     }
//     if(y>n)
//     {
//         cout<<-1<<'\n';
//     }
//     else
//     {
//         cout<<y<<'\n';
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



// B. Having Been a Treasurer in the Past, I Help Goblins Deceive
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// void solve()
// {
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     LL s1=0;
//     LL s2=0;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]=='-')
//         {
//             s1++;
//         }
//         if(s[i]=='_')
//         {
//             s2++;
//         }
//     }
//     LL x=s1/2;
//     LL y=s1-x;
//     LL ans=x*y*s2;
//     cout<<ans<<'\n';
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
// }



// C. Creating Keys for StORages Has Become My Main Skill
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// void solve()
// {
//     int n,x;
//     cin>>n>>x;
//     int p=-1;
//     int p2=0;
//     for(int i=0;(1<<i)<=x;i++)
//     {
//         if((x&(1<<i)))
//         {
//             p2=1<<i;
//         }        
//         if((x&(1<<i))==0)
//         {
//             p=1<<i;
//             break;
//         }

//     }
//     // printf("{%d,%d}",p,p2);
//     if(p==-1)
//     {
//         if(p2+1<=n)
//         {
//             for(int i=0;i<n;i++)
//             {
//                 if(i>x)
//                 {
//                     cout<<0<<' ';
//                 }
//                 else
//                 {
//                     cout<<i<<' ';
//                 }
                
//             }      
//             // printf("*");      
//         }
//         else
//         {
//             cout<<x<<' ';
//             for(int i=0;i<n-1;i++)
//             {
//                 if(i>x)
//                 {
//                     cout<<0<<' ';
//                 }
//                 else
//                 {
//                     cout<<i<<' ';
//                 }
//             }            
//         }
//         cout<<'\n';

//     }
//     else
//     {
//         cout<<x<<' ';
//         for(int i=0;i<n-1;i++)
//         {
//             if(i<p)
//             {
//                 cout<<i<<' ';
//             }
//             else if(i>=p)
//             {
//                 cout<<0<<' ';
//             }
            
//         }           
//         cout<<'\n';

//     }


// }
// int main()
// {
//     // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
// }



// D. For Wizards, the Exam Is Easy, but I Couldn't Handle It
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e3+5;
// int a[N];
// void solve()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     int ans=0;
//     int p1=1;
//     int p2=1;

//     for(int i=1;i<=n;i++)
//     {
//         int s1=0;
//         int s2=0;
//         for(int j=i+1;j<=n;j++)
//         {
//             if(a[j]<a[i])
//             {
//                 s1++;
//             }
//             if(a[j]>a[i])
//             {
//                 s2++;
//             }
//             if(s2-s1<ans)
//             {
//                 ans=s2-s1;
//                 p1=i;
//                 p2=j;
//             }
//         }
        
//     }
//     cout<<p1<<' '<<p2<<'\n';
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



// E. Do You Love Your Hero and His Two-Hit Multi-Target Attacks?
#include<bits/stdc++.h>
using namespace std;
const int N=501;
int inits[N];
void init()
{
    for(int i=1;i<=500;i++)
    {
        inits[i]=((i-1)*i)/2;
    }
}
void solve()
{
    vector<int> b;
    int k;
    cin>>k;
    if(k==0)
    {
        printf("0\n");

        return;
    }
    int s=0;
    while(k)
    {
        
        int a=lower_bound(inits+1,inits+500,k)-inits;
        // printf("{%d}",inits[a]);
        if(inits[a]>k)
        {
            a--;
        }
        s+=a;
        k=k-inits[a];
        b.push_back(a);
        
    }
    int cnt=0;
    printf("%d\n",s);
    for(int i:b)
    {
        cnt++;
        for(int j=1;j<=i;j++)
        {
            printf("%d %d\n",cnt,cnt+(j-1)*1000);
        }
        
    }
    
}
int main()
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}