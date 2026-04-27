#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
struct point{
    LL x,y;
    bool operator < (const point& a) const{
        if(x!=a.x)return x<a.x;
        return y<a.y;
    }
    bool operator == (const point& a) const{
        return x==a.x&&y==a.y;
    }
    point operator + (const point& a) const {
        return {x+a.x,y+a.y};
    }
    point operator - (const point& a) const{
        return {x-a.x,y-a.y};
    }
};
LL n;
LL xc,yc,R;
point c;
vector<point> p;
LL cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
LL cross(point a,point b,point c){
    return cross(b-a,c-a);
}
LL cross128(point a,point b){
    return (i128)a.x*b.y-(i128)a.y*b.x;
}
LL check(point a, point b){
    point ca=a-c;
    point cb=b-c;
    i128 s=cross128(ca,cb);
    i128 dx=(i128)a.x-b.x;
    i128 dy=(i128)a.y-b.y;
    i128 len=dx*dx+dy*dy;
    return s>0&&s*s>=(i128)R*R*len;
}

LL work(){
    LL l=1,r=2;
    LL s=0;
    LL ans=0;
    while(r<=2*n&&l<=n){
        // if (r >= l + n) {
        //     s -= abs(cross(p[r - 1] - p[l], p[r - 1] - p[l + 1]));
        //     l++;
        //     continue;
        // }
        if(check(p[l],p[r])){
            s+=abs(cross(p[r]-p[l],p[r-1]-p[l]));
            //printf("{%lld,%lld,1}",l,r);
            r++;
        }else{
            s-=abs(cross(p[r-1]-p[l],p[r-1]-p[l+1]));
            //printf("{%lld,%lld,0}",l,r);
            l++;
        }
        //printf("{%lf}",s);
        ans=max(ans,s);
        
    }
    return ans;
}
void solve(){
    cin>>n;
    cin>>c.x>>c.y>>R;
    p.resize(2*n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    for(int i=1;i<=n;i++){
        p[i+n]=p[i];
    }
    LL ans=work();
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}