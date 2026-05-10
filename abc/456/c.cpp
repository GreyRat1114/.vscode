#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    string s;
    cin>>s;
    LL n=s.size();
    vector<LL> pre(n+1,0),lst(n+1,0);
    set<LL> st;
    vector<LL> a,b,c;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='a'){
            a.push_back(i);
        }else if(s[i-1]=='b'){
            b.push_back(i);
        }else{
            c.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(st.count(s[i-1]))st.clear();
        st.insert(s[i-1]);
        pre[i]=st.size();
    }
    st.clear();
    for(int i=n;i>=1;i--){
        if(st.count(s[i-1]))st.clear();
        st.insert(s[i-1]);
        lst[i]=st.size();
    }
    for(int i=1;i<=n;i++){
        //printf("{%lld}",pre[i]);
    }
    //cout<<'\n';
    for(int i=1;i<=n;i++){
        //printf("{%lld}",lst[i]);
    }    
    LL ans=n;
    for(int i=1;i<=n;i++){
        ans+=pre[i]*lst[i];
    }
    cout<<ans/2<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}