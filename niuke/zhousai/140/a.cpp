#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL a,b,c,l,r;
    cin>>a>>b>>c>>l>>r;
    LL cnt=0;
    set<LL> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    for(auto x:st){
        if(x>=l&&x<=r){
            cnt++;
        }        
    }
    cout<<r-l+1-cnt<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}