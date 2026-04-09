#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL x,y;
    cin>>x>>y;
    LL ans=0;
    for(int i=0;i<=30;i++){
        LL x1=x>>i;
        for(int j=0;j<=30;j++){
            LL y1=y>>j;
            ans=max(ans,x1^y1);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}