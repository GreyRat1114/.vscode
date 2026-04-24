#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k;
    cin>>n>>k;
    k=n*n-k+1;
    auto check=[&](LL mid)->LL{
        LL x=n,y=1;
        LL cnt=0;
        while(x>=1&&y<=n){
            cout<<'?'<<' '<<x<<' '<<y<<' '<<mid<<'\n';
            cout.flush();
            LL z;
            cin>>z;
            //printf("{%lld}",z);
            //fflush(stdout);
            if(z==0){
                x--;
            }else{
                cnt+=x;
                y++;
            }
        }
        // printf("{%lld,%lld}",cnt,k);
        // fflush(stdout);
        if(cnt>=k){
            return 1;
        }else{
            return 0;
        }
        //return cnt>=k?1:0;
    };
    LL l=1;
    LL r=n*n;
    LL ans=0;
    while(l<=r){
        LL mid=(l+r)/2;
        if(check(mid)){
            // printf("{%lld}",mid);
            // fflush(stdout);            
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<'!'<<' '<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}