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
double getdist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
map<double,pair<point,point>> a;
double minn;
void dfs(auto it,double dist,double h){
    if(it==a.end()){
        minn=min(minn,dist);
    }
    auto it2=it;
    it2++;

}
void solve(){
    LL n;
    cin>>n;
    a.clear();
    minn=1e9;
    for(int i=1;i<=n;i++){
        LL x;
        cin>>x;
        cin>>a[x].first.x>>a[x].first.y;
        cin>>a[x].second.y>>a[x].second.y;
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}