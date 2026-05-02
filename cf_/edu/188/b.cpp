#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<LL> stk;
    vector<LL> pos(n+1,0);
    LL maxn=0;
    LL p;
    for(int i=1;i<=n;i++){
        if(a[i]>=maxn){
            p=i;
            maxn=a[i];
        }
        pos[i]=p;
    }
    p=pos[n]-1;
    LL cnt=1;
    while(p!=0){
        cnt++;
        p=pos[p]-1;
    }
    cout<<cnt<<'\n';
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