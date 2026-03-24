#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;

void solve(){

    string s;
    cin>>s;
    int n=s.length();
    int pos=-1;
    for(int i=0;i<n;i++){
        int num=s[i]-'0';
        if(num>=5){
            pos=i;
            // if(i-1>=0){
            //     int c=s[i-1]-'0'+1;
            //     s[i-1]=c;
            // }
            s[i]='0';
            
            break;
        }
    }
    if(pos==-1){
        s[n-1]='0';
        cout<<s<<"\n";
        return;
    }
    for(int i=pos;i<n;i++){
        s[i]='0';
    }    
    string s1="";
    int d=1;
    for(int i=pos-1;i>=0;i--){
        int num=s[i]-'0'+d;
        //cout<<num<<'\n';
        if(num>=10){
            s[i]='0';
            d=1;
        }else{
            char c=(char)num;
            s[i]='0'+num;
            d=0;
        }
    }
    if(d==1){
        s1="1";
        cout<<s1+s<<'\n';
    }else{
        cout<<s<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}