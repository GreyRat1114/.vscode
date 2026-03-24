#include<bits/stdc++.h>
using namespace std;
const int N=500+5;
using LL=long long;
#define mp make_pair
LL a[N][N];
LL cnt[N][N];
LL dx[]={-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
LL dy[]={0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};
LL dd[]={5,8,8,8,5,8,13,8,5,8,8,8,5};
int n,m,q;
void sum(int x,int y){
    LL s=0;
    for(int i=0;i<13;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1<1||y1<1||x1>n||y1>m){
            continue;
        }
        s+=a[x1][y1];
    }
    cnt[x][y]=s;
}
void solve(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum(i,j);
            //printf("{%lld} ",cnt[i][j]);
            
        }
        //cout<<'\n';
    }    

    LL maxn=-1;
    LL mx,my;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cnt[i][j]>=maxn){
                mx=i;
                my=j;
                maxn=cnt[i][j];
            }
        }
    }      
    //printf("{%lld,%lld}",mx,my);  
    int x,y;
    LL z;
    for(int i=1;i<=q;i++){
        cin>>x>>y>>z;
        //update(x,y,z);
        for(int i=0;i<13;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<1||y1<1||x1>n||y1>m){
                continue;
            }

            cnt[x1][y1]+=z;
            if(cnt[x1][y1]>=maxn){
                mx=x1;
                my=y1;
                maxn=cnt[x1][y1];
            }
        } 
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("{%lld} ",cnt[i][j]);
            
    //     }
    //     cout<<'\n';
    // }  
        cout<<mx<<' '<<my<<'\n';      
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}