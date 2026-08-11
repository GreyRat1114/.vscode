#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
struct node{
    LL x,y,z;
};
void solve(){
    LL n;
    cin>>n;
    LL x,y,z;
    vector<node> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        a[i]={x,y,z};
        cin>>x>>y>>z;
        b[i]={x,y,z};
    }   
    LL s1=0,s2=0;
    for(int i=1;i<=n;i++){
        s1+=a[i].x;
        s2+=b[i].x;
    }
    node tar;
    tar.x=a[1].x+(s1)
    
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}