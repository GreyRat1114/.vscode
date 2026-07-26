#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+10;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> p(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        //printf("{%lld}",p[i]);
        mp[p[i]]=i;
    }
    auto check=[&](LL x,LL l,LL r,LL pos)->LL{
        LL ans=0;
        LL pt1=0;
        LL pt2=0;
        LL pt3=0,pt4=0;
        while(l<=r){
            LL mid=(l+r)/2;

            if(pos==mid){
                //printf("{%lld,%lld,%lld,%lld}",pt1,pt2,pt3,pt4);
                if(n-x<pt3||x-1<pt4){
                    return -1;
                }
                return max(pt1,pt2)*2;
            }else if(pos<mid){
                if(p[mid]<x){
                    pt1++;
                }
                    pt3++;
                r=mid-1;
            }else{
                if(p[mid]>x){
                    pt2++;
                }
                    pt4++;
                    //printf("{%lld,%lld}",mid,pt4);
                l=mid+1;
            }
            //printf("{%lld,%lld,%lld,%lld}",l,r,pt1,pt2);
        }
    };    
    for(int i=1;i<=q;i++){
        LL l,r,k;
        cin>>l>>r>>k;
        //printf("{%lld,%lld,%lld,%lld}",l,r,k,i);
        if(l>r||mp[k]<l||mp[k]>r){
            cout<<-1<<' ';
            continue;
        }
        cout<<check(k,l,r,mp[k])<<' ';
    }
    cout<<'\n';

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