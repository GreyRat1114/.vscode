#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL tot=0;
    double d=0.011;
    double z0=0.0,z1=1.0;
    cout<<2*n<<'\n';
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            //<<' '
            cout<<fixed<<setprecision(10)<<i*d<<' '<<j*d<<' '<<z0<<'\n';
            tot++;
            if(tot==n)break;
        }
        if(tot==n)break;
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            cout<<fixed<<setprecision(10)<<i*d<<' '<<j*d<<' '<<z1<<'\n';
            tot++;
            if(tot==2*n)break;
        }
        if(tot==2*n)break;
    }    

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}