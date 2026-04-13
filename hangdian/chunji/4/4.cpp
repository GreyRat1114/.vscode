#include<bits/stdc++.h>
using namespace std;
using LL=long long; 
LL n,m;
vector<LL> a;
vector<LL> xr;
vector<LL> vis;
bool dfs(LL mask){
    if(mask==0)return false;
    if(vis[mask]!=-1)return vis[mask];
    LL x=xr[mask];
    if(x==0)return vis[mask]=0;
    LL hb;
    for(int i=20;i>=0;i--){
        if((1<<i)&x){
            hb=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if((mask>>i)&1){
            if((a[i]>>hb)&1){
                LL nxt=mask^(1<<i);
                if(!dfs(nxt)){
                    return vis[mask]=1;
                }
            }
        }
    }
    return vis[mask]=0;
}
void solve(){
    cin>>n;
    LL S=(1<<n);
    a.resize(n+1);
    xr.assign(S,0);
    vis.assign(S,-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=(1<<n)-1;i++){
        LL s=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                s=s^a[j];
            }
        }
        xr[i]=s;
    }
    LL ans=dfs(S-1);
    if(ans){
        cout<<"Left"<<'\n';
    }else{
        cout<<"Right"<<'\n';
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}