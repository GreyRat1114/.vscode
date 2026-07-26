#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        LL x;
        cin>>x;
        a[i]=abs(x%2);
    }
    //cout<<(-3)%2<<'\n';
    if(n==0){
        cout<<0<<'\n';
        return;
    }
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    LL tag=1;
    for(int i=2;i<=n;i++){
        if((a[i]^a[i-1])==0){
            tag=0;
        }
    }
    if(tag){
        cout<<2<<'\n';
        return;
    }
    LL c0=0,c1=0;
    LL tot=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            c1=0;
            c0++;
        }
        if(a[i]==1){
            c0=0;
            c1++;
        }
        if((c1==2)||(c0==2)){
            tot++;
        }
        if((c1>=3)||(c0>=3)){
            cout<<0<<'\n';
            return;
        }
    }
    if(tot>=2){
        cout<<0<<'\n';
        return;
    }
    cout<<2<<'\n';

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