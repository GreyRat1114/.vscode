#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=998244353;
LL a[N];
LL dp[N];
LL s[N];
LL p[N];
void solve(){
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    a[0]=0;
    p[0]=0;
    int n;
    cin>>n;
    int last=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=last;
        if(a[i]){
            last=i;
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("{%d}",p[i]);
    // }
    dp[0]=0;
    s[0]=0;
    dp[1]=1;
    s[1]=1;
    for(int i=1;i<=n;i++){
        LL x=0;
        int j=i;
        for(;j>0;){
            if((x&a[j])!=0){
                break;
            }
            x=x|a[j];
            j=p[j];
        }
        LL y=(s[i]-s[j]+mod)%mod;
        dp[i+1]=y;        
        //printf("{%d}",i);
        s[i+1]=(s[i]+dp[i+1])%mod;
    }
    cout<<(dp[n+1]+mod)%mod<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}