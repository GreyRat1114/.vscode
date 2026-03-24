#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
struct node{
    LL x;
    LL y;
    double k;
}a[N];
priority_queue<pair<double,int>> q;
LL check(double k,LL l,LL r,LL x){
    LL ans=l;
    while(l<=r){
        LL mid=(l+r)/2;
        double k1=1.0*mid/x;
        if(k1<k){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
void solve(){
    LL n,w;
    cin>>n>>w;
    LL x,y;
    double k;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        k=1.0*y/x;
        a[i].x=x;
        a[i].y=y;
        a[i].k=k;
        q.push(mp(k,i));
    }
    if(n==1){
        LL minn=max(0ll,a[1].y-w);
        cout<<setprecision(10)<<fixed<<sqrt(minn*minn+a[1].x*a[1].x)<<'\n';
        return;
    }
    while(w){
        k=q.top().first;
        int num=q.top().second;
        q.pop();
        double k2=q.top().first;
        x=a[num].x;
        y=a[num].y;
        double k1=1.0*y/x;
        //printf("{%lld,%lld}",x,y);
        y=check(k2,max(0ll,y-w),y,x);
        //printf("{%lld,%lld}",max(0ll,y-w),y);
        
        w-=a[num].y-y;
        a[num].y=y;
        //printf("{%lld,%d,%d}",y,num,w);
        if(y!=0){
            q.push(mp(k1,num));
        }
        if(q.size()==1){
            break;
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++){
        ans+=sqrt(a[i].y*a[i].y+a[i].x*a[i].x);
    }
    cout<<setprecision(10)<<fixed<<ans<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}