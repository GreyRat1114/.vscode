#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
vector<LL> a;
LL n,m;
LL minn;
LL maxn=0;
LL check(LL x){
    LL p=minn;
    LL ans=x;
    while(p<=maxn){
        auto it=upper_bound(a.begin()+1,a.end(),p+x);
        //printf("{%lld,%lld,%lld}",x,p,ans);
        if(it==a.end()){
            ans++;
            break;
        }
        p=*it;
        ans++;
    }
    return ans;
}
void solve(){
    cin>>n;
    minn=1e9;
    maxn=0;
    vector<LL> b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b.begin()+1,b.end());
    m=unique(b.begin()+1,b.end())-b.begin()-1;
    //cout<<m<<'\n';
    a.assign(m+1,0);
    for(int i=1;i<=m;i++){
        a[i]=b[i];
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]);
    }
    LL ans=1e18;
    for(int i=0;i<=maxn;i++){
        ans=min(ans,check(i));
    }   
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}