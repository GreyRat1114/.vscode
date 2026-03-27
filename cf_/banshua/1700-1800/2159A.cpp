#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL l=0,r;
    LL tot=0;
    LL b;
    set<LL> st;
    vector<LL> a(2*n+1,0);
    for(int i=1;i<=2*n;i++){
        st.insert(i);
        cout<<'?'<<' '<<st.size()<<' ';
        for(auto x:st){
            cout<<x<<' ';
        }
        cout<<'\n';
        cout.flush();
        cin>>b;
        if(b!=0){
            st.erase(i);
            a[i]=b;
        }
    }
    st.clear();
    for(int i=1;i<=2*n;i++){
        if(a[i]){
            st.insert(i);
        }
    }
    for(int i=2*n;i>=1;i--){
        if(!a[i]){
            st.insert(i);
            cout<<'?'<<' '<<st.size()<<' ';
            for(auto x:st){
                cout<<x<<' ';
            }
            cout<<'\n';
            cout.flush();   
            cin>>b;
            if(b!=0){
                st.erase(i);
                a[i]=b;
            }        
        }
    }
    cout<<'!';
    for(int i=1;i<=2*n;i++){
        cout<<' '<<a[i];
    }
    cout<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}