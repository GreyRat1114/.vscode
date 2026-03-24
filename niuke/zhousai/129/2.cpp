#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]<s[n-i-1]){
            cout<<"right"<<'\n';
            return;
        }else if(s[i]>s[n-i-1]){
            cout<<"left"<<'\n';
            return;
        }
    }
    cout<<"equal"<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}