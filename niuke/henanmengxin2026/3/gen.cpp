#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using LL=long long;
const LL mod=1e9;
int main(){
    int n=rnd()%10+2;
    int m=rnd()%20+1;
    cout<<n<<' '<<m<<'\n';
    for(int i=1;i<=n;i++){
        cout<<rnd()%10<<' ';
    }

    return 0;
}