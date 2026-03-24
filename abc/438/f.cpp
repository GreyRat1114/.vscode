#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
vector<int> e[N];
LL siz[N];
int fa[N];
bool vis[N];
void dfs(int u,int f){
    siz[u]=1;
    fa[u]=f;
    for(auto v:e[u]){
        if(v==f){
            continue;
        }
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    int n;
    int u,v;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0,0);
    int l,r;
    l=0;
    r=0;
    LL ans=0;
    int tag=1;
    vis[0]=true;
    // for(int i=0;i<n;i++){
    //     printf("<%d>",fa[i]);
    // }
    for(int i=1;i<n;i++){
        if(vis[i]){
            continue;
        }
        int u=i;
        int pre;
        
        while(!vis[u]){
            vis[u]=true;
            pre=u;
            u=fa[u];
        }
        //printf("{%d %d %d}",u,pre,i);
        if(l==r){
            LL s=0;
            for(auto j:e[l]){
                if(j==pre){
                    ans+=(s+1)*(siz[j]-siz[i]);
                    s+=siz[j]-siz[i];
                }else{
                    ans+=(s+1)*siz[j];
                    s+=siz[j];
                }
            }
            ans++;
            //siz2[l]=siz[l]-siz[pre];
            siz[l]-=siz[pre];
            l=i;
            //cout<<ans<<'\n';
            continue;

        }
        if(u==l){
            ans+=siz[r]*(siz[l]-siz[i])*i;
            l=i;
        }else if(u==r){
            ans+=siz[l]*(siz[r]-siz[i])*i;
            
            r=i;

        }else{
            ans+=siz[l]*siz[r]*i;
            tag=0;
            break;
        }
        
    }
    if(tag){
        ans+=n;
    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}