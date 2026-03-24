#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
#define mp make_pair
void solve(){
    LL n,m,k;
    cin>>n>>k>>m;
    vector<LL> a(n+1);
    vector<vector<pair<LL,LL>>> dp(n+1,vector<pair<LL,LL>>(3,{0,0}));
    vector<LL> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    dp[1][0].first=a[1];
    dp[1][1].first=a[1]*2;
    dp[1][1].second=1+k;
    for(int i=1;i<=n;i++){
        if(i==1){
            continue;
        }
        if(dp[i-1][0].first){
            dp[i][0].first=max(dp[i-1][0].first+a[i],dp[i][0].first);
        }   
        if(dp[i-1][1].first&&i>dp[i-1][1].second){
            dp[i][0].first=max(dp[i-1][1].first+a[i],dp[i][0].first);
        }        
        if(i>=1+m&&dp[i-m][0].first){
            dp[i][0].first=max(dp[i-m][0].first+s[i]-s[i-m],dp[i][0].first);
        }        
        if(i>=1+m&&dp[i-m][1].first&&i>dp[i-m][1].second){
            LL sum=s[i]-s[i-m];
            dp[i][0].first=max(dp[i-m][1].first+sum,dp[i][0].first);
        }
        if(dp[i-1][0].first+a[i]*2>dp[i][1].first){
            dp[i][1].first=max(dp[i-1][0].first+a[i]*2,dp[i][1].first);  
            dp[i][1].second=i+k;               
        } 
        if(dp[i-1][1].first&&i<=dp[i-1][1].second){
            if(dp[i-1][1].first+a[i]/2>dp[i][1].first){
                dp[i][1].first=dp[i-1][1].first+a[i]/2;
                dp[i][1].second=dp[i-1][1].second;
            }
        }
        if(i>=1+m&&dp[i-m][1].first){
            if(i<=dp[i-m][1].second){
                LL sum=s[i]-s[i-m];
                if(dp[i-m][1].first+sum>dp[i][1].first){
                    dp[i][1].first=dp[i-m][1].first+sum;
                    dp[i][1].second=dp[i-m][1].second;
                }                              
            }
        }
    }
    LL ans=max(dp[n][0].first,dp[n][1].first);
    cout<<ans<<'\n';    
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
