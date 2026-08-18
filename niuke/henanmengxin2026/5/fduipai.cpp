#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
using ll=long long;
struct MInt{
    ll val;
    constexpr static ll norm(ll x,ll m=mod){
        x%=m;
        if(x<0)x+=m;
        return x;
    }
    constexpr MInt():val(0){}
    constexpr MInt(ll x):val(norm(x)){}
    constexpr MInt pow(ll x) const {
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
        ll v;
        is>>v;
        x=MInt(v);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os,const MInt& x){
        return os<<x.val;
    }
};
using Z=MInt;
LL qpow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b=b>>1;
        a=(a*a)%mod;
    }
    return ans%mod;
}
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<Z> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        if(i==17){
            for(int j=1;j<=n;j++){
                cout<<a[j]<<' ';
            }
            cout<<'\n';
            break;
        }
        LL op;
        cin>>op;
        LL l,r;
        cin>>l>>r;
        if(op==1){
            LL k;
            cin>>k;
            for(int j=l;j<=r;j++){
                a[j]=(a[j]+k);
            }
        }else if(op==2){
            LL k;
            cin>>k;
            for(int j=l;j<=r;j++){
                a[j]=k;
            }           
        }else if(op==3){
            Z avg=0;
            for(int j=l;j<=r;j++){
                avg=(avg+a[j]);
            }         
            LL len=r-l+1;
            avg=avg*qpow(len,mod-2);
            Z ss=0;
            for(int j=l;j<=r;j++){
                ss=(ss+(a[j]-avg)*(a[j]-avg));
            }                
            ss=ss*qpow(len,mod-2);
            Z ans=ss+mod;
            cout<<ans<<'\n';
        }else{
            Z avg=0;
            for(int j=l;j<=r;j++){
                avg=(avg+a[j]);
            }         
            LL len=r-l+1;
            avg=avg*qpow(len,mod-2);
            Z ss=0;
            for(int j=l;j<=r;j++){
                ss=(ss+((a[j]-avg)*(a[j]-avg)*(a[j]-avg)));
            }                
            ss=ss*qpow(len,mod-2);
            Z ans=ss+mod;
            cout<<ans<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}