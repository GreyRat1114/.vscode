#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<vector<LL>> xz(LL x,LL y,vector<vector<LL>> a){
    vector<vector<LL>> b(5,vector<LL>(5,0));
    b[x][y]=a[x][y+1];
    b[x][y+1]=a[x+1][y+1];
    b[x+1][y]=a[x][y];
    b[x+1][y+1]=a[x+1][y];
    return b;
}
LL get_v(LL x,LL y,vector<vector<LL>> &a){
    return a[x][y]+a[x+1][y]+a[x][y+1]+a[x+1][y+1];
}
LL dfs(LL c,LL val,vector<vector<LL>> a){
    LL maxn=0;
    LL mini=1e14;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            vector<vector<LL>> b=xz(i,j,a);
            LL v=get_v(i,j,a);
            dfs(c+1,val+v,b);
        }
    }
}
void solve(){
    LL k;
    cin>>k;
    vector<vector<LL>> a(5,vector<LL>(5,0));
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cin>>a[i][j];
        }
    }
    dfs(0,0);
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