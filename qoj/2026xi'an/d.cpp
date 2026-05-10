#include<bits/stdc++.h>
//using namespace std;
using ll=long long;
const int N=5e5+10;
int a[N];
void solve(){
     int n;
     ll m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    std::sort(a+1,a+1+n);
    ll y=1;
    ll  maxn=m;
    int t=0;
    ll x=0;
    for(int i=1;i<=n;i++){
        if(x>=a[i]){
            x-=a[i];
            y++;
            maxn=std::max((m-t)*y+x,maxn);
        }else{
            ll cal=(a[i]-x+y-1)/y;
            t+=cal;
            x+=cal*y;
            y++;
            x-=a[i];
            if(t>m){
                break;
            }else{
                maxn=std::max(maxn,(m-t)*y+x);
            }
        }
        if(t>m){
            break;
        }
    }
    std::cout<<maxn<<'\n';
}
int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}