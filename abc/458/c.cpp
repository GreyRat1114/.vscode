#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void solve(){
    string s;
    cin>>s;
    LL n=s.size();
    LL ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!='C')continue;
        LL l=i+1;
        LL r=n-i;

        //printf("{%lld,%lld,%lld}",i,l,r);
        ans+=min(l,r);
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
