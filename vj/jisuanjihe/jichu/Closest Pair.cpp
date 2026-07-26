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
bool cmp(point a,point b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
double minn;
point ans1,ans2;
void upd_ans(point a,point b){
    double dist=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    if(dist<minn){
        minn=dist;
        ans1=a;
        ans2=b;
    }
}
void solve(LL n){
    minn=1e18;
    multiset<pair<double,point>> st;
    vector<point> a(n+1);
    for(int i=1;i<=n;i++){
        double x,y;
        cin>>x>>y;
        a[i]={x,y};
    }
    sort(a.begin()+1,a.end(),cmp);
    LL l=1;
    for(int i=1;i<=n;i++){
        while((a[i].x-a[l].x)*(a[i].x-a[l].x)>minn){
            st.erase(st.find({a[l].y,a[l]}));
            l++;
            if(l==i)break;
        }
        auto it=st.lower_bound({a[i].y-sqrt(minn)+1e-6,point()});
        for(;it!=st.end()&&(it->first-a[i].y)*(it->first-a[i].y)<minn;it++){
            upd_ans(it->second,a[i]);
        }
        st.insert({a[i].y,a[i]});

    }
    cout<<setprecision(2)<<fixed<<ans1.x<<' '<<ans1.y<<' '<<ans2.x<<' '<<ans2.y<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(1){
        LL n;
        cin>>n;
        if(n==0)break;
        solve(n);
    }
    return 0;
}