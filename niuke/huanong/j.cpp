#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=2e5+5;
LL d[N];
vector<LL> e[N];
LL m[N];
LL fa[N][30];
LL siz[N];
LL n;
vector<multiset<LL>> st(N+1);

void dfs(LL u,LL f) {
    d[u]=d[f]+1;
    fa[u][0]=f;
    //printf("{%lld,%lld,%lld}",fa[u][0],u,f);
    siz[u]=1;
    for(auto v:e[u]) {
        if(v==f) {
            continue;
        }
        dfs(v,u);
        st[u].insert(m[v]);
        siz[u]+=siz[v];
        //chmax[u]=max(m[v],chmax[u]);
    }
}
void init(LL n) {
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=1; i<=n; i++) {
            fa[i][j]=fa[fa[i][j-1]][j-1];

        }
    }
}
LL find(LL u,LL cnt) {
    LL p=u;
    for(int i=19;i>=0;i--) {
        if((1<<i)<=cnt) {
         //   std::cerr<<i<<" "<<endl;
            cnt-=(1<<i);
            p=fa[p][i];
        }
        if(cnt==0) {
            break;
        }
    }
//    std::cerr<<p<<endl;
    return m[p];
}
LL check(LL u,LL w) {
    LL l=1;
    LL r=d[u];
    LL ans=1;
    while(l<=r) {
        LL mid=(l+r)/2;
        
        LL mw=find(u,d[u]-mid);

        if(mw>=w) {
            ans=mid;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }

    return ans;
}
void solve() {

    LL q;
    cin>>n>>q;
    for(int i=0; i<=n; i++) {
        e[i].clear();
        st[i].clear();
    }

    for(int i=1; i<=n; i++) {
        cin>>m[i];
    }
    LL u,v;
    for(int i=1; i<=n-1; i++) {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    init(n); 
    LL op,a,b;
    //std::cout<<endl;
    for(int i=1; i<=q; i++) {
        cin>>op>>a>>b;
        if(op==1) {
            LL pos=check(a,b);
            
            LL p=a;
            LL cnt=d[a]-pos;
            //printf("{%lld,%lld,%lld,%lld}",d[a],pos,p,cnt);
            for(int i=19; i>=0; i--) {
                if((1<<i)<=cnt) {
                    cnt-=(1<<i);
                    p=fa[p][i];
                }
                if(cnt==0) {
                    break;
                }
            }
            
            if(m[p]>=b){
                std::cout<<p<<'\n';
            
            }else{
                cout<<-1<<'\n';
            }
        }else{
            
            
            if(siz[a]==1&&a==1){
                cout<<"SUCCESS"<<'\n';
                m[a]+=b;
                continue;
            }            
            if(siz[a]==1) {
                if(m[fa[a][0]]<m[a]+b) {
                    std::cout<<"FAILED"<<'\n';
                } else {
                    std::cout<<"SUCCESS"<<'\n';
                    
                    st[fa[a][0]].erase(m[a]);
                    m[a]+=b;
                    st[fa[a][0]].insert(m[a]);
                    //chmax[fa[a][0]]=std::max(m[a],chmax[fa[a][0]]);
                }
                //printf("{%lld}",*st[1].rbegin());
                continue;
            }
            if(a==1){
                if(m[a]+b<*st[a].rbegin()) {
                    std::cout<<"FAILED"<<'\n';
                }else{
                    std::cout<<"SUCCESS"<<'\n';
                    m[a]+=b;
                    //chmax[fa[a][0]]=std::max(m[a],chmax[fa[a][0]]);
                }
                continue;
            }
            if(m[a]+b>m[fa[a][0]]||m[a]+b<*st[a].rbegin()) {
                cout<<"FAILED"<<'\n';
            } else {
                cout<<"SUCCESS"<<'\n';
                st[fa[a][0]].erase(m[a]);
                m[a]+=b;
                st[fa[a][0]].insert(m[a]);
            }
            //printf("{%lld}",m[a]);
            
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}