#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n,m;
    cin>>n>>m;
    map<LL,vector<array<LL,3>>> mp;
    for(int i=1;i<=n;i++){
        LL x,y;
        cin>>x>>y;
        mp[x].push_back({y,0,i});
    }
    vector<array<LL,3>> ans(n+1);
    for(int i=1;i<=m;i++){
        LL l,r,u,v;
        cin>>l>>r>>u>>v;
        auto itl=mp.lower_bound(l);
        //cerr<<i<<'\n';
        if(itl==mp.end())continue;
        //printf("{%lld}",i);
        vector<array<LL,4>> q;
        vector<LL> d;
        for(;itl!=mp.end()&&itl->first<=r;itl++){
            LL x=itl->first;
            for(auto j:itl->second){
                LL y=j[0];
                LL k=j[1];
                LL id=j[2];
                if(k==6){
                    ans[id]={x,y,k};
                    continue;
                }
                q.push_back({x+u,y+v,k+1,id});
                // //mp[x+u].push_back({});
            }
            d.push_back(x);
        }
        for(int j=0;j<d.size();j++){
            mp.erase(d[j]);
        }
        for(int j=0;j<q.size();j++){
            mp[q[j][0]].push_back({q[j][1],q[j][2],q[j][3]});
        }   

    }
    for(auto p:mp){
        for(auto dot:p.second){
            LL x=p.first;
            LL y=dot[0];
            LL k=dot[1];
            LL id=dot[2];
            ans[id]={x,y,k};
        }
        
    }
    for(int i=1;i<=n;i++){
        if(ans[i][2]==0){
            cout<<"Cumulus"<<' '<<ans[i][0]<<' '<<ans[i][1];
        }else if(ans[i][2]==6){
            cout<<"Disappeared";
        }else{
            cout<<"Cirrus"<<' '<<ans[i][0]<<' '<<ans[i][1];
        }
        cout<<'\n';
    }
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