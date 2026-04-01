#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;

void solve(){
    string s,t;
    cin>>s;
    cin>>t;
    if(s.size()!=t.size()){
        LL d=abs((int)s.size()-(int)t.size());
        string w(d,'0');
        if(s.size()<t.size()){
            s=w+s;
        }else{
            t=w+t;
        }
    }
    LL n=s.size();

    LL dp[2][2][2][2]={};
    LL ndp[2][2][2][2]={};
    dp[0][0][0][0]=1;
    for(int i=0;i<n;i++){
        memset(ndp,0,sizeof(ndp));
        
    }
    cout<<s<<'\n'<<t<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}