#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    set<char> st;
    st.insert('r');
    st.insert('e');
    st.insert('d');
    string s;
    cin>>s;
    for(int i=0;i<3;i++){
        if(!st.count(s[i])){
            cout<<"No"<<'\n';
            return;
        }
    }
    cout<<"Yes"<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}