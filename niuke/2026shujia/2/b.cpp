#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> p;
void insert(LL x){
    for(int i=63;i>=0;i--){
        if((x>>i)&1){
            if(p[i]){
                x^=p[i];            
            }else{
                p[i]=x;
                break;
            }
        }
    }
}
void solve(){
    LL n;
    cin>>n;
    p.assign(100,0);
    vector<LL> a(n+1);
    LL yh=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        yh^=a[i];
    }
    LL fyh=((1<<30)-1)^yh;
    //printf("{%lld,%lld}",yh,fyh);
    for(int i=1;i<=n;i++){
        insert(fyh&a[i]);
    }    
    LL ans=0;
    for(int i=30;i>=0;i--){
        if(((yh&(1<<i))==0)&&((ans&(1<<i))==0)){
            ans^=p[i];
        }
    }
    cout<<2*ans+yh<<'\n';
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