#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=1e9+7;
vector<int> e[N];
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    LL ans=0;
    map<char, LL> mp;
    LL sa=0,sc=0,sm=0;
    LL sac=0,scm=0;

    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            sa++;
            sac+=sc;
            ans+=scm;
        }
        else if(s[i]=='c'){
            sc++;
            scm+=sm;
        }
        else if(s[i]=='m'){
            sm++;
        }
        else if(s[i]=='A'){
            sa++;
        }
        else if(s[i]=='C'){
            sc++;
            sac+=sa;
        }
        else if(s[i]=='M'){
            sm++;
            scm+=sc;
            ans+=sac;
        }
        sa%=mod;
        sc%=mod;
        sm%=mod;
        sac%=mod;
        scm%=mod;
        ans%=mod;
        cout<<ans<<' ';
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}