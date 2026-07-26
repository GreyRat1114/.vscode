#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;

void solve(){
    LL n,m,d;
    cin>>n>>m>>d;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++){
            a[n-i+1][j+1]=s[j];
        }
    }
    vector<vector<LL>> dp(n+1,vector<LL>(m+1,0));
    auto pf=[&](int c)->void{
        for(int i=1;i<=m;i++){
            printf("{%lld}",dp[c][i]);
        }
        cout<<'\n';
    };
    for(int i=1;i<=m;i++){
        if(a[1][i]!='X')continue;
        dp[1][i]=1;
    }

    auto check=[&](int c)->void{
        vector<LL> pre(m+1,0);
        for(int i=1;i<=m;i++){
            pre[i]=(pre[i-1]+dp[c][i])%mod;
        }
        for(int i=1;i<=m;i++){
            if(a[c][i]!='X')continue;
            LL l=max(1ll,i-d);
            LL r=min(m,i+d);
            LL cnt=(pre[r]-pre[l-1]-dp[c][i]+mod)%mod;
            dp[c][i]=(dp[c][i]+cnt)%mod;
        }
    };
    check(1);
    //pf(1);
    for(int i=2;i<=n;i++){
        vector<LL> pre(m+1,0);
        for(int j=1;j<=m;j++){
            pre[j]=(pre[j-1]+dp[i-1][j])%mod;
        }
        for(int j=1;j<=m;j++){
            if(a[i][j]!='X')continue;
            LL d2=d*d;
            LL l=max(1ll,j-(LL)(sqrt(d2-1)));
            LL r=min(m,j+(LL)(sqrt(d2-1)));
            //printf("{%lld,%lld}",l,r);
            dp[i][j]=(dp[i][j]+pre[r]-pre[l-1]+mod)%mod;
            //dp[i][j]+=pre[r]-pre[l-1];
        }
        //pf(i);
        check(i);
        //pf(i);
    }
    LL ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans<<'\n';
    //cout<<((ans==0)?-1:ans)<<'\n';
    //cout<<ceil(3.17463);
    
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