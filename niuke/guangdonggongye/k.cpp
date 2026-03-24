#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
void solve(){
    int n,m;
    int w,p,q;
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p>>q>>w;
        int x=(m*p-1)/q+1;
        if(x>w){
            ans+=x-w;
        }

    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}