// P3382 三分
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ld=long double;
const ld eps=0.0000001;
LL n;
vector<ld> a;

ld f(ld x){
    ld ans=0;
    for(int i=1;i<=n+1;i++){
        ans=ans*x+a[i];
    }
    return ans;

}
void solve(){
    ld l,r;
    cin>>n;
    cin>>l>>r;
    a.resize(n+2);
    for(int i=1;i<=n+1;i++){
        cin>>a[i];
    }
    while(r-l>eps){
        ld mid=1.0*(l+r)/2.0;
        ld fl=f(mid-eps);
        ld fr=f(mid+eps);
        if(fl<fr){
            l=mid;
        }else {
            r=mid;
        }
    }
    cout<<r<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}