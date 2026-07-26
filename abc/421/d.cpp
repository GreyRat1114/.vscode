#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ld=long double;
struct point{
    LL x,y;
};
void solve(){
    point t,a;
    cin>>t.x>>t.y>>a.x>>a.y;
    LL n,m,l;
    cin>>n>>m>>l;
    vector<pair<LL,LL>> cp1,cp2;
    for(int i=1;i<=m;i++){
        cin>>cp1[i].first>>cp1[i].second;
    }

    for(int i=1;i<=l;i++){
        cin>>cp2[i].first>>cp2[i].second;
    }   
    point p1=t,p2=a;
    

}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}