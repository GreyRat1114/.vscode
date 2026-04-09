#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL check(LL x){
    LL ans=0;
    while(x){
        LL y=x%10;
        ans+=y;
        x=x/10;
    }
    return ans;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=0;
    for(int i=n-1;i>=1;i--){
        while(a[i]>a[i+1]&&a[i]>=10){
            a[i]=check(a[i]);
            ans++;
        }
        if(a[i]>a[i+1]){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}