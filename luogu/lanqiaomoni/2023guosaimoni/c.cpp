#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct node{
    LL x,y;
};
inline LL dist(LL x1,LL y1,LL x2,LL y2){
    LL d1=x1-x2;
    LL d2=y1-y2;
    return d1*d1+d2*d2;
}
void solve(){
    LL n;
    cin>>n;
    LL x,y;
    vector<node> a(n+1);
    map<pair<LL,LL>,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a[i]={x,y};
        mp[{2*x,2*y}]++;
    }
    // vector<map<LL,LL>> cnt(n+1);
    map<LL,LL> cnt;
    LL ans=0;
    for(int i=1;i<=n;i++){
        cnt.clear();
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            LL d=dist(a[i].x,a[i].y,a[j].x,a[j].y);
            ans+=cnt[d];
            cnt[d]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            LL x1=a[i].x+a[j].x;
            LL y1=a[i].y+a[j].y;
            if((x1%2==0)&&(y1%2==0)){
                //printf("{%lld,%lld}",x1,y1);
                ans-=mp[{x1,y1}];
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