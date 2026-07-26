#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
const LL mod=998244353;
struct node{
    LL x,y;
    bool operator < (const node &o)const{
        if(x==o.x)return y<o.y;
        return x<o.x;
    }
};
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+2),b(n+1);
    vector<node> cp(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }    
    for(int i=1;i<=n;i++){
        LL mx=max(a[i],b[i]);
        LL mi=min(a[i],b[i]);
        cp[i]={mx,mi};
    }
    sort(cp.begin(),cp.end());
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans+=(cp[i].x-cp[i].y);
        //printf("{%lld,%lld}",cp[i].x,cp[i].y);
    }
    //printf("{%lld}",ans);
    LL minn=1e12;
    for(int i=n;i>=2;i--){
        LL d=2*max(0ll,cp[i].y-cp[i-1].x);
        minn=min(minn,d);
    }
    ans+=minn;
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