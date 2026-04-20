#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<LL> pre0(n+1,0),pre1(n+1,0),cnt(n+1,0);
    //LL m=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='+'){
            pre0[i]=pre0[i-1]+i;
            pre1[i]=pre1[i-1];
            cnt[i]=cnt[i-1]+1;
        }else{
            pre1[i]=pre1[i-1]+i;
            pre0[i]=pre0[i-1];
            cnt[i]=cnt[i-1];
        }
    }
    auto check=[&](LL l,LL r)->LL{
        LL m=cnt[r]-cnt[l-1];
        LL mid=m+l-1;
        LL ans=2*((pre0[r]-pre0[mid])-(pre1[mid]-pre1[l-1]))+m;
        return ans;
    };
    LL ans=0;
    for(int i=1;i<=q;i++){
        LL l,r;
        cin>>l>>r;
        ans=ans^check(l,r);
        //printf("{%lld}",check(l,r));
        //cout<<check(l,r)<<'\n';
    }
    cout<<ans<<'\n';
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