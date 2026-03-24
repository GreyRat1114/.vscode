#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int bfs(vector<vector<LL>> &dist,vector<pair<LL,LL>> &a,LL k){
    queue<pair<LL,LL>> q;
    q.push(make_pair(100,100));
    while(!q.empty()){
        LL x=q.front().first;
        LL y=q.front().second;
        q.pop();
        //printf("{%lld,%lld}",x,y);
        for(int i=1;i<=k;i++){
            LL x1=x+a[i].first;
            LL y1=y+a[i].second;

            if(x1==100&&y1==100){
                return dist[x][y]+1;
            }             
            if(x1>200||x1<0||y1<0||y1>200||dist[x1][y1]){
                continue;
            }   

            q.push(make_pair(x1,y1)); 
            dist[x1][y1]=dist[x][y]+1; 
                  
        }
    }
    return -1;
}
void solve(){
    int k;
    cin>>k;
    vector<vector<LL>> dist(205,vector<LL>(205,0));
    vector<pair<LL,LL>> a(k+1);
    LL x,y;
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        a[i].first=x;
        a[i].second=y;
    }
    LL ans=bfs(dist,a,k);
    cout<<ans<<'\n';
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}