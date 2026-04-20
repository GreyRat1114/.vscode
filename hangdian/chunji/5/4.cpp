#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
const LL mod=1e9+7;
void solve(){
    LL n;
    cin>>n;
    LL m=log2(n);
    //printf("{%lld}",m);
    LL ans=0;
    for(int i=1;i<=m;i++){
        LL a=(1<<i);
        LL b=(1<<(i+1));
        //printf("{%lld,%lld,%lld}",i,a,b);
        //LL d=n/a;
        LL l1=n/b;
        LL x=(n-l1*a)/a;
        //printf("{%lld,%lld}",l1,x);
        LL pt1=x*(n-a*l1+1)-a*((1+x)*x/2);
        LL pt2=((1+l1)*l1/2)*(b-a);
        //printf("{%lld,%lld}",pt1,pt2);
        ans+=i*pt1+i*pt2;
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