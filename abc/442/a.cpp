#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
const LL mod=998244353;
void solve(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='i'||s[i]=='j'){
            ans++;
        }
    }
    cout<<ans<<'\n';

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}