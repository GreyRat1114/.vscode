#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL x,y,n,m;
    cin>>x>>y>>n>>m;
    vector<LL> a(n+1),b(m+1);
    LL maxa=-1e9,maxb=-1e9,mina=1e9,minb=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mina=min(mina,a[i]);
        maxa=max(maxa,a[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        minb=min(minb,b[i]);
        maxb=max(maxb,b[i]);
    }
    if((n==0)&&(m==0)){
        cout<<x*y<<'\n';
        return;
    }
    if(n==0){
        LL a1=x*(y+maxb);
        LL a2=x*(y+minb);
        LL c=x*y;
        cout<<max({a1,a2,c})<<'\n';
        return;
    }
    if(m==0){
        LL a1=y*(x+maxa);
        LL a2=y*(x+mina);
        LL c=x*y;
        cout<<max({a1,a2,c})<<'\n';
        return;        
    }
    LL a1=(x+maxa)*(y+maxb);
    LL e1=(x+mina)*(y+maxb);
    LL a2=(x+mina)*(y+minb);
    LL e2=(x+maxa)*(y+minb);
    LL b1=x*(y+maxb);
    LL b2=y*(x+maxa);
    LL d1=x*(y+minb);
    LL d2=y*(x+mina);
    LL c=x*y;
    LL ans=max({a1,a2,b1,b2,c,d1,d2,e1,e2});
    cout<<ans<<'\n';
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