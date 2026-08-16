#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
void solve(){
    LL x,a,b;
    cin>>x>>a>>b;
    if(a==1){
        cout<<(x-1)/b+1<<'\n';
        return;
    }
    auto getv=[&](LL c,LL kx)->LL{
        i128 A=a*a-a;
        i128 B=2*a-2*b;
        i128 C=2*b*c;   
        
        if(B<0){
            i128 k=0;
            i128 ans=(A*k*k+B*k+C)/2;
            //printf("{%lld,%lld}",c,ans);
            return ans;
        }
        i128 p1=(B-1)/(-2*A)+1;
        i128 p2=-B/(2*A);
        //printf("{%lld,%lld,%lld}",c,p1,p2);
        i128 ans=0;
        if(p2>=kx-1){
            i128 k=kx-1;
            ans=(A*k*k+B*k+C)/2;
        }else{
            i128 k1=p1;
            i128 k2=p2;
            ans=max((A*k1*k1+B*k1+C)/2,(A*k2*k2+B*k2+C)/2);
        }        
        return ans;
    };
    auto check=[&](LL c)->LL{
        i128 A=-a;
        i128 B=a-2*b+2*a*c;
        i128 C=2*c*b-c*c+c;
        i128 kx=(c-1)/a+1;
        i128 res=getv(c,kx);
        if(res>=x)return 1;
        //printf("{%lld,%lld,%lld}\n",A,B,C);
        if(B<0){
            i128 k1=kx;
            i128 ans=(A*k1*k1+B*k1+C)/2;

            return ans>=x?1:0;
        }
        i128 p1=(B-1)/(-2*A)+1;
        i128 p2=-B/(2*A);
        i128 ans=0;
        if(p2>=c){
            i128 k=c;
            ans=(A*k*k+B*k+C)/2;
        }else{
            i128 k1=max(kx,p1);
            i128 k2=max(kx,p2);
            ans=max((A*k1*k1+B*k1+C)/2,(A*k2*k2+B*k2+C)/2);
        }
        ans=max(ans,res);
        if(ans>=x){
            return 1;
        }else{
            return 0;
        }
    };    
    LL l=1;
    LL r=1e9+5;
    LL ans=1;
    while(l<=r){
        LL mid=(l+r)/2;
        LL tag=check(mid);
        if(tag){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
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