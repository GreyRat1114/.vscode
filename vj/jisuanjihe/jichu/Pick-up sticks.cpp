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
void solve(){
    LL n;
    while(1){
        cin>>n;
        if(n==0)break;
        vector<vector<point>> a(n+1,vector<point>(2));
        set<LL> st;
        for(int i=1;i<=n;i++){
            st.insert(i);
            double x,y;
            cin>>x>>y;
            a[i][0]={x,y};
            cin>>x>>y;
            a[i][1]={x,y};
            queue<LL> q;
            for(auto t:st){
                if(check(a[t][0],a[t][1],a[i][0],a[i][1]))q.push(t);
            }
            while(!q.empty()){
                st.erase(q.front());
                q.pop();
            }
            st.insert(i);
        }
        cout<<"Top sticks: ";
        LL tot=0;
        
        for(auto t:st){
            if(tot==0){
                tot=1;
                cout<<t;
                continue;
            }
            cout<<", "<<t;
        }
        cout<<'.';
        cout<<'\n';        
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