#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
struct DSU{
    vector<LL> fa;
    LL siz;
    void init(LL n){
        fa.resize(n+1);
        siz=n;
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
    }
    LL find(LL x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void merge(LL x,LL y){
        LL fx=find(x);
        LL fy=find(y);
        if(fx!=fy){
            fa[fx]=fy;
            siz--;
        }
    }
};
void solve(){
    LL n,d;
    cin>>n>>d;
    string s;
    cin>>s;
    vector<LL> vis(n+1,0);
    map<LL,map<char,LL>> mp; 
    DSU fa;
    fa.init(n+1);
    for(int i=0;i<n;i++){
        if(vis[i])continue;
        LL l=i;
        LL r=n-i-1;
        do{
            fa.merge(l,r);
            vis[l]=1;
            vis[r]=1;
            l=(l+d)%n;
            r=(r+d)%n;
        }while(l!=i);
    }

    for(int i=0;i<n;i++){
        LL fx=fa.find(i);
        mp[fx][s[i]]++;
    }
    LL ans=0;
    for(auto cp:mp){
        LL maxn=0;
        for(auto cp2:cp.second){
            maxn=max(maxn,cp2.second);
        }
        ans+=maxn;
        //printf("{%lld}",x);
    }
    cout<<n-ans<<'\n';

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