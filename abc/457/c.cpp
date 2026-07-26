#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<vector<LL>> a(n+1);
    for(int i=1;i<=n;i++){
        LL l;
        cin>>l;
        a[i].resize(l);
        for(int j=0;j<l;j++){
            cin>>a[i][j];
            //printf("{%lld}",a[i][j]);
        }
    }
    vector<LL> c(n+1);
    vector<LL> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>c[i];
        //cerr<<c[i]<<'\n';
        
        s[i]=s[i-1]+c[i]*(a[i].size());
        //printf("{%lld,%lld}",c[i],s[i]);
    }

    auto check=[&](LL x)->LL{
        LL l=1;
        LL r=n;
        LL ans=0;
        while(l<=r){
            LL mid=(l+r)/2;
            if(s[mid]<=x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    };
    LL p=check(k);
    //printf("{%lld}",p);
    
    if(s[p]==k){
        cout<<a[p].back();
    }else{
        LL def=k-s[p];
        //printf("<%lld>",def);
        p++;
        LL y=def%a[p].size()-1;
        y=(y+a[p].size())%a[p].size();
        //printf("{%lld}",y);
        cout<<a[p][y]<<'\n';


    }
    

    


}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}