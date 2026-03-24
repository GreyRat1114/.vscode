#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x,y,z;
    cin>>x>>y>>z;
    int ans=(x-z*y)/(z-1);
    if((x-z*y)%(z-1)==0&&(x-z*y)/(z-1)>=0){
        cout<<"Yes"<<'\n';
    }
    else{
        cout<<"No"<<'\n';
    }
}
int main(){
    solve();
    return 0;
}