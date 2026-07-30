#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
void solve(){
    LL w,x,h;
    cin>>w>>x>>h;
    vector<vector<vector<LL>>> a(w+1,vector<vector<LL>>(x+1,vector<LL>(h+1,1)));
    LL q;
    cin>>q;
    auto op=[&](LL x1,LL y1,LL z1,LL x2,LL y2,LL z2)->void{
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                for(int k=z1;k<=z2;k++){
                    a[i][j][k]=0;
                }
            }
        }
    };
    for(int i=1;i<=q;i++){
        LL x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        op(x1,y1,z1,x2,y2,z2);
    }
    
    LL ans=0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=x;j++){
            for(int k=1;k<=h;k++){
                ans+=a[i][j][k];
            }
        }
    }    
    cout<<ans<<'\n';
     
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