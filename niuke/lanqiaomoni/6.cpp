#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1),s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    auto check=[&](LL mask)->bool{
        LL need=mask;
        LL cnt=0;
        for(int i=1;i<n;i++){
            if(cnt<m-1&&(s[i]&mask)==need){
                cnt++;
                need=need^mask;
            }
        }
        return (cnt==m-1&&(s[n]&mask)==need);
    };
    LL ans=0;
    for(int i=30;i>=0;i--){
        LL cand=ans|(1ll<<i);
        if(check(cand))ans=cand;
    }
    cout<<ans<<'\n';

}
int main(){
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}