#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using LL=long long;
const LL mod=1e9;
int main(){
    int n=rnd()%20+1;
    int m=rnd()%20+1;
    cout<<n<<' '<<m<<'\n';
    for(int i=1;i<=n;i++){
        LL x=rnd()%100+1;
        LL y=rnd()%100+1;
        cout<<x-y<<' ';
    }
    for(int i=1;i<=m;i++){
        LL x=rnd()%4+1;
        cout<<x<<' ';
        LL l=rnd()%n+1;
        LL r=-1;
        while(r<l){
            r=rnd()%n+1;
        }
        cout<<l<<' '<<r<<' ';
        if(x==1||x==2){
            LL k=rnd()%100+1;
            LL y=rnd()%100+1;
            cout<<k-y;
        }
        cout<<'\n';
    }
    return 0;
}