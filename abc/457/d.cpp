#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
using i128=__int128;
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+1);
    LL maxn=0;
    LL minn=1e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    auto check=[&](i128 x)->LL{
        i128 cnt=0;
        for(i128 i=1;i<=n;i++){
            if(a[i]<x){
                i128 y=a[i];
                i128 c=(x-y-1)/i+1;
                cnt+=c;
            }
        }
        if(cnt<=(i128)k){
            return 1;
        }else{
            return 0;
        }
    };
    i128 l=minn;
    i128 r=1e30;
    i128 ans=l;
    while(l<=r){
        i128 mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    print(ans);
    cout<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}