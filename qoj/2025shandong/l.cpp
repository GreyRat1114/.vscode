#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    //cout<<s1<<s2;
    map<char,LL> mp;
    mp['O']=7;
    mp['B']=6;
    mp['A']=5;
    mp['F']=4;
    mp['G']=3;
    mp['K']=2;
    mp['M']=1;
    if(mp[s1[0]]>mp[s2[0]]){
        cout<<"hotter"<<'\n';
    }else if(mp[s1[0]]<mp[s2[0]]){
        cout<<"cooler"<<'\n';
    }else{
        if(s1[1]<s2[1]){
            cout<<"hotter"<<'\n';
        }else if(s1[1]>s2[1]){
            cout<<"cooler"<<'\n';
        }else{
            cout<<"same"<<'\n';
        }
    }
}
int main(){
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}