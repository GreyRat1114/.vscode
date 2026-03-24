#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=5e5+5;
struct node{
    LL maxn;
    LL minn;
    int p1;
    int p2;
};

node f[N][25];
int n,q;
void solve(){
    
    int lt,rt;
    cin>>n>>q;
    for(int i=0;i<=n+100;i++){
        for(int j=0;j<=20;j++){
            f[i][j].maxn=-1;
            f[i][j].minn=1e9;
            f[i][j].p1=0;
            f[i][j].p2=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>f[i][0].maxn;
        f[i][0].minn=f[i][0].maxn;
        f[i][0].p1=i;
        f[i][0].p2=i;
    }
    for(int j=1;j<=20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            
            if(f[i][j-1].maxn>=f[i][j].maxn){
                f[i][j].maxn=f[i][j-1].maxn;
                f[i][j].p1=f[i][j-1].p1;
            }
            if(f[i+(1<<(j-1))][j-1].maxn>f[i][j].maxn){
                f[i][j].maxn=f[i+(1<<(j-1))][j-1].maxn;
                f[i][j].p1=f[i+(1<<(j-1))][j-1].p1;
            }
            if(f[i][j-1].minn<=f[i][j].minn){
                f[i][j].minn=f[i][j-1].minn;
                f[i][j].p2=f[i][j-1].p2;
            }
            if(f[i+(1<<(j-1))][j-1].minn<f[i][j].minn){
                f[i][j].minn=f[i+(1<<(j-1))][j-1].minn;
                f[i][j].p2=f[i+(1<<(j-1))][j-1].p2;
            }            
            printf("{%d,%d,%lld,%lld,%d,%d}",f[i][j].p1,f[i][j].p2,f[i][j].maxn,f[i][j].minn,i,j);
        }
    }
    
    for(int i=1;i<=q;i++){
        cin>>lt>>rt;
        int k=log2(rt-lt+1);
        LL p1,p2;
        // printf("<%d,%d,%lld,%lld>",f[lt][k].p1,f[lt][k].p2,f[rt-(1<<k)+1][k].maxn,f[rt-(1<<k)+1][k].minn);
        if(f[lt][k].maxn<=f[rt-(1<<k)+1][k].maxn){
            p1=f[rt-(1<<k)+1][k].p1;
        }
        if(f[lt][k].maxn>f[rt-(1<<k)+1][k].maxn){
            p1=f[lt][k].p1;
        }
        if(f[lt][k].minn<=f[rt-(1<<k)+1][k].minn){
            p2=f[lt][k].p2;
        }
        if(f[lt][k].minn>f[rt-(1<<k)+1][k].minn){
            p2=f[rt-(1<<k)+1][k].p2;
        }
        if(p1==lt&&p2==rt){
            cout<<'d'<<'\n';
        }
        if(p2==lt&&p1==rt){
            cout<<'u'<<'\n';
        }      
        if(p1<rt&&p1>lt){
            cout<<'t'<<'\n';
        } 
        if(p2<rt&&p2>lt){
            cout<<'t'<<'\n';
        } 
        printf("{%d,%d,%lld,%lld}",p1,p2,f[lt][k].maxn,f[rt-(1<<k)+1][k].maxn);
    }
}
int main()
{
    solve();
    return 0;
}