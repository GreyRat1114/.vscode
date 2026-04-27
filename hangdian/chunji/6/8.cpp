#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct DSU{
    vector<LL> fa;
    LL cnt;
    void init(LL n){
        fa.resize(n+1); 
        cnt=n;  
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
    }
    LL find(LL x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void merge(LL x,LL y){
        LL fx=find(x);
        LL fy=find(y);
        if(fx!=fy){
            fa[fx]=fy;
            cnt--;
        }
    }
};
void solve(){
    LL n,m;
    cin>>n>>m;
    DSU all,b,w;
    all.init(n);
    b.init(n);
    w.init(n);
    for(int i=1;i<=m;i++){
        LL u,v,c;
        cin>>u>>v>>c;
        all.merge(u,v);
        if(c){
            w.merge(u,v);
        }else{
            b.merge(u,v);
        }
    }
    if(all.cnt!=1){
        cout<<0<<'\n';
        return;
    }
    LL r=n-b.cnt;
    LL l=w.cnt-1;
    cout<<r-l+1<<'\n';
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