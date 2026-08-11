#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> prim;
vector<LL> not_prim;
void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            if(i%p==0)break;
        }
    }
}
void init(LL n){
    not_prim.assign(n+10,0);
    get_prim(n+1);
}
void solve(){

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}