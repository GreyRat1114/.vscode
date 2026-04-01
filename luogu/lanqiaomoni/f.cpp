#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
void solve(){
    LL n,x,y,w;
    cin>>n>>x>>y>>w;
    vector<LL> a(y+1);
    //LL minn=1e9,maxn=0;
    LL x1,y1;
    for(int i=1;i<=n;i++){
        cin>>x1>>y1;
        a[x1]=y1;
    }
    vector<LL> cnt(y+1,0);
    LL lst=0;
    for(LL i=1;i<=y;i++){
        if(a[i]==0){
            continue;
        }
        if(a[i]<=lst){
            lst-=a[i];
            continue;
        }
        LL s=a[i]-lst;
        
        cnt[i]=(s-1ll)/w+1ll;
        
        lst=(s%w==0)?0:w-(s%w);
        //printf("{%lld,%lld,%lld,%lld}\n",i,s,cnt[i],lst);
    }
    LL ans=0;
    LL p=x;
    // for(LL i=1;i<=y;i++){
    //     printf("{%lld}",cnt[i]);
    // }
    int tag=1;
    for(LL i=1;i<=y;i++){
        if(a[i]==0)continue;
        LL d;
        if(tag){
            d=max(0ll,x-i)+y-i;
            LL d2=(y-i)*2;
            ans+=d+d2*(cnt[i]-1);
            tag=0;
        }else{
            d=(y-i)*2;
            ans+=d*cnt[i];
        }   
        //ans+=d*cnt[i];
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}