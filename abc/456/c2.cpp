#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    string s;
    cin>>s;
    LL n=s.size();
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    LL pre=1;
    LL ans=0;
    if(s[0]==s[1]){
        pre=2;
    }
    for(int i=2;i<=n;i++){
        if(s[i-1]==s[i-2]){
            pre=i;
        }else{
            ans=(ans+i-pre)%mod;
        }
        //printf("{%lld,%lld}",pre,ans);
    }
    cout<<ans+n<<'\n';
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