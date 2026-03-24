#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    LL n,ax,ay,bx,by;
    cin>>n>>ax>>ay>>bx>>by;
    LL x,y;
    vector<pair<LL,LL>> pos(n+2);
    map<LL,set<LL>> p2;
    vector<LL> inv(n+1);
    map<LL,pair<LL,LL>> dp;
    pos[0]=mp(ax,ay);
    for(int i=1;i<=n;i++){
        cin>>x;
        pos[i].first=x;
    }
    for(int i=1;i<=n;i++){
        cin>>y;
        pos[i].second=y;     
    }
    pos[n+1]=mp(bx,by);
    
    sort(pos.begin()+1,pos.end());
    for(int i=0;i<=n+1;i++){
        p2[pos[i].first].insert(pos[i].second);
    }
    int tot=0;
    dp[0]=mp(0,0);
    LL x0=ax;
    LL maxy0=ay;
    LL miny0=ay;
    for(auto it:p2){
        tot++;

        LL x1=it.first;
        LL maxy=*(it.second.rbegin());
        LL miny=*(it.second.begin());
        LL d=maxy-miny;
        dp[tot].first=min(dp[tot-1].first+d+abs(miny-maxy0)+x1-x0,dp[tot-1].second+d+abs(miny-miny0)+x1-x0);
        dp[tot].second=min(dp[tot-1].first+d+abs(maxy-maxy0)+x1-x0,dp[tot-1].second+d+abs(maxy-miny0)+x1-x0);
        x0=x1;
        maxy0=maxy;
        miny0=miny;
        //printf("%lld,%lld,%lld\n",x1,dp[tot].first,dp[tot].second);
    }
    cout<<dp[tot].first<<'\n';
    //printf("{%lld,%lld}\n",dp[tot].first,dp[tot].second);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}