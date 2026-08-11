//cf230B
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> prim;
vector<LL> not_prim;
void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            if(i%p==0)break;
        }
    }
}
void init(LL n){
    not_prim.assign(n+10,0);
    get_prim(n+1);
}
void solve(){
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++){
        LL x;
        cin>>x;
        if(x==1){
            cout<<"NO"<<'\n';
            continue;
        }
        auto it=lower_bound(prim.begin(),prim.end(),sqrt(x));
        //cout<<*it<<'\n';
        if(it==prim.end()||(*it)*(*it)!=x){
            cout<<"NO"<<'\n';       
        }else{
            cout<<"YES"<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    init(1e6+5);
    //cout<<prim.size()<<'\n';
    while(t--){
        solve();
    }
    return 0;
}