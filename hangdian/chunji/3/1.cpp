#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL n,m;
LL check(LL mid,vector<LL> &a,vector<LL> &b){

    LL ans=0;
    LL p=n;
    int tag=1;
    for(int i=n+1;i>=1;i--){
        if(a[p]<=mid&&tag){
            ans+=mid*b[i];
            tag=0;
        }else{
            ans+=a[p]*b[i];
            p--;
        }
        if(ans>=m){
            return m;
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    vector<LL> a(n+1,0),b(n+2,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n+1;i++){
        cin>>b[i];
    }
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    LL l=0;
    LL r=1e9;
    LL ans=0;
    while(l<=r){
        LL mid=(l+r)/2;
        LL x=check(mid,a,b);
        if(x<m){
            l=mid+1;

        }else{
            ans=mid;
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}