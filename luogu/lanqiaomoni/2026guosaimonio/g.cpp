#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL x,y,z;
    cin>>x>>y>>z;
    LL ans=0;
    LL k=1;
    if(z){
        ans++;
        z--;
        k++;
        ans+=k*y;
        if(z>=x){
			ans+=2*(z-x+1);
			ans+=2;
			ans+=3*(x-1);
        }else{
            ans+=3*z;
            ans+=2;
            if(x-z>2){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }else if(x!=0){
        cout<<y+1<<'\n';
    }else{
        cout<<y<<'\n';
    }
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}