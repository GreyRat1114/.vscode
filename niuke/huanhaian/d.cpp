#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
LL b[N];
LL s1[N],s2[N];

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<=n+10;i++){
        s1[i]=0;
        s2[i]=0;
    }
    LL x,y;
    s1[0]=0;
    s2[n+1]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        s1[i]=s1[i-1]+a[i];
        // printf("{%lld}",s1[i]);
    }
    // cout<<'\n';
    for(int i=n;i>=1;i--){
        s2[i]=s2[i+1]+b[i];
        // printf("{%lld}",s2[i]);
    }
    LL minn=1e18;
    for(int i=1;i<=n+1;i++){
        LL z=s1[i-1]+s2[i];
        minn=min(z,minn);
    }
    cout<<minn<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}