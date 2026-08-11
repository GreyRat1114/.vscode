#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n,m;
    cin>>n>>m;

    vector<vector<LL>> a(n+1,vector<LL>(m+1,0)),b(n+1,vector<LL>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    if(n==1&&m==1){
        cout<<0<<'\n';
        return;
    }    
    if(n==1){
        //printf("{}");
        for(int i=2;i<=m;i++){
            if(a[1][i]!=a[1][i-1]){
                cout<<-1<<'\n';
                return;
            }
        }
        cout<<0<<'\n';
        return;
    }
    if(m==1){
        for(int i=2;i<=n;i++){
            if(a[i][1]!=a[i-1][1]){
                cout<<-1<<'\n';
                return;
            }
        }
        cout<<0<<'\n';
        return;
    }
    if(a[1][2]<a[1][1]&&a[2][1]<a[1][1]){
        cout<<-1<<'\n';
        return;
    }
    LL pre=max(a[1][2],a[2][1]);
    if(a[1][2]>=a[2][1]){
        LL d=a[1][2]-a[2][1];
        b[2][1]=d;
        b[1][1]=d;
        a[1][1]+=d;
    }else{
        LL d=a[2][1]-a[1][2];
        b[1][2]=d;
        b[1][1]=d;
        a[1][1]+=d;
    }
    LL def=(pre-a[1][1]);
    if(def<0){
        cout<<-1<<'\n';
        return;
    }
    //printf("{%lld}",def);
    b[2][1]+=def;
    b[1][2]+=def;
    pre+=def;
    LL flow=b[1][2]+b[2][1];
    //printf("{%lld}",pre);
    if(n<=m){
        LL tot=4;
        LL maxm=min(2ll,m);
        
        while(tot<=n+m){
            maxm=min(maxm+1,m);
            //printf("{%lld}",maxm);
            LL pp=0;
            LL s=0;
            LL c=0;
            for(int j=maxm;j>=1;j--){
                int i=tot-j;
                if(i>n)break;
                //printf("{%lld,%lld}",i,j);
                c++;
                s+=a[i][j];
                if(i==1){
                    LL d=pre-a[i][j];
                    if(d<0||d>b[i][j-1]){
                        
                        cout<<-1<<'\n';
                        return;
                    }
                    b[i][j-1]-=d;
                    b[i][j]=d;
                    pp+=d;
                    continue;
                }
                if(j==1){
                    LL d=pre-a[i][j];
                    if(d<0||d>b[i-1][j]){
                        cout<<-1<<'\n';
                        return;
                    }           
                    b[i-1][j]-=d;    
                    b[i][j]=d;
                    pp+=d;
                    continue; 
                }
                LL d=pre-a[i][j];
                if(d<0||b[i][j-1]+b[i-1][j]<d){
                    cout<<-1<<'\n';
                    return;
                }
                LL pt1=min(b[i-1][j],d);
                b[i-1][j]-=pt1;
                d-=pt1;
                LL pt2=min(b[i][j-1],d);
                b[i][j-1]-=pt2;
                b[i][j]+=pt2+pt1;
                pp+=b[i][j];
            }   
            tot++;
            if(pp!=flow){
                //printf("{%lld}",tot);
                //printf("{%lld}",pp);
                cout<<-1<<'\n';
                return;
            }   
        }
    }else{
        LL tot=4;
        LL maxn=min(2*1ll,n);
        while(tot<=n+m){
            maxn=min(maxn+1,n);
            LL pp=0;
            LL s=0;
            LL c=0;
            for(int i=maxn;i>=1;i--){
                int j=tot-i;
                if(j>m)break;
                //printf("{%lld,%lld}",i,j);
                c++;
                s+=a[i][j];
                if(i==1){
                    LL d=pre-a[i][j];
                    if(d<0||d>b[i][j-1]){
                        cout<<-1<<'\n';
                        return;
                    }
                    b[i][j-1]-=d;
                    b[i][j]=d;
                    pp+=d;
                    continue;
                }
                if(j==1){
                    LL d=pre-a[i][j];
                    if(d<0||d>b[i-1][j]){
                        cout<<-1<<'\n';
                        return;
                    }           
                    b[i-1][j]-=d;    
                    b[i][j]=d;
                    pp+=d;
                    continue; 
                }
                LL d=pre-a[i][j];
                if(d<0||b[i][j-1]+b[i-1][j]<d){
                    cout<<-1<<'\n';
                    return;
                }
                LL pt1=min(b[i-1][j],d);
                b[i-1][j]-=pt1;
                d-=pt1;
                LL pt2=min(b[i][j-1],d);
                b[i][j-1]-=pt2;
                b[i][j]+=pt1+pt2;
                pp+=b[i][j];
            }   
            tot++;        
            if(pp!=flow){
                cout<<-1<<'\n';
                return;
            }   
        }
    }
    cout<<flow<<'\n';
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