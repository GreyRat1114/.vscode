#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
set<LL> tr;
LL check(LL num,vector<LL> &dp){
    LL minn=1e9;
    if(tr.count(num)){
        dp[num]=1;
        return 1;
    }
    for(int i=1;i*i<=num;i++){
        if(num%i==0){
            LL x=i;
            LL y=num/i;
            if(dp[x]!=1e9&&dp[y]!=1e9){
                minn=min(dp[x]+dp[y],minn);
            } 
        }
    }
    dp[num]=minn;
    if(minn==1e9){
        return -1;
    }else{
        return minn;
    }
}
void solve(){
    tr.clear();
    int n;
    cin>>n;
    vector<LL> dp(n+1,1e9);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tr.insert(a[i]);
    }
    for(int i=1;i<=n;i++){
        LL ans=check(i*1ll,dp);
        cout<<ans<<' ';
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}