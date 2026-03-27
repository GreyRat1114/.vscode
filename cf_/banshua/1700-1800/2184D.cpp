#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL dp[105][135];
LL s[105][135];
void solve(){
    LL n,k;
    cin>>n>>k;
    LL m=n;
    int cnt=0;
    while(n!=1){
        n=n>>1;
        cnt++;
    }
    LL sum=0;
    k=min(70ll,k);
    for(int i=1;i<=cnt;i++){
        sum+=s[k][i];
    }if(k>=cnt+1){
        sum++;
    }
    cout<<m-sum<<'\n';
    //printf("{%lld}",sum);
}
int main(){
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    dp[1][1]=1;
    dp[2][2]=1;    
    for(int i=3;i<=100;i++){
        for(int j=2;j<=100;j++){
            dp[i][j]+=dp[i-2][j-1];
        }
        for(int j=2;j<=100;j++){
            dp[i][j]+=dp[i-1][j-1];
        }        
    }    
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            s[j][i]=s[j-1][i]+dp[j][i];
            //printf("{%lld}",s[j][i]);
        }
        //cout<<'\n';
    }           
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}