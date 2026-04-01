#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL n,k;
    cin>>n>>k;
    LL s=0;
    LL maxn=0;
    vector<LL> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
        maxn=max(maxn,a[i]);
    }
    LL l=maxn;
    LL r=s;
    LL ans;
    while(l<=r){
        LL mid=(l+r)/2;
        LL d=0;
        LL cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]+d<=mid){
                d+=a[i];
            }else{
                cnt++;
                d=a[i];
            }
        }
        //printf("{%lld,%lld,%lld,%lld,}\n",l,r,mid,cnt);
        if(cnt+1<=k+1){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
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