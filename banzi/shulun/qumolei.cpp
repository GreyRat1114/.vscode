#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
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
int main(){
    int n;
    cin>>n;
    MInt x;
    for(int i=1;i<=n;i++){
        cin>>x;
        cout<<x<<'\n';
    }
    return 0;
}