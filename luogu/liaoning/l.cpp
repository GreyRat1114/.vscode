#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
int r[N];
int c[N];
int ans[N][N];
void solve(){
    int n;
    cin>>n;
    int m=n+1;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=(c[j]+r[i])%m;
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }

}
signed main(){
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;

}