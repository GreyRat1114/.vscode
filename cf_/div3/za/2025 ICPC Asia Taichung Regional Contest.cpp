



// E. Number Maze
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// void solve(){
//     int n,k,j;
//     cin>>n>>j>>k;
//     vector<vector<int>> a={{12,21},{123,132,213,231,312,321},{1234,1243,1324,1342,1423,1432,2134,2143,2314,2341,2413,2431,3124,3142,3214,3241,3412,3421,4123,4132,4213,4231,4312,4321}};
//     map<int,int> mp;
//     mp[12]=0;
//     mp[123]=1;
//     mp[1234]=2;
//     int m=mp[n];
//     int x=a[m][j-1];
//     int y=a[m][k-1];
//     int cnt=0;
//     while(x!=0){
//         if(x%10==y%10){
//             cnt++;
//         }
//         x/=10;
//         y/=10;
//     }
//     cout<<cnt<<'A'<<m+2-cnt<<'B'<<'\n';
//     // cout<<x<<' '<<y<<'\n';
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }


// I. Birthday
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+10;
// const long double pi=acos(-1.0);
// #define int long long
// struct Node{
//     int x;
//     int y;
// }p[N],s[N];
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
//     n=t;
//     // cout<<'\n';

// }
// void solve(){
//     long double r;
//     cin>>n>>r;

//     for(int i=1;i<=n;i++){
//         cin>>p[i].x;
//         cin>>p[i].y;

//     }
//     if(n==1||n==2)
//     {
//         cout<<setprecision(10)<<fixed<<1LL*pi*r*r/2.0<<'\n';
//         return;
//     }    
//     Andrew();

//     long double x1,x2;
//     long double y1,y2;
//     long double a,b,c,d,cc;
//     long double minn=1e18;
//     long double maxn=0.0;
//     for(int i=2;i<=n;i++)
//     {
//         x1=1.0*s[i-1].x;
//         y1=1.0*s[i-1].y;
//         x2=1.0*s[i].x;
//         y2=1.0*s[i].y;
//         a=y1-y2;
//         b=x2-x1;
//         c=x1*y2-x2*y1;
//         cc=abs(c);
//         d=1.0*cc/sqrt(a*a+b*b);
//         if(check({0,0},s[i-1],{0,0},s[i])>=0)
//         {
//             long double cs=d/r;
//             long double sn=sqrt(1-cs*cs);
//             long double sita=acos(cs);
//             // printf("{%lf}",2*sita);
//             long double s1=(1LL*pi*r*r)*((2*sita)/(2*pi));
//             long double s2=1LL*r*sn*d;
//             long double s3=s2-s1;
//             long double s4=1ll*pi*r*r-s3;
//             minn=min(s3,s4);
//             maxn=max(maxn,s1-s2);
//         }
//         else
//         {
//             cout<<setprecision(10)<<fixed<<1LL*pi*r*r/2.0<<'\n';
//             return;
//         }

//         // cout<<d<<'\n';

//     }
//     // cout<<'\n';
//     cout<<setprecision(10)<<fixed<<maxn<<'\n';
// }
// signed main(){
//     solve();
//     return 0;
// }


// M. Maximum Distance To Port
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+5;
// #define mp make_pair
// vector<int> e[N];
// int kx[N];
// bool vis[N];
// int dist[N];
// void dijkstra(int s){
//     memset(dist,0x3f,sizeof(dist));
//     priority_queue<pair<int,int>> q;
//     q.push(mp(0,s));
//     vis[s]=true;
//     dist[s]=0;
//     while(!q.empty()){
//         int u=q.top().second;
//         q.pop();
//         vis[u]=false;
//         for(int v:e[u]){
//             if(dist[u]+1<dist[v])
//             {
//                 dist[v]=dist[u]+1;
//                 if(vis[v]==false)
//                 {
//                     q.push(mp(-dist[v],v));
//                     vis[v]=true;
//                 }
//             }
//         }
//     }
// }
// void solve(){
//     memset(vis,false,sizeof(vis));
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<int> kx(n+10);
//     vector<int> ans(k+10); 
//     for(int i=1;i<=n;i++){
//         cin>>kx[i];
//     }
//     int u,v;
//     for(int i=1;i<=m;i++){
//         cin>>u>>v;
//         e[u].push_back(v);
//         e[v].push_back(u);
//     }
//     dijkstra(1);
//     for(int i=1;i<=n;i++){
//         int kk=kx[i];
//         ans[kk]=max(ans[kk],dist[i]);

//     }
//     for(int i=1;i<=k;i++){
//         cout<<ans[i]<<' ';
//     }
// }
// int main(){
//     solve();
//     return 0;
// }



// F. Cluster Computing System
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
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
// LL f[N][25];
// void solve(){
//     int n,q;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>f[i][0];
//     }
//     for(int j=1;j<=20;j++){
//         for(int i=1;i+(1<<j)-1<=n;i++){
//             f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//         }
//     }
//     LL l=1,r=n;
//     LL k=log2(r-l+1);
//     LL sum=gcd(f[l][k],f[r-(1<<k)+1][k]);
//     for(int i=2;i<=n-1;i++){
//         l=1,r=i;
//         k=log2(r-l+1);
//         LL s1=gcd(f[l][k],f[r-(1<<k)+1][k]);
//         l=i,r=n;
//         LL k=log2(r-l+1);
//         LL s2=gcd(f[l][k],f[r-(1<<k)+1][k]);
//         sum+=min(s1,s2);
//     }
//     cout<<sum<<'\n';
// }
// int main(){
//     solve();
//     return 0;
// }


// B. Buses
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
struct node{
    int s,t;
    int num;
}line[N];
int p[N];
bool cmp(node a,node b)
{
    return a.s<b.s;
}
void solve(){
    int n,m,l,x,y;
    cin>>n>>m>>l>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>line[i].s>>line[i].t;
        line[i].num=i;
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    sort(line+1,line+1+n,cmp);
    for(int i=1;i<=m;i++){

    }
}
int main(){
    solve();
    return 0;
}