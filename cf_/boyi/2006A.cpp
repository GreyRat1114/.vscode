#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
vector<vector<LL>> e;
void solve(){
    LL n;
    cin>>n;
    e.assign(n+1,vector<LL>());
    for(int i=1;i<=n-1;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    string s;
    cin>>s;
    LL c0=0;
    LL c1=0;
    LL c2=0;
    LL cnt=0;
    for(int i=2;i<=n;i++){
        if(e[i].size()!=1){
            if(s[i-1]=='?')cnt++;
            continue;
        }
        if(s[i-1]=='1'){
            c1++;
        }else if(s[i-1]=='0'){
            c0++;
        }else{
            c2++;
        }
    }  
    
    LL ans=0;
    if(s[0]=='0'){
        ans+=c1+(c2+1)/2;
    }else if(s[0]=='1'){
        ans+=c0+(c2+1)/2;
    }else{
        if(c0==c1){
            if(cnt%2==0){
                ans=c0+c2/2;
            }else{
                ans=c0+(c2+1)/2;
            }
        }else{
            LL max0=c1+c2/2;
            LL max1=c0+c2/2;
            ans=max({ans,max1,max0});            
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