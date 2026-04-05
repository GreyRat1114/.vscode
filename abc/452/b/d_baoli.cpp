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
void solve(){
     string s1,s2;
     std::cin>>s1>>s2;
     s1=" "+s1;
     int n=s1.size();
     //std::cerr<<n<<endl;
     int ans=0;
     for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            int cnt=0;
           // std::cerr<<i<<j<<endl;
            for(int k=i;k<=j;k++){
                if(s1[k]==s2[cnt]){
                    cnt++;
                }
            }
            if(cnt!=s2.size()){
          //      std::cerr<<i<<" "<<j<<endl;
                ans++;
            }
        }
     }
     std::cout<<ans<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T=1;
//    std::cin>>T;
    while(T--){
        solve();
    }

    return 0;
}