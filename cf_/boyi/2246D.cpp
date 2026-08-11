#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=1e5+5;
vector<vector<LL>> inv;
vector<vector<LL>> pre;
vector<LL> a;
LL n;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a);
        }
        b=b>>1;
        a=(a*a);
    }
    return ans;
}
LL getv(LL x){
    LL ans=0;
    while(x){
        LL d=((x&1)==0)?1:2;
        ans+=d;
        x=x>>1;
    }
    return ans-1;
}
LL getc(LL x){
    LL ans=0;
    while(x%2==0){
        x=x/2;
        ans++;
    }
    return ans;
}
void init(){
    inv.assign(50,vector<LL>(N+1,0));
    pre.assign(50,vector<LL>(N+1,-1));

}
LL work(LL ans,LL c){
    LL res=1e10;
    for(LL i=0;i<31;i++){
        LL def=i-c;
        //
        for(int j=1;j<=n;j++){
            LL d=(inv[c][a[j]]-pre[c][a[j]]);
            def+=d;
        }
        //printf("{%lld}",def);
        res=min(res,ans-def);
        
    }
    //cerr<<res<<'\n';
    return res;
}
void solve(){
    cin>>n;
    a.assign(n+1,0);
    LL ans=0;
    LL mini=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mini=min(mini,getc(a[i]));
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i]/qpow(2,mini);
        ans+=inv[mini][a[i]];
    }
    ans=work(ans,mini);
    cout<<ans<<'\n';
    //printf("{%lld}",1&(-1));
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        solve();
    }
    return 0;
}