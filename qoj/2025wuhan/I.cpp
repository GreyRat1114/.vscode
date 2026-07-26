#include<bits/stdc++.h>
int ans[60][60];
bool vis[3000];
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=0;
        }
    }
    for(int i=1;i<=n*n;i++){
        vis[i]=false;
    }
}
void solve(){
    int n,k;
    std::cin>>n>>k;
    int m=n*n-n+1;
    init(n+3);
    if(k<n||k>m){
        std::cout<<"No"<<'\n';
        return ;
    }
    std::cout<<"Yes"<<'\n';
    // int cnt=k-1;
    // for(int i=1;i<=n-1;i++){
    //     ++cnt;
    //     vis[cnt]=true;
    //     ans[i][n]=cnt;
    // }
    // for(int j=1;j<n;j++){
    //     ++cnt;
    //     vis[cnt]=true;
    //     ans[n][j]=cnt;
    // }

    // int pos=1;
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<n;j++){
    //         while(vis[pos]){
    //             pos++;
    //         }
    //         vis[pos]=true;
    //         ans[i][j]=pos;
    //         ++pos;
    //     }
    // }
    // for(int i=1;i<=n*n;i++){
    //     if(!vis[i]){
    //         ans[n][n]=i;
    //         break;
    //     }
    // }
    int v = 1;
    for(int i=1;i<n;i++){
        ans[1][i] = v;
        vis[v] = true;
        v++;
    }
    ans[1][n] = k;
    vis[k] = true;
    int r = n*n;
    int ypos=1;
    for(int i=n;i>1;i--){
        ans[i][ypos] = r;
        vis[r] = true;
        r--;
        ypos++;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]==0){
                while(vis[v]){
                    ++v;
                }
                vis[v]=true;
                ans[i][j]=v;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<'\n';
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
