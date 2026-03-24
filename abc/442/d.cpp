#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
LL b[N];
LL din[N];
const LL mod=998244353;
void solve(){
    memset(b,0,sizeof(b));
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }

    int op;
    int x,l,r;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            cin>>x;
            b[x]=b[x]-a[x]+a[x+1];
            LL tmp=a[x];
            a[x]=a[x+1];
            a[x+1]=tmp;
        }else{
            cin>>l>>r;
            LL ans=b[r]-b[l-1];
            cout<<ans<<'\n';
        }
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}