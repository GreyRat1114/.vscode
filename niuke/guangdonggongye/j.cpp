#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
LL b[N];
bool vis[N];
bool cmp(LL a,LL b){
    return a>b;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL l=a[1];
    LL r=a[n];
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];

    }
    sort(b+1,b+1+n,cmp);
    LL ans=r-l;
    cout<<ans<<' ';
    for(int i=1;i<=n-1;i++){
        ans-=b[i];
        cout<<ans<<' ';
    }
}
int main(){
    solve();
    return 0;
}