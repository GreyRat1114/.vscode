#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    if(n==1&&m==1){
        cout<<-1<<'\n';
        return;
    }
    if(n==1){
        cout<<"0";
        for(int i=2;i<=m;i++){
            cout<<"1";
        }
        cout<<'\n';
        
    }else if(m==1){
        cout<<"0"<<'\n';
        for(int i=2;i<=n;i++){
            cout<<"1"<<'\n';
        }        
    }else{
        cout<<-1<<'\n';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}