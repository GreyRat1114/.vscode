#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const double eps=0.000000001;
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
};
double cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
LL cross(point a,point b,point c){
    return cross(b-a,c-a);
}
double getk(LL x1,LL y1,LL x2,LL y2){
    double ans=1.0*(y2-y1)/(x2-x1);
    return ans;
}
double getb(LL x1,LL y1,LL x2,LL y2){
    double ans=1.0*(x2*y1-x1*y2)/(x2-x1);
    return ans;
}
void solve(){
    cout<<"INTERSECTING LINES OUTPUT"<<'\n';
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++){
        LL x1,x2,x3,x4;
        LL y1,y2,y3,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        double k1=getk(x1,y1,x2,y2);
        double k2=getk(x3,y3,x4,y4);
        double b1=getb(x1,y1,x2,y2);
        double b2=getb(x3,y3,x4,y4);
        printf("{%lf,%lf,%lf,%lf}",k1,k2,b1,b2);
        LL tagk=0,tagb=0;
        if(abs(k1-k2)<eps){
            tagk=1;
        }
        if(abs(b1-b2)<eps){
            tagb=1;
        }       
        if(tagk&&tagb){
            cout<<"LINE"<<'\n';
        }else if(tagk){
            cout<<"NONE"<<'\n';
        }else{
            double x=(b2-b1)/(k1-k2);
            double y=k1*x+b1;
            cout<<"POINT"<<' '<<x<<' '<<y<<'\n';
        }

    }
    cout<<"END OF OUTPUT"<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}