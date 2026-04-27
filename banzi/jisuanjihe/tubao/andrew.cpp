//P2742圈奶牛
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
double cross(point a,point b,point c){
    return cross(b-a,c-a);
}
LL tot=0;
vector<point> p;
vector<LL> stk;
LL n;
void andrew(){
    tot++;
    stk.resize(2*n+5);
    stk[1]=1;
    for(int i=2;i<=n;i++){
        while(tot>=2&&cross(p[stk[tot-1]],p[stk[tot]],p[i])<=0){
            tot--;
        }
        tot++;
        stk[tot]=i;
    }
    LL m=tot;
    for(int i=n-1;i>=1;i--){
        while(tot>=m+1&&cross(p[stk[tot-1]],p[stk[tot]],p[i])<=0){
            tot--;
        }
        tot++;
        stk[tot]=i;
    }
    stk.resize(tot+1);
}
void solve(){
    cin>>n;
    p.resize(n+1);
    tot=0;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }    
    sort(p.begin()+1,p.end());
    n=unique(p.begin()+1,p.end())-p.begin()-1;
    andrew();
    double ans=0;
    
    for(int i=2;i<=tot;i++){
        double dx=1.0*(p[stk[i]].x-p[stk[i-1]].x)*(p[stk[i]].x-p[stk[i-1]].x);
        double dy=1.0*(p[stk[i]].y-p[stk[i-1]].y)*(p[stk[i]].y-p[stk[i-1]].y);
        ans+=sqrt(dx+dy);
    }
    cout<<fixed<<setprecision(2)<<ans<<'\n';
    //cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}