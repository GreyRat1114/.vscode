#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using LL=long long;

void solve(){
    string s;
    cin>>s;
    int maxn=0,p=0;
    int ans=s.length();
    // cout<<ans<<'\n';
    for(int i=s.length()-1;i>=0;i--){
        int x=s[i]-'0';
        LL y=(x-p+100000000)%10;
        p+=y;
    }
    ans+=p;
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}