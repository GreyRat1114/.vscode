#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
void solve(){
    LL n,s,x;
    cin>>n>>s>>x;
    LL sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    LL d=s-sum;
    if(d<0){
        cout<<"No"<<'\n';
        return;
    }
    if(d%x==0){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
    // if(sum==s){
    //     cout<<"Yes"<<'\n';
    //     return;
    // }
    // for(int i=0;i<(1<<n);i++){
    //     LL s2=sum;
    //     for(int j=0;(1<<j)<=i;j++){
    //         if(i&j){
    //             s2+=x-a[i];
    //         }
    //     }
    //     if(s2==s){
    //         cout<<"Yes"<<'\n';
    //         return;            
    //     }
    // }
    // cout<<"No"<<'\n';
    // return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}