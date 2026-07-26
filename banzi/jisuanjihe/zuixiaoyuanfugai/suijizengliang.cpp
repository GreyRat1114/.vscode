#include<bits/stdc++.h>
using namespace std;
using LL=long long;;
const double eps=1e-9;
struct point{
    double x,y;
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
    point operator * (double k) const {
        return {x*k,y*k};
    }      
    point operator / (double k) const {
        return {x/k,y/k};
    }    
};
struct circle{
    point o;
    double r;
    circle(){}
    circle(point _o,double _r):o(_o),r(_r){}
};
double dot(point a,point b){
    return a.x*b.x+a.y*b.y;
}
double cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
double cross(point a,point b,point c){
    return cross(b-a,c-a);
}
double norm2(point a){
    return dot(a,a);
}
double dist(point a,point b){
    return sqrt(norm2(a-b));
}
double dist2(point a,point b){
    return norm2(a-b);
}
bool incircle(circle c,point p){
    return dist2(c.o,p)<=(c.r+eps)*(c.r+eps);
}
circle circle1(point a){
    return circle(a,0);
}
circle circle2(point a,point b){
    point o=(a+b)/2.0;
    return circle(o,dist(a,b)/2.0);
}
circle circle3(point a,point b,point c){
    double d=2.0*cross(b-a,c-a);
    if(fabs(d)<eps){
        circle c1=circle2(a,b);
        circle c2=circle2(a,c);
        circle c3=circle2(b,c);
        circle ans=c1;
        if(c2.r>ans.r)ans=c2;
        if(c3.r>ans.r)ans=c3;
        return ans;
    }
    double aa=norm2(a);
    double bb=norm2(b);
    double cc=norm2(c);
    point o;
    o.x = (aa * (b.y - c.y) + bb * (c.y - a.y) + cc * (a.y - b.y)) / d;
    o.y = (aa * (c.x - b.x) + bb * (a.x - c.x) + cc * (b.x - a.x)) / d;
    return circle(o,dist(o,a));
}
LL n;
circle work(vector<point> &a){
    random_device rd;
    mt19937 rng(rd());
    shuffle(a.begin()+1,a.begin()+n+1,rng);//随机打乱

    circle c({0,0},-1);
    for(int i=1;i<=n;i++){
        if(c.r<0||!incircle(c,a[i])){
            c=circle1(a[i]);
            for(int j=1;j<i;j++){
                if(!incircle(c,a[j])){
                    c=circle2(a[i],a[j]);
                    for(int k=1;k<j;k++){
                        if(!incircle(c,a[k])){
                            c=circle3(a[i],a[j],a[k]);
                        }
                    }
                }
            }
        }

    }
    return c;
}
void solve(){
    vector<point> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    circle ans=work(a);
    double x=ans.o.x;
    double y=ans.o.y;
    double r=ans.r;
    cout<<fixed<<setprecision(2)<<x<<' '<<y<<' '<<r<<'\n';
}
int main(){
    int t=1;
    while(1){
        cin>>n;
        if(n==0)break;
        solve();
    }
    return 0;
}