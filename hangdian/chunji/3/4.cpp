#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
void check(){
    for(LL x=2;x<=N;x++){
        LL tot=0;
        for(LL i=1;i*i<=x;i++){
            if(i*i==x){
                tot++;
            }else if(x%i==0){
                tot+=2;
            }
        }   
        a[x]=tot-1;           
    }
    //return tot;
}
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> b(n+1,0);
    for(LL i=1;i<=n;i++){
        b[i]=a[i]+n/i-1;
    }

    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",b[i]);
    // }
    sort(b.begin()+1,b.end());
    cout<<b[n+1-k]<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(a,0,sizeof(a));

    check();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}