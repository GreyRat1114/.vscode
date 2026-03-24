#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e7+5;
#define tag fa
LL fa[N];
LL vis[N];
void init(){
    for(int i=0;i<=N;i++){
        fa[i]=i;
        vis[i]=-1;
    }
}
LL find(LL x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(LL x,LL y){
    //printf("<%lld,%lld>");
    LL fx=find(x);
    LL fy=find(y);
    if(fx!=fy){
        fa[fy]=fx;     
        //printf("<%lld,%lld>",fx,fy);
    }
}
void solve(){
    LL n;
    cin>>n;
    init();
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(vis[a[i]]==-1){
            vis[a[i]]=i;
            tag[i]=i;
        }else{
            tag[i]=vis[a[i]];
        }
    }
    LL tot=n;
    LL m;
    cin>>m;
    LL x,y,z;
    for(int i=1;i<=m;i++){
        cin>>x;
        if(x==1){
            cin>>y>>z;
            //printf("{%d,%d}",vis[y],vis[z]);
            if(vis[z]==-1){
                vis[z]=vis[y];
                a[vis[y]]=z;
            }else{
                tag[vis[y]]=vis[z];
            }
            vis[y]=-1;
        }else if(x==2){
            cin>>y;
            tot++;
            a.push_back(y);
            if(vis[a[tot]]==-1){
                vis[a[tot]]=tot;
                tag[tot]=tot;
            }else{
                tag[tot]=vis[a[tot]];
            }           
        }else{
            cin>>y;
            a[vis[y]]=0;
            vis[y]=-1;
        }
    
    }
    for(int i=1;i<=tot;i++){
        LL fx=find(i);
        if(a[fx]!=0){
            cout<<a[fx]<<' ';
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}