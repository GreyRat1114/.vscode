#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a,LL b)
{
    LL t;
    while(b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
void solve(){
    LL n,m,q;
    cin>>n>>m>>q;
    vector<LL> a(n+1,1);
    LL x,y,g;

    for(int i=1;i<=m;i++){
        cin>>x>>y>>g;
        if(a[x]%g!=0){
            LL gx=gcd(a[x],g);
            a[x]=a[x]*(g/gx);
        }
        if(a[y]%g!=0){
            LL gy=gcd(a[y],g);
            a[y]=a[y]*(g/gy);            
        }

    }
    LL p1,p2;
    for(int i=1;i<=q;i++){
        cin>>p1>>p2;
        cout<<gcd(a[p1],a[p2])<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}