#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> q(n+1);
    //stack<char> st; 
    LL tot=0;
    for(int i=0;i<n;i++){
        char c=s[i];
        LL tag=0;
        if(tot>=1){
            if(q[tot]=='m'&&c=='o'){
                tot=tot-1;
                tag^=1;
                continue;
            }else{
                tag^=0;
            }
        }
        if(tot>=2){
            if(q[tot-1]=='n'&&q[tot]=='i'&&c=='u'){
                tot=tot-2;
                tag^=1;
                continue;
            }else{
                tag^=0;
            }
        }
        if(tag==0){
            tot++;
            q[tot]=c;
        }
    }
    if(tot==0){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}