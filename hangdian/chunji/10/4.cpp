#include<bits/stdc++.h>
using namespace std;
using LL=long long;
bool cmp(pair<LL,LL> a,pair<LL,LL> b ){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
void solve(){
    LL L,n,m;
    cin>>L>>n>>m;
    vector<pair<LL,LL>> cp(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        LL l,r;
        cin>>l>>r;
        cp[i]={l,r};
    }
    vector<LL> a(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    LL tot=0;
    for(int i=1;i<=n;i++){
        LL l=cp[i].first;
        LL r=cp[i].second;
        auto pos=lower_bound(a.begin()+1,a.end(),l);
        if(pos==a.end())continue;
        if((*pos)<=r){
            tot++;
            cp[tot]={l,r};
            mp[r]=tot;
        }
    }
    if(tot==0){
        cout<<0<<'\n';
        return;
    }
    sort(cp.begin()+1,cp.begin()+1+tot,cmp);
    vector<LL> dp(2*tot,0);
    dp[0]=0;    
    mp[cp[1].second]=1;
    dp[1]=cp[1].second-cp[1].first+1;
    for(int i=2;i<=tot;i++){
        LL r=cp[i].second;
        LL l=cp[i].first;
        auto it=mp.lower_bound(l);
        if(it==mp.begin()){
            dp[i]=r-l+1;
        }else{
            it--;
            dp[i]=max(dp[i],dp[it->second]+r-l+1);
        }
        dp[i]=max(dp[i],dp[i-1]);

        mp[r]=i;
    }
    cout<<dp[tot]<<'\n';


}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}