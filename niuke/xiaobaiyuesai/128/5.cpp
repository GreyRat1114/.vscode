#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
using LL=long long;
int a[N][N];
void solve(){

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=n+2;i++){
        for(int j=0;j<=m+2;j++){
            a[i][j]=0;
        }
    }
    int x1=n/3;
    int y1=n%3;
    int x2=m/3;
    int y2=m%3;
    for(int i=1;i<=x1;i++){
        a[2+3*(i-1)][0]=1;
    }
    if(y1==1){
        a[3*x1+1][0]=1;
    }else if(y1==2){
        a[3*x1+2][0]=1;
    }
    for(int i=1;i<=x2;i++){
        a[0][2+3*(i-1)]=1;
    }    
    if(y2==1){
        a[0][3*x2+1]=1;
    }else if(y2==2){
        a[0][3*x2+2]=1;
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[0][j]&&a[i][0]){
                tot++;
                a[i][j]=1;
            }
        }
    }

    int x=n*m-tot;
    //printf("{%d,%d}",x,tot);
    if(k>x){
        cout<<-1<<'\n';
        return;
    }

    for(int i=1;i<=n&&x!=k;i++){
        for(int j=1;j<=m&&x!=k;j++){
            if(a[i][j]==1){
                continue;
            }
            a[i][j]=1;
            x--;
        }
    }     

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
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