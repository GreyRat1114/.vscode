#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
// LL a[N];
// LL b[N];
long double ck[N];
// double yy[N];
map<long double,int> tr;
map<long double,int> tr2;
long double a[N];
int b[N];
int s[N];
const LL mod=998244353;
const long double pi=acosl(-1.0L);
int tot;

void solve(){
    memset(s,0,sizeof(s));

    int n,q;
    cin>>n>>q;
    LL x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        long double z=atan2l(y,x);
        long double zeta;
        if(z<0){
            zeta=2*pi+z;
        }else{
            zeta=z;
        }    
        ck[i]=zeta;
        tr[zeta]++;
    }
    tot=0;
    for(auto x:tr){
        //cout<<x.first<<' ';
        tot++;
        a[tot]=x.first;
        b[tot]=x.second;
        tr2[x.first]=tot;
    }
    for(int i=1;i<=tot;i++){
        s[i]=s[i-1]+b[i];
    }
    int l,r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        int ans;
        int p1=tr2[ck[l]];
        int p2=tr2[ck[r]];
        //printf("{%d %d}",p1,p2);
        if(p1>=p2){
            ans=s[p1]-s[p2-1];
        }else{
            ans=n-s[p2]+s[p1-1]+tr[ck[l]]+tr[ck[r]];
        }
        cout<<ans<<'\n';
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}