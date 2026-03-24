#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e7+5;
LL b[N];
LL s1[N],s2[N];

void solve(){
    int n,m;
    int x,y,z;
    int a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    int op;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>x>>y>>z;
        }
        else{
            cin>>x>>y;
            cout<<0<<'\n';
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