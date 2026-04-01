#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<LL> b(n+1,0);
    vector<pair<LL,LL>> c(n+1); 
    b[1]=0;
    c[1].first=a[1];
    c[1].second=a[1];
    LL maxn=0;
    for(int i=2;i<=n;i++){
        LL pt1=0;
        c[i].first=c[i-1].first;
        c[i].second=c[i-1].second;
        if(a[i]>c[i-1].first){
            pt1=a[i]-c[i-1].first;
            c[i].first=a[i];
        }
        if(a[i]<c[i-1].second){
            pt1=c[i-1].second-a[i];
            c[i].second=a[i];
        }
        b[i]=max(b[i-1]+pt1-1,0ll);
        maxn=max(maxn,b[i]);
        printf("{%lld,%lld,}",i,b[i]);
    }
    cout<<maxn<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}