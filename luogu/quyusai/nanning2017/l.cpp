#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
struct BigInt{
    static const int base=1e9,w=9;
    vector<int>a;
    int s=1;

    BigInt(long long x=0){*this=x;}
    BigInt(string x){read(x);}

    BigInt& operator=(long long x){
        s=1;a.clear();
        unsigned long long y;
        if(x<0)s=-1,y=0ULL-(unsigned long long)x;
        else y=x;
        while(y)a.push_back(y%base),y/=base;
        return *this;
    }

    BigInt& read(string x){
        s=1;a.clear();
        int p=0;
        if(x[p]=='-'||x[p]=='+'){
            if(x[p]=='-')s=-1;
            p++;
        }
        for(int i=x.size()-1;i>=p;i-=w){
            int v=0;
            for(int j=max(p,i-w+1);j<=i;j++)
                v=v*10+x[j]-'0';
            a.push_back(v);
        }
        trim();
        return *this;
    }

    void trim(){
        while(a.size()&&a.back()==0)a.pop_back();
        if(a.empty())s=1;
    }

    bool zero()const{return a.empty();}

    BigInt abs()const{
        BigInt x=*this;
        x.s=1;
        return x;
    }

    static int cmpabs(const BigInt&a,const BigInt&b){
        if(a.a.size()!=b.a.size())
            return a.a.size()<b.a.size()?-1:1;
        for(int i=a.a.size()-1;i>=0;i--)
            if(a.a[i]!=b.a[i])
                return a.a[i]<b.a[i]?-1:1;
        return 0;
    }

    friend bool operator<(const BigInt&a,const BigInt&b){
        if(a.s!=b.s)return a.s<b.s;
        int c=cmpabs(a,b);
        return a.s==1?c<0:c>0;
    }
    friend bool operator>(const BigInt&a,const BigInt&b){return b<a;}
    friend bool operator<=(const BigInt&a,const BigInt&b){return !(b<a);}
    friend bool operator>=(const BigInt&a,const BigInt&b){return !(a<b);}
    friend bool operator==(const BigInt&a,const BigInt&b){
        return a.s==b.s&&a.a==b.a;
    }
    friend bool operator!=(const BigInt&a,const BigInt&b){return !(a==b);}

    BigInt operator-()const{
        BigInt x=*this;
        if(!x.zero())x.s=-x.s;
        return x;
    }

    BigInt& operator+=(const BigInt&v){
        if(s==v.s){
            int c=0;
            for(int i=0;i<(int)max(a.size(),v.a.size())||c;i++){
                if(i==(int)a.size())a.push_back(0);
                long long x=(long long)a[i]+c+(i<(int)v.a.size()?v.a[i]:0);
                c=x>=base;
                if(c)x-=base;
                a[i]=x;
            }
        }else{
            if(cmpabs(*this,v)>=0){
                int c=0;
                for(int i=0;i<(int)v.a.size()||c;i++){
                    long long x=(long long)a[i]
                               -(i<(int)v.a.size()?v.a[i]:0)-c;
                    c=x<0;
                    if(c)x+=base;
                    a[i]=x;
                }
                trim();
            }else{
                BigInt x=v;
                x+=*this;
                *this=x;
            }
        }
        return *this;
    }

    BigInt& operator-=(const BigInt&v){return *this+=-v;}
    friend BigInt operator+(BigInt a,const BigInt&b){return a+=b;}
    friend BigInt operator-(BigInt a,const BigInt&b){return a-=b;}

    BigInt& operator*=(int v){
        if(v<0)s=-s,v=-v;
        if(v==0||zero())return a.clear(),s=1,*this;

        long long c=0;
        for(int i=0;i<(int)a.size()||c;i++){
            if(i==(int)a.size())a.push_back(0);
            long long x=c+1LL*a[i]*v;
            a[i]=x%base;
            c=x/base;
        }
        trim();
        return *this;
    }

    friend BigInt operator*(BigInt a,int b){return a*=b;}
    friend BigInt operator*(int b,BigInt a){return a*=b;}

    BigInt& operator*=(const BigInt&v){
        if(zero()||v.zero())return a.clear(),s=1,*this;

        vector<long long>r(a.size()+v.a.size());
        for(int i=0;i<(int)a.size();i++){
            long long c=0;
            for(int j=0;j<(int)v.a.size()||c;j++){
                long long x=r[i+j]+c+
                    (j<(int)v.a.size()?1LL*a[i]*v.a[j]:0);
                r[i+j]=x%base;
                c=x/base;
            }
        }

        a.assign(r.begin(),r.end());
        s*=v.s;
        trim();
        return *this;
    }

    friend BigInt operator*(BigInt a,const BigInt&b){return a*=b;}

    BigInt& operator/=(int v){
        if(!v)throw runtime_error("div0");
        if(v<0)s=-s,v=-v;

        long long r=0;
        for(int i=a.size()-1;i>=0;i--){
            long long x=a[i]+r*base;
            a[i]=x/v;
            r=x%v;
        }
        trim();
        return *this;
    }

    friend BigInt operator/(BigInt a,int v){return a/=v;}

    int operator%(int v)const{
        if(!v)throw runtime_error("mod0");
        int vv=std::abs(v);
        long long r=0;
        for(int i=a.size()-1;i>=0;i--)
            r=(a[i]+r*base)%vv;
        return s*r;
    }

    static pair<BigInt,BigInt> divmod(const BigInt&A,const BigInt&B){
        if(B.zero())throw runtime_error("div0");

        int norm=base/((long long)B.a.back()+1);
        BigInt a=A.abs()*norm,b=B.abs()*norm,q,r;
        q.a.assign(a.a.size(),0);

        for(int i=a.a.size()-1;i>=0;i--){
            r.a.insert(r.a.begin(),a.a[i]);
            r.trim();

            long long x1=r.a.size()<=b.a.size()?0:r.a[b.a.size()];
            long long x2=r.a.size()<b.a.size()?0:r.a[b.a.size()-1];
            long long d=((long long)base*x1+x2)/b.a.back();
            d=min<long long>(d,base-1);

            r-=b*(int)d;
            while(r.s==-1)r+=b,d--;

            q.a[i]=d;
        }

        q.s=A.s*B.s;
        r.s=A.s;
        q.trim();r.trim();
        r/=norm;
        return {q,r};
    }

    BigInt& operator/=(const BigInt&v){
        return *this=divmod(*this,v).first;
    }
    BigInt& operator%=(const BigInt&v){
        return *this=divmod(*this,v).second;
    }

    friend BigInt operator/(const BigInt&a,const BigInt&b){
        return divmod(a,b).first;
    }
    friend BigInt operator%(const BigInt&a,const BigInt&b){
        return divmod(a,b).second;
    }

    friend istream& operator>>(istream&in,BigInt&x){
        string s;in>>s;
        return x.read(s),in;
    }

    friend ostream& operator<<(ostream&out,const BigInt&x){
        if(x.s==-1)out<<'-';
        if(x.a.empty())return out<<0;

        out<<x.a.back();
        for(int i=x.a.size()-2;i>=0;i--)
            out<<setw(w)<<setfill('0')<<x.a[i];
        return out;
    }
};
vector<BigInt> ans;
void init(){
    BigInt n=1;
    for(int i=1;i<=200;i++){
        n=n*10;
    }
    LL n0=0;
    LL n1=3;
    BigInt cur=0,pre=3,lst=0;
    ans.push_back(n0);
    ans.push_back(n1);
    while(cur<=n){
        cur=6*pre-lst+2;
        ans.push_back(cur);
        lst=pre;
        pre=cur;
    }
}
void solve(){
    BigInt x;
    cin>>x;
    auto it=lower_bound(ans.begin(),ans.end(),x);
    if(it==ans.end()){
        cout<<-1<<'\n';
    }else{
        BigInt res=*it;
        cout<<res<<'\n';
    }
    

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--){
        solve();
    }
    return 0;
}