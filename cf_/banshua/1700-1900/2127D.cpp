#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=1e9+7;
vector<LL> e[N];
//vector<vector<LL>> e;
vector<LL> fa;
vector<LL> siz;
vector<LL> f;
void init(LL n){
    for(int i=0;i<=n;i++){
        fa[i]=i;
        e[i].clear();
    }
}

void init1(LL n){
    f[0]=1;
    for(LL i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
}

LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans%mod;
}

LL find(LL x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

LL merge(LL x,LL y){
    LL fx=find(x);
    LL fy=find(y);
    if(fx==fy){
        return 0;
    }else{
        fa[fy]=fx;
        return 1;
    }
}
void solve(){
    LL n,m;
    cin>>n>>m;
    //e.assign(n+1,vector<LL>());
    fa.resize(n+1);
    f.assign(n+1,0);
    init(n);
    init1(n);
    LL tg=0;
    for(int i=1;i<=m;i++){
        LL u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        if(merge(u,v)==0){
            tg=1;
        }
    } 
    if(tg){
        cout<<0<<'\n';
        return;
    }
    vector<LL> vis(n+1,0);
    LL tot=0;
    for(int i=1;i<=n;i++){
        if(e[i].size()>1){
            vis[i]=1;
            tot++;
        }
    }
    LL ans=1;
    auto check=[&](LL x)->LL{  
        LL cnt=0; 
        for(auto y:e[x]){
            if(vis[y])cnt++;
        }
        return cnt;
    };
    for(int i=1;i<=n;i++){
        if(check(i)>2){
            cout<<0<<'\n';
            return;
        }   
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])continue;
        ans=ans*f[e[i].size()-check(i)]%mod;
    }
    LL d=tot>=2?2:1;
    cout<<2*d*ans%mod<<'\n';
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