#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n,k,u,v;
    cin>>n>>k>>u>>v;
    LL l=k-1;
    LL r=n-k;    
    LL s=l*u+r*v;
    if(u<2*v&&v<2*u){
        LL d=l-r;
        if(d%3==0){
            cout<<u+v<<'\n';
        }else if(d%3==1){
            cout<<u<<'\n';
        }else{
            cout<<v<<'\n';
        }
    }else if(u<2*v){
        LL d=u-2*v;
        LL ans=s+r/2*d;
        LL sl=l+r/2;
        if(r%2==1&&-u-v<0&&sl>=2){
            ans+=-v-u;
            sl--;
        }
        LL cnt=(sl-1)/3;
        if(u>0){
            ans+=cnt*(-3*u);
        }
        cout<<ans<<'\n';
    }else if(v<2*u){
        LL d=v-2*u;
        LL ans=s+l/2*d;
        LL sr=r+l/2;
        if(l%2==1&&-u-v<0&&sr>=2){
            ans+=-u-v;
            sr--;
        }
        LL cnt=(sr-1)/3;
        if(v>0){
            ans+=cnt*(-3*v);
        }        
        cout<<ans<<'\n';        
    }else{
        cout<<s<<'\n';
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