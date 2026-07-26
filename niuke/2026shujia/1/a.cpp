#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    set<char> st={'a','o','e','i','u'};
    string s;
    cin>>s;
    LL siz=s.size();
    LL tag=1;
    if(siz!=8)tag=0;
    for(int i=0;i<siz;i+=2){
        if(st.count(s[i])){
            tag=0;
            break;
        }
    }
    for(int i=1;i<siz;i+=2){
        if(!st.count(s[i])){
            tag=0;
            break;
        }
    }
    if(tag){
        cout<<"Suspected Virus"<<'\n';
    }else{
        cout<<"Well-Being"<<'\n';    
    }

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}