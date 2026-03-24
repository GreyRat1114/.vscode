#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e6+5;
#define mp make_pair
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
//vector<pair<LL,LL>> e1[N];
LL n,m;
bool bfs(LL my,vector<LL> &t,LL tl,vector<bool> &vis,vector<vector<pair<LL,LL>>> &e){
    priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> q;
    q.push({0,1});
    while(!q.empty()){
        LL c=q.top().first;
        LL u=q.top().second;
        q.pop();        
        if(vis[u]){
            continue;
        }
        vis[u]=true;

        if(c>my){
            continue;
        }
        if(u==n*m){
            return true;
        }
        for(auto x:e[u]){
            LL v=x.first;
            LL c1=x.second;
            if(vis[v]){
                continue;
            }
            if(t[v]>tl){
                continue;
            }
            //printf("{%lld,%lld,%lld,%lld,}",tl,u,v,t[v]);
            q.push({c+c1,v});
        }

    }
    return false;
}

void solve(){
    LL my,k;
    cin>>n>>m>>my>>k;
    vector<LL> t(n*m+1,0);
    vector<LL> t1(n*m+1,0);
    vector<vector<pair<LL,LL>>> e(n*m+1);
    //vector<vector<LL>> t(n+1,vector<LL>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>t[m*(i-1)+j];
            t1[m*(i-1)+j]=t[m*(i-1)+j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            LL pos0=m*(i-1)+j;
            for(int k1=0;k1<4;k1++){
                int x1=i+dx[k1];
                int y1=j+dy[k1];
                if(x1<1||y1<1||x1>n||y1>m){
                    continue;
                }                
                LL pos=m*(x1-1)+y1;
                e[pos0].push_back(mp(pos,0));
            }
        }
    }    
    LL x,y,p,q,w;
    for(int i=1;i<=k;i++){
        cin>>x>>y>>p>>q>>w;
        LL p1=m*(x-1)+y;
        LL p2=m*(p-1)+q;
        e[p1].push_back(mp(p2,w));
    }
    LL l=1;
    LL r=n*m;
    t1[0]=0;
    sort(t1.begin(),t1.end());
    LL ans=0;
    vector<bool> vis(n*m+1,false);
    while(l<=r){
        for(int i=0;i<=n*m;i++){
            vis[i]=false;
        }
        LL mid=(l+r)/2;
        //printf("<%d,%lld>",h,mid);
        if(bfs(my,t,t1[mid],vis,e)){
            ans=t1[mid];
            r=mid-1;
        }else{
            l=mid+1;
        }
        //cout<<'\n';
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);    
    int t1=1;
    cin>>t1;
    while(t1--){
        solve();
    }
    return 0;
}