#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
using LL=long long;
void solve(){
    int n;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    LL d=1e9+1;
    if(x1==x2){
        cout<<d<<' '<<y2<<' '<<d<<' '<<y1<<'\n';
    }
    else if(y1==y2){
        cout<<x1<<' '<<d<<' '<<x2<<' '<<d<<'\n';
    }
    else{
        cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1<<'\n';
    }
    
}
int main(){
    solve();
    return 0;
}