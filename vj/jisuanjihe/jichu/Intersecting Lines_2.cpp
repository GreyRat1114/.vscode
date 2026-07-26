#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const double eps=0.0000001;
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
    point operator * (const double&a) const{
        return {x*a,y*a};
    }    
    point operator / (const double&a) const{
        return {x/a,y/a};
    }     
};
double cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
LL cross(point a,point b,point c){
    return cross(b-a,c-a);
}

void solve(){
    cout<<"INTERSECTING LINES OUTPUT"<<'\n';
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++){
        double x1,x2,x3,x4;
        double y1,y2,y3,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        point p1={x1-x2,y1-y2};
        point p2={x3-x4,y3-y4};
        point p3={x1-x3,y1-y3};
        if(abs(cross(p1,p2))<eps){
            if(abs(cross(p3,p2))<eps){
                cout<<"LINE"<<'\n';
            }else{
                cout<<"NONE"<<'\n';
            }
        }else{
            point pos1={x2,y2};
            point pos2={x4,y4};
            double t=(cross(pos2-pos1,p2))/(cross(p1,p2));
            //printf("{%lf}",t);
            point ans=pos1+p1*t;
            cout<<"POINT"<<setprecision(2)<<fixed<<' '<<ans.x<<' '<<ans.y<<'\n';
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