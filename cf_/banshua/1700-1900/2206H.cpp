#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL gcd(LL a,LL b){
    while(b){
        LL tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    vector<LL> g;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2){
            g.push_back(2*abs(a[i]-a[i-1]));
            // printf("{%lld}",g.back());
            s+=g.back();
        };
        
    }
    LL pre=-1;
    for(auto x:g){
        if(pre==-1){
            pre=x;
        }else{
            pre=gcd(pre,x);
        }
    }
    if(pre==0){
        cout<<a[n]<<'\n';
        return;
    }
    a[1]=a[1]%pre==0?pre:a[1]%pre;
    cout<<a[1]+s/2<<'\n';
      
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}