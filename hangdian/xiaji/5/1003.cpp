#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
struct point{
    LL x,y;
    LL v;
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
struct node{
    LL x,y;
    LL id;
};
LL cross(point a,point b){
    return a.x*b.y-a.y*b.x;
}
LL cross(point a,point b,point c){
    return cross(b-a,c-a);
}

LL tot=0;
vector<point> p;
LL n;
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
void work(){
    
}
void solve(){
    cin>>n;
    p.resize(n+1);
    vector<node> q;

    vector<vector<LL>> dp(n+1,vector<LL>(n+1,0));
    for(int i=1;i<=n;i++){
        LL x,y,t;
        cin>>x>>y>>t;
        p[i]={x,y,t};
        q.push_back({x,y,i});
        // q[i]={x,y,i};
    }
    sort(p.begin()+1,p.begin()+n);
    for(int s=1;s<=n;s++){
        for(int b=s+1;b<=n;b++){
            o=p[b];
            sort(q.begin(),q.end(),cmp);
            vector<node> vec=q;
            for(int a=b+1;a<=n;a++){

            }
        }
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}