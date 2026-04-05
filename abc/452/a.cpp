#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    LL x,y;
    cin>>x>>y;
    if((x==1&&y==7)||(x==3&&y==3)||(x==7&&y==7)||(x==9&&y==9)||(x==5&&y==5)){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
    
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}