#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    int n;
    cin >> n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin()+1,a.end());
    int ans = -1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            LL ave = (a[i] + a[j]);
            LL mid = (i+j)/2;
            int len = j - i + 1;
            if(ave == 2LL*a[mid]) ans = max(ans,len);
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}