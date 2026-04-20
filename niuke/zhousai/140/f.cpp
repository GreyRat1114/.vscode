#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL isp(LL x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
void solve(){
    LL x;
    cin>>x;
    for(LL i=1;i<=1000;i++){
        LL y=i*i+x*x;
        LL z=(LL)sqrt(y);
        if(z*z==y){
            if(x+i<=sqrt(y)){
                continue;
            }            
            //printf("{%lld,%lld,%lld}",i,x,y);
            cout<<"Yes"<<'\n';
            cout<<i<<' '<<x<<' '<<z<<'\n';
            return;
        }
    }
    cout<<"No"<<'\n';

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}