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
point dline(point a,point b){//垂直平分线
    point dl=a-b;
    return {-dl.y,dl.x};
}