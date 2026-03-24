#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=20;
#define LL long long
int n,m;
int a[N][N];
int nw[N][N];
int b[N][N];
int c[N][N];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int work(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=nw[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i!=1&&a[i-1][j]){
                b[i][j]=1;
            }
            if(b[i][j]==1){
                a[i][j]=!a[i][j];
                for(int k=0;k<4;k++){
                    int x1=i+dx[k];
                    int y1=j+dy[k];
                    if(x1<1||y1<1||x1>m||y1>n){
                        continue;
                    }
                    a[x1][y1]=!a[x1][y1];
                }
            }
        }
    }    
    int res=0;
    for(int i=1;i<=n;i++){
        if(a[m][i]){
            return -1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]){
                res++;
            }
        }
    }    
    return res;        
}
void solve(){
    memset(a,0,sizeof(a));
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>nw[i][j];
        }
    }
    int tag=0;
    int ans=1e9;
    for(int i=0;i<(1<<n);i++){
        memset(b,0,sizeof(b));
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                b[1][j+1]=1;
            }
        }
        
        int minn=work();
        if(minn!=-1){
            tag=1;
            if(minn<ans){
                for(int i1=1;i1<=m;i1++){
                    for(int j1=1;j1<=n;j1++){
                        c[i1][j1]=b[i1][j1];
                    }
                }          
                ans=minn;      
            }
        }

    }
    if(!tag){
        cout<<"IMPOSSIBLE"<<'\n';
    }else{
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cout<<c[i][j]<<' ';
            }
            cout<<'\n';
        }            
    }
}
int main(){
    solve();
    return 0;
}