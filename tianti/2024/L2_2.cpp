#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
void solve(){
    int n;
    cin>>n;
    getchar();
    map<string,multiset<string>> tr;
    for(int i=1;i<=n;i++){
        string s;
        getline(cin,s);
        int m=s.size(); 
        //cout<<s[m-1]<<'\n';     
        string s1="";
        if(s[0]!=' '){
            s1.push_back(s[0]);            
        }

        for(int j=0;j<m-1;j++){
            if(s[j]==' '&&s[j+1]!=' '){
                s1.push_back(s[j+1]);
            }
        }
        //cout<<s1<<'\n';
        tr[s1].insert(s);
        // cout<<s;
    }
    // for(auto x:tr){
    //     cout<<'\n';
    //     for(auto y:x.second){
    //         cout<<y<<'\n';
    //     }
    // }
    int q;
    cin>>q;
    getchar();
    for(int i=1;i<=q;i++){
        string s;
        getline(cin,s);
        int m=s.size();
        string s1="";
        if(s[0]!=' '){
            s1.push_back(s[0]);            
        }
        for(int j=0;j<m-1;j++){
            if(s[j]==' '&&s[j+1]!=' '){
                s1.push_back(s[j+1]);
            }
        }
        if(tr[s1].size()==0){
            cout<<s<<'\n';
        }else{
            for(auto k=tr[s1].begin();k!=tr[s1].end();k++){
                if(k!=tr[s1].begin()){
                    cout<<'|';
                }
                cout<<*k;  
            }
            cout<<'\n';
        }    
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}