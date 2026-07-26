#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> x(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    double l=0.000001;
    double r=1e10;
    LL ans=0;
    for(int i=2;i<=n;i++){
        double d=x[i]-x[i-1];
        if(d<=l){
            l=0.000001;
            r=d-l;
        }else if(d>l&&d<=r){
            ans++;
            r=d-l;    
            l=0.000001;        
        }else{
            ans++;
            double pr=r;
            r=d-l;
            l=d-pr;
        }
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