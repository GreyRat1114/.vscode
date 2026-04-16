#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
vector<LL> cnt,pre;
void solve(){
    LL n,y;
    cin>>n>>y;
    vector<LL> c(n+1);
    
    LL mx=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        mx=max(mx,c[i]);
    }
    pre.assign(mx+1,0);
    cnt.assign(mx+1,0);
    for(int i=1;i<=n;i++){
        cnt[c[i]]++;
    }
    for(int i=1;i<=mx;i++){
        pre[i]=pre[i-1]+cnt[i];
    }
    LL ans=-1e18;
    for(LL i=2;i<=mx+1;i++){
        LL sum=0;
        LL d=0;
        for(LL j=1;i*(j-1)+1<=mx;j++){
            LL r=min(i*j,mx);
            LL l=i*(j-1)+1;
            LL pt1=pre[r]-pre[l-1];
            sum+=pt1*j;
            d+=min(pt1,cnt[j]);
            
        }
        ans=max(ans,sum-y*(n-d));
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