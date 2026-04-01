#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL h,w;
    cin>>h>>w;
    vector<vector<LL>> a(h+1,vector<LL>(w+1,0)),s(h+1,vector<LL>(w+1,0));

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
        }
    }
    

}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    return 0;
}