#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    LL s=0;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=s^a[i];
    }
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    if(s==0){
        cout<<1<<'\n';
    }else{
        LL ans=0;
        for(int i=1;i<=n;i++){
            if((s^a[i])<a[i]){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}