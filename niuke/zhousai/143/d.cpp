#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n,k;
    cin>>n>>k;
    map<LL,LL> mp;
    vector<pair<LL,LL>> b(n+1);
    map<LL,LL> mpl,mpr;
    for(int i=1;i<=n;i++){
        LL l,r;
        cin>>l>>r;
        b[i]={l,r};
        mp[l]++;
        mp[r]++;
        mpl[l]++;
        mpr[r]++;
    }
    LL m=mp.size();
    vector<LL> a(m+1),pre(m+1,0),lst(m+2,0);
    LL tot=0;
    for(auto x:mp){
        tot++;
        a[tot]=x.first;
    }
    // for(int i=1;i<=m;i++){
    //     printf("{%lld}",a[i]);
    // }
    // cout<<'\n';
    for(int i=1;i<=m;i++){
        pre[i]=pre[i-1]+mpr[a[i]];

    }
    for(int i=m;i>=1;i--){
        lst[i]=lst[i+1]+mpl[a[i]];
    }
    // for(int i=1;i<=m;i++){
    //     printf("{%lld}",pre[i]);
    // }
    // cout<<'\n';
    // for(int i=1;i<=m;i++){
    //     printf("{%lld}",lst[i]);
    // }    
    // cout<<'\n';
    auto check=[&](LL x)->LL{
        LL lt=1;
        LL rt=m;
        LL ans=m+1;
        while(lt<=rt){
            LL mid=(lt+rt)/2;
            if(a[mid]>x){
                ans=mid;
                rt=mid-1;
                
            }else{
                lt=mid+1;
            }
        }
        return ans;
    };
    LL ans=0;
    for(int i=1;i<=m;i++){
        LL l=i;
        LL r=check(a[i]+k);
        
        LL pt1=pre[l-1];
        LL pt2=lst[r]-lst[m+1];
        ans=max(ans,n-pt1-pt2);
        //printf("{%lld,%lld,%lld,%lld}",l,r,pt1,pt2);
    }
    cout<<ans<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}