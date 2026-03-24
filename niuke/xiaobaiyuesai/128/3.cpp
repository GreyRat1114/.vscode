#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int gcd(int a,int b){
    while(b!=0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}
void solve(){
    int n,a0,a1;
    cin>>n>>a0>>a1;
    if(a0==0){
        for(int i=1;i<=n;i++){
            cout<<1;
        }
        cout<<'\n';
        return;
    }
    if(a1==0){
        for(int i=1;i<=n;i++){
            cout<<0;
        }
        cout<<'\n';
        return;
    }
    int x=gcd(a0,a1);
    int y=(a0*a1)/x;
    // int n0=y/a0;
    // int n1=y/a1;
    int t0=0;
    int t1=0;
    for(int i=1;i<=n;i++){
        int x=t1*a0-t0*a1;
        if(x>0&&x==a1){
            cout<<0;
            t0++;
        }else if(x<0&&x+a0==0){
            cout<<1;
            t1++;
        }else{
            if(abs(t1*a0-(t0+1)*a1)<=abs((t1+1)*a0-t0*a1)){
                cout<<0;
                t0++;
            }else{
                cout<<1;
                t1++;
            }            
        }



    }
    cout<<'\n';

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}