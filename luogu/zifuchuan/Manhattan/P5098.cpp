#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int b[N];
void solve(){
    int n;
    cin>>n;
    int x,y;
    int a,b;
    int maxn=-1e9,maxn2=-1e9;
    int minn=1e9,minn2=1e9;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a=x+y;
        maxn=max(maxn,a);
        minn=min(minn,a);
        b=x-y;
        maxn2=max(maxn2,b);
        minn2=min(minn2,b);        
    }
    int ans=max((maxn-minn),(maxn2-minn2));
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}