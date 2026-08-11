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
    LL g=__gcd(n,2*d);
    //cout<<g<<'\n';
    vector<vector<LL>> q(g+1,vector<LL>(30,0));
    for(int i=0;i<n;i++){
        LL p=i%g;
        q[p][s[i]-'a']++;
    }
    vector<LL> vis(g+1,0);
    LL ans=0;
    for(int i=0;i<g;i++){
        if(vis[i])continue;
        LL o=(g-i-1)%g;
        vis[i]=1;
        vis[o]=1;
        LL s=0;
        LL maxn=0;
        for(int j=0;j<26;j++){
            LL x=q[i][j];
            if(i!=o){
                x+=q[o][j];
            }
            s+=x;
            maxn=max(maxn,x);
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