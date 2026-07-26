#include<bits/stdc++.h>
using namespace std;
using LL=long long;
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
struct point2{
    point p1,p2;
};
double cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
LL cross(point a,point b,point c){
    return cross(b-a,c-a);
}
void solve(){
    LL n;
    cin>>n;
    vector<point> a;
    vector<point2> b(n+1);
    for(int i=1;i<=n;i++){
        point p1,p2;
        cin>>p1.x>>p1.y>>p2.x>>p2.y;
        b[i]={p1,p2};
        a.push_back(p1);
        a.push_back(p2);
    }
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
            if(a[i]==a[j]){
                //printf("{%lf,%lf}",a[i].x,a[i].y);
                continue;
            }
            if(i==j)continue;
            LL cnt=0;
            for(int k=1;k<=n;k++){
                point p1=a[i]-a[j];
                point p2=b[k].p1-a[i];
                point p3=b[k].p2-a[i];
                if(cross(p1,p2)*cross(p1,p3)<=0){
                    cnt++;
                }
            }
            if(cnt==n){
                cout<<"Yes!"<<'\n';
                return;
            }
        }
    }
    cout<<"No!"<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}