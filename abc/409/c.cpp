#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+5;
LL vis[N];
void solve(){
    memset(vis,0,sizeof(vis));
    LL n,l;
    cin>>n>>l;
    LL x;
    LL y=l/3;
    vis[0]++;
    LL p=0;
    LL ans=0;
    for(int i=2;i<=n;i++){
        cin>>x;
        x=x%l;
        p=(p+x)%l;
        vis[p]++;
    }
    if(l%3!=0){
        cout<<0<<'\n';
        return;
    }    
    for(int i=0;i<l;i++){
        ans+=vis[i]*vis[(i+y)%l]*vis[(i+y+y)%l];    
    }
    cout<<ans/3<<'\n';
}
int main(){ 
    solve();
    return 0;
}