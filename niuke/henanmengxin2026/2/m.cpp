#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
struct node{
    LL v,l;

};
void solve(){
    LL n;
    cin>>n;
    vector<node> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].v>>a[i].l;
    }
    vector<LL> s(n+1,0);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i].l;
    }
    LL m;
    cin>>m;
    for(int i=1;i<=m;i++){
        LL x;
        cin>>x;
        LL p=lower_bound(s.begin(),s.end(),x)-s.begin();
        cout<<a[p].v<<'\n';
    }
    
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