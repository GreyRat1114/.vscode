#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
bool vis[N];
void solve(){
    LL a,b,l,r;
    cin>>a>>b>>l>>r;
    LL t=l-b;
    LL h=r-b;
    // LL h=min(2*b-a,r)-b;
    // LL t=max(b+1,l)-b;
    int tot=0;
    LL n=b-a;
    for(int i=1;i*i<=n;i++){
        // printf("(%d)",i);
        if(n%i==0){
            LL j=n/i;
            // printf("{%lld,%lld}",i,j);
            if(i>=t&&i<=h){
                tot++;
            }
            if(j!=i){
                if(j<=h&&j>=t){
                    tot++;
                }
            }
        }
    }
    cout<<tot<<'\n';
}    
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}