#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        mp[a[i]]=i;

    }
    // for(auto x:mp){
    //     cout<<x.first<<' '<<x.second<<'\n';
    // }

    // auto check=[&](LL x,LL l,LL r)->LL{
    //     LL ans=l;
    //     while(l<=r){
    //         LL mid=(l+r)/2;
    //         if(a[mid]<=x){
    //             ans=mid;
    //             l=mid+1;
    //         }else{
    //             r=mid-1;
    //         }
    //     }
    //     return ans;
    // };
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            LL need=2*a[i]-a[j];
            LL l=j;
            LL mid=i;
            if(!mp.count(need))continue;
            LL r=mp[need];
            LL p=(l+r)/2;
            LL d;
            LL ll=mid-l;
            LL rr=r-mid;
            if(ll==rr){
                ans=max(ans,2*rr+1);
            }else if(ll>rr){
                ans=max(ans,2*rr+1);
            }else if(ll<rr){
                ans=max(ans,2*ll+2);
            }
            // if((r-l+1)%2==1){
            //     LL len1=mid-l;
            //     LL len2=r-mid;
            //     d=abs(len1-len2);
            //     //printf("{1}");
            // }else{
            //     LL len1=mid-l+1;
            //     LL len2=r-mid;   
            //     d=abs(len1-len2);     
            //     //printf("{2}");
            // }
            //printf("{%lld,%lld,%lld,%lld}\n",r-l+1-d,l,mid,r);
            
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}