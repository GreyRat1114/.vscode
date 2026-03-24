#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
LL s[N];
void solve(){
    memset(s,0,sizeof(s));
    map<LL,int> tr;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tr[a[i]]=0;
    }
    LL x=0;
    for(int i=1;i<=n;i++){
        LL l=i-tr[a[i]];
        x+=l;
        s[i]=s[i-1]+x;
        tr[a[i]]=i;
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        ans+=s[i];
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}