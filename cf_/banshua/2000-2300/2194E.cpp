#include<bits/stdc++.h>
using namespace std;
using LL =long long;
struct node{
    LL val;
    LL x,y;
};
bool cmp(node a,node b){
    return a.val>b.val;

}
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<vector<LL>> a(n+1,vector<LL>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<LL>> dp1(n+2,vector<LL>(m+2,-1e18)),dp2(n+2,vector<LL>(m+2,-1e18));
    dp1[1][1]=a[1][1];
    dp2[n][m]=a[n][m];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)continue;
            dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
            //printf("{%lld}",dp1[i][j]);
        }
        //cout<<'\n';
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(i==n&&j==m)continue;
            dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+a[i][j];
        }
    }
    LL ans=-1e18;
    vector<vector<LL>> b(n+1,vector<LL>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            LL s=dp1[i][j]+dp2[i][j]-a[i][j];
            //printf("<%lld>",s);
            ans=max(ans,s);
            b[i][j]=s;
        }
    }        
    //printf("<%lld>",ans);
    LL tot=1;
    
    for(int k=2;k<=n+m;k++){
        // map<LL,pair<LL,LL>> mp;
        LL INF=1e18;
        node fi={-INF,0ll,0ll};
        node se={-INF,0ll,0ll};
        for(int i=max(1ll,k-m);i<=min(n,(LL)(k-1));i++){
            int j=k-i;
            if(j>m||j<1)continue;
            LL s=b[i][j];
            if(s>fi.val){
                se=fi;
                fi={s,i,j};
            }else if(s>se.val){
                se={s,i,j};
            }
        }
        LL minn=1e18;
        
        if(se.val==-1e18){
            ans=min(ans,fi.val-2*a[fi.x][fi.y]);
        }else{
            ans=min(ans,max(fi.val-2*a[fi.x][fi.y],se.val));
        }
        tot++;
    }    
    cout<<ans<<'\n';
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