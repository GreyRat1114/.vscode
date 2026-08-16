#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
void solve(){
    LL x,a,b;
    cin>>x>>a>>b;
    auto check=[&](LL c)->LL{
        LL ans=0;
        for(LL k=0;k<=c;k++){
            LL pre=0;
            LL pans=0;
            for(int j=1;j<=k;j++){
               pre+=a;
               pans+=pre;
               pre--; 
            }
            for(int i=k+1;i<=c;i++){
                pans+=std::max(0ll,pre)+b;
                pre--;
            } 
            ans=std::max(ans,pans);
        }
        if(ans>=x){
            return 1;
        }else{
            return 0;
        }
    };    
    LL l=1;
    LL r=1e3+5;
    LL ans=1;
    while(l<=r){
        LL mid=(l+r)/2; 
        //std::cout<<l<<" "<<r<<' '<<mid<<" ";
        LL tag=check(mid);
      
        if(tag){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
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