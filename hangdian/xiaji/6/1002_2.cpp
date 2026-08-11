#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
LL dx[]={-1,0,0,1};
LL dy[]={0,-1,1,0};
LL n,m;
vector<vector<LL>> a;
struct node{
    LL x,y,h,k;
    bool operator < (const node &o) const{
        return h>o.h;
    };
};
LL gets(map<LL,LL> &vis,LL tag){
    LL cnt=vis.size();
    if(tag==0){
        if(cnt==0)return 14;
        if(cnt==1)return 13;
        if(cnt==2){
            if((vis.count(0)&&vis.count(3))||(vis.count(1)&&vis.count(2))){
                return 7;
            }else{
                return 11;
            }
        } 
        if(cnt==3)return 6;
        if(cnt==4)return 0;        
    }else if(tag==1){
        if(cnt==0)return 20;
        if(cnt==1)return 18;
        if(cnt==2){
            if((vis.count(0)&&vis.count(3))||(vis.count(1)&&vis.count(2))){
                return 13;
            }else{
                return 15;
            }
        } 
        if(cnt==3)return 11;
        if(cnt==4)return 6;
    }else if(tag==2){
        if(cnt==0)return 21;
        if(cnt==1)return 20;
        if(cnt==2){
            if((vis.count(0)&&vis.count(3))||(vis.count(1)&&vis.count(2))){
                return 14;
            }else{
                return 18;
            }
        } 
        if(cnt==3)return 13;
        if(cnt==4)return 7;
    }
}
LL check(LL x,LL y){
    LL ans=0;
    vector<node> q;
    for(int i=0;i<4;i++){
        LL x1=x+dx[i];
        LL y1=y+dy[i];
        q.push_back({x1,y1,a[x1][y1],i});
    } 
    sort(q.begin(),q.end());
    
    map<LL,LL> vis;
    LL pre=a[x][y]-1;
    for(int i=0;i<4;i++){
        if(q[i].h>=pre){
            vis[q[i].k]=1;
            continue;
        }else{
            LL d=pre-max(1ll,q[i].h);
            ans+=d*gets(vis,0);
            pre=q[i].h;
            vis[q[i].k]=1;
        }
    }
    LL d=pre-1;
    ans+=d*gets(vis,0);
    return ans;
}
void solve(){
    cin>>n>>m;
    a.assign(n+2,vector<LL>(m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    LL ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0)continue;
            LL x=i;
            LL y=j;            
            if(a[i][j]==1){
                map<LL,LL> vis;
                for(int k=0;k<4;k++){
                    LL x1=x+dx[k];
                    LL y1=y+dy[k];
                    if(a[x1][y1]>=a[x][y])vis[k]=1;
                }
                ans+=gets(vis,2);
                //printf("{%lld,%lld,%lld}",i,j,ans);
            }else{
                map<LL,LL> vis;
                for(int k=0;k<4;k++){
                    LL x1=x+dx[k];
                    LL y1=y+dy[k];
                    if(a[x1][y1]>=a[x][y])vis[k]=1;
                }
                ans+=gets(vis,1);  
                //
                vis.clear();
                for(int k=0;k<4;k++){
                    LL x1=x+dx[k];
                    LL y1=y+dy[k];
                    if(a[x1][y1]>=1)vis[k]=1;
                }                
                ans+=gets(vis,1);
                
            }
            //
        }
    }
    //printf("{%lld}",ans);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((a[i][j]==0)||(a[i][j]==1)||(a[i][j]==2))continue;
            ans+=check(i,j);
            //printf("{%lld,%lld,%lld}",i,j,ans);
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
