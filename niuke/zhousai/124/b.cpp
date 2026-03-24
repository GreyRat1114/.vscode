#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
bool cmp(LL a,LL b){
    return a>b;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
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