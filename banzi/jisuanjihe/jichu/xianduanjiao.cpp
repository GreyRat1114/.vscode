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
double cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
LL check(point a,point b,point c,point d){
    if(cross(d-a,b-a)*cross(b-a,c-a)>=0&&cross(a-c,d-c)*cross(d-c,b-c)>=0){
        return 1;
    }else{
        return 0;
    }
}
//判断两个线段是否相交