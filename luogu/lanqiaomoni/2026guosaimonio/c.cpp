#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans;
}
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1);
    vector<LL> s(n+1,0);
    LL sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        sum+=a[i];
    }

    for(int i=1;i<=m;i++){
        LL k;
        cin>>k;
        vector<LL> b(n+1,0);
        vector<LL> pre(n+1,0);
        for(int j=1;j<=n;j++){
            b[j]=a[j]^k;
            LL d=b[j]-a[j];
            pre[j]=pre[j-1]+d;
            //printf("{%lld}",pre[j]);
        }
        LL maxn=0;
        LL minn=0;
        LL ans1=-1e9;
        LL ans2=1e9;
        for(int j=1;j<=n;j++){
            ans1=max(ans1,pre[j]-minn);
            ans2=min(ans2,pre[j]-maxn);
            minn=min(pre[j],minn);
            maxn=max(pre[j],maxn);
        }
        cout<<sum+ans2<<' '<<sum+ans1<<'\n';
        
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}