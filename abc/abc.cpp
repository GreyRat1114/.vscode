// Grandma's Footsteps
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int s,a,b,x;
//     cin>>s>>a>>b>>x;
//     int c=a+b;
//     int p=x/c;
//     int q=x%c;
//     int ans=0;
//     ans=p*s*a;
//     if(q)
//     {
//         ans+=min(q*s,a*s);

//     }
//     cout<<ans<<'\n';
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



// B - Most Frequent Substrings
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     vector<string> ans1;
//     vector<int> ans2(1005,0);
//     map<string,int> mp; 
//     int n,k;
//     string s;
//     cin>>n>>k;
//     cin>>s;
//     string ss;
//     for(int i=0;i+k<=n;i++)
//     {
//         ss.resize(k);
//         for(int j=0;j<k;j++)
//         {
//             ss[j]=s[i+j];
            
//         }
//         if(mp.find(ss)==mp.end())
//         {
//             mp.insert({ss,0});
//         }
//         ans1.push_back(ss);

//     }
//     // for(int i=0;i<ans1.size();i++)
//     // {
//     //     cout<<ans1[i]<<'\n';
//     // }
//     for(auto i=mp.begin();i!=mp.end();i++)
//     {
//         string s1=i->first;
//         for(int j=0;j+k<=n;j++)
//         {
//             int tag=1;
//             for(int l=0;l<k;l++)
//             {
//                 if(s1[l]!=s[l+j])
//                 {
//                     tag=0;
//                 }

//             }
//             if(tag)
//             {
//                 mp[s1]++;

//             }
//         }
//     }
//     int maxn=0;

//     for(const auto&[key,val]:mp)
//     {
//         maxn=max(maxn,val);
//     }
//     cout<<maxn<<'\n';
//     for(const auto&[key,val]:mp)
//     {
//         if(val==maxn)
//         {
//             cout<<key<<'\n';
//         }
//     }
// }
// int main()
// {

//     solve();

//     return 0;
// }



// C - Brackets Stack Query
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair

// void solve()
// {
    
//     int q;
//     cin>>q;
//     char c;
//     stack<pair<int,int>> st;
//     st.push(mp(0,0));

//     int op;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>op;
//         if(op==1)
//         {
//             cin>>c;
//             int fst=st.top().first;
//             int sec=st.top().second;

//             if(c=='(')
//             {
//                 fst++;
//             }
//             if(c==')')
//             {
//                 fst--;

//             }           
//             sec=min(sec,fst);
//             st.push(mp(fst,sec));

//             if(st.top().second>=0&&st.top().first==0)
//             {
//                 cout<<"Yes"<<'\n';
//             }
//             else
//             {
//                 cout<<"No"<<'\n';
//             }                

//         }
//         else if(op==2)
//         {
//             st.pop();
//             if(st.top().second>=0&&st.top().first==0)
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
//     solve();
//     return 0;
// }



// 
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair

// void solve()
// {
//     int h,b;
//     cin>>h>>b;
//     if(h>b)
//     {
//         cout<<h-b<<'\n';
//     }
//     else
//     {
//         cout<<0<<'\n';
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// B - Robot Weight
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair
// const int N=1e3+5;
// int w[N];
// bool vis[N];
// void solve()
// {
//     int x;
//     int n;

//     cin>>x;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>w[i];

//     }
//     int q;
//     cin>>q;
//     int p;
//     int ans=x;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>p;
//         if(!vis[p])
//         {
//             vis[p]=true;
//             ans+=w[p];
//         }
//         else
//         {
//             vis[p]=false;
//             ans-=w[p];
//         }
//         cout<<ans<<'\n';
//     }
    
// }
// int main()
// {
//     solve();
//     return 0;
// }


// C - Robot Factory
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair
// const int N=2e5+5;
// using LL=long long;
// LL h[N];
// LL b[N];
// bool vis[N];
// void solve()
// {
//     int n,m,k;
//     cin>>n>>m>>k;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>h[i];
//     }
//     for(int i=1;i<=m;i++)
//     {
//         cin>>b[i];
//     }    
//     sort(h+1,h+1+n);
//     sort(b+1,b+1+m);
//     int p=1;
//     int q=1;
//     int s=0;
//     while(p<=n&&q<=m)
//     {
//         if(h[p]<=b[q])
//         {
//             p++;
//             q++;
//             s++;
//         }
//         else
//         {
//             q++;
//         }
//     }
//     if(s>=k)
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
//     solve();
//     return 0;
// }


// D - Robot Customize
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair
// const int N=505;
// using LL=long long;
// LL w[N];
// LL h[N];
// LL b[N];
// LL d[N];
// void solve()
// {
//     int n;
//     cin>>n;
    
//     LL sv=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>w[i]>>h[i]>>b[i];
//         d[i]=h[i]-b[i];
//         sv+=w[i];
//     }
//     LL sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         sum+=b[i];
//     }
//     sv=sv/2;
//     vector<LL> dp(sv+10,0);
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=sv;j>=0;j--)
//         {
//             if(j-w[i]>=0)
//             {
//                 dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
//             }
//             ans=max(ans,dp[j]);
//         }
//     }
//     cout<<ans+sum<<'\n';
//     // cout<<sv<<'\n';
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     solve();
//     return 0;
// }



// E - Reflection on Grid
// #include<bits/stdc++.h>
// using namespace std;
// #define mp make_pair
// const int N=505;
// using LL=long long;
// LL w[N];
// LL h[N];
// LL b[N];
// LL d[N];
// void solve()
// {
//     int n;
//     cin>>n;
    
//     LL sv=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>w[i]>>h[i]>>b[i];
//         d[i]=h[i]-b[i];
//         sv+=w[i];
//     }
//     LL sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         sum+=b[i];
//     }
//     sv=sv/2;
//     vector<LL> dp(sv+10,0);
//     LL ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=sv;j>=0;j--)
//         {
//             if(j-w[i]>=0)
//             {
//                 dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
//             }
//             ans=max(ans,dp[j]);
//         }
//     }
//     cout<<ans+sum<<'\n';
//     // cout<<sv<<'\n';
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     solve();
//     return 0;
// }


// F - Almost Sorted 2
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// const int mod=998244353;
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

// void solve()
// {
//     init();
//     vector<LL> cnt(N,0);
//     int n;
//     int d;
//     cin>>n>>d;
//     LL maxn=0;
//     vector<LL> a(n+10);
//     for(int i=1;i<=n;i++)
//     {

//         cin>>a[i];
//         cnt[a[i]]++;
//         maxn=max(maxn,a[i]);

//     }
//     LL s=0;
//     LL ans=1;
//     for(int i=1;i<=maxn;i++)
//     {

//         s+=cnt[i];
//         if(i>=d+2)
//         {
//             s-=cnt[i-d-1];
//         }
//         ans=(ans*getc(s,cnt[i]))%mod;

//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// D - 183184
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// LL gpow(int n)
// {
//     LL ans=1;
//     while(n--)
//     {
//         ans*=10;
//     }
//     return ans;
// }

// void solve()
// {
//     LL c,d;
//     cin>>c>>d;
//     LL ans=0;
//     int len=log10(c*d);

//     for(int i=1;i<=18;i++)
//     {
//         LL l=gpow(i-1)-c;
//         LL r=gpow(i)-c-1;
        

//         l=max(1ll,l);
//         r=min(d,r);
//         if(l>r||r<0)
//         {
//             // printf("()");
//             continue;
//         }        
        
//         LL lt=c*gpow(i)+l+c;
//         LL rt=c*gpow(i)+r+c;
        
//         LL sl=ceil(sqrtl(lt));
//         LL sr=floor(sqrtl(rt));
//         // printf("{%lld %lld}",sl,sr);
//         ans+=(sr-sl+1);
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


// E - Farthest Vertex 
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;

// vector<int> e[N];
// int dist1[N];
// int dist2[N];
// int maxn=0;
// int p;
// void dfs1(int u,int fa,int d)
// {
//     if(d>maxn)
//     {
//         maxn=d;
//         p=u;
//     }
//     else if(d==maxn)
//     {
//         p=max(p,u);
//     }
//     for(int v:e[u])
//     {
//         if(v==fa)
//         {
//             continue;
//         }
//         dfs1(v,u,d+1);
//     }
// }
// int maxn2;
// int p2;
// void dfs2(int u,int fa,int d)
// {
//     dist1[u]=d;
//     if(d>maxn2)
//     {
//         maxn2=d;
//         p2=u;
//     }
//     else if(d==maxn2)
//     {
//         p2=max(p2,u);
//     }
//     for(int v:e[u])
//     {
//         if(v==fa)
//         {
//             continue;
//         }
//         dfs2(v,u,d+1);
//     }    
// }
// void dfs3(int u,int fa,int d)
// {
//     dist2[u]=d;
//     for(int v:e[u])
//     {
//         if(v==fa)
//         {
//             continue;
//         }
//         dfs3(v,u,d+1);
//     }       
// }
// void solve()
// {
//     int n;
//     cin>>n;
//     for(int i=1;i<=n-1;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);
//     }
//     maxn=0;
//     p=-1;
//     dfs1(1,1,0);
//     maxn2=0;
//     p2=-1;    
//     dfs2(p,p,0);

//     dfs3(p2,p2,0);
//     // printf("<%d %d>\n",p,p2);
//     // for(int i=1;i<=n;i++)
//     // {
//     //     printf("{%d %d}",dist1[i],dist2[i]);
//     // }
//     for(int i=1;i<=n;i++)
//     {
//         if(dist1[i]>dist2[i])
//         {
//             cout<<p<<'\n';
//         }
//         else if(dist1[i]<dist2[i])
//         {
//             cout<<p2<<'\n';
//         }
//         else
//         {
//             cout<<max(p,p2)<<'\n';
//         }
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// A - Stage Clear
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     string s;
//     cin>>s;
//     int x=s[0]-'0';
//     int y=s[2]-'0';
//     if(y==8)
//     {
//         x++;
//         y=0;
//     }
//     cout<<x<<'-'<<y+1;
// }
// int main()
// {
//     solve();

//     return 0;
// }



// B - Looped Rope
// #include<bits/stdc++.h>
// using namespace std;
// const int N=55;
// int dx[]={-1,0,0,1};
// int dy[]={0,-1,1,0};
// char s[N][N];
// void solve()
// {
//     int h,w;
//     cin>>h>>w;
//     for(int i=0;i<h;i++)
//     {
//         cin>>s[i];
//     }

//     for(int i=0;i<h;i++)
//     {
//         for(int j=0;j<w;j++)
//         {

//             if(s[i][j]=='#')
//             {
//                 int x1,y1;
//                 int sum=0;                
//                 for(int k=0;k<4;k++)
//                 {
//                     x1=i+dx[k];
//                     y1=j+dy[k];
//                     if(x1<0||x1>=h||y1<0||y1>=w)
//                     {
//                         continue;
//                     }
//                     if(s[x1][y1]=='#')
//                     {
//                         sum++;

//                     }
//                 }     

//                 if(sum!=2&&sum!=4)
//                 {
//                     cout<<"No"<<'\n';
//                     return;
//                 }           
//             }

//         }
        
//     }
//     cout<<"Yes"<<'\n';
// }
// int main()
// {
//     solve();

//     return 0;
// }



// C - AtCoder AAC Contest
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// const int N=55;

// char s[N][N];
// void solve()
// {
//     LL n1=0;
//     LL n2=0;
//     LL n3=0;
//     cin>>n1>>n2>>n3;
//     LL s1=n1+n3;
//     LL minn=min(n1,n3);
//     LL d=n2+s1-2*minn;
//     LL ans=min(minn,d);
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

// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=55;
// void solve()
// {
//     LL n1=0;
//     LL n2=0;
//     LL n3=0;
//     cin>>n1>>n2>>n3;
//     LL minn=min(n1,n3);
//     LL ans=min(minn,(n1+n2+n3)/3);
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



// D - Least Unbalanced
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=55;
// LL n,k;
// void dfs(int m,LL num)
// {
//     if(m==n)
//     {
//         cout<<num<<' ';
//         return;
//     }
//     LL x=num/2;
//     LL y=num-x;
//     dfs(m+1,x);
//     dfs(m+1,y);
// }
// void solve()
// {

//     cin>>n>>k;
//     LL x=(1<<n);
//     LL y=k%x;
//     if(y==0)
//     {
//         cout<<0<<'\n';
//     }
//     else
//     {
//         cout<<1<<'\n';
//     }
//     dfs(0,k);

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



//E - Colinear
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=5e5+5;
// LL x[N];
// LL y[N];
// mt19937_64 rng(58);
// void solve()
// {
//     LL n;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cin>>x[i]>>y[i];
//     }
//     int t=100;
//     while(t--)
//     {
//         int p,q;
//         do{
//             p=rng()%n;
//             q=rng()%n;            
//         }while(p==q);
//         LL x1=x[p];
//         LL x2=x[q];
//         LL y1=y[p];
//         LL y2=y[q];
//         LL pt1=x1-x2;
//         LL pt2=y2-y1;
//         LL pt3=y1*x2-x1*y2;
//         LL sum=0;
//         for(int i=0;i<n;i++)
//         {
//             LL x3=x[i];
//             LL y3=y[i];
//             if(pt1*y3+pt2*x3+pt3==0)
//             {
//                 sum++;
//             }
//         }
//         if(sum*2>n)
//         {
//             cout<<"Yes"<<'\n';
//             cout<<pt2<<' '<<pt1<<' '<<pt3<<'\n';
//             return;
//         }
    
//     }
//     cout<<"No"<<'\n';

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



// D - Max Multiple
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=105;
// LL aa[N];
// LL a[N];
// LL dp[N][N][N];

// void solve()
// {

//     LL n,k,d;
//     cin>>n>>k>>d;
//     for(int i=0;i<=n+10;i++)
//     {
//         for(int j=0;j<=N;j++)
//         {
//             for(int l=0;l<=N;l++)
//             {
//                 dp[i][j][l]=-1;
//             }
//         }
//     }    
//     for(int i=1;i<=n;i++)
//     {
//         cin>>aa[i];
//         a[i]=aa[i]%d+1;
//     }
//     for(int i=0;i<=N;i++)
//     {
//         dp[i][0][0]=0;
//     }
    

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=d+k;j++)
//         {
//             for(int l=1;l<=k;l++)
//             {
//                 if(j-a[i]>=0&&dp[i-1][j-a[i]][l-1]!=-1)
//                 {
//                     dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-a[i]][l-1]+aa[i]);
//                     printf("{%d %d %d %lld}\n",i,j,l,dp[i][j][l]);
//                 }
//             }
//         }
//     }
//     cout<<dp[n][d+k][k]<<'\n';
// }
// int main()
// {
//     solve();

//     return 0;
// }



// F - Eat and Ride
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e4+5;
// vector<int> e[N];
// LL w[N];
// LL dp[N][N];

// void solve()
// {
//     memset(dp,0x3f,sizeof(dp));

//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>w[i];
//     }
//     int u,v;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);
//     }
//     for(int i=0;i<=n;i++)
//     {    
//         dp[1][i]=i*1ll*w[1];
//     }
//     for(int i=n;i>=1;i--)
//     {
//         for(int u=1;u<=n;u++)
//         {
//             for(int v:e[u])
//             {
//                 dp[v][i-1]=min(dp[v][i-1],dp[u][i]+w[v]*(i-1));
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         cout<<dp[i][0]<<'\n';
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// A - Sigma Cubes
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int n;
//     cin>>n;
//     int sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         int x=i*i*i;

//         if(i%2==1)
//         {
//             sum-=x;
//         }
//         else
//         {
//             sum+=x;
//         }
//     }
//     cout<<sum<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// B - Find Permutation 2
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e3+5;

// int a[N];
// void solve()
// {
    
//     int n;
//     cin>>n;
//     vector<int> pos(n+10,0);
//     vector<int> ans(n+10,0);
//     int s=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
         
//         if(a[i]==-1)
//         {
//             s++;
//         }
//         else
//         {
//             if(pos[a[i]]>0)
//             {
//                 cout<<"No"<<'\n';
//                 return;
//             }              
//             pos[a[i]]=i;
//         }     


//     }
//     cout<<"Yes"<<'\n';
//     for(int i=1;i<=n;i++)
//     {
//         if(pos[i])
//         {
//             ans[pos[i]]=i;
//         }
//     }
//     int p=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]==-1)
//         {
//             p++;
//             while(pos[p]!=0)
//             {
//                 p++;
//             }
//             ans[i]=p;
//         }
//         else
//         {
//             ans[i]=a[i];
//         }

//     }
//     for(int i=1;i<=n;i++)
//     {
//         cout<<ans[i]<<' ';
//     }
//     cout<<'\n';


// }
// int main()
// {
//     solve();
//     return 0;
// }



// C - Rotate and Sum Query
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=5e5+5;

// int a[N];
// LL s[N];
// void solve()
// {
//     int n,q;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         a[i+n]=a[i];

//     }
//     s[0]=0;
//     s[1]=a[1];
//     for(int i=2;i<=2*n;i++)
//     {
//         s[i]=s[i-1]+a[i];
//     }
//     int op,l,r,c;
//     int h=0;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>op;
//         if(op==1)
//         {
//             cin>>c;
//             h+=c;
//             h=h%n;

//         }
//         else if(op==2)
//         {
//             cin>>l>>r;
//             l=l+h;
//             r=r+h;
//             LL ans=s[r]-s[l-1];
//             cout<<ans<<'\n';
//         }
//     }


// }
// int main()
// {
//     solve();
//     return 0;
// }



//D - Ulam-Warburton Automaton
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// #define mp make_pair
// const int N=5e5+5;
// int dx[]={-1,0,0,1};
// int dy[]={0,-1,1,0};
// int sum;
// int h,w;
// void solve()
// {
//     sum=0;
//     cin>>h>>w;
//     vector<vector<int>> a(h+10,vector<int>(w+10,0));
//     vector<vector<int>> vis(h+10,vector<int>(w+10,0));
//     string s;
//     for(int i=1;i<=h;i++)
//     {
//         cin>>s;
//         for(int j=0;j<w;j++)
//         {
//             if(s[j]=='.')
//             {
//                 a[i][j+1]=0;
//             }
//             else
//             {
//                 a[i][j+1]=1;
//             }
//         }
//     }

//     queue<pair<int,int>> q;
//     for(int i=1;i<=h;i++)
//     {
//         for(int j=1;j<=w;j++)
//         {
//             if(a[i][j])
//             {
//                 sum++;
//                 q.push(mp(i,j));
//                 vis[i][j]=1;
//             }
//         }
//     }
//     int x,y;
//     while(!q.empty())
//     {
//         x=q.front().first;
//         y=q.front().second;
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int x1=x+dx[i];
//             int y1=y+dy[i];  
            
//             if(x1<1||y1<1||x1>h||y1>w) 
//             {
//                 continue;
//             }     
//             if(vis[x1][y1])
//             {
//                 continue;
//             }
//             vis[x1][y1]=vis[x][y]+1;
//             int s=0;       
//             for(int j=0;j<4;j++)
//             {
//                 int x2=x1+dx[j];
//                 int y2=y1+dy[j];  
//                 if(x2<1||y2<1||x2>h||y2>w) 
//                 {
//                     continue;
//                 }
//                 if(a[x2][y2]&&(vis[x2][y2]!=vis[x1][y1]))
//                 {
//                     s++;
//                 }    
//             }            
//             if(s==1)
//             {
//                 sum++;
//                 q.push(mp(x1,y1));
//                 a[x1][y1]=1;
//             }                 
//         }
//     }
//     cout<<sum<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// E - Count Sequences 2
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// #define mp make_pair
// const int N=3e5+5;
// const int M=5e3+5;
// LL mod;
// LL c[N];
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
// void solve()
// {
//     int n;
//     LL s;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>c[i];
//     }
//     s=c[1];
//     LL ans=1;
//     for(int i=2;i<=n;i++)
//     {
//         s+=c[i];
//         LL x=cul[s][c[i]];

//         ans=(ans*x)%mod;
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
    
//     int t;
//     cin>>t>>mod;
//     init();
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }



// A - What month is it?
// #include<bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int x,y;
//     cin>>x>>y;
//     x--;
//     cout<<(x+y)%12+1<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// B - Most Minority
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// string s;

// void solve()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> cnt1(m+10);
//     vector<vector<int>> cnt2(m+10);
//     vector<int> ans(n+10,0);

//     for(int i=1;i<=n;i++)
//     {
//         cin>>s;
//         for(int j=1;j<=m;j++)
//         {
//             if(s[j-1]=='1')
//             {
//                 cnt1[j].push_back(i);
//             }
//             else
//             {
//                 cnt2[j].push_back(i);
//             }
//         }

//     }
//     for(int i=1;i<=m;i++)
//     {
//         if(cnt1[i].size()==0&&cnt2[i].size()==0)
//         {
//             for(int j=0;j<cnt1[i].size();j++)
//             {
//                 ans[cnt1[i][j]]++;
//             }            
//             for(int j=0;j<cnt2[i].size();j++)
//             {
//                 ans[cnt2[i][j]]++;
//             }
//             continue;            
//         }
//         if(cnt1[i].size()<cnt2[i].size())
//         {
//             for(int j=0;j<cnt1[i].size();j++)
//             {
//                 ans[cnt1[i][j]]++;
//             }
//         }
//         else if(cnt1[i].size()>cnt2[i].size())
//         {
//             for(int j=0;j<cnt2[i].size();j++)
//             {
//                 ans[cnt2[i][j]]++;
//             }
//         }
//     }
//     int maxn=0;

//     for(int i=1;i<=n;i++)
//     {
//         maxn=max(maxn,ans[i]);

//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(ans[i]==maxn)
//         {
//             cout<<i<<' ';
//         }
//     }
//     cout<<'\n';

// }
// int main()
// {
//     solve();
//     return 0;
// }


// C - Sum of Min Query
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// using LL=long long;


// void solve()
// {
    
//     int n,q;
//     cin>>n>>q;
//     vector<LL> a(n+10);
//     vector<LL> b(n+10);
//     vector<LL> minn(n+10);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];

//     }
//     for(int i=1;i<=n;i++)
//     {
//         cin>>b[i];
        
//     }
//     LL s=0;
//     for(int i=1;i<=n;i++)
//     {
//         minn[i]=min(a[i],b[i]);
//         s+=minn[i];
//     }
//     char c;
//     int x;
//     LL v;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>c;
//         cin>>x>>v;
//         s-=minn[x];
//         if(c=='A')
//         {
//             a[x]=v;
//         }
//         else
//         {
//             b[x]=v;
//         }
//         minn[x]=min(a[x],b[x]);
//         s+=minn[x];
//         cout<<s<<'\n';
//     }
    
// }
// int main()
// {
//     solve();
//     return 0;
// }



// D - Toggle Maze
// #include<bits/stdc++.h>
// using namespace std;
// const int N=505;
// using LL=long long;
// #define MP make_pair
// int dx[]={-1,0,0,1};
// int dy[]={0,-1,1,0};
// char mp[N][N];
// int h,w;
// int dis[N][N][2];
// int bfs(int sx,int sy)
// {
//     queue<pair<pair<int,int>,int>> q;
//     q.push(MP(MP(sx,sy),0));
//     while(!q.empty())
//     {
//         int x=q.front().first.first;
//         int y=q.front().first.second;
//         int z=q.front().second;
//         // printf("{%d %d}",x,y);
//         q.pop();

//         for(int i=0;i<4;i++)
//         {
//             int x1=x+dx[i];
//             int y1=y+dy[i];
            
//             if(x1<1||y1<1||x1>h||y1>w)
//             {
//                 continue;
//             }
//             if(mp[x1][y1]=='G')
//             {
//                 return dis[x][y][z]+1;
//             }
//             if(mp[x1][y1]=='#')
//             {
//                 continue;
//             }

//             if(mp[x1][y1]=='x'&&z==0)
//             {
//                 continue;
//             }           
//             if(mp[x1][y1]=='o'&&z==1)
//             {
//                 continue;
//             }
//             int k=z;
//             if(mp[x1][y1]=='?')
//             {
//                 k=k^1;
//             }
//             if(dis[x][y][z]+1<dis[x1][y1][k])
//             {
//                 q.push(MP(MP(x1,y1),k));
//                 dis[x1][y1][k]=dis[x][y][z]+1;          
//             }

//         }
        
//     }
//     return -1;
// }

// void solve()
// {

//     memset(dis,0x3f,sizeof(dis));
//     cin>>h>>w;
//     string s;
//     for(int i=1;i<=h;i++)
//     {
//         cin>>s;
//         for(int j=0;j<w;j++)
//         {
//             mp[i][j+1]=s[j];
//         }
//     }
//     int ans;
//     for(int i=1;i<=h;i++)
//     {
//         for(int j=1;j<=w;j++)
//         {
//             if(mp[i][j]=='S')
//             {

//                 // printf("{%d %d}",i,j);
//                 dis[i][j][0]=0;
//                 ans=bfs(i,j);
//                 break;
//             }
//         }
//     }
//     cout<<ans<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// E - Reachability Query
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;

// int fa[N];
// int cnt[N];
// bool vis[N];
// void init(int n)
// {
//     for(int i=0;i<=n;i++)
//     {
//         fa[i]=i;
//         cnt[i]=0;
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
// void merge(int x,int y)
// {
//     int fx=find(x);
//     int fy=find(y);
//     if(fx!=fy)
//     {
//         fa[fx]=fy;
//         cnt[fy]+=cnt[fx];
//     }
// }
// void solve()
// {
//     memset(vis,false,sizeof(vis));

//     int n,q;
//     cin>>n>>q;
//     init(n);
//     int op;
//     int u,v;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>op;
//         if(op==1)
//         {
//             cin>>u>>v;
//             merge(u,v);
//         }
//         else if(op==2)
//         {
//             cin>>v;
//             int fx=find(v);
//             if(vis[v])
//             {
//                 vis[v]=false;
//                 cnt[fx]=max(cnt[fx]-1,0);
//             }
//             else if(vis[v]==false)
//             {
//                 vis[v]=true;
//                 cnt[fx]++;
//             }
//         }
//         else if(op==3)
//         {
//             cin>>v;
//             int fx=find(v);
//             if(cnt[fx])
//             {
//                 cout<<"Yes"<<'\n';
//             }
//             else
//             {
//                 cout<<"No"<<'\n';
//             }
//         }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("{%d}",cnt[i]);

//         // }
//         // for(int i=1;i<=n;i++)
//         // {
//         //     printf("<%d>",vis[i]);

//         // }        
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// F - kirinuki
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;

// void solve()
// {

// }
// int main()
// {
//     solve();
//     return 0;
// }



// A - Permute to Maximize
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// int a[4];
// void solve()
// {
//     a[0]=0;
//     for(int i=1;i<=3;i++)
//     {
//         cin>>a[i];
//     }
//     sort(a+1,a+1+3);
//     for(int i=3;i>=1;i--)
//     {
//         cout<<a[i];
//     }
//     cout<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// B - Permute to Minimize
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// int a[10];
// void solve()
// {
//     memset(a,0,sizeof(a));
//     LL n;
//     cin>>n;
//     int tot=0;
//     int cnt=0;
//     while(n!=0)
//     {
//         if(n%10!=0)
//         {
//             tot++;
//             a[tot]=n%10;            
//         }
//         else
//         {
//             cnt++;
//         }
//         n=n/10;
//     }
//     sort(a+1,a+1+tot);
//     for(int i=1;i<=tot;i++)
//     {
//         cout<<a[i];
//         if(i==1)
//         {
//             for(int j=1;j<=cnt;j++)
//             {
//                 cout<<0;
//             }
//         }
//     }
//     cout<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }


// C - Candy Tribulation
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// LL a[N];
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
// void solve()
// {
//     LL n,x,y;
//     cin>>n>>x>>y;
//     LL s=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         s+=a[i];
//     }
//     if(x==y)
//     {
//         cout<<s<<'\n';
//         return;
//     }
//     sort(a+1,a+1+n);
//     LL sum=a[1];
//     LL gd=gcd(x,y);
//     LL mb=x*y/gd;
//     LL xg=mb/x;
//     LL yg=mb/y;
//     LL d=abs(xg-yg);
//     // cout<<xg<<yg<<d<<'\n';
//     for(int i=2;i<=n;i++)
//     {
//         LL dist=a[i]-a[1];
//         if(dist%d!=0)
//         {
//             cout<<-1<<'\n';
//             return;            
//         }

//         if(a[1]-(dist/d)*yg<0)
//         {
//             // printf("{%lld,%lld}",dist,i);
//             cout<<-1<<'\n';
//             return;
//         }
    
//         sum+=a[1]-(dist/d)*yg;
//     }
//     cout<<sum<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }



// D - Suddenly, A Tempest
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;

// void solve()
// {
//     LL n,x,y;
//     cin>>n>>x>>y;
//     for(int i=1;i<=n;i++)
//     {

//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }



// E - Clamp
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=5e5+5;
// #define lc u<<1
// #define rc u<<1|1
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
// void solve()
// {
//     memset(w,0,sizeof(w));
//     LL n,x,y;
//     LL q;
//     cin>>n>>q;
//     LL z;
//     LL maxn=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>z;
//         maxn=max(maxn,z);
//         w[z]++;
//     }
//     build(1,1,maxn);

//     LL l,r;
//     int op;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>op;
//         cin>>l>>r;
//         if(op==1)
//         {
//             LL k1=query(1,l,l);
//             update(1,l,l,k1-1);
//             LL k2=query(1,r,r);
//             update(1,r,r,k2+1);
//         }
//         else
//         {
//             LL sum=0;
//             if(l>=r)
//             {
//                 sum=n*l;
//             }
//             else
//             {
//                 sum+=query(1,l,r);

//             }
//         }
        
//         cout<<query(r)-query(l-1);
//     }

// }
// int main()
// {
//     solve();
//     return 0;
// }



// F - kirinuki
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// #define int long long
// const int N=5e5+5;
// int m;
// int n,s[N],s1[N];
// int lowbit(int x)
// {
//     return x&-x;
// }
// void change(int x,int k)//向后修
// {
//     while(x<=N)
//     {
//         s[x]+=k;
//         x+=lowbit(x);
//     }
// }
// int query(int x)//向前查
// {
//     int t=0;
//     while(x)
//     {
//         t+=s[x];
//         x-=lowbit(x);
//     }
//     return t;
// }
// void change1(int x,int k)//向后修
// {
//     while(x<=N)
//     {
//         s1[x]+=k;
//         x+=lowbit(x);
//     }
// }
// int query1(int x)//向前查
// {
//     int t=0;
//     while(x)
//     {
//         t+=s1[x];
//         x-=lowbit(x);
//     }
//     return t;
// }
// int a[N];
// void solve(){
//     memset(s,0,sizeof(s));
//     memset(s1,0,sizeof(s1));
//     int q;
//     cin>>n>>q;
//     int x;
    
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         m=max(m,a[i]);
//     }
//     vector<int> cnt(N,0);

//     for(int i=1;i<=n;i++){
//         x=a[i];
//         change1(x+1,1);
//         change(x+1,x);    
//     //     for(int i=1;i<=m+10;i++){
//     //     // printf("{%d}",query1(i)-query1(i-1));
//     // }
//     // cout<<'\n';
//     }    
//     // for(int i=1;i<=m+10;i++){
//     //     printf("{%d}",query1(i)-query1(i-1));
//     // }
//     // cout<<'\n';
//     int l,r;
//     int op;
//     for(int i=1;i<=q;i++){
//         cin>>op>>l>>r;
//         if(op==1){
//             x=a[l];
//             m=max(m,a[i]);
//             a[l]=r;
//             change(x+1,-x);
//             change1(x+1,-1);
//             change(r+1,r);    
//             change1(r+1,1);      
//         }
//         else{
//             if(l>=r){
//                 cout<<l*n<<'\n';
//             }
//             else{
//                 int s1=query(r+1);
//                 int s2=query(l);
//                 int s3=query1(l)*l;
//                 int s4=(query1(N)-query1(r+1))*r;
//                 // printf("{%d,%d,%d}",query1(l-1),query1(m+5),query1(r+1));
//                 cout<<s1-s2+s3+s4<<'\n';    
//             }
//         }
//     }
// }
// signed main(){
//     solve();
//     return 0;
// }