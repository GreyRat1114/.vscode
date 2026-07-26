#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct point{
    LL x,y;
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
LL cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
LL cross(point a,point b,point c){
    return cross(b-a,c-a);
}
bool cmp(vector<point> a,vector<point> b){
    if(a[0].x==b[0].x){
        return a[0].y<b[0].y;
    }
    return a[0].x<b[0].x;

}
void solve(){
    LL n,m;
    point l,r;
    while(1){
        cin>>n;
        if(n==0)break;
        cin>>m>>l.x>>l.y>>r.x>>r.y;
        //cout<<n<<m;
        vector<vector<point>> a(n+2,vector<point>(2));
        a[0][0]={l.x,l.y};
        a[0][1]={l.x,r.y};
        a[n+1][0]={r.x,l.y};
        a[n+1][1]={r.x,r.y};
        for(int i=1;i<=n;i++){
            LL u,v;
            cin>>u>>v;
            //printf("{%lld,%lld}",u,v);
            a[i][0]={u,l.y};
            a[i][1]={v,r.y};
        }
        sort(a.begin(),a.end(),cmp);
        vector<LL> ans(n+2,0);
        for(int i=1;i<=m;i++){
            LL x,y;
            cin>>x>>y;
            for(int j=1;j<=n+1;j++){
                point p1={x-a[j-1][0].x,y-a[j-1][0].y};
                point p2={x-a[j][0].x,y-a[j][0].y};
                //printf("{%lld,%lld}",p2.x,p2.y);
                point p3={a[j-1][0].x-a[j-1][1].x,a[j-1][0].y-a[j-1][1].y};
                point p4={a[j][0].x-a[j][1].x,a[j][0].y-a[j][1].y};
                //printf("{%d,%d}{%lld,%lld|%lld,%lld|%lld,%lld|%lld,%lld}",i,j,p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y);
                if((cross(p3,p1)<0)&&(cross(p4,p2)>0)){
                    //printf("{%lld,%lld,%lld,%lld}",i,j,cross(p3,p1),cross(p4,p2));
                    ans[j]++;
                    
                }
            }
        }
        for(int i=1;i<=n+1;i++){
            printf("%d: %lld\n",i-1,ans[i]);
        }
        cout<<'\n';

    }

}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}