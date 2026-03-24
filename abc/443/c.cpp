#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
void solve(){
    LL n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=k;
    LL tag=0;
    LL s=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]>=tag){
            s=s+a[i]-tag;
            tag=a[i]+100;
        }
    }
    cout<<s<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}