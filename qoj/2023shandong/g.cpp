#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    map<LL,priority_queue<LL>> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[i-a[i]].push(a[i]);
    }
    LL ans=0;
    for(auto x:mp){
        LL tag=0;
        LL pre=0;
        while(!x.second.empty()){
            LL val=x.second.top();
            x.second.pop();
            tag^=1;
            if(tag==0){
                if(pre+val<0){
                    break;
                }
                ans+=pre+val;
            }
            pre=val;
        }
    }
    cout<<ans<<'\n';

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