#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),s(n+1,0);
    LL maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]^a[i];
        maxn=max(maxn,s[i]);
        //printf("{%lld}",s[i]);
    }
    LL m=(n+1)*n/2;
    LL pt1=0;
    for(int i=1;i<=n;i++){
        pt1+=(i+1ll)/2;
    }
    LL pt2=0;
    vector<LL> cnt0(maxn*2+5,0);
    vector<LL> cnt1(maxn*2+5,0);
    cnt0[0]=1;
    for(int i=1;i<=n;i++){
        if(i&1){
            pt2+=cnt1[s[i]];
            cnt1[s[i]]++;
        }else{
            pt2+=cnt0[s[i]];
            cnt0[s[i]]++;
        }
    }

    LL ans2=pt1+pt2;
    LL ans1=m-pt1-pt2;
    //printf("{%lld,%lld,%lld,}\n",m,pt1,pt2);
    cout<<ans1<<' '<<ans2<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}