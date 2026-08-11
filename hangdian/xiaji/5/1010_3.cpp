#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
vector<i128> a;
vector<i128> p;// 把所有向量insert，得到第i为可表示为1的pi
vector<LL> val;
map<i128,LL> mp;
i128 yi=1;
void insert(i128 x){
    i128 v=mp[x];
    for(int i=105;i>=0;i--){
        if((x>>i)&yi){
            if(p[i]){
                x^=p[i];  
                v^=val[i];  
            }else{
                p[i]=x;
                val[i]=v;
                break;
            }
        }
    }
}
void solve(){
    //print((i128)1<<100);
    LL k;
    cin>>k;
    p.assign(200,(i128)0);
    val.assign(1e4+5,0);
    a.clear();
    mp.clear();
    vector<LL> s(k+1);
    vector<vector<LL>> c(k+1,vector<LL>());
    vector<LL> vis(1e4+5,0);
    for(int i=1;i<=k;i++){
        LL cx,sx;
        cin>>cx>>sx;
        i128 res=0;
        for(int j=1;j<=cx;j++){
            LL x;
            cin>>x;
            x--;
            res=res^(yi<<x);
        }
        a.push_back(res);
        mp[res]=sx;
    }
    for(int i=0;i<a.size();i++){
        insert(a[i]);
    }
    LL q;
    cin>>q;
    
    for(int i=1;i<=q;i++){
        LL d;
        cin>>d;
        i128 res=0;
        LL ans=0;
        LL tag=1;
        for(int j=1;j<=d;j++){
            LL r;
            cin>>r;
            r--;
            res=res^(yi<<r);
        }
        for(int i=105;i>=0;i--){
            if(res&(yi<<i)){
                if(p[i]){
                    res=res^p[i];
                    ans=ans^val[i];
                }else{
                    tag=0;
                }
            }
        }
        if(tag){
            cout<<ans<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    //cout<<1<<'\n';
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
