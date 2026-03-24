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
priority_queue<LL,vector<LL>,greater<LL>> b;
void solve(){
    LL n,m;
    LL c,w;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>c>>w;
        a[i].c=c;
        a[i].w=w;
        b.push(w*c);
        //b[i]=w*c;
    }
    //sort(b+1,b+1+n);
    LL ans=0;
    for(LL i=1;i<=n;i++){
        c=a[i].c;
        w=a[i].w;
        LL x=c;
        LL y=w;
        LL pt2=0;
        priority_queue<LL,vector<LL>,greater<LL>> q;
        while(x>=2){
            LL cnt=x/2;
            LL z=x%2;
            pt2=(pt2+(((cnt*y)%mod)*2)%mod)%mod;
            if(z){
                q.push(y);
            }
            x=x/2;
            y=(y*2);
        }        
        pt2=pt2%mod;
        ans=(ans+pt2)%mod;
        //printf("[%lld]",pt2);
        q.push(y);
        LL pre,cur;
        while(q.size()!=1){
            pre=q.top()%mod;
            q.pop();
            cur=q.top()%mod;
            q.pop();
            LL pt=(pre+cur)%mod;
            //printf("{%lld}",pt);
            q.push(pt);
            ans=(ans+pt)%mod;
        }       
    }
    LL pre;
    LL cur;
    while(b.size()!=1){
        pre=b.top();
        b.pop();
        cur=b.top();
        b.pop();
        b.push(pre+cur);
        LL pt=(pre%mod+cur%mod)%mod;
        //printf("{%lld}",pt);
        ans=(ans+pt)%mod;
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