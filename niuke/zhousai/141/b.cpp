#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL x,y;
    cin>>x>>y;
    if(x>y){
        cout<<0<<'\n';
        return;
    }else if(x<y){
        for(LL i=30;i>=0;i--){
            
            LL a=(1<<i);
            //printf("{%lld,%lld,%lld}",i,(!(a&x)),((a&y)>0));
            if((!(a&x))&&((a&y)>0)){
                cout<<(1<<i)<<'\n';
                return ;
            }
        }
    }
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}