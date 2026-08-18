//cf1749D
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
using i128=__int128_t;
using u128=__uint128_t;
ostream& operator<<(ostream& out,i128 x){
    if(x<0)out<<'-';
    u128 y=x<0?-(u128)x:(u128)x;
    if(!y)return out<<0;
    string s;
    while(y)s+=char('0'+y%10),y/=10;
    reverse(s.begin(),s.end());
    return out<<s;
}
istream& operator>>(istream& in,i128& x){
    string s;in>>s;
    x=0;
    int p=0,tag=1;
    if(s[0]=='-')tag=-1,p=1;
    for(;p<s.size();p++)x=x*10+s[p]-'0';
    x*=tag;
    return in;
}
vector<LL> prim;
vector<LL> not_prim,minp;

void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
            minp[i]=i;
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            minp[i*p]=p;
            if(i%p==0)break;
        }
    }
}
void init(LL n){
    not_prim.assign(n+10,0);
    minp.assign(n+1,0);
    minp[1]=1;
    get_prim(n+1);
}
LL getv(i128 x,set<i128> &st){
    while(minp[x]!=1){
        st.insert(minp[x]);
        x/=minp[x];
    }
    i128 ans=1;
    for(auto v:st){
        ans*=v;
    }
    return ans;
}
void solve(){
    i128 n,m;
    cin>>n>>m;
    vector<i128> dp(n+1,0);
    dp[1]=m;
    set<i128> st;
    i128 s=dp[1]%mod;
    i128 pre=1;
    i128 ans=0;
    i128 md=m%mod;
    for(int i=1;i<=n;i++){
        pre=pre*md%mod;
        ans=(ans+pre)%mod;        
    }
    for(i128 i=2;i<=n;i++){
        i128 x=getv(i,st);
        if(x>m)break;
        dp[i]=(dp[i-1]%mod*(m/x)%mod)%mod;
        s=(s+dp[i])%mod;
        //printf("{%lld,%lld,%lld,%lld}",x,m/x,dp[i],i);
    }
    //cout<<ans<<'\n';
    ans=(ans-s+mod)%mod;
    cout<<ans<<'\n';
    //cout<<mod*mod<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    init(3e5+5);
    while(t--){
        solve();
    }
    return 0;
}