#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128;
void solve(){
    LL n;
    cin>>n;

    vector<pair<LL,LL>> a(n+10),b(n+10);
    for(int i=1;i<=n;i++){
        LL r,c;
        cin>>r>>c;
        a[i]={r,c};
    }
    vector<vector<LL>> vis(10,vector<LL>(10,0));
    for(int i=1;i<=n;i++){
        LL r,c;
        cin>>r>>c;
        vis[r][c]=1;
    }    
    if(n==1||n==0){
        cout<<"Columbina Hyposelenia"<<'\n';
        return;
    }    
    auto check=[&](LL x,LL y,LL z)->LL{
        LL x1=a[z].first;
        LL y1=a[z].second;
        LL x2=a[z+1].first;
        LL y2=a[z+1].second;
        if((x==x1&&y==y1)||(x==x2&&y==y2)){
            return 0;
        }
        LL tag=0;
        if((x+y==x1+y1)&&(x1+y1==x2+y2)){
            tag=1;
        }
        if((x-y==x1-y1)&&(x1-y1==x2-y2)){
            tag=1;
        }        
        if((x==x1)&&(x1==x2)){
            tag=1;
        }
        if((y==y1)&&(y1==y2)){
            tag=1;
        }
        return tag;
    };

    if(n==3){
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(vis[i][j])continue;
                if(check(i,j,2)){
                    cout<<i<<' '<<j<<'\n';
                    return;
                }
            }
        }
    }else{
        //printf("{''}");
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(vis[i][j])continue;
                if(check(i,j,1)){
                    cout<<i<<' '<<j<<'\n';
                    return;
                }
            }
        }        
    }
    cout<<"Columbina Hyposelenia"<<'\n';
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