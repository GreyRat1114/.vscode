#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using LL=long long;
const LL mod=1e9;
int main(){
    LL x=rnd()%1000+1;
    LL a=rnd()%x+1;
    LL b=rnd()%x+1;
    cout<<x<<' '<<a<<' '<<b<<'\n';
    return 0;
}