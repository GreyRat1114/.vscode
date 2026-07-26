#include <bits/stdc++.h>
using namespace std;
#define int long long
using LL=long long;
int c[3505],p[3005];
int nex[2505];
int a[2505];
int vis[3005];
int price[3005],toll[3005];
bool stock[2505];
int pre[2505];
int cnt[2505];
void solve() {
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
       std::cin>>c[i];
       nex[i]=i+1;
       pre[i]=i-1;   
    }
    pre[1]=n;
    nex[n]=1;
    for(int i=0;i<m;i++){
        std::cin>>p[i];
        if(p[i]==1){
            std::cin>>price[i]>>toll[i];
        }
    }
    int len=n,k;
    std::cin>>k;
    memset(a,0,sizeof(a));
    memset(stock,false,sizeof(stock));
    memset(vis,-1,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    int pos=1;
    vector<LL> dd(k+1);
    for(int i=1;i<=k;i++){
        cin>>dd[i];
}
    LL kk=k;
    while((len>1)&&k){
        if(stock[pos]){
            stock[pos]=false;
            pos=nex[pos];
            continue;
        }
        LL d=dd[kk-k+1];
        k--;
        
        a[pos]=(a[pos]+d)%m;
        if(a[pos]==0){
            c[pos]+=200;
            pos=nex[pos];
        }else if((p[a[pos]]==1)&&(vis[a[pos]]==-1)){
            if(c[pos]>=price[a[pos]]){
                c[pos]-=price[a[pos]];
                vis[a[pos]]=pos;
                cnt[pos]++;
            }
            pos=nex[pos];
        }else if((p[a[pos]]==1)&&(vis[a[pos]]!=-1)){
            if(vis[a[pos]]==pos){
                pos=nex[pos];
                continue;
}
            if(c[vis[a[pos]]]<0){
              if(c[pos]>=price[a[pos]]){
                c[pos]-=price[a[pos]];
                vis[a[pos]]=pos;
                cnt[pos]++;
              }else{
                 vis[a[pos]]=-1;
              }
            }else{
               c[vis[a[pos]]]+=std::min(toll[a[pos]],c[pos]);
               c[pos]-=toll[a[pos]];
               if(c[pos]<0){
                  nex[pre[pos]]=nex[pos];
                  pre[nex[pos]]=pre[pos];
                  len--;
               }
            } 
            pos=nex[pos];
        }else if(p[a[pos]]==4){
            stock[pos]=true;
            pos=nex[pos];
        }else if(p[a[pos]]==2){
             c[pos]+=150;
             pos=nex[pos];
        }else if(p[a[pos]]==3){
              c[pos]-=100;
              if(c[pos]<0){
                nex[pre[pos]]=nex[pos];
                pre[nex[pos]]=pre[pos];
                len--;
              }
              pos=nex[pos];
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]>=0){
           std::cout<<c[i]<<" "<<cnt[i]<<'\n';
        }else{
            std::cout<<"bankrupt 0"<<'\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;

    while (t--) {
        solve();
    }

    return 0;
}