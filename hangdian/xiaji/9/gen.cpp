#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using LL=long long;
const LL mod=1e15;
int main(){
    int t=rnd()%10+1;
    cout<<t<<'\n';
    for(int i=1;i<=t;i++){
        LL x=rnd()%10+1;
        cout<<x<<' ';     
    }
    return 0;
}