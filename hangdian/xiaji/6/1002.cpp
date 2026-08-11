#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;

LL dx[]={-1,0,0,1};
LL dy[]={0,-1,1,0};
vector<vector<LL>> c(10,vector<LL>(3,0));
LL n,m;
vector<vector<LL>> a;
void init(){
    c[1][0]=6;
    c[2][0]=11;
    c[2][1]=7;
    c[3][0]=15;
    c[3][1]=13;
    c[4][0]=14;
    c[4][1]=18;
    c[5][0]=20;
    c[6][0]=21;
}
struct node{
    LL x,y,h,f;
    bool operator < (const node &o) const{
        return h>o.h;
    };
};
// LL check(LL x,LL y){
//     LL cnt=0;
//     vector<node> q;
//     for(int i=0;i<4;i++){
//         LL x1=x+dx[i];
//         LL y1=y+dy[i];
//         q.push_back({x,y,a[x1][y1]});
//         if(a[x1][y1]>=a[x][y])cnt++;
//     }
//     sort(q.begin(),q.end());
//     LL pre=a[x][y];
//     if(cnt==4){
//         LL res=2*c[1][0];
//         return res;
//     }
//     if(cnt==1){
//         LL res=18;
//         int j=1;
//         int ms=1;
//         LL nex=std::max(1ll,q[j].h);
//         res+=(pre-q[j].h)*13;
//         if(q[j].x!=x&&q[j].y!=y)ms=0;
//         else ms=1;
//         pre=nex;
//         j++;
//         nex=std::max(1ll,q[j].h);
//         res+=(pre-nex)*c[2][ms];
//         j++,ms=0;
//         nex=std::max(1ll,q[j].h);
//         res+=(pre-nex)*c[1][0];
//         if(q[3].h>=1)res+=6;
//         else if(q[2].h>=1)res+=11;
//         else if(q[1].h>=1)res+=
//         else res+=18;
//     }

// }
LL check2(map<LL,LL> &vis,LL tag=0){
    LL cnt=vis.size();
    if(tag==0){
        if(cnt==0)return c[4][0];
        if(cnt==4)return 0;
        if(cnt==1)return c[3][1];
        if(cnt==3)return c[1][0];
        if(cnt==2){
            if((vis[0]&&vis[3])||(vis[1]&&vis[2])){
                return c[2][1];
            }else{
                return c[2][0];
            }
        }        
    }else if(tag==1){
        if(cnt==0)return c[5][0];
        if(cnt==4)return c[1][0];
        if(cnt==1)return c[4][0];
        if(cnt==3)return c[2][0];
        if(cnt==2){
            if((vis[0]&&vis[3])||(vis[1]&&vis[2])){
                return c[3][1];
            }else{
                return c[3][0];
            }
        }            
    }else{
        if(cnt==0)return 21;
        if(cnt==4)return 7;
        if(cnt==1)return 20;
        if(cnt==3)return 11;
        if(cnt==2){
            if((vis[0]&&vis[3])||(vis[1]&&vis[2])){
                return 14;
            }else{
                return 18;
            }
        }            
    }
    

}
LL work(){
    LL ans=0;
    map<LL,node> mp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(a[i][j]==0)continue;
            
            if(a[i][j]==1){
                map<LL,vector<LL>> inv;
                map<LL,LL> vis;
                for(int k=0;k<4;k++){
                    LL x1=i+dx[k];
                    LL y1=j+dy[k];
                    if(a[x1][y1]==0)continue;
                    inv[a[x1][y1]].push_back(k);
                }      
                for(auto mp:inv){
                    for(auto k:mp.second){
                        vis[k]=1;
                    }
                }
                ans+=check2(vis,2);     
                continue;
            }

            printf("{%lld,%lld,%lld}",i,j,ans);
            map<LL,vector<LL>> inv;
            map<LL,LL> vis;
            for(int k=0;k<4;k++){
                LL x1=i+dx[k];
                LL y1=j+dy[k];
                if(a[x1][y1]==0)continue;
                inv[a[x1][y1]].push_back(k);
            }      
            for(auto mp:inv){
                for(auto k:mp.second){
                    vis[k]=1;
                }
            }
            ans+=check2(vis,2);   

            for(int k=0;k<4;k++){
                LL x1=i+dx[k];
                LL y1=j+dy[k];
                mp[a[x1][y1]]={x1,y1,1,k};
            }   

            map<LL,LL> vis;
            auto it=mp.rbegin();
            for(;it->first>=a[i][j]&&it!=mp.rend();it++){
                vis[it->second.f]=1;
            }

            LL pre=a[i][j]-1;
            ans+=check2(vis,1);

            for(;it!=mp.rend();it++){
                LL cur=it->first;
                LL d=pre-cur;                
                if(it->first==0){
                    ans+=(d-1)*check2(vis,0);
                    ans+=check2(vis,1);
                }else{
                    ans+=d*check2(vis,0);
                }
                vis[it->second.f]=1;
            }
            
            //cout<<ans<<'\n';
        
        }
    }
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
    LL ans=work();
    cout<<ans<<'\n';
}

int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}
