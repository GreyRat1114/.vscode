#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    LL n,m;
    cin >> n >> m;
    m=m;
    vector<LL> a(2*n+2);
    for(int i=1;i<=2*n;i++){ 
        LL x;
        cin >> x;
        a[i]=x;
    }
    vector<LL> b=a;
    LL ans1=0;
    LL ans2=0;
    LL pre=a[1];
    a[2]+=m;
    if(a[2]>pre)ans1++;
    for(int i=2;i<=n;i++){
        LL x=a[2*i-1];
        LL y=a[2*i];
        LL mini=min(x,y);
        LL maxn=max(x,y);
        if(mini>pre){
            ans1+=2;
        }else if(maxn>pre){
            ans1++;
            if(pre-mini+1<=m)ans1++;
        }else{
            LL d=2*pre-maxn-mini;
            if(m-d>=1){
                ans1+=2;
            }else if(m-d==0){
                ans1++;
            }else{
                if(pre-maxn+1<=m)ans1++;
            }
        }
    }
    b[1]+=m;
    pre=b[1];
    if(b[2]>pre)ans2++;
    for(int i=2;i<=n;i++){
        LL x=b[2*i-1];
        LL y=b[2*i];
        LL mini=min(x,y);
        LL maxn=max(x,y);
        if(mini>pre){
            ans2+=2;
        }else if(maxn>pre){
            ans2++;
        }else{
            LL d=2*pre-maxn-mini;
            if(m-d>=1){
                ans2++;
            }
        }            
    }
    cout<<ans2<<' '<<ans1<<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}