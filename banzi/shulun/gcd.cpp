#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
LL gcd(LL a,LL b){
    while(b){
        LL t=a;
        a=b;
        b=t%b;
    }
    return a;
}
int main(){
    LL x,y;
    cin>>x>>y;
    cout<<gcd(x,y)<<'\n';
}