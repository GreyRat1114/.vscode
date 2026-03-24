#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
struct node{
    LL w,p;
}a[N];
LL d[N];
bool cmp(LL x,LL y){
    return x>y;
}
void solve(){
    int n;
    cin>>n;
    LL s=0;
    for(int i=1;i<=n;i++){
        
        cin>>a[i].w>>a[i].p;
        d[i]=a[i].p+a[i].w;
        s+=a[i].w;
    }
    sort(d+1,d+1+n,cmp);
    LL x=0;
    for(int i=1;i<=n;i++){
        x+=d[i];
        if(x-s>=0){
            cout<<n-i<<'\n';
            return;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
