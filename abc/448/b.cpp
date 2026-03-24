#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1),c(m+1),b(n+1);
    LL sum=0;
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    LL s=0;
    for(int i=1;i<=n;i++){
        if(b[i]>=c[a[i]]){
            s+=c[a[i]];
            c[a[i]]=0;
            
        }else{
            c[a[i]]-=b[i];
            s+=b[i];
        }
        //printf("{%lld}",s);
        // for(int j=1;j<=m;j++){
        //     printf("{%d}",c[j]);
        // }
        // cout<<'\n';
    }
    cout<<s<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}