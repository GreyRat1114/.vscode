//luogu p1020
//最长上升子序列
#include<bits/stdc++.h>
using namespace std;
using LL=long long;;
void solve(){
    LL n=0;
    vector<LL> a(1e6+5,0);
    LL x;
    while(scanf("%lld",&x)!=EOF){
        n++;
        a[n]=x;
    }
    vector<LL> b(n+1);
    for(int i=1;i<=n;i++){
        b[n-i+1]=a[i];
    }
    vector<LL> dp,dp2;
    LL len=0;//最长上升子序列
    for(int i=1;i<=n;i++){
        auto it=lower_bound(dp.begin(),dp.end(),a[i]);
        if(it==dp.end()){
            //printf("{)}");
            len++;
            dp.push_back(a[i]);
        }else{
            //LL p=();
            dp[it-dp.begin()]=a[i];
        }
    }
    LL len2=0;//最长不升子序列
    for(int i=1;i<=n;i++){
        auto it=upper_bound(dp2.begin(),dp2.end(),b[i]);
        if(it==dp2.end()){
            len2++;
            dp2.push_back(b[i]);
        }else{
            dp2[it-dp2.begin()]=b[i];
        }
    }
    cout<<len2<<'\n'<<len<<'\n';
    // cout<<max(len,len2)<<'\n';
    // cout<<min(len,len2)<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}