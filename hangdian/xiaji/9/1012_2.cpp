#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
struct Tree{
    LL n;
    vector<LL> s;
    void init(LL _n){
        n=_n;
        s.assign(n+1,0);
    }
    LL lowbit(LL x){
        return x&-x;
    }
    void update(LL x,LL k){
        while(x<=n){
            s[x]+=k;
            x+=lowbit(x);
        }
    }
    LL query(LL x){
        LL ans=0;
        while(x){
            ans+=s[x];
            x-=lowbit(x);
        }
        return ans;
    }
};

void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    vector<pair<LL,LL>> b;
    LL m=3e5;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&i!=n)b.push_back({a[i],i});
    }
    LL ans=0;
    for(int i=1;i<=n;i++){

        for(int j=i+1;j<=n;j++){
            LL pre=0,cur=0;
            for(int k=1;k<=n-1;k++){
                pre+=(a[k]-a[k+1])*(a[k]-a[k+1]);
            }            
            swap(a[i],a[j]);
            for(int k=1;k<=n-1;k++){
                cur+=(a[k]-a[k+1])*(a[k]-a[k+1]);
            }
            swap(a[i],a[j]);
            if(cur>pre)ans++;
            
        }
    }
    cout<<ans<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}