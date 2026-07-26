//P10814
//求区间l,r内小于x的点的个数
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=2e6+10;
struct Tree{
    LL n;
    vector<LL> s;
    void init(LL _n){
        n=_n;
        s.assign(n+1,0);
    }
    LL lowbit(LL x){
        return x&-x;
    }
    void update(LL x,LL k){
        while(x<=n){
            s[x]+=k;
            x+=lowbit(x);
        }
    }
    LL query(LL x){
        LL ans=0;
        while(x){
            ans+=s[x];
            x-=lowbit(x);
        }
        return ans;
    }
};
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<pair<LL,LL>>> mp(n+1);
    //map<LL,> mp;
    Tree tr;
    tr.init(N);
    for(int i=1;i<=m;i++){
        LL l,r,x;
        cin>>l>>r>>x;
        mp[l-1].push_back({x,i});
        mp[r].push_back({x,i});
    }
    vector<vector<LL>> def(m+1);
    for(int i=0;i<=n;i++){
        if(i>=1)tr.update(a[i],1);
        if(mp[i].size()){
            for(auto x:mp[i]){
                LL q=x.first;
                LL id=x.second;
                def[id].push_back(tr.query(q));
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<def[i][1]-def[i][0]<<'\n';
    }
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