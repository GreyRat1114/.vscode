#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using pll=pair<LL,LL>;
vector<LL> w;
LL dx[]={-1,0,0,1};
LL dy[]={0,-1,1,0};
struct DSU{
    vector<LL> fa;
    vector<LL> siz,need,val;
    LL cnt;
    void init(LL n){
        fa.resize(n+1);
        siz.assign(n+1,1);
        need.assign(n+1,0);
        val.assign(n+1,0);
        cnt=n;
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
    } 
    pair<LL,LL> find(LL x){
        if(fa[x]==x){
            return {x,0};
        }
        pair<LL,LL> cp=find(fa[x]);
        LL fx=cp.first;
        LL cur=cp.second;
        cur=max(val[x],cur);
        fa[x]=fx;
        val[x]=cur;
        return {fx,cur};
    }
    void merge(LL x,LL y){
        pair<LL,LL> fx=find(x);
        pair<LL,LL> fy=find(y);
        if(fx.first!=fy.first){
            fa[fx.first]=fy.first;
            val[fx.first]=w[fy.first]-siz[fx.first]+1;
            siz[fy.first]+=siz[fx.first];
            cnt--;
        }
    }
    LL outsiz(LL x){
        pll fx=find(x);
        return siz[fx.first];
    }
};
void solve(){
    LL n,m,q;
    cin>>n>>m>>q;
    w.assign(n*m+1,-1);
    DSU fa;
    fa.init(n*m+1);
    LL op;
    LL l=0;
    for(int i=1;i<=q;i++){
        cin>>op;
        LL x,y,v;
        if(op==1){
            cin>>x>>y>>v;
            x=x^l;
            y=y^l;
            LL id1=(x-1)*m+y;
            w[id1]=v;
            for(int i=0;i<4;i++){
                LL x1=x+dx[i];
                LL y1=y+dy[i];
                if(x1<=0||x1>n||y1<=0||y1>m)continue;
                LL id2=(x1-1)*m+y1;
                //
                if(w[id2]==-1)continue;
                fa.merge(id2,id1);
                //printf("{%lld,%lld,%lld,%lld}\n",x,y,x1,y1);
            }
            l=fa.outsiz(id1)-1;
            cout<<l<<'\n';
        }else{
            cin>>x>>y;
            x=x^l;
            y=y^l;
            LL id1=(x-1)*m+y;  
            pll cp=fa.find(id1);          
            l=max(0ll,cp.second-w[id1]);
            cout<<l<<'\n';
        }
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