#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void solve(){
    int n,m;
    cin>>n;
    int sum=1;
    int stx,sty;
    if(n&1){
        stx=sty=(n+1)/2;
    }
    else{
        stx=sty=(n)/2;
    }
    int dir=0;
    int x=stx,y=sty;
    vector<vector<int>>vis(n+5,vector<int>(n+5,false));
    vector<vector<int>>ans(n+5,vector<int>(n+5));
    for(int i=1;i<=n;i++){
        vis[0][i]=true,vis[i][0]=true;
        vis[n+1][i]=true,vis[i][n+1]=true;
    }
    vis[x][y]=true;
    while(sum<n*n){
       if(dir==0){
          y=y+1;
          if(!vis[x+1][y]){
            dir=(dir+1)%4;
            
          }
       }
       else if(dir==1){
           x=x+1;
            if(!vis[x][y-1]){
            dir=(dir+1)%4;
            //vis[x][y]=true;
          }
           
       }
       else if(dir==2){
          y=y-1;
          if(!vis[x-1][y]){
            dir=(dir+1)%4;
          //  vis[x][y]=true;
          }
       }
       else if(dir==3){
           x=x-1;
           if(!vis[x][y+1]){
            dir=(dir+1)%4;
            //vis[x][y]=true;
          }
       }
       ans[x][y]=sum;
       vis[x][y]=true;
       sum++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}