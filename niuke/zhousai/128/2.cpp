#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    int x1,y1;
    int x2,y2,x3,y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    int x=(x1+x2+x3)/3;
    int y=(y1+y2+y3)/3;
    if(x==x1&&y==y1){
        cout<<1<<'\n';
    }else if(x==x2&&y==y2){
        cout<<2<<'\n';
    }else{
        cout<<3<<'\n';
    }
}
int main(){
    solve();
    return 0;
}