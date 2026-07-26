#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    vector<vector<LL>> b(40,vector<LL>(4,0));

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL c=0;
    for(int i=1;i<=n;i++){
        LL x=a[i];
        LL pre=0;
        //printf("{%lld}",pre);
        for(int j=0;j<31;j++){
            LL cur=((x&(1<<j))==0)?0:1;
            //printf("{%lld}",cur);
            LL y=2*cur+pre;
            
            b[j][y]++;
            
            // if(y==2){
            //     //printf("{%lld,%lld,%lld,%lld,%lld,%lld}",i,j,b[j][y],cur,pre,y);
            // }
            pre=cur;
        }
    }   
    //     for(int j=0;j<31;j++){
    //         c+=b[j][2];
    //     }
    //     cout<<c<<'\n';
    // for(int i=7;i>=0;i--){
    //     printf("{%lld}",b[i][2]);
    // }
    LL m;
    cin>>m;
    for(int i=1;i<=m;i++){
        LL type,x;
        cin>>type>>x;
        if(type==1){
            for(int j=0;j<31;j++){
                if((x&(1<<j))==0){
                    b[j][1]+=b[j][3];
                    b[j][0]+=b[j][2];
                    b[j][2]=0;
                    b[j][3]=0;                    
                    b[j+1][0]+=b[j+1][1];
                    b[j+1][2]+=b[j+1][3];
                    b[j+1][1]=0;
                    b[j+1][3]=0;
                    // printf("|");
    // for(int i=7;i>=0;i--){
    //     printf("{%lld}",b[i][2]);
    // }
                }
            }
        }else if(type==2){
            for(int j=0;j<31;j++){
                if((x&(1<<j))!=0){
                    b[j][3]+=b[j][1];
                    b[j][2]+=b[j][0];
                    b[j][1]=0;
                    b[j][0]=0;                    
                    b[j+1][1]+=b[j+1][0];
                    b[j+1][3]+=b[j+1][2];
                    b[j+1][0]=0;
                    b[j+1][2]=0;

                }
            }            
        }else{
            for(int j=0;j<31;j++){
                if((x&(1<<j))!=0){
                    swap(b[j][0],b[j][2]);
                    swap(b[j][1],b[j][3]);
                    swap(b[j+1][0],b[j+1][1]);
                    swap(b[j+1][2],b[j+1][3]);                    
                }                
            }               
        }
        LL ans=0;
        for(int j=0;j<31;j++){
            ans+=b[j][2];
        }
        cout<<ans<<'\n';
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