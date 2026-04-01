#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(2*n+1),s(2*n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++){
        s[i]=s[i-1]+a[i];

    }
    set<LL> tr;
    int tag=1;
    for(int i=1;i<=n;i++){
        tr.insert(s[i]);
        if(s[i]<0)tag=0;
    }
    if(tag){
        cout<<1<<'\n';
        return;
    }

    for(int i=n+1;i<=2*n;i++){
        tr.erase(s[i-n]);
        tr.insert(s[i]);
        LL d=*tr.begin()-s[i-n];
        //printf("{%lld,%lld,%lld,%lld}",i,*tr.begin(),s[i-n],d);
        if(d>=0){
            //printf("(%lld)",i);
            cout<<i-n+1<<'\n';
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}