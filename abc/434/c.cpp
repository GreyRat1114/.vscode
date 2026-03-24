#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
struct node{
    LL u,l;
    LL t;
}a[N];
bool cmp(node a,node b){
    return a.t<b.t;
}
void solve(){
    LL n,h;
    cin>>n>>h;
    LL t,l,u;
    for(int i=1;i<=n;i++){
        cin>>t>>l>>u;
        a[i].l=l;
        a[i].u=u;
        a[i].t=t;
    }
    sort(a+1,a+1+n,cmp);
    LL cur=0;
    LL pos=0;
    LL lt=h;
    LL rt=h;
    LL low=1;
    for(int i=1;i<=n;i++){
        t=a[i].t;
        l=a[i].l;
        u=a[i].u;
        LL dt=t-cur;
        cur=t;
        lt=max(low,max(lt-dt,l));
        rt=max(low,min(rt+dt,u));
        if(lt>rt){
            cout<<"No"<<'\n';
            return;
        }
        
    }
    
    cout<<"Yes"<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}