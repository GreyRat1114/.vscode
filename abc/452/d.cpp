#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    string s,t;
    cin>>s;
    cin>>t;
    LL n=s.size();
    LL m=t.size();
    LL tot=(m-1)*m/2;
    //vector<vector<LL>> dp(n+1,vector<LL>(m+1,0));
    vector<LL> dp(m+1,0);
    map<char,vector<LL>> mp;
    for(int i=0;i<m;i++){
        mp[t[i]].push_back(i);
    }



    LL cnt=0;
    for(int i=0;i<n;i++){
        for(auto j:mp[s[i]]){
            if(j==0){
                dp[j]++;
                printf("{%lld}",dp[j]);
            }else if(dp[j-1]){
                
                dp[j]=dp[j-1];
                if(dp[m-1]){
                    cnt+=dp[m-2];
                }
                printf("{%lld,%lld,%lld}",i,j-1,dp[j]);
            }        
        }
    }
    //LL cnt=dp[m-1];
    // vector<LL> dp1(m+1,0);
    // for(int i=n;i>=0;i--){
    //     for(auto j:mp[s[i]]){
    //         if(j==m-1){
    //             dp1[j]++;
    //             printf("{%lld}",dp1[j]);
    //         }else if(dp1[j+1]){
    //             dp1[j]+=dp1[j+1];
    //             printf("{%lld,%lld,%lld}",i,j+1,dp1[j]);
    //         }        
    //     }
    // }    
    //cnt+=dp1[0];
    cout<<cnt<<'\n';


}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}