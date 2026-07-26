#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
struct node{
    LL x,y;
    bool operator < (const node &o)const{
        if(x==o.x)return y<o.y;
        return x<o.x;
    }
};
void solve(){
    LL n,m;
    cin>>n>>m;
    map<LL,vector<node>> mp;
    vector<vector<LL>> d(n+3,vector<LL>(m+3,0)),a(n+3,vector<LL>(m+3,0)),ans(n+3,vector<LL>(m+3,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            LL x;
            cin>>x;
            mp[x].push_back({i,j});
        }
    }
    auto add=[&](LL x1,LL y1,LL x2,LL y2)->void{
        d[x1][y1]++;
        d[x1][y2+1]--;
        d[x2+1][y1]--;
        d[x2+1][y2+1]++;
    };
    for(auto &cp:mp){
        LL v=cp.first;
        LL siz=cp.second.size();
        if(siz==1)continue;
        sort(cp.second.begin(),cp.second.end());
        vector<node> pre,lst;
        pre.push_back(cp.second[0]);
        lst.push_back(cp.second[siz-1]);
        for(int i=1;i<siz;i++){
            if(cp.second[i].x!=cp.second[i-1].x){
                LL pnd=pre.back().y;
                if(pre.back().y<=cp.second[i].y){
                    pre.push_back(pre.back());
                }else{
                    pre.push_back(cp.second[i]);
                }
            }
        }
        for(int i=siz-2;i>=0;i--){
            if(cp.second[i].x!=cp.second[i+1].x){
                LL lnd=lst.back().y;
                if(lst.back().y>=cp.second[i].y){
                    lst.push_back(lst.back());
                }else{
                    lst.push_back(cp.second[i]);
                }
            }            
        }
        LL cnt=pre.size();
        for(int i=1;i<cnt;i++){
            if(pre[i-1].y>=lst[cnt-i-1].y)continue;
            add(pre[i-1].x,pre[i-1].y,lst[cnt-i-1].x,lst[cnt-i-1].y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[i][j]=d[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            LL x=ans[i][j]>=1?1:0;
            cout<<x;
        }
        cout<<'\n';
    }
    //printf("{|}");
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