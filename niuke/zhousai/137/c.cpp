#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    LL x;
    vector<LL> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=x;
    }
    sort(a.begin()+1,a.end());
    LL tot=1;
    LL pre=a[1];
    LL ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]==pre){
            continue;
        }
        if(i>=2){
            if(a[i]-pre>=tot){
                tot++;
                pre=a[i];
            }
        }
    }
    cout<<tot<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}