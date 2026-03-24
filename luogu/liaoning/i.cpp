#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
using LL=long long;
LL a[N];
void solve(){
    LL n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    LL x=a[0];
    sort(a+1,a+n);
    for(int i=1;i<=n-1;i++){
        if(a[i]>x){
            LL d=a[i]-x;
            // printf("{%d}",d);
            LL y=(d-1)/2+1;
            x=x+y;
        }
    }
    cout<<x<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}