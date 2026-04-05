#include<bits/stdc++.h>
#define fi first
#define sc second
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using ll=long long ;
using ull=unsigned long long;
using i128=__int128;
using PII=std::pair<int,int>;
using Pll=std::pair<int,ll>;
using std::string;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
void init(){
    
}
const int N=2e5+10;
int dp[N][26];
void solve(){
    string s;
    std::cin>>s;
    s=" "+s;
    int n=s.size();
    string t;
    std::cin>>t;
    for(int i=0;i<26;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n;i++){
       int s1=s[i]-'a';
       //std::cerr<<s1<<endl;
       dp[i][s1]=i;
       for(int j=0;j<26;j++){
          if(j!=s1){
             dp[i][j]=dp[i-1][j];
          }
       }   
    }
 //   std::cerr<<dp[1][0]<<endl;
    ll ans=0;
    for(int i=1;i<n;i++){
        int cnt=t.size();
        int pos=i;
        while(cnt>0&&pos>0){
            int k=t[cnt-1]-'a';
            cnt--;
            pos=dp[pos][k];
            
        }
        ans+=i-pos;
        //std::cerr<<ans<<endl;
    }
    std::cout<<ans<<endl;
    
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T=1;
   // std::cin>>T;
    while(T--){
        solve();
    }

    return 0;
}