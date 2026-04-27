#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n;
    cin>>n;   
    LL m=sqrt(n); 
    if(m*m!=n){
        cout<<"NO"<<'\n';
        return;
    }
    vector<LL> a(100);
    LL tot=0;
    while(n){
        tot++;
        a[tot]=n%10;
        n=n/10;
    }
    LL tag1=1;
    LL tag2=1;
    for(int i=1;i<=tot;i++){
        if(a[i]!=a[tot-i+1]){
            tag1=0;
        }   
    }
    a.clear();
    tot=0;
    while(m){
        tot++;
        a[tot]=m%10;
        m=m/10;
    }
    for(int i=1;i<=tot;i++){
        if(a[i]!=a[tot-i+1]){
            tag2=0;
        }   
    }    
    if(tag1&&tag2){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
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