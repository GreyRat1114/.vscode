// A - Candy Cookie Law
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N][N];

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c>=a&&d>=b){
        cout<<"No"<<'\n';
        return;
    }
    if(c>=a&&d<b){
        cout<<"Yes"<<'\n';
        return;
    }    
    cout<<"No"<<'\n';
}
int main(){
    solve();
    return 0;
}