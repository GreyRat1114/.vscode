#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+10;
bool cmp(pair<LL,LL> a,pair<LL,LL> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
void solve(){
    LL n;
    cin>>n;
    vector<pair<LL,LL>> a(n+1);
    for(int i=1;i<=n;i++){
        LL t,x;
        cin>>t>>x;
        // cin>>t[i]>>x[i];
        a[i]={t+x,t-x};
    }
    vector<LL> dp;
    sort(a.begin()+1,a.begin()+1+n,cmp);
    for(int i=1;i<=n;i++){
        auto it=lower_bound(dp.begin(),dp.end(),a[n-i+1].second);
        if(it==dp.end()){
            dp.push_back(a[n-i+1].second);
        }else{
            dp[it-dp.begin()]=a[n-i+1].second;
        }
    }
    cout<<dp.size()<<'\n';
}
int main(){
    LL t=1;
    while(t--){
        solve();
    }
    return 0;
}