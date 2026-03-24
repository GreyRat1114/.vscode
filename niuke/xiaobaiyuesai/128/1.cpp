#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

void solve(){
    string s1,s2;
    int n;
    cin>>n;
    cin>>s1;
    cin>>s2;
    // cout<<s1<<'\n';
    // cout<<s2<<'\n';
    int tag=1;
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i]){
            continue;
        }
        char c1=s1[i];
        char c2=s2[i];
        if((c1=='0'&&c2=='O')||(c1=='O'&&c2=='0')){
            continue;
        }
        if(((c1=='1')&&(c2=='l'||c2=='I'))||((c1=='l')&&(c2=='1'||c2=='I'))||((c1=='I')&&(c2=='l'||c2=='1'))){
            continue;
        }
        tag=0;
        //printf("{%d}",i);
        break;
    }
    if(tag){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
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