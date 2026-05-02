#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    string s;
    cin>>s;
    vector<LL> sa(n+1,0),sb(n+1,0),sc(n+1,0);
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1];
        sb[i]=sb[i-1];
        sc[i]=sc[i-1];
        if(s[i-1]=='A'){
            sa[i]++;
        }else if(s[i-1]=='B'){
            sb[i]++;
        }else{
            sc[i]++;
        }
    }
    vector<LL> d2(n+1,0),d3(n+1,0),d23(n+1,0);
    for(int i=1;i<=n;i++){
        d2[i]=sb[i]-sa[i];
        d3[i]=sc[i]-sb[i];
        d23[i]=d2[i]+d3[i];
    }
    map<LL,LL> mp1,mp2,mp3;
    map<pair<LL,LL>,LL> mp12,mp23,mp13;
    map<tuple<LL,LL,LL>,LL> mp123;
    mp1[0]++;
    mp2[0]++;
    mp3[0]++;
    mp12[{0,0}]++;
    mp23[{0,0}]++;
    mp13[{0,0}]++;
    mp123[{0,0,0}]++;
    // mp[{2,3}]++;
    LL ans=0;
    for(int i=1;i<=n;i++){
        LL cnt=mp1[d2[i]]+mp2[d3[i]]+mp3[d23[i]]-mp12[{d2[i],d3[i]}]-mp23[{d3[i],d23[i]}]-mp13[{d2[i],d23[i]}]+mp123[{d2[i],d3[i],d23[i]}];
        mp1[d2[i]]++;
        mp2[d3[i]]++;
        mp3[d23[i]]++;
        mp12[{d2[i],d3[i]}]++;
        mp23[{d3[i],d23[i]}]++;
        mp13[{d2[i],d23[i]}]++;
        mp123[{d2[i],d3[i],d23[i]}]++;
        ans=ans+i-cnt;
        // if(sa[i]!=sb[i]&&sa[i]!=sc[i]&&sb[i]!=sc[i]){
        //     ans++;
        // }
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