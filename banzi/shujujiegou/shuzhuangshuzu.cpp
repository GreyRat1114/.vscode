//luogu P3374
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
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
    LL n,m;
    cin>>n>>m;
    Tree tr;
    tr.init(n);
    LL op,x,k,y;
    for(int i=1;i<=n;i++){
        cin>>x;
        tr.update(i,x);
    }
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>x>>k;
            tr.update(x,k);
        }else if(op==2){
            cin>>x>>y;
            cout<<tr.query(y)-tr.query(x-1)<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
