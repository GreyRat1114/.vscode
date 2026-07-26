#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m,l;
    cin>>n>>m>>l;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    multiset<LL> st;
    for(int i=1;i<=m;i++){
        st.insert(0);
    }
    for(int i=1;i<=n;i++){
        LL d=a[i]-a[i-1];
        while(st.size()>n-i+2){
            st.erase(st.begin());
        }
        for(int j=1;j<=d;j++){
            auto it=st.begin();
            LL val=*it;
            st.erase(it);
            st.insert(val+1);
        }
        auto it=st.end();
        it--;
        st.erase(it);
        st.insert(0);
    }
    LL val=*st.rbegin();
    cout<<val+(l-a[n])<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}