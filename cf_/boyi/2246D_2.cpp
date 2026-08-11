#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=1e5+5;
vector<vector<LL>> inv;
vector<vector<LL>> pre;
vector<LL> a;
LL n;
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
    inv.assign(50,vector<LL>(N+1,1e15));
    pre.assign(50,vector<LL>(N+1,1e15));
    for(LL i=0;i<=20;i++){
        LL d=(1ll<<i);
        for(LL j=1;j<=N;j++){
            inv[i][j]=j*d+getv(j);
        }
    }
    for(LL i=0;i<=20;i++){
        LL d=(1ll<<i);
        for(LL j=N-1;j>=0;j--){
            pre[i][j]=min(inv[i][j],pre[i][j+1]);
        }
    }    
}
void work(LL minc){
    LL ans=1e15;
    for(int i=0;i<=20;i++){
        LL res=i;
        for(int j=1;j<=n;j++){
            LL l=(a[j]-1)/(1ll<<i)+1;
            res+=(pre[i][l]-a[j]);
        }
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
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
    work(mini);

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        solve();
    }
    return 0;
}