//luogu p3366
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> fa;
void init(LL n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
LL find(LL x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
LL merge(LL x,LL y){
    LL fx=find(x);
    LL fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
        return 1;
    }else{
        return 0;
    }
}
bool cmp(vector<LL> &a,vector<LL> &b){
    return a[2]<b[2];
}
void solve(){
    LL n,m;
    cin>>n>>m;
    fa.resize(n+1);
    init(n);
    vector<vector<LL>> e(m+1,vector<LL>(3,0));
    for(int i=1;i<=m;i++){
        LL x,y,z;
        cin>>x>>y>>z;
        e[i]={x,y,z};
    }
    sort(e.begin()+1,e.end(),cmp);
    LL cnt=0;
    LL ans=0;
    for(int i=1;i<=m;i++){
        if(merge(e[i][0],e[i][1])){
            cnt++;
            ans+=e[i][2];
        }
        if(cnt==n-1)break;
    }
    if(cnt==n-1){
        cout<<ans<<'\n';
    }else{
        cout<<"orz"<<'\n';
    }
    
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}