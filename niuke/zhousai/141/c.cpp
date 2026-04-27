#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n;
    string s;
    cin>>s;
    n=s.size();
    LL l=0;
    LL r=n-1;
    while(l<=r){
        if(s[l]==s[r]){
            l++;
            r--;
            continue;
        }
        if(s[l]=='m'&&s[r]=='n'&&s[r-1]=='n'){
            r--;
        }else if(s[r]=='m'&&s[l]=='n'&&s[l+1]=='n'){
            l++;
        }else{
            cout<<"NO"<<'\n';
            return;
        }      
        l++;
        r--;   
        if(l>=r)break;
    }
    cout<<"YES"<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}