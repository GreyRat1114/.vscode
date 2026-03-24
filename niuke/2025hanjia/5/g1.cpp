#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=1000000007;
struct node{
    LL c;
    LL w;
}a[N];
priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> b;
void solve(){
    LL n,m;
    LL c,w;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>c>>w;
        a[i].c=c;
        a[i].w=w;
        b.push(mp(w,c));
        //b[i]=w*c;
    }
    //sort(b+1,b+1+n);
    LL ans=0;
    LL pre;
    LL cur;
    LL ct1,ct2;
    while(b.size()!=1){
        pre=b.top().first%mod;
        ct1=b.top().second;
        b.pop();
        LL t=ct1/2;
        if(ct1%2==0){
            LL pt=(pre*t)%mod;
            b.push(mp(pt,t));
            ans=(ans+pt)%mod;
        }else{
            cur=b.top().first%mod;
            ct2=b.top().second;
            b.pop();
            LL pt1=(pre*t)%mod;
            LL pt2=(cur+pre)%mod;
            if(ct2!=1){
                b.push(mp(cur,ct2-1));
            }
            b.push(mp(pt1,t));
            b.push(mp(pt2,1));
            ans=(ans+pt1)%mod;
            ans=(ans+pt2)%mod;
        }
    }        
    cout<<ans<<'\n';    
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}