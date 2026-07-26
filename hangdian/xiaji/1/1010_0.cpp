#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n%2==1){
        LL mid=n/2+1;
        i128 c1=0,c2=0;
        i128 cl=0,cr=0;
        for(int i=1;i<=n;i++){
            if(i<mid)cl+=a[i];
            if(i>mid)cr+=a[i];        
        }
        if(cl>cr){
            cout<<"YES"<<'\n';
            return;
        }else if(cl<cr){
            cout<<"NO"<<'\n';
            return;
        }
        //printf("{%lld,}",n);
        for(int i=1;i<=n;i++){
            if(i<mid)c1+=(a[i]*(mid-i));
            if(i>mid)c2+=(a[i]*(i-mid));
        }
        if(c1>c2){
            cout<<"YES"<<'\n';
        }else if(c1<=c2){
            cout<<"NO"<<'\n';
        }      
    }else{
        LL mid=n/2+1;
        i128 c1=0,c2=0;
        i128 cl=0,cr=0;
        for(int i=1;i<=n;i++){
            if(i<mid)cl+=a[i];
            if(i>mid)cr+=a[i];        
        }
        if(cl>cr){
            cout<<"YES"<<'\n';
            return;
        }else if(cl<cr){
            cout<<"NO"<<'\n';
            return;
        }
        //printf("{%lld,}",n);
        a[2]+=a[1];
        for(int i=2;i<=n;i++){
            if(i<mid)c1+=(a[i]*(mid-i));
            if(i>mid)c2+=(a[i]*(i-mid));
        }
        if(c1>=c2){
            cout<<"YES"<<'\n';
        }else if(c1<c2){
            cout<<"NO"<<'\n';
        }   
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