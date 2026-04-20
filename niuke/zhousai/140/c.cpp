#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;

    vector<vector<LL>> a(n+1,vector<LL>(m+1));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            a[i][j]=s[j-1]-'0';
        }
    }
    LL cnt=0;
    for(int i=1;i+1<=n;i++){
        for(int j=1;j+1<=m;j++){
            set<LL> st;
            for(int d1=0;d1<=1;d1++){
                for(int d2=0;d2<=1;d2++){
                    st.insert(a[i+d1][j+d2]);
                }
            }
            if(st.size()==3){
                cnt++;
            }
        }
    }
    cout<<cnt*2<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}