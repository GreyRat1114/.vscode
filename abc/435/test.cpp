#include<bits/stdc++.h>
using namespace std;
#define IT set<node>::iterator
const int N=5e5+5;
using LL=long long;
struct node{
    LL l,r;
    // bool operator < (node o) {
    //     return l<o.l;
    // }
}a[N];
bool operator < (node a,node b){
    return a.l<b.l;
}
void solve(){
    LL n,q;
    cin>>n;
    LL l,r;
    int tot=0;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        a[i].l=l;
        a[i].r=r;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        printf("{%lld,%lld}",a[i].l,a[i].r);
    }    
}
int main(){
    solve();
    return 0;
}
