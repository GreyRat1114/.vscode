#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
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
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL tag=1;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1])tag=0;
    }
    if(tag){
        cout<<"Bob"<<'\n';
        return;
    }
    LL c=0;
    vector<vector<LL>> p(n+1);
    for(int i=1;i<=n;i++){
        LL x=a[i];
        for(auto y:prim){
            if(x%y==0)p[i].push_back(y);
            while(x&&x%y==0){
                x=x/y;
            }
        }
        if(x!=a[i]&&x!=1)p[i].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(p[i].size()>=2){
            cout<<"Alice"<<'\n';
            return;
        }
    }
    LL pre=-1;
    for(int i=1;i<=n;i++){
        
        if(p[i].empty()){
            if(a[i]<pre){
                cout<<"Alice"<<'\n';
                return;
            }            
            pre=a[i];
        }else{
            if(p[i][0]<pre){
                cout<<"Alice"<<'\n';
                return;
            }
            pre=p[i][0];
        }

    }
    cout<<"Bob"<<'\n';
    //cout<<c<<'\n';


}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    not_prim.assign(1e3+15,0);
    get_prim(1e3+5);
    //cout<<prim.size()<<'\n';
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}