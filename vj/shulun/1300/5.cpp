//cf1401C
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=100005;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),b(n+1,0);
    LL mini=1e11;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mini=min(mini,a[i]);
    }
    priority_queue<LL,vector<LL>,greater<LL>> q;
    for(int i=1;i<=n;i++){
        if(a[i]%mini==0){
            q.push(a[i]);
        }else{
            b[i]=a[i];
        }
    }
    // for(auto x:b){
    //     cout<<x<<' ';
    // }
    // cout<<'\n';
    LL tag=1;
    for(int i=1;i<=n;i++){
        if(b[i]){
            if(b[i]<b[i-1])tag=0;
            continue;
        }
        LL x=q.top();
        q.pop();
        if(x<b[i-1])tag=0;
        b[i]=x;
    }

    if(tag){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
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