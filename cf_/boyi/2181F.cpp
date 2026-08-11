#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    LL c=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)c++;
    }
    if(n==1){
        cout<<"Alice"<<'\n';
        return;
    }
    if(c==n){
        if(c%2==0){
            cout<<"Bob"<<'\n';
        }else{
            cout<<"Alice"<<'\n';
        }
        return;
    }
    if(c%2==0){
        cout<<"Alice"<<'\n';
    }else{
        cout<<"Bob"<<'\n';
    }
    

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}