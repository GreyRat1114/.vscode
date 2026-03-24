#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
// LL a[N];
// LL b[N];
double ck[N];
// double yy[N];
map<double,int> tr;
map<double,int> tr2;
double a[N];
int b[N];
int s[N];
const LL mod=998244353;
int tot;
int check(double x){
    int l=1;
    int r=tot;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid]<=x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return l-1;
}
void solve(){
    memset(s,0,sizeof(s));

    int n,q;
    cin>>n>>q;
    double x,y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        // xx[i]=x;
        // yy[i]=y;
        double z=sqrt(x*x+y*y);
        double cs=x/z;
        double sn=y/z;
        double cs2;
        if(sn>0){
            cs2=sqrt((cs+1)/2);
        }else{
            cs2=-sqrt((cs+1)/2);
        }
        double sn4=(1-cs2)/2;
        ck[i]=sn4;
        tr[sn4]++;
        // if(tr.count(sn4)){
        //     tr[sn4].second++;
        // }else{
        //     tr[sn4].first=i;
        //     tr[sn4].second=0;
        // }
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
        
        // int p1=check(ck[l]);
        // int p2=check(ck[r]);
        // int ans;
        if(p1>=p2||(p1<p2&&ck[r]==1)){
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