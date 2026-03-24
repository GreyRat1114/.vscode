#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;

void solve(){
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<sum<<'\n';
}
int main(){
    solve();
    return 0;
}
