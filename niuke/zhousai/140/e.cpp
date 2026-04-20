#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> fa;
void init(LL n){
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
}
LL find(LL x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
void merge(LL x,LL y){
    LL fx=find(x);
    LL fy=find(y);
    if(fx!=fy){
        fa[fy]=fx;
    }
}
void solve(){
    LL n,x,y;
    cin>>n>>x>>y;
    fa.resize(n+1);
    init(n);
    vector<LL> a(n+1),d(n+1,0),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=abs(a[i]-i);
        pos[a[i]]=i;
    }
    //vector<LL> vis(n+1,0);
    for(int i=1;i<=n;i++){
        //if(vis[i])continue;
        if(i+x<=n){
            merge(i,i+x);
        }
        if(i+y<=n){
            merge(i,i+y);
        }
        if(i-x>=1){
            merge(i,i-x);
        }
        if(i-y>=1){
            merge(i,i-y);
        }
    }
    for(int i=1;i<=n;i++){
        if(find(i)!=find(pos[i])){
            cout<<"No"<<'\n';
            return;
        }
    }
    cout<<"Yes"<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}