#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+10;
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
    Tree tr1,tr2;
    tr1.init(n);
    tr2.init(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<set<LL>> q(2);
    LL s1=0,s2=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            s1+=tr1.query(n)-tr1.query(a[i]);
            tr1.update(a[i],1);
        }else{
            s2+=tr2.query(n)-tr2.query(a[i]);
            tr2.update(a[i],1);
        }
    }
    for(int i=1;i<=n;i++){
        q[i%2].insert(a[i]);
    }
    for(int i=1;i<=n-3;i++){
        a[i]=*q[i%2].begin();
        q[i%2].erase(q[i%2].begin());        
    }
    for(int i=n-2;i<=n;i++){
        a[i]=*q[i%2].begin();
        q[i%2].erase(q[i%2].begin());
    }
    if(s1%2!=s2%2){
        swap(a[n],a[n-2]);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' '; 
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}