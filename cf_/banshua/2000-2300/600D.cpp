#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
const LL mod=1e9+7;
using ld=long double;
const long double pi=acos(-1);
void solve(){
    ld x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1;
    cin>>x2>>y2>>r2;
    ld dist=sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    ld dist2=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    ld r12=r1*r1+r2*r2+2*r1*r2;
    if(dist2>r12){
        cout<<0<<'\n';
        return;
    }else if(dist2<=r1*r1+r2*r2-2*r1*r2){
        ld s1=pi*r1*r1;
        ld s2=pi*r2*r2;
        cout<<setprecision(20)<<fixed<<min(s1,s2)<<'\n';
        return;
    }
    //cout<<dist<<'\n';
    //printf("{%lf}",dist);
    ld cosa=(r1*r1+dist*dist-r2*r2)/(2*r1*dist);
    ld cosb=(r2*r2+dist*dist-r1*r1)/(2*r2*dist);
    ld sina=sqrtl(1-cosa*cosa);
    ld sinb=sqrtl(1-cosb*cosb);
    ld sin2a=2*sina*cosa;
    ld sin2b=2*sinb*cosb;
    ld cos2a=cosa*cosa-sina*sina;
    ld cos2b=cosb*cosb-sinb*sinb;
    //printf("{%Lf,%Lf}",sin2a,sin2b);
    //printf("{%Lf,%Lf}",acos(cosa),acos(cosb));
    ld s1=r1*r1*acos(cosa)-r1*r1*sin2a/2;
    ld s2=r2*r2*acos(cosb)-r2*r2*sin2b/2;
    ld ans=s1+s2;
    cout<<setprecision(20)<<fixed<<ans<<'\n';
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