#include<bits/stdc++.h>
using namespace std;
using LL=long long;
bool cmp(pair<LL,LL> a,pair<LL,LL> b){
    return a.second<b.second;
}
void solve(){
    LL n,k;
    cin>>n>>k;

    vector<LL> a(n+1);

    for(int i=1;i<=n;i++){
        LL w,t;
        cin>>w>>t;
        a[i]=k-w+t;
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        a[i]=max(a[i-1]+1,a[i]);
    }
    cout<<a[n]<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}