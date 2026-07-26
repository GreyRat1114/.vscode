#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(n+1,0);
    map<LL,pair<LL,LL>> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[i]={0,1e10};
    }
    for(int i=1;i<=q;i++){
        LL p,l,r;
        cin>>p>>l>>r;
        mp[p].first=max(mp[p].first,l);
        mp[p].second=min(mp[p].second,r);
    }
    LL ans=0;
    for(auto x:mp){
        LL id=x.first;
        LL l=x.second.first;
        LL r=x.second.second;
        if(l>r){
            cout<<-1<<'\n';
            return;
        }
        //if(l==0&&r==1e10)continue;
        if(a[id]<l){
            ans+=l-a[id];
        }else if(a[id]>r){
            ans+=a[id]-r;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}