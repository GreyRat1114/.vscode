#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k,p,m;
    cin>>n>>k>>p>>m;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=0;
    priority_queue<LL,vector<LL>,greater<LL>> q;
    for(int i=1;i<=k;i++){
        q.push(a[i]);
    }
    if(p<=k){
        ans++;
        m-=a[k];
        q.pop();
    }else{
        int r=k+1;
        while(1){
            m-=q.top();
            if(m<=0)break;
            q.pop();
            if(r==p)break;
            q.push(a[r]);
            r++;
        }   
        if(m>=a[p])m-=a[p],ans++;

    }

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}