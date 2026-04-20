#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        //s+=a[i];
    }
    sort(a.begin()+1,a.end());
    LL m=unique(a.begin()+1,a.end())-a.begin()-1;
    vector<pair<LL,LL>> cnt(m+1);
    for(int i=1;i<=m;i++){
        cnt[i].first=a[i];
        cnt[i].second=mp[a[i]];
    }
    sort(cnt.begin()+1,cnt.end(),[&](pair<LL,LL> &x,pair<LL,LL> &y){
        return x.second>y.second;
    });
    // for(int i=1;i<=m;i++){
    //     printf("{%lld,%lld}",cnt[i].first,cnt[i].second);
    // }
    LL tag=0;
    vector<LL> ans(2,0);
    for(int i=1;i<=m;i++){
        if((cnt[i].first&1)==0){
            s+=cnt[i].first*cnt[i].second;
            continue;
        }
        ans[tag]+=cnt[i].second;
        tag=tag^1;
        s+=(cnt[i].first-1)*cnt[i].second;
    }
    //printf("{%lld,%lld}",ans[0],ans[1]);
    LL ans1=s/2+ans[0];
    LL ans2=s/2+ans[1];
    cout<<ans1<<' '<<ans2<<'\n';
    //cout<<m<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}