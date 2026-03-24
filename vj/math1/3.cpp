#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;

void solve(int t){
    
    int n;
    string s;
    cin>>n>>s;
    cout<<"Case "<<t<<": ";
    if(s=="Alice"){
        if((n-1)%3==0){
            cout<<"Bob"<<'\n';
        }else{
            cout<<"Alice"<<'\n';
        }
    }else{
        if(n%3==0){
            cout<<"Alice"<<'\n';
        }else{
            cout<<"Bob"<<'\n';
        }        
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}