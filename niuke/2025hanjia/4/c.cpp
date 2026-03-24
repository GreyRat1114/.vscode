#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define mp make_pair
LL ans[N];
LL a[N];
void solve(){
    LL n;
    cin>>n;
    if(n==1){
        cout<<0<<' '<<1<<'\n';
        return;
    }
    if(n==2){
        cout<<0<<' '<<1<<' '<<3<<' '<<2<<'\n';
        return;
    }
    LL x=(1ll<<n);
    LL d=4;
    ans[1]=0;
    ans[2]=1;
    ans[3]=3;
    ans[4]=2;
    int tot=0;
    for(LL i=5;i<=x;i++){
        tot++;
        a[tot]=ans[i-d]+d;
        if(i==d*2){
            if((a[1]^ans[d])<(a[tot]^ans[d])){
                for(int j=1;j<=tot;j++){
                    ans[d+j]=a[j];
                }
            }else{
                for(int j=1;j<=tot;j++){
                    ans[d+j]=a[tot-j+1];
                }                
            }
            d=d*2;
            tot=0;
        }        
    }
    for(int i=1;i<=x;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}