#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using LL=long long;
using PII=std::pair<int,int>;
const int mod=998244353;
const int N=1e7+5;
std::vector<int>prime,minp;//素数表,最小素因子表
void seive(int n){
      minp.assign(n+1,0); 
      for(int i=2;i<=n;i++){
            if(minp[i]==0){
               minp[i]=i;
               prime.push_back(i);
            }
            for(auto p:prime){
               if(i*p>n){
                  break;
               }
               minp[i*p]=p;//每一个点只会被筛选一次
               if(minp[i]==p){
                  break;
               }
            }
       }   
}
struct MInt{
    LL val;
    constexpr static LL norm(LL x,LL m=mod){
        x%=m;
        if(x<0)x+=m;
        return x;
    }
    constexpr MInt():val(0){}
    constexpr MInt(LL x):val(norm(x)){}
    constexpr MInt pow(LL x) const {
        MInt res=1;
        MInt a=*this;
        while(x>0){
            if(x&1)res*=a;
            a*=a;
            x>>=1;
        }
        return res;
    }

    constexpr MInt inv() const {
        return pow(mod-2);
    }

    constexpr friend MInt operator+(MInt a,MInt b){return a.val+b.val;}
    constexpr friend MInt operator-(MInt a,MInt b){return a.val-b.val;}
    constexpr friend MInt operator*(MInt a,MInt b){return 1ll*a.val*b.val;}
    constexpr friend MInt operator/(MInt a,MInt b){return a.val*b.inv();}

    constexpr friend MInt& operator+=(MInt& a,MInt b){return a=a+b;}
    constexpr friend MInt& operator-=(MInt& a,MInt b){return a=a-b;}
    constexpr friend MInt& operator*=(MInt& a,MInt b){return a=a*b;}
    constexpr friend MInt& operator/=(MInt& a,MInt b){return a=a/b;}

    constexpr friend bool operator==(MInt a,MInt b){return a.val==b.val;};
    constexpr friend bool operator!=(MInt a,MInt b){return a.val!=b.val;};
    
    friend std::istream& operator>>(std::istream& is,MInt& x){
        LL v;
        is>>v;
        x=MInt(v);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os,const MInt& x){
        return os<<x.val;
    }
};
using Z=MInt;
void solve(){
     int n,c;
     std::cin>>n>>c;
     std::vector<Z>p(n+1);
     p[1]=c;
     for(int i=2;i<=n;i++){
        p[i]=p[i-1]*c;
     }
     std::vector<ll>g(n+1);
     std::vector<int>vec(n+5);
     Z ans=0;
     for(int i=1;i<=n;i++){
        if(i==1||minp[i]==i){
            g[i]=1;
        }else{
          int ps=i;
          int pre=minp[ps];
          vec[i]=0;
          while(ps!=1){
             vec[i]++;
             ps/=minp[ps];
          }
     }
    }
     for(int i=2;i<=n;i++){
        if(minp[i]==i)continue;
        g[i]=prime[(vec[i]-2)];
        
     }
     for(int i=1;i<=n;i++){
     //   std::cout<<g[i]<<" "<<p[i]<<'\n';
        ans+=g[i]*p[i];
     }
     std::cout<<ans<<'\n';
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    seive(N);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}