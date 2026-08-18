#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
using ld=long double;
const ld eps=1e-10;
struct node{
    LL x,y,z;
};
void solve(){
    LL n,m,l;
    cin>>n>>m>>l;
    node o;
    vector<node> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            string s;
            cin>>s;
            for(int k=1;k<=l;k++){
                if(s[k-1]=='H'){
                    o={i,j,k};
                }else if(s[k-1]=='T'){
                    q.push_back({i,j,k});
                }
            }
        }
    }
    map<LL,map<LL,set<LL>>> mp;
    for(auto p:q){
        node p1={p.x-o.x,p.y-o.y,p.z-o.z};
        LL g=abs(__gcd(__gcd(p1.x,p1.y),p1.z));
        node p2={p1.x/g,p1.y/g,p1.z/g};
        //printf("{%lld,%lld,%lld}",p2.x,p2.y,p2.z);
        mp[p2.x][p2.y].insert(p2.z);
    }
    LL ans=0;
    for(auto i:mp){
        for(auto j:i.second){
            for(auto k:j.second){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    cout<<16*16*16*16*16<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    //init(1e6+5);
    while(t--){
        solve();
    }
    return 0;
}