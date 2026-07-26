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
void solve(){
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++){
        
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}