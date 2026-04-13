#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    LL minn=0;
    LL maxn=1e18;
    LL a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        maxn=min(maxn,a/b);
        minn=max(minn,(a-1)/(b+1)+1);
    }
    cout<<minn<<' '<<maxn<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}