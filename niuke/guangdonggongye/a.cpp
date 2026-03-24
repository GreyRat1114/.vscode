#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
void solve(){
    int n;
    cin>>n;
    int maxn=-1;
    int minn=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    cout<<1<<' '<<n<<' '<<maxn-minn<<'\n';
}
int main(){
    solve();
    return 0;
}