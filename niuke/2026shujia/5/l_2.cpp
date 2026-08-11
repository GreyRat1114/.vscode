#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
LL dx[]={0,1};
LL dy[]={1,0}; 
LL n,m;
vector<vector<LL>> a,b,vis;
LL pre;
LL bfs(){
    queue<pair<LL,LL>> q;
    q.push({1,2});
    q.push({2,1});
    vis[1][2]=1;
    vis[2][1]=1;
    while(!q.empty()){
        LL x=q.front().first;
        LL y=q.front().second;
        q.pop();
        for(int i=0;i<2;i++){
            LL x1=x+dx[i];
            LL y1=y+dy[i];
            if(x1<1||y1<1||x1>n||y1>m)continue;
            LL d=pre-a[x1][y1];
            if(d<0)return 0;
            LL def=min(d,b[x][y]);
            b[x][y]-=def;
            a[x1][y1]+=def;
            b[x1][y1]+=def;
            if(a[x1][y1]==pre&&vis[x1][y1]!=1){
                vis[x1][y1]=1;
                q.push({x1,y1});
            }
        }
    }
    return 1;
}
void solve(){
    pre=-1e10;
    cin>>n>>m;
    a.assign(n+1,vector<LL>(m+1,0));
    b.assign(n+1,vector<LL>(m+1,0));
    vis.assign(n+1,vector<LL>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    if(n==1&&m==1){
        cout<<0<<'\n';
        return;
    }    
    if(n==1){
        //printf("{}");
        for(int i=2;i<=m;i++){
            if(a[1][i]!=a[1][i-1]){
                cout<<-1<<'\n';
                return;
            }
        }
        cout<<0<<'\n';
        return;
    }
    if(m==1){
        for(int i=2;i<=n;i++){
            if(a[i][1]!=a[i-1][1]){
                cout<<-1<<'\n';
                return;
            }
        }
        cout<<0<<'\n';
        return;
    }
    if(a[1][2]<a[1][1]&&a[2][1]<a[1][1]){
        cout<<-1<<'\n';
        return;
    }
    pre=max(a[1][2],a[2][1]);
    if(a[1][2]>=a[2][1]){
        LL d=a[1][2]-a[2][1];
        b[2][1]=d;
        b[1][1]=d;
        a[1][1]+=d;
    }else{
        LL d=a[2][1]-a[1][2];
        b[1][2]=d;
        b[1][1]=d;
        a[1][1]+=d;
    }
    LL def=(pre-a[1][1]);
    if(def<0){
        cout<<-1<<'\n';
        return;
    }
    //printf("{%lld}",def);
    b[2][1]+=def;
    b[1][2]+=def;
    pre+=def;
    LL flow=b[1][2]+b[2][1];
    if(!bfs()){
        cout<<-1<<'\n';
        //printf("{}");
    }else{
        LL tag=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i+j<=3)continue;
                if(a[i][j]!=pre)tag=0;
                if(i==n&&j==m)continue;
                if(b[i][j]!=0)tag=0;
            }
        }
        if(tag){
            cout<<flow<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    
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