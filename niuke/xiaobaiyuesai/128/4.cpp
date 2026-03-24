#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL s[N];
LL ans[N];
struct node{
    LL x;
    int num;
}a[N];
bool cmp(node x,node y){
    return x.x<y.x;
}

LL n,m;
int check(int x){
    int l=1;
    int r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid].x+a[x].x<=m){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return l-1;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].num=i;
    }
    sort(a+1,a+1+n,cmp);
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i].x;
    }
    for(int i=1;i<=n;i++){
        LL p=check(i);
        LL q=p;
        if(p>=i){
            q--;
        }
        LL d=0;
        if(p<i){
            d=a[i].x;
        }
        //printf("{%lld}",d);
        ans[a[i].num]=q*a[i].x-(s[n]-s[p])+d;
        //printf("<%d %lld>",a[i].x,s[n]-s[p]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}