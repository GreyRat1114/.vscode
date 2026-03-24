#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> cnt(m+10,0);
    vector<int> s(m+10,0);
    int a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        cnt[a]++;
        s[a]+=b;
    }
    for(int i=1;i<=m;i++){
        double ans=1.0*s[i]/cnt[i];
        cout<<setprecision(10)<<fixed<<ans<<'\n';
    }
}
int main(){
    solve();
    return 0;
}