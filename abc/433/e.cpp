#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
using LL=long long;
const LL mod=998244353;
LL a[N];
LL f[N];
LL g[N];

LL qpow(LL a,LL b)
{
    LL ans=1;
    LL p;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    return ans;
}
void init()
{
    f[0]=g[0]=1;
    for(int i=1;i<=N;i++)
    {
        f[i]=f[i-1]*i%mod;
        g[i]=g[i-1]*qpow (i,mod-2)%mod;
    }
}
LL getc(LL n,LL m)
{
    if(m>n){
        return 0;
    }
    return f[n]*g[n-m]%mod*g[m]%mod;
}

void solve(){
    init();
    string s;
    cin>>s;
    int len=s.length();
    if(len==1){
        cout<<0<<'\n';
        return;
    }
    int tag=0;
    for(int i=0;i<len;i++){
        a[i+1]=s[i]-'0';
    }
    a[len+1]=-1;
    map<LL,LL> mp;
    LL l1=1;
    LL ans=0;
    mp[a[1]]++;
    for(int i=2;i<=len+1;i++){
        if(a[i]==a[i-1]){
            l1++;
        }
        else{
            LL x=mp[a[i-1]-1];
            LL y=l1;
            LL z=min(x,y);
            printf("[%lld %lld,%lld,%lld,%lld]",x,i,y,z,a[i-1]);            
            for(int j=1;j<=z;j++){
                LL p1=getc(y,j)%mod;
                LL p2=getc(x,j)%mod;
                ans=ans+(p1*p2)%mod;
                printf("{%lld,%lld,%lld}",getc(x,z),getc(y,z),ans);
            }
            l1=1;
        }
        mp[a[i]]++;
    }

    cout<<ans%mod<<'\n';
}
int main(){
    solve();
    return 0;
}

