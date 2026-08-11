//cf1538D
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> prim;
vector<LL> not_prim;
vector<LL> minp;
void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
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
    minp.assign(n+10,0);
    get_prim(n+1);
}
void solve(){
    LL a,b,k;
    cin>>a>>b>>k;
    LL maxn=max(a,b);
    LL mini=min(a,b);    
    vector<LL> ax,bx;
    for(LL i=0;prim[i]*prim[i]<=a;i++){
        while(a%prim[i]==0){
            ax.push_back(i);
            a=a/prim[i];
        }
    }
    if(a!=1)ax.push_back(a);
    for(LL i=0;prim[i]*prim[i]<=b;i++){
        while(b%prim[i]==0){
            bx.push_back(i);
            b=b/prim[i];
        }
    }
    if(b!=1)bx.push_back(b);
    LL l=2;
    if(maxn%mini==0&&maxn!=mini){
        l=1;
    }
    LL r=ax.size()+bx.size();
    //printf("{%lld,%lld}",l,r);
    if(k>=l&&k<=r){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    init(1e6+5);
    while(t--){
        solve();
    }
    return 0;
}