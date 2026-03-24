#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    int n;
    cin>>n;
    vector<LL> a(n+1);
    LL minn=1e9;
    LL maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]);
    }
    cout<<maxn-minn+1<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}