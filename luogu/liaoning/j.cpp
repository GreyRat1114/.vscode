#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
LL a[N];
    vector<int> s[N];
void solve(){
    
    LL n,m;
    cin>>n>>m;

    int op;
    LL x,y;
    LL i1,j1,i2,j2;
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            s[x].push_back(y);
        }
        else{
            cin>>i1>>j1>>i2>>j2;
            LL t=s[i1][j1-1];
            s[i1][j1-1]=s[i2][j2-1];
            s[i2][j2-1]=t;

        }
    }
    for(int i=1;i<=n;i++){
        cout<<s[i].size()<<' ';
        for(auto j :s[i]){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    
    return 0;
}