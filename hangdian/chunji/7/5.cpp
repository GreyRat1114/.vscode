#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<LL> w(n+1,0);
    LL s=0;
    for(int i=1;i<=n;i++){
        if(i-k+1>=1){
            s-=a[i-k];
            s+=a[i];
            w[i]=s;
        }else{
            s+=a[i];
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",w[i]);
    // }
    vector<LL> premax(n+2,0),lstmax(n+2,0);
    for(int i=1;i<=n;i++){
        premax[i]=max(premax[i-1],w[i]);
    }
    //lstmax[n]=
    for(int i=n;i>=1;i--){
        if(i+k-1<=n)lstmax[i]=max(lstmax[i+1],w[i+k-1]);
    }
    LL ans=0;
    if(k*2<=n){
        for(int i=1;i<=n-1;i++){
            ans=max(ans,premax[i]+lstmax[i+1]);
        }
        LL pt1=2*k*k;
        pt1-=(k-1)*k;
        //printf("{%lld,%lld}",ans,pt1);
        cout<<ans+pt1<<'\n';
    }else{
        for(int i=1;i<=n;i++){
            ans+=a[i];
        }
        LL pt1=n*k;
        LL k1=n/2;
        LL k2=n-k1;
        pt1-=(k1-1)*k1/2+(k2-1)*k2/2;
        cout<<ans+pt1<<'\n';
    }
    

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}