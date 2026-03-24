#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
LL d[N];
LL s1[N],s2[N];
void solve(){
    LL mod=1e9+7;
    LL n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    string s;
    cin>>s;
    LL sum=0;
    LL len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='G'){
            a[i+1]=2*d[i+1];
        }
        else{
            a[i+1]=d[i+1];
        }
        sum+=a[i+1];
    }
    // printf("{%lld}",sum);
    s1[0]=0;
    s2[n+1]=0;
    set<LL> st;
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        s2[i]=s2[i+1]+a[i];
        st.insert(s2[i]);
    }
    // st.erase(s2[1]);
    LL minn=sum;
    for(int i=1;i<=n;i++){
        st.erase(s2[i]);
        if(st.count(s1[i])){
            // printf("<%lld>",s1[i]);
            LL x=sum-s1[i]*2;
            minn=min(minn,x);
        }
    }
    minn=minn%mod;
    minn=(minn*k)%mod;
    cout<<minn<<'\n';
    // for(int i=1;i<=len;i++){
    //     printf("{%d}",s2[i]);
    // }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}