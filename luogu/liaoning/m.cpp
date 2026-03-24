#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
using LL=long long;
struct node{
    LL a;
    LL b;

}a[N];
bool cmp(node x, node y) {
    if (max(x.a, x.b) == max(y.a, y.b)) {
        return x.a < y.a;
    }
    return max(x.a, x.b) < max(y.a, y.b);
}
void solve(){
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
    }
    sort(a+1,a+1+n,cmp);
    LL x=0;
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(x>a[i].a){
            continue;
        }
        x=max(a[i].b,x);
        ans++;
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    return 0;
}