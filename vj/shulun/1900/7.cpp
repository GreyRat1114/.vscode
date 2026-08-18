//cf1547F
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
struct ST{
    vector<vector<LL>> st; 
    vector<LL> lg;
    void init(vector<LL>& a,LL n){
        st.assign(n+5,vector<LL>(30,0));
        lg.assign(n+5,0);
        lg[1]=0;
        for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;

        for(int i=1;i<=n;i++)st[i][0]=a[i];

        for(int j=1;(1<<j)<=n;j++){
            for(int i=1;i+(1<<j)-1<=n;i++){
                st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }
    LL query(LL l,LL r){
        LL k=lg[r-l+1];
        return __gcd(st[l][k],st[r-(1<<k)+1][k]);
    }
};
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(2*n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    ST st;
    st.init(a,2*n);
    auto check=[&](LL mid)->LL{
        LL pre=st.query(1,1+mid);
        for(int i=2;i<=n;i++){
            LL g=st.query(i,i+mid);
            if(g!=pre)return 0;
        }
        return 1;
    };
    LL l=0;
    LL r=n-1;
    LL ans=0;
    while(l<=r){
        LL mid=(l+r)/2;
        LL tag=check(mid);
        if(tag){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
        //cerr<<mid<<'\n';
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}