#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    priority_queue<LL> q;
    int n;
    LL x,ans=0;
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>x;
        q.push(x);
        if(i%2==1){
            ans+=q.top();
            q.pop();
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}