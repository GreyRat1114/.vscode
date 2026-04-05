#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
LL f[N];
LL g[N];
LL qpow(LL a,LL b)
{
    LL ans=1;
    LL p;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    return ans;
}
void init()
{
    f[0]=g[0]=1;
    for(int i=1;i<=N;i++)
    {
        f[i]=f[i-1]*i%mod;
        g[i]=g[i-1]*qpow (i,mod-2)%mod;
    }
}
LL getc(LL n,LL m)
{
    return f[n]*g[n-m]%mod*g[m]%mod;
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1,0);
    //vector<vector<LL>> dp(n+1,vector<LL>(3,1e9));
    vector<LL> dp(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    dp[1]=0;
    for(int i=2;i<=n;i++){
        LL c0=getc(a[i],a[1]);
        LL c1=getc(a[i],a[i-1]);
        dp[i]=(dp[i-1]+min(c0,c1))%mod;
        // dp[i][0]=(min(dp[i-1][2],min(dp[i-1][0],dp[i-1][1]))+c0)%mod;
        // dp[i][1]=(min(dp[i-1][2],min(dp[i-1][0],dp[i-1][1])+c1))%mod;

        //printf("{%lld,%lld,%lld,%lld}\n",i,dp[i][0],dp[i][1],dp[i][2]);
    }
    LL ans=dp[n];
    cout<<ans%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    for(int i=1;i<=100;i++){
        cout<<getc(i,i/2)<<' ';
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}