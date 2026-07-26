#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
struct node{
    LL x,y,r;
};
void solve(){
    LL n;
    cin>>n;
    
    vector<node> a(n+1);
    for(int i=1;i<=n;i++){
        LL x,y,z;
        cin>>x>>y>>z;
        a[i]={x,y,z};
    }
    LL q;
    cin>>q;
    //printf("{%lld}",q);
    for(int i=1;i<=q;i++){
        LL x,y;
        cin>>x>>y;
        LL cnt=0;
        for(int j=1;j<=n;j++){
            LL d1=x-a[j].x;
            LL d2=y-a[j].y;
            LL r=a[j].r;
            if(d1*d1+d2*d2<=r*r)cnt++;
        }
        if(cnt%2){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}