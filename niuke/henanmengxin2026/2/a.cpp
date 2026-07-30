#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
const LL atk=669;
LL dx[]={-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
LL dy[]={0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};
LL dx1[]={-1,0,0,1};
LL dy1[]={0,-1,1,0};
struct node{
    LL x,y;
    bool operator < (const node &o)const{
        if(x==o.x)return y<o.y;
        return x<o.x;
    }
};
map<node,LL> mp;
map<node,vector<node>> inv;
set<node> st;
void fang(LL x,LL y){
    //printf("|%lld,%lld|\n",x,y);
    LL d=0;
    if((x>=0)&&(x<=4)&&(y>=-2)&&(y<=2)){
        d=4*atk;
    }else{
        d=2*atk;
    }
    for(int i=0;i<13;i++){
        LL x1=x+dx[i];
        LL y1=y+dy[i];
        mp[{x1,y1}]+=d;
        inv[{x1,y1}].push_back({x,y});
        //printf("{%lld,%lld,%lld}\n",x1,y1,d);
    }    
}
void xiao(LL x,LL y){
    
    LL d=0;
    if((x>=0)&&(x<=4)&&(y>=-2)&&(y<=2)){
        d=4*atk;
    }else{
        d=2*atk;
    }
    for(int i=0;i<13;i++){
        LL x1=x+dx[i];
        LL y1=y+dy[i];
        mp[{x1,y1}]-=d;
        //printf("{%lld,%lld,%lld}\n",x1,y1,mp[{x1,y1}]);
    }      
}
void zha(LL x,LL y){
    for(auto nd:inv[{x,y}]){
        //printf("{%lld,%lld}",nd.x,nd.y);
        //printf("|%lld,%lld|\n",nd.x,nd.y);
        if(!st.count({nd.x,nd.y}))continue;
        xiao(nd.x,nd.y);
        st.erase({nd.x,nd.y});
    }
    //inv.erase({x,y});
}
void solve(){
    mp.clear();
    LL n;
    cin>>n;
    map<node,LL> vis;
    vis.clear();
    inv.clear();
    for(int i=1;i<=n;i++){
        LL x,y;
        cin>>x>>y;
        vis[{x,y}]++;
        st.insert({x,y});
        fang(x,y);
    }
    LL m;
    cin>>m;
    for(int i=1;i<=m;i++){
        LL x,y;
        cin>>x>>y;
        vis[{x,y}]++;
        st.insert({x,y});
        fang(x,y);
        if((x>=0)&&(x<=4)&&(y>=-2)&&(y<=2)){
            for(int j=0;j<4;j++){
                LL x1=x+dx1[j];
                LL y1=y+dy1[j];
                //printf("{%lld,%lld}",x1,y1);
                if(vis[{x1,y1}]!=0)continue;         
                if(x1==0&&y1==0)continue;
                fang(x1,y1);
                vis[{x1,y1}]++;
                st.insert({x1,y1});
                //printf("{%lld,%lld}",x1,y1);
            }
        }
    }
    LL q;
    cin>>q;
    for(int i=1;i<=q;i++){
        LL x,y;
        cin>>x>>y;
        cout<<mp[{x,y}]<<'\n';
        zha(x,y);
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