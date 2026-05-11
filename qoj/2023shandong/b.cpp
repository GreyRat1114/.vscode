#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL gn;
    cin>>gn;
    vector<pair<LL,LL>> g(gn+1);
    LL x,y;
    for(int i=0;i<gn;i++){
        cin>>x>>y;
        g[i].first=x;
        g[i].second=y;
        //printf("{%lld,%lld}",x,y);
    }
    
    LL n;
    cin>>n;
    vector<vector<pair<LL,LL>>> need(n+1),come(n+1);
    map<LL,map<LL,LL>> mp;
    map<LL,priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>>> pq;
    queue<LL> q; 
    LL ans=0;
    come[0]=g;
    q.push(0);
    for(int i=1;i<=n;i++){
        LL m;
        cin>>m;
        if(m==0)q.push(i);
        for(int j=1;j<=m;j++){
            cin>>x>>y;
            need[i].push_back({x,y});
            mp[i][x]=y;
            pq[x].push(make_pair(y,i));
        }
        LL k;
        cin>>k;
        
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            come[i].push_back({x,y});
        }
    }

    
    
    //printf("{%lld,%lld}",come[0][0].first,come[0][0].second);
      
    
    map<LL,LL> c;
    while(!q.empty()){
        ans++;
        LL u=q.front();
        //cerr<<u<<'\n';
        //printf("{%lld}",u);
        q.pop();
        for(auto z:come[u]){
            LL id=z.first;
            LL cnt=z.second;
            c[id]+=cnt;
            //cerr<<id<<' '<<cnt<<'\n';
            //cerr<<c[id]<<'\n';
            while(!pq[id].empty()&&pq[id].top().first<=c[id]){
                //cerr<<id<<' '<<pq[id].top().first<<'\n';
                LL v=pq[id].top().second;
                pq[id].pop();
                mp[v].erase(id);
                if(mp[v].size()==0){
                    q.push(v);
                    //cerr<<v<<' '<<id<<' '<<ans<<'\n';
                }
            }
        }
    }
    cout<<ans-1<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}