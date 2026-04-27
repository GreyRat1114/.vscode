#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> a;
void solve(){
    LL n,k;
    cin>>n>>k;
    a.assign(n+1,0);
    stack<pair<LL,LL>> stk;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(stk.empty()){
            stk.push({a[i],1});
            continue;
        }
        if(a[i]==stk.top().first){
            LL cnt=stk.top().second;
            stk.pop();
            if(cnt+1!=k){
                stk.push({a[i],cnt+1});
            }
        }else{
            stk.push({a[i],1});
        }
    }
    LL tot=0;
    vector<LL> b(n+1);
    while(!stk.empty()){
        LL x=stk.top().first;
        LL cnt=stk.top().second;
        stk.pop();
        for(int i=1;i<=cnt;i++){
            tot++;
            b[tot]=x;
        }
    }
    cout<<tot<<'\n';
    for(int i=tot;i>=1;i--){
        cout<<b[i]<<' ';
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