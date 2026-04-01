#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL n;
    cin>>n;
    vector<pair<LL,LL>> a(n+1);
    map<LL,LL> mp;
    set<LL> st;
    
    LL s,e;
    for(int i=1;i<=n;i++){
        cin>>s>>e;
        st.insert(s);
        st.insert(e);
        mp[s]=e;
        a[i]=make_pair(s,e);
    }
    LL tot=0;
    map<LL,LL> inv;
    for(auto x:st){
        tot++;
        inv[x]=tot;
    }
    vector<LL> d(tot+1,0);
    for(int i=1;i<=n;i++){
        LL l=inv[a[i].first];
        LL r=inv[a[i].second];
        d[l]++;
        d[r]--;
    }
    LL ans=0;
    LL sum=0;
    for(int i=1;i<=tot;i++){
        sum+=d[i];
        ans=max(ans,sum);
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