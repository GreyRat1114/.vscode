#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,z;
    cin>>n>>z;
    vector<LL> b(n+1);
    vector<LL> q1,q2,q0;
    LL pos=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]==0)continue;
        if(b[i]==1){
            q0.push_back(i);
            continue;
        }
        if(b[i]%2==1){  
            q1.push_back(i);
        }else{  
            q2.push_back(i);
        }
    }
    vector<LL> ans(n+1,0),vis(n+1,0);
    LL tag=1;
    LL n0=q0.size(),n1=q1.size(),n2=q2.size();
    //printf("{%lld,%lld,%lld}",n0,n1,n2);
    for(int i=n0-1;i>=0;i--){
        vis[q0[i]]=1;
        ans[q0[i]]=tag;
        tag=tag^1;
    }
    if((z+n1)%2==0){
        tag=tag^1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]||b[i]==0)continue;

        ans[i]=tag;
    }
    for(int i=n;i>=1;i--){
        cout<<ans[i];
    }
    cout<<'\n';
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