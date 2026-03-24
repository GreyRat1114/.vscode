#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
LL b[N][11];
vector<map<int,int>> s(11);
void solve(){
    LL n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        LL x=a[i]%m;
        LL y=a[i];
        LL tot=0;
        while(y){
            tot++;
            y=y/10;
        }
        // printf("{%d}",tot);
        s[tot][x]++;
        b[i][0]=x;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            b[i][j]=(b[i][j-1]*10)%m;
            // printf("{%lld %lld,%lld}",i,j,b[i][j]);
        }
    }
    LL ans=0;
    // for(int i=1;i<=n;i++){
    //     LL d=m-b[i][0];
    //     ans+=s[0][d];
    // }
    // cout<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            LL d=(m-b[i][j])%m;
            ans+=s[j][d];
            // printf("<%d,%d,%lld,%lld,%lld>",i,j,d,s[j][d],ans);
        }
    }    
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}