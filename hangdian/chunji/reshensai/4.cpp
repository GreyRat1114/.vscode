#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL num[1005];
LL prim[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127};
LL check(LL x){
    LL l=0;
    LL r=30;
    LL ans=0;
    while(l<=r){
        LL mid=(l+r)/2;
        if(prim[mid]<=x){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<LL> a(2*n+1);
    vector<vector<LL>> dp(2*n+1,vector<LL>(31,0));
     //printf("{%d}",n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[n+i]=a[i];
        //printf("{%d,%lld}",i,check(a[i]));
    }
    LL ans=0;
    for(int i=1;i<=2*n;i++){  
        dp[i][num[a[i]]]=i;     
        if(i==1){
            continue;
        }           
        for(int j=0;j<=30;j++){
            if(dp[i-1][j]&&i-dp[i-1][j]+1<=n){
                LL p=num[prim[j]+a[i]];
                dp[i][p]=max(dp[i][p],dp[i-1][j]);
                ans=max(ans,prim[p]);
            }
        }
    }
    vector<vector<LL>> dp2(2*n+1,vector<LL>(31,1e9));
    for(int i=2*n;i>=1;i--){  
        dp2[i][num[a[i]]]=i;     
        if(i==2*n){
            continue;
        }           
        for(int j=0;j<=30;j++){
            if(dp2[i+1][j]&&dp2[i+1][j]-i+1<=n){
                LL p=num[prim[j]+a[i]];
                dp2[i][p]=min(dp2[i][p],dp2[i+1][j]);
                ans=max(ans,prim[p]);
            }
        }
    }    
    cout<<ans<<'\n';
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p=0;
    for(int i=0;i<=150&&p<=30;i++){
        if(i>=prim[p+1]){
           p++; 
        }         
        num[i]=p;
       
        //printf("{%d,%lld}",i,num[i]);
    }
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
