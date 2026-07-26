#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
LL gcd(LL a,LL b){
    while(b){
        LL t=a;
        a=b;
        b=t%b;
    }
    return a;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),d(n+1),d2(n+1);
    for(int i=1;i<=n;i++){ 
        cin>>a[i];
    }
    LL tag=1;
    LL def=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=def)tag=0;
    }
    if(tag){
        cout<<-1<<'\n';
        return;
    }
    for(int i=1;i<=n-1;i++){
        d[i]=a[i+1]-a[i];
        //printf("{%lld}",d[i]);
    }
    for(int i=1;i<=n-2;i++){
        d2[i]=d[i+1]-d[i];
    }
    LL g=d2[1];
    for(int i=2;i<=n-2;i++){
        g=gcd(g,d2[i]);
    }
    cout<<abs(g)<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}