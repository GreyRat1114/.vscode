#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
struct point{
    i128 x,y;
    bool operator < (const point& a) const{
        if(x!=a.x)return x<a.x;
        return y<a.y;
    }
    bool operator == (const point& a) const{
        return x==a.x&&y==a.y;
    }
    point operator + (const point&a) const {
        return {x+a.x,y+a.y};
    }
    point operator - (const point&a) const{
        return {x-a.x,y-a.y};
    }
};
vector<point> a;
vector<i128> s;
vector<i128> s2;
LL n,k;

i128 cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
void gets1(){
    i128 pre=0;
    for(int i=2;i<=k+1;i++){
        pre+=cross(a[i-1],a[i]);
    }
    pre+=cross(a[k+1],a[1]);
    i128 lst=cross(a[k+1],a[1]);
    s[1]=pre;
    for(int i=2;i<=n;i++){
        pre-=lst;
        pre+=cross(a[i+k-1],a[i+k]);
        pre-=cross(a[i-1],a[i]);
        pre+=cross(a[i+k],a[i]);
        // printf("{%lld,%lld;%lld,%lld}",a[i+k-1].x,a[i+k-1].y,a[i+k].x,a[i+k].y);
        // printf("{%lld,%lld,%lld}",lst,cross(a[i+k-1],a[i+k]),cross(a[i-1],a[i]));
        s[i]=pre;
        lst=cross(a[i+k],a[i]);
    }
}
void gets2(){
    LL pos=k+2;
    for(int i=1;i<=n;i++){
        LL l=i+k+1;
        LL r=i+n-1;
        point cur=a[i]-a[i+k];
        pos=min(r,pos);
        pos=max(l,pos);        
        while(pos+1<=r&&cross(a[pos+1]-a[i+k],cur)>cross(a[pos]-a[i+k],cur)){
            pos++;
            if(pos>=2*n)break;
        }        
        if(pos>=2*n)break;

        s2[i]=cross(a[pos]-a[i+k],cur);
    }

}
void solve(){
    cin>>n>>k;
    a.resize(3*n+1);
    s.assign(3*n+1,0);
    s2.assign(3*n+1,0);
    //a[0]={0,0};
    for(int i=1;i<=n;i++){
        LL x,y;
        cin>>x>>y;
        a[i].x=x;
        a[i].y=y;
        a[i+n]=a[i];
        a[i+2*n]=a[i+n];
    }
    // for(int i=1;i<=2*n;i++){
    //     printf("{%lld,%lld}",a[i].x,a[i].y);
    // }
    gets1();
    gets2();
    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",s2[i]);
    // }
    double ans=0;
    for(int i=1;i<=n;i++){
        double ss=(double)s[i]/2+(double)s2[i]/2;
        //printf("{%lf}",ss);
        ans=max(ans,ss);
    }
    cout<<fixed<<setprecision(20)<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}