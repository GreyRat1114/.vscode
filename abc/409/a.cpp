#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    for(int i=0;i<n;i++){
        if(s1[i]=='o'&&s2[i]=='o'){
            cout<<"Yes"<<'\n';
            return;
        }
    }
    cout<<"No"<<'\n';
    
}
int main(){ 
    solve();
    return 0;
}