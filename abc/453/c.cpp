#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> l;
LL n;
LL ans;
void dfs(double p,LL cnt,LL i){
    //printf("{%lld,%lld,%lld}",p,cnt,i);
    if(i==n){
        ans=max(ans,cnt);
        return;
    }
    i++;
    double p1=p-l[i];
    double p2=p+l[i];
    LL cnt1=cnt;
    LL cnt2=cnt;
    if(p>0&&p1<0)cnt1++;
    if(p<0&&p2>0)cnt2++;
    dfs(p1,cnt1,i);
    dfs(p2,cnt2,i);
}
void solve(){
    ans=0;
    cin>>n;
    l.resize(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    dfs(0.5,0,0);
    cout<<ans<<'\n';

}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}