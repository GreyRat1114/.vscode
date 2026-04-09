#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,q;
    cin>>n;
    cin>>q;
    vector<vector<LL>> op(q+1,vector<LL>(4,0));
    LL dir,x,y,len;
    for(int i=1;i<=q;i++){
        cin>>op[i][0]>>op[i][1]>>op[i][2]>>op[i][3];
    }
    LL d;
    cin>>d;
    LL dx,dy;
    vector<pair<LL,LL>> qy(d+1);
    for(int i=1;i<=d;i++){
        cin>>qy[i].first>>qy[i].second;
    }
    
    for(int i=q;i>=1;i--){
        dir=op[i][0];
        x=op[i][1];
        y=op[i][2];
        len=op[i][3];
        for(int j=1;j<=d;j++){
            LL x1=qy[j].first;
            LL y1=qy[j].second;
            if(x1>=x&&x1<=x+len-1&&y1>=y&&y1<=y+len-1){
                LL x2=x1-x;
                LL y2=y1-y;
                //printf("{%lld,%lld}",x2,y2);
                LL x3,y3;
                if(dir==1){
                    LL x3=len-y2-1;
                    LL y3=x2;
                    qy[j].first=x3+x;
                    qy[j].second=y3+y;                    
                }else{
                    LL x3=y2;
                    LL y3=len-x2-1;  
                    qy[j].first=x3+x;
                    qy[j].second=y3+y;                                     
                }

                //printf("{%lld,%lld,%lld,%lld}",i,j,x3+x,y3+y); 
            }
        }
    }
    for(int i=1;i<=d;i++){
        cout<<(qy[i].first-1)*n+qy[i].second<<'\n';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}