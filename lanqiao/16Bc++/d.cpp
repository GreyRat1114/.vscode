#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
void solve(){
    int n,x;
    int a,b,c;
    int k;
    cin>>a>>b>>c>>k;
    for(int i=1;i<=k;i++){
        int a1=(b+c)/2;
        int b1=(a+c)/2;
        int c1=(a+b)/2;
        a=a1;
        b=b1;
        c=c1;
        if(a==b&&b==c){
            break;
        }
    }
    cout<<a<<' '<<b<<' '<<c<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}