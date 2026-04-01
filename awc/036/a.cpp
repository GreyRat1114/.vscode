#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1,vector<LL>(1001,0));
    vector<LL> tot(n+1,0);
    LL m,s;
    for(int i=1;i<=n;i++){
        cin>>m;
        tot[i]=m;
        for(int j=1;j<=m;j++){
            cin>>s;
            a[i][j]=s;
        }
    }
    LL q;
    cin>>q;
    LL v,d;
    LL cnt=0;
    for(int i=1;i<=q;i++){
        cin>>v>>d;
        if(a[v][d]==0){
            cnt++;
        }else{
            a[v][d]--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=tot[i];j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<cnt<<'\n';
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    return 0;
}