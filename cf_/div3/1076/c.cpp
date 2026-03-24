#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
LL b[N];
LL s[N];
void solve(){
    LL n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[i]=max(a[i],b[i]);
    }
    LL maxn=0;
    s[0]=0;
    for(int i=n;i>=1;i--){
        maxn=max(maxn,a[i]);
        b[i]=maxn;
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+b[i];
    }    
    // for(int i=1;i<=n;i++){
    //     cout<<s[i]<<' ';
    // }
    int l,r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<' ';
    }
    cout<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}