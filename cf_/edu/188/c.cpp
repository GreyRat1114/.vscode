#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL a,b,c,m;
    cin>>a>>b>>c>>m;
    LL ab=(a*b)/__gcd(a,b);
    LL ac=(a*c)/__gcd(a,c);
    LL ba=(b*a)/__gcd(b,a);
    LL bc=(b*c)/__gcd(b,c);    
    LL abc=(ab*c)/__gcd(ab,c);
    //printf("{%lld,%lld,%lld}",ab,ac,abc);
    LL cnta=m/a-m/ac-m/ab+m/abc;
    LL cntb=m/b-m/bc-m/ba+m/abc;
    LL cntc=m/c-m/bc-m/ac+m/abc;
    //printf("{%lld,%lld,%lld}",cnta,cntb,cntc);
    LL ans1=cnta*6+(m/ac+m/ab-2*(m/abc))*3+m/abc*2;
    //printf("{%lld}",(m/ac+m/ab-2*(m/abc))*3);
    LL ans2=cntb*6+(m/bc+m/ba-2*(m/abc))*3+m/abc*2;
    LL ans3=cntc*6+(m/bc+m/ac-2*(m/abc))*3+m/abc*2;
    cout<<ans1<<' '<<ans2<<' '<<ans3<<'\n';

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