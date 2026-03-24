#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    int n;
    cin>>n;
    vector<LL> a(n+1),s(n+1,0);
    vector<LL> ml(n+1),mr(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    ml[1]=a[1];
    for(int i=2;i<=n;i++){
        ml[i]=max(ml[i-1]+a[i],a[i]);
    }
    mr[n]=a[n];
    for(int i=n-1;i>=1;i--){
        mr[i]=max(mr[i+1]+a[i],a[i]);
    }

    vector<LL> m1(n+1,-1e18),m2(n+1,-1e18);
    m1[1]=ml[1];
    m2[n]=mr[n];
    for(int i=2;i<=n;i++){
        m1[i]=max(m1[i-1],ml[i]);
    }    
    for(int i=n-1;i>=1;i--){
        m2[i]=max(m2[i+1],mr[i]);
    }
    
    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",m1[i]);
    // }
    // cout<<'\n';
    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",m2[i]);
    // }    
    LL ans=-1e18;
    for(int i=3;i<=n-2;i++){
        int l=i-2;
        int r=i+2;
        ans=max(ans,m1[l]+m2[r]+a[i]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}