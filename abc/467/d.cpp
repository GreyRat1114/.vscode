#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ld=long double;
const ld eps=1e-19;
struct point{
    ld x,y;
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
    point operator * (ld k) const {
        return {x*k,y*k};
    }      
    point operator / (ld k) const {
        return {x/k,y/k};
    }    
};
ld dot(point a,point b){
    return a.x*b.x+a.y*b.y;
}
ld cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
point dline(point a,point b){//垂直平分线
    point dl=a-b;
    return {-dl.y,dl.x};
}
void solve(){
    point p,q,r,s;
    LL px,py,qx,qy,rx,ry,sx,sy;
    cin>>px>>py>>qx>>qy>>rx>>ry>>sx>>sy;
    p={1.0*px,1.0*py};
    q={1.0*qx,1.0*qy};
    r={1.0*rx,1.0*ry};
    s={1.0*sx,1.0*sy};
    point dl1=dline(p,q);
    point dl2=dline(r,s);
    //point dd=dline({1.0,0.0},{0.0,2.0});
    //printf("{%lf,%lf}",dd.x,dd.y);
    point p1=(p+q)/2;
    point p2=(r+s)/2;
    point d=p1-p2;
    //cout<<eps<<'\n';
    if((cross(dl1,dl2)!=0)||(dot(d,(p1-q))==0)){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}