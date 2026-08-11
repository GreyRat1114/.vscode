#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n,d;
    cin>>n>>d;
    string s;
    cin>>s;
    vector<LL> vis(n+1,0);
    LL ans=0;
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        LL l=i;
        LL r=n-i-1;
        map<char,LL> mp;
        do{
            mp[s[l]]++;
            mp[s[r]]++;
            vis[l]=1;
            vis[r]=1;
            l=(l+d)%n;
            r=(r+d)%n;
        }while(l!=i);
        LL maxn=0;
        LL s=0;
        for(auto cp:mp){
            s+=cp.second;
            maxn=max(maxn,cp.second);
            printf("{%c,%lld,%lld}",cp.first,s,maxn);
        }
        ans+=(s-maxn);
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