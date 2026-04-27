#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n,m;
    cin>>n>>m;
    if(n==m*(m+1)/2+1){
        cout<<"YES"<<'\n';
        LL tot=1;
        for(int i=1;i<=m;i++){
            LL pre=1;
            for(int j=1;j<=i;j++){
                tot++;
                cout<<tot<<' '<<pre<<'\n';
                pre=tot;
            }
        }
        return;
    }
    if(n%2==0&&m==n/2){
        cout<<"YES"<<'\n';
        for(int i=1;i<=n;i+=2){
            cout<<i<<' '<<i+1<<'\n';
            if(i==n-1)break;
            cout<<i<<' '<<i+2<<'\n';
        }        
        return;
    }else if(n%2==1&&m==n/2&&n>5){
        cout<<"YES"<<'\n';
        //printf("0");
        int i=1;
        for(;i<=n;i+=2){ 
            cout<<i<<' '<<i+1<<'\n';
            if(i==n-4)break;
            cout<<i<<' '<<i+2<<'\n';
        }        
           
        cout<<i-2<<' '<<i+2<<'\n';
        cout<<i+2<<' '<<i+3<<'\n';
        cout<<i+3<<' '<<i+4<<'\n';

        return;
    }
    cout<<"NO"<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}