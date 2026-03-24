#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
void solve(){
    int xa,ya;
    int xb,yb;
    cin>>xa>>ya;
    cin>>xb>>yb;
    long double x1=1.0*xa;
    long double x2=1.0*xb;
    long double y1=1.0*ya;
    long double y2=1.0*yb;
    if(y1==y2){
        if(x1==x2){
            cout<<"no answer"<<'\n';
            return;
        }
        long double dd=abs(x1-x2);
        long double S=dd*abs(y1);
        long double SS=1.0*4;
        if(S==SS){
            cout<<0<<'\n';
        }else{
            cout<<"no answer"<<'\n';
        }
        return;
    }
    long double A=(y2-y1);
    long double B=-1.0*(x2-x1);
    long double C=(x2-x1)*y1-(y2-y1)*x1;
    //long double d=sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    //cout<<C<<'\n';
    long double pt1=(1.0*4);
    //cout<<pt1<<'\n';
    long double xl=(pt1-C)/A;
    long double xr=(-pt1-C)/A;
    cout<<setprecision(10)<<fixed<<xr<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}