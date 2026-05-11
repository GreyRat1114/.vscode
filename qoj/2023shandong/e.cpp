#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
void solve(){
    LL nn,kk,mm,aa,bb;
    cin>>nn>>kk>>mm>>aa>>bb;
    i128 n=nn,k=kk,m=mm,a=aa,b=bb;
    i128 ans=1e18;
    i128 cntb=0;
    if(k==1){
        if(n%m==0){
            cout<<0<<'\n';
        }else{
            cout<<-1<<'\n';
        }
        return;
    }
    while(n){
        i128 l=n,r=n;
        i128 cnta=0;
        //printf("\n{%lld}",cntb);
        while(r<=1e27){
            //printf("{%lld,%lld}",l,r);
            i128 yu=r%m;
            if(r-yu>=l){
                break;
            }
            cnta++;            
            l=k*l;
            r=k*r+k-1;
        }
        ans=min(ans,cntb*b+cnta*a);
        n=n/k;
        cntb++;
    }
    if(ans==1e18){
        cout<<-1<<'\n';
    }else{
        //printf("{%lld}",(LL)cntb*b);
        cout<<(LL)min(ans,cntb*b)<<'\n';
    }
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}