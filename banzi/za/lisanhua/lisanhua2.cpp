#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
void solve(){
    LL n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    LL m=unique(a+1,a+1+n)-a-1;
    cout<<m<<'\n';
    for(int i=1;i<=m;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
    for(int i=1;i<=q;i++){
        LL x;
        cin>>x;
        LL p=lower_bound(a+1,a+1+m,x)-a;//第一个大于等于x的值的位置
        //LL p=upper_bound(a+1,a+1+m,x)-a-1;//第一个小于等于x的值的位置
        cout<<p<<'\n';
    }
    
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}