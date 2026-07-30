#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=2000+10;
const LL atk=669;
vector<vector<LL>> e;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    e.assign(n+1,vector<LL>());
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    double ans=0;
    for(int i=1;i<=n-1;i++){
        LL u,v;
        cin>>u>>v;
        ans=max(ans,1.0*(a[u]+a[v])/2);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<pair<LL,LL>> b(n+1);
    for(int i=1;i<=n;i++){
        LL u=i;
        LL m1=0;
        LL m2=0;
        for(auto v:e[u]){
            if(a[v]>=a[m1]){
                m2=m1;
                m1=v;
            }else if(a[v]>=m2){
                m2=v;
            }
        }
        b[u]={m1,m2};
    }
    for(int i=1;i<=n;i++){
        LL u=i;
        for(auto v:e[u]){
            LL w;
            if(b[v].first==u){
                w=b[v].second;
            }else{
                w=b[v].first;
            }
            ans=max(ans,1.0*(a[u]+a[v]+a[w])/3);
        }
    }
    cout<<setprecision(2)<<fixed<<ans<<'\n';

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