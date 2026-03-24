#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e3+5;
int d[N][N];
int ans[N][N];
void solve(){
    memset(ans,0,sizeof(ans));
    int n,m;
    cin>>n>>m;
    int x1,x2,y1,y2;
    for(int i=1;i<=m;i++){
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<=x2;j++){
            d[j][y1]++;
            d[j][y2+1]--;
            
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=ans[i][j-1]+d[i][j];
            cout<<ans[i][j]<<' ';

        }
        cout<<'\n';
    }

}
int main(){
    solve();
    return 0;
}