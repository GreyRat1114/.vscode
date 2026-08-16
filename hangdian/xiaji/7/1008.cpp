#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,w;
    cin>>n>>w;
    string s;
    cin>>s;
    LL tag=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='^')tag=max(1ll,tag);
        if(s[i]=='&')tag=max(2ll,tag);
    }
    if(tag==0){
        cout<<"Yes"<<'\n';
        cout<<w<<' ';
        for(int i=2;i<=n;i++){
            cout<<0<<' ';
        }
        cout<<'\n';
    }else if(tag==1){
        cout<<"Yes"<<'\n';
        LL p;
        for(int i=0;i<s.size();i++){
            if(s[i]=='^'){
                p=i+1;
            }
            break;
        }
        for(int i=1;i<=n;i++){
            if(i==p){
                cout<<w<<' ';
            }else{
                cout<<0<<' ';
            }
        }
        cout<<'\n';
    }else{
        cout<<"Yes"<<'\n';
        LL l,r=s.size()+1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='&'){
                l=i+1;
                //
                for(int j=i+1;j<s.size();j++){
                    if(s[j]!='&'){
                        r=j+1;
                        break;
                    }
                }
                break;
            }
        }        
        //printf("{%lld,%lld}",l,r);
        for(int i=1;i<=n;i++){
            if(i>=l&&i<=r){
                cout<<w<<' ';
            }else{
                cout<<0<<' ';
            }
        }
        cout<<'\n';        
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}