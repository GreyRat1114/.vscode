#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1,vector<LL>(2));
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='R'){
            a[i][0]=1;
        }else{
            a[i][0]=0;
        }
    }
    cin>>s;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='R'){
            a[i][1]=1;
        }else{
            a[i][1]=0;
        }
    }    
    vector<LL> dp(n+1,1e9);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i][0]==a[i][1]){
            dp[i]=dp[i-1];
        }else{
            dp[i]=dp[i-1]+1;
        }
        LL c=0;
        if(i>=2){
            if(a[i][0]!=a[i-1][0])c++;
            if(a[i][1]!=a[i-1][1])c++;
            dp[i]=min(dp[i],dp[i-2]+c);            
        }
    }
    cout<<dp[n]<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}