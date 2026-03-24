#include<bits/stdc++.h>
using namespace std;
const int N=505;
using LL=long long;
#define mp make_pair
LL a[N][N];
map<LL,int> tr;
void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    int s=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                s++;
            }else{
                tr[a[i][j]]++;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){

    //         cout<<a[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // if(s==0){
    //     cout<<0<<' '<<0<<'\n';
    //     return;
    // }
    int tot=0;
    LL ans1=0;
    LL ans2=0;    
    for(auto xx:tr){
        LL x=xx.first;
        
        LL y=xx.second;
        LL z=y/2;
        if(z==0){
            continue;
        }
        ans1+=z;
        if(x+1>=k){
            ans2+=z;
        }   
        //printf("{%lld %lld %lld %lld}",x,y,z,ans2);
        tr[x+1]+=z;
    }
    cout<<ans1<<' '<<ans2<<'\n';

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}