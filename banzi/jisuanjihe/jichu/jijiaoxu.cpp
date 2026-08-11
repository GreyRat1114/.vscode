#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const double eps = 1e-9;
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
point o;
bool cmp(const point &a,const point &b){
    double anglea=atan2(a.y-o.y,a.x-o.x);
    double angleb=atan2(b.y-o.y,b.x-o.x);
    if(anglea!=angleb){
        return anglea<angleb;
    }
    LL da=(a.x-o.x)*(a.x-o.x)+(a.y-o.y)*(a.y-o.y);
    LL db=(b.x-o.x)*(b.x-o.x)+(b.y-o.y)*(b.y-o.y);
    return da<db;
}
int main(){
    return 0;
}