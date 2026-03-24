#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using LL=long long;
const LL mod=1e15;
int main(){

    int t=rnd()%10000+1;
    cout<<t<<'\n';
    for(int i=1;i<=t;i++){
        LL l=rnd()%mod+1;
        LL r=rnd()%mod+1;   
        if(l>r){
            continue;
        }
        cout<<l<<' '<<r<<'\n';     
    }
    return 0;
}