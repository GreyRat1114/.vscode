#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
LL xi[N];
LL yi[N];
LL dx[]={-1,-2,-2,-1,1,2,2,1};
LL dy[]={-2,-1,1,2,2,1,-1,-2};
LL ddx[]={-1,-1,-1,0,0,1,1,1};
LL ddy[]={-1,0,1,-1,1,-1,0,1};
LL xx[N];
LL yy[N];
bool vis[N];
void solve(){
    memset(vis,false,sizeof(vis));
    LL n,x,y;
    cin>>x>>y>>n;
    for(int i=1;i<=n;i++){
        cin>>xi[i]>>yi[i];
        // printf("{%d,%d}",xi[i],yi[i]);
    }

    for(int i=0;i<8;i++){
        xx[i]=x+ddx[i];
        yy[i]=y+ddy[i];
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<8;j++){
            LL x1=xi[i]+dx[j];
            LL y1=yi[i]+dy[j];
            // printf("{%lld,%lld}",x1,y1);
            if(x1==x&&y1==y){
                cout<<'B'<<'\n';
                return;
            }
            for(int k=0;k<8;k++){
                if(xx[k]==x1&&yy[k]==y1&&!vis[k]){
                    tot++;
                    vis[k]=true;
                }
            }
        }        
    }
    // printf("(%d)",tot);
    if(tot==8){
        cout<<'A'<<'\n';
    }
    else{
        cout<<'C'<<'\n';
    }

}    
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}