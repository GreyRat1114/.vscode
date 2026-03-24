#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
void solve(){
    int n;
    cin>>n;
    vector<LL> a(n,0),b(n,0);
    for(int i=1;i<=n;i++){
        cin>>a[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i-1];
    }
    vector<LL> c(40,0),w(40,0),id(40,0);
    for(int i=0;i<n;i++){
        LL x=a[i]^b[i];
        LL y=0;
        for(int j=30;j>=0;j--){
            if(x&(1<<j)){
                if(c[j]){
                    x=x^c[j];
                    y=y^w[j];
                }else{
                    c[j]=x;
                    id[j]=i;
                    w[j]=y^(1<<j);
                    break;
                }
            }
        }
    }
    LL tar=0;
    LL op=0;
    for(auto x:a){
        tar=tar^x;
    }
    for(int j=30;j>=0;j--){
        if(tar&(1<<j)){
            tar=tar^c[j];
            op=op^w[j];
        }
    }
    if(tar!=0){
        cout<<-1<<'\n';
        return;
    }
    for(int j=30;j>=0;j--){
        if(op&(1<<j)){
            a[id[j]]=b[id[j]];
        }
    }  
    for(auto x:a){
        cout<<x<<' ';
    }      
    cout<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}