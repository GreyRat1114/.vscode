#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;

void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    vector<LL> c(n+1,0),a(n+1,0),d(n+1,0);
    for(int i=1;i<=n-1;i++){
        cin>>c[i+1];
        d[i+1]=d[i]+c[i+1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=0;
    multiset<LL> st;
    priority_queue<LL,vector<LL>,greater<LL>> q;
    LL s=0;
    for(int i=1;i<=n;i++){
        q.push(a[i]);
        if(q.size()>k){
            LL x=q.top();
            q.pop();
            s-=x;
        }
        s+=a[i];
        ans=max(ans,min(m-d[i],s));
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}