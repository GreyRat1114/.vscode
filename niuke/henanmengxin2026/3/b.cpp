#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    string s;
    cin>>s;
    map<LL,LL> mp;
    vector<vector<LL>> c(n+1,vector<LL>(3,0));
    //vector<map<LL,LL>> inv;
    map<LL,map<LL,LL>> inv;
    inv[0][0]=0;
    for(int i=0;i<n;i++){
        mp[s[i]-'0']++;
        c[i+1][0]=c[i][0];
        c[i+1][1]=c[i][1];
        c[i+1][2]=c[i][2];
        c[i+1][s[i]-'0']++;
        if(!inv[c[i+1][0]-c[i+1][1]].count(c[i+1][1]-c[i+1][2]))inv[c[i+1][0]-c[i+1][1]][c[i+1][1]-c[i+1][2]]=i+1;
        //printf("{%lld,%lld,%lld}",c[i+1][0],c[i+1][1],c[i+1][2]);
    }
    //printf("{%lld}",inv[0][0]);
    LL ans=0;
    for(int i=0;i<n;i++){
        LL d1=c[i+1][0]-c[i+1][1];
        LL d2=c[i+1][1]-c[i+1][2];
        auto it1=inv.lower_bound(d1);
        if(it1==inv.end()||it1->first!=d1)continue;
        auto it2=it1->second.lower_bound(d2);
        if(it2==it1->second.end()||it2->first!=d2)continue;
        ans=max(ans,i+1-it2->second);
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