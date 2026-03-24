#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
vector<int> e[N];
bool vis[N];
LL d[N];
LL dp[N][3];
LL ans[N];
bool ok[N];
int n;
LL k,c;
void dfs0(int u,int fa){
    
    for(auto v:e[u]){
        if(v==fa){
            continue;
        }
        d[v]=d[u]+1;
        dfs0(v,u);
    }    
}
void dfs(int u){
    // printf("{%d}",u);
    vis[u]=true;
    int tot=0;
    for(auto v:e[u]){
        if(vis[v]){
            continue;
        }
        tot++;
        dfs(v);
        ok[v]=true;
    }
    if(tot==0){
        return;
    }
    LL max1=-1,max2=-1;
    LL max3=-1,max4=-1;
    int p1=0,p2=0;
    
    for(auto v:e[u]){
        if(!ok[v]){
            continue;
        }
        if(dp[v][1]>max2){
            max2=dp[v][1];
            if(max2>max1){
                swap(max1,max2);
                p1=v;
            }
        }
        if(dp[v][0]>max4){
            max4=dp[v][0];
            if(max4>max3){
                swap(max3,max4);
                p2=v;
            }
        }
    }    
    //printf("{%lld %lld %d %d}",dp[p2][0],dp[p1][1],p1,p2);
    dp[u][0]=dp[p2][0]+k;
    dp[u][1]=dp[p1][1]+(k-c);  
    //printf("{%lld %lld %d}\n",dp[u][0],dp[u][1],u);  
    if(p1==p2){
        if(tot==1){
            ans[u]=dp[u][0]-d[u]*c;
        }
        else{
            //printf("<%lld><%lld>",max1+max4,max2+max3);
            ans[u]=max(max(max1+max4,max2+max3)-d[u]*c+k+k-c,max(dp[u][1],dp[u][0]));
        }   
    }else{
        ans[u]=max(max(dp[u][1],dp[u][0]),dp[u][1]+dp[u][0])-d[u]*c;
    }
}

void solve(){
    // memset(vis,false,sizeof(vis));
    // memset(ok,false,sizeof(ok));
    // memset(d,0,sizeof(d));
    // memset(dp,0,sizeof(dp));
    // memset(ans,0,sizeof(ans));
    int u,v;
    cin>>n>>k>>c;

    for(int i=0;i<=n+5;i++){
        e[i].clear();
        vis[i]=false;
        ok[i]=false;
        d[i]=0;
        ans[i]=0;
        dp[i][0]=0;
        dp[i][1]=0;
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    // if(c>=k){

    //     return;
    // }
    dfs0(1,1);
    dfs(1);
    LL res=0;
    for(int i=1;i<=n;i++){
        res=max(res,ans[i]);
    }
    cout<<res<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}