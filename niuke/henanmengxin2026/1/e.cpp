#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
vector<LL> a;
void solve(){
    LL n,k,d;
    cin>>n>>k>>d;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<LL,LL> mp1,mp2;
    LL ll=1,lr=1;
    LL r=1;
    LL ans=0;
    LL len=0;
    while(r!=n+1){
        mp1[a[r]]++;
        mp2[a[r]]++;
        while(mp1.size()>k){
            mp1[a[ll]]--;
            if(mp1[a[ll]]==0)mp1.erase(a[ll]);
            ll++;
        }
        while(mp2.size()>=k){
            mp2[a[lr]]--;
            if(mp2[a[lr]]==0)mp2.erase(a[lr]);
            if(mp2.size()<k){
                mp2[a[lr]]++;
                break;
            }
            lr++;
        }
        LL maxn=mp1.rbegin()->first;
        LL minn=mp1.begin()->first;
        if((mp1.size()==k)&&(maxn-minn<=d)){
            ans+=(lr-ll+1);
        }
        r++;
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