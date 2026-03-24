#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair

void solve(){
    int n;
    cin>>n;
    vector<LL> a(n+1);
    vector<int> vis(n+1);
    LL minn=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<priority_queue<LL,vector<LL>,greater<LL>>> q(n+1);
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            continue;
        }
        
        int p=i;
        while(p<=n){
            vis[p]=1;
            q[i].push(a[p]);
            //printf("{%lld,%lld}",i,a[p]);
            p=p*2;
        }
    }
    // for(int i=1;i<=n;i++){
        
    // }
    vector<LL> ans(n+1);
    ans[0]=0;
    for(int i=1;i<=n;i++){
        LL x=i;
        while(x%2==0){
            x=x/2;
        }
        LL y=q[x].top();
        q[x].pop();
        if(y<ans[i-1]){
            cout<<"NO"<<'\n';
            return;
        }
        ans[i]=y;
    }
    cout<<"YES"<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}