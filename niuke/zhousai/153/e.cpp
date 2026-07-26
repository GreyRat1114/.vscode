#include<bits/stdc++.h>
using namespace std;
using LL=long long;
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
    point operator * (LL k) const {
        return {x*k,y*k};
    }      
    point operator / (LL k) const {
        return {x/k,y/k};
    }    
};
double dot(point a,point b){
    return a.x*b.x+a.y*b.y;
}
LL cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
void solve(){
    LL n;
    cin>>n;
    vector<point> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            point p1=a[i]-a[j];
            LL c1=0,c2=0;
            for(int k=1;k<=n;k++){
                if(k==i||k==j)continue;
                point p2=a[k]-a[j];
                if(cross(p1,p2)<0){
                    c1++;
                }else if(cross(p1,p2)>0){
                    c2++;
                }
            }
            if(c1==c2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}