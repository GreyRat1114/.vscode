#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL x,y;
    cin>>x>>y;
    if(x>0&&y>0){
        cout<<x+1<<' '<<y+1<<'\n';
    }
    else if(x>0&&y<0){
        cout<<x+1<<' '<<y-1<<'\n';
    }
    else if(x<0&&y>0){
        cout<<x-1<<' '<<y+1<<'\n';
    }
    else{
        cout<<x-1<<' '<<y-1<<'\n';
    }
}    
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}