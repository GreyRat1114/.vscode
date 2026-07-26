#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ld=long double;
const ld pi=acos(-1);
struct point{
    ld x,y,z;
    bool operator < (const point& a) const{
        if(x!=a.x)return x<a.x;
        return y<a.y;
    }
    bool operator == (const point& a) const{
        return x==a.x&&y==a.y&&z==a.z;
    }
    point operator + (const point&a) const {
        return {x+a.x,y+a.y,z+a.z};
    }
    point operator - (const point&a) const{
        return {x-a.x,y-a.y,z-a.z};
    }
};
point cross(point a,point b){
    point c;
    c.x=a.y*b.z-a.z*b.y;
    c.y=a.z*b.x-a.x*b.z;
    c.z=a.x*b.y-a.y*b.x;
    return c;
}
ld cheng(point a,point b){
    ld ans=a.x*b.x+a.y*b.y+a.z*b.z;
    return ans;
}
ld mol(point a){
    ld ans=sqrtl(a.x*a.x+a.y*a.y+a.z*a.z);
    return ans;
}
ld clamp(ld x){
    if(x>1)return 1;
    if(x<-1)return -1;
    return x;
}
void solve(){
    point home,s,t;
    ld r;
    cin>>r>>home.x>>home.y>>home.z;
    cin>>s.x>>s.y>>s.z;
    cin>>t.x>>t.y>>t.z;
    point p1=cross(s,t);
    point t0={0,0,0};
    point t2=t0-t;

    if(cheng(cross(p1,s),home)>0&&cheng(cross(p1,t),home)<0){
        
        ld sina=cheng(home,p1)/(mol(home)*mol(p1));
        ld alpha=asin(sina);
        ld d=abs(alpha*r);   
        cout<<fixed<<setprecision(20)<<d<<'\n';     

    }else{
        ld coss=clamp(cheng(home,s)/(mol(home)*mol(s)));
        ld cost=clamp(cheng(home,t)/(mol(home)*mol(t)));
        ld ss=acos(coss);
        ld tt=acos(cost);
        ld d1=abs(ss*r);
        ld d2=abs(tt*r);   
        cout<<fixed<<setprecision(20)<<min(d1,d2)<<'\n';       
    }
    // point a={4.0,5.0,6.0};
    // point b={4.0,5.0,6.0};
    // point ans=cross(a,b);
    // printf("{%lf,%lf,%lf}",(double)ans.x,(double)ans.y,(double)ans.z);

}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
