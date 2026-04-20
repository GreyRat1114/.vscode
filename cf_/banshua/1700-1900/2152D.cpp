#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL check(LL x){
    LL y=x;
    LL cnt=0;
    while(x){
        if(x&1)cnt++;
        x=x>>1;
    }
    if(cnt==2&&y&1)return 0;
    return cnt;
}
LL tot(LL x){
    LL cnt=0;
    while(x){
        cnt++;
        x=x>>1;

    }
    return cnt-1;
}
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(n+1,0),s1(n+1,0),s2(n+1),s3(n+1,0),s(n+1,0);
    LL pt1=0,pt2=0,pt3=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        LL x=check(a[i]);
        s[i]=s[i-1]+tot(a[i]);
        s1[i]=s1[i-1];
        s2[i]=s2[i-1];
        s3[i]=s3[i-1];
        if(x==0){
            s1[i]++;
        }else if(x==1){
            s2[i]++;
        }else{
            s3[i]++;
        }
    }
    LL l,r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        LL ans=(s1[r]-s1[l-1])/2+s3[r]-s3[l-1]+s[r]-s[l-1];
        cout<<ans<<'\n';
    }

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
    return 0;
}