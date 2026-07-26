#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    int n;
    cin >> n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n % 2 == 1){
        LL ans = 0;
        for(int i=2;i<=n;i+=2) ans += max(a[i-1],a[i+1]);
        cout << ans << "\n";
    }
    else{
        LL ans1 = 0;
        LL ans2 = 0;
        for(int i=2;i<=n-2;i+=2) ans1 += max(a[i-1],a[i+1]);
        ans1 += min(a[n],a[n-1]);
        for(int i=n-1;i>=3;i-=2) ans2 += max(a[i-1],a[i+1]);
        ans2 += min(a[1],a[2]);
        cout << min(ans1,ans2) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}