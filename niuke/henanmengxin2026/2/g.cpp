#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=2000+10;
const LL atk=669;
struct node{
    LL x1,y1,x2,y2;
};
void solve(){
    LL n;
    cin>>n;
    LL m=2000;
    vector<node> a(n+1);
    vector<vector<LL>> d(N,vector<LL>(N,0)),s(N,vector<LL>(N,0)),c(N,vector<LL>(N,0));
    for(int i=1;i<=n;i++){
        LL x1,y1,x2,y2;
        cin>>x1>>x2>>y1>>y2;
        a[i]={x1,y1,x2,y2};
        d[x1][y1]++;
        d[x1][y2+1]--;
        d[x2+1][y1]--;
        d[x2+1][y2+1]++;
    }
    LL ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+d[i][j];
            if(s[i][j]==0)ans++;
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            LL def=0;
            if(s[i][j]==1)def=1;
            c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+def;
        }
    }
    //vector<LL> cnt(n+1,0);
    LL cnt=0;
    for(int i=1;i<=n;i++){
        cnt=c[a[i].x2][a[i].y2]-c[a[i].x1-1][a[i].y2]-c[a[i].x2][a[i].y1-1]+c[a[i].x1-1][a[i].y1-1];
        cout<<ans+cnt<<'\n';
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