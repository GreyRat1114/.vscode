
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1,vector<LL>(n+1));
    vector<set<LL>> h(n+1);
    vector<set<LL>> w(n+1);
    set<LL> st;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            st.insert(a[i][j]);
            h[i].insert(a[i][j]);
            w[j].insert(a[i][j]);
        }
    }
    vector<LL> q;
    for(auto x:st){
        LL tag=1;
        for(int i=1;i<=n;i++){
            if(!h[i].count(x)){
                tag=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(!w[i].count(x)){
                tag=0;
            }
        }     
        if(tag){
            q.push_back(x);
        }
        
    }
    cout<<q.size()<<'\n';
    for(int i=0;i<q.size();i++){
        cout<<q[i]<<' ';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}