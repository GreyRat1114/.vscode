#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
LL a[]={48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70};
void solve(){
    string s;
    cin>>s;
    LL m=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')m=m*16+(s[i]-'0');
        if(s[i]>='A'&&s[i]<='F')m=m*16+((s[i]-'A')+10);
    }
    
    m=m-'B'-'C';
    //cout<<m<<'\n';
    vector<LL> dp(m+1);
    dp[0]=1;
    for(int i=0;i<=15;i++){
        for(int j=1;j<=m;j++){
            if(j-a[i]<0)continue;
            if(dp[j-a[i]]==0)continue;
            dp[j]=a[i];
        }
    }
    string ans="";
    while(dp[m]!=1){
        ans.push_back(dp[m]);
        m-=dp[m];
    }
    ans=ans+s;
    cout<<ans<<'\n';
    //cout<<dp[m]<<'\n';
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