#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e7+5;
LL a[N];

void solve(){
    int n;
    cin>>n;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans+=s*a[i];
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;;
    while(t--){
        solve();
    }
    
    return 0;
}