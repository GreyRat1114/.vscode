#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
const int M=2e5+5;
int dx[N][N];
int sum[N][N];
int uu[M],dd[M],ll[M],rr[M];
void solve(){
    memset(sum,0,sizeof(sum));
    int n;
    int m=2000;
    cin>>n;
    int u,d,l,r;
    for(int i=1;i<=n;i++){
        cin>>u>>d>>l>>r;
        uu[i]=u,dd[i]=d,ll[i]=l,rr[i]=r;
        dx[u][l]++;
        dx[d+1][r+1]++;
        dx[u][r+1]--;
        dx[d+1][l]--;
    }
    for(int i=1;i<=m;i++){
        int s=0;
        for(int j=1;j<=m;j++){
            s+=dx[i][j];
            dx[i][j]=s+dx[i-1][j];
        }   
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        
        for(int j=1;j<=m;j++){
            if(dx[i][j]==0){
                cnt++;
                
            }
            if(dx[i][j]==1){
                sum[i][j]=1;
            }
        }   
    } 
    for(int i=1;i<=m;i++){
        int s=0;
        for(int j=1;j<=m;j++){
            s+=sum[i][j];
            sum[i][j]=s+sum[i-1][j];
        }   
    }     
    for(int i=1;i<=n;i++){
        u=uu[i];
        d=dd[i];
        l=ll[i];
        r=rr[i];
        int s=sum[d][r]-sum[u-1][r]-sum[d][l-1]+sum[u-1][l-1];
        int ans=cnt+s;
        cout<<ans<<'\n';
    }
    // for(int i=1;i<=7;i++){
    //     int s=0;
    //     for(int j=1;j<=7;j++){
    //         cout<<sum[i][j]<<' ';
    //     }   
    //     cout<<'\n';
    // }    
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    
    return 0;
}