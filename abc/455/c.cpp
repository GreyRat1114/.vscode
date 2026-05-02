#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    LL ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]+=a[i];
        ans+=a[i];
    }
    LL cnt=0;
    priority_queue<LL> q;
    for(auto x:mp){
        q.push(x.second);
    }
    while(!q.empty()){
        cnt++;
        ans-=q.top();
        q.pop();
        if(cnt==k)break;
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